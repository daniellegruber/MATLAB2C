% dftfilt2() - discrete complex wavelet filters
%
% Usage:
%   >> wavelet = dftfilt2( freqs, cycles, srate, cyclefact)
%
% Inputs:
%   freqs    - frequency array
%   cycles   - cycles array. If one value is given, all wavelets have
%              the same number of cycles. If two values are given, the
%              two values are used for the number of cycles at the lowest
%              frequency and at the highest frequency, with linear 
%              interpolation between these values for intermediate
%              frequencies
%   srate    - sampling rate (in Hz)
%
%   cycleinc - ['linear'|'log'] increase mode if [min max] cycles is
%              provided in 'cycle' parameter. {default: 'linear'}
%   type     - ['sinus'|'morlet'] wavelet type is a sinusoid with
%              cosine (real) and sine (imaginary) parts tapered by
%              a Hanning or Morlet function. 'morlet' is a typical Morlet 
%              wavelet (with p=2*pi and sigma=0.7) best matching the 
%              'sinus' Hanning taper) {default: 'morlet'}
% Output:
%   wavelet - cell array of wavelet filters
%
% Note: The length of the window is automatically computed from the 
%       number of cycles and is always made odd.
%
% Authors: Arnaud Delorme, SCCN/INC/UCSD, La Jolla, 3/28/2003

% Copyright (C) 3/28/2003 Arnaud Delorme 8, SCCN/INC/UCSD, arno@salk.edu
%
% This file is part of EEGLAB, see http://www.eeglab.org
% for the documentation and details.
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
% 1. Redistributions of source code must retain the above copyright notice,
% this list of conditions and the following disclaimer.
%
% 2. Redistributions in binary form must reproduce the above copyright notice,
% this list of conditions and the following disclaimer in the documentation
% and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
% THE POSSIBILITY OF SUCH DAMAGE.

function wavelet = dftfilt2_2_c( freqs, cycles, srate, cycleinc, type)

    if nargin < 3
        error('3 arguments required');
    end
    if nargin < 5
        type = 'morlet';
    end

    % compute number of cycles at each frequency
    % ------------------------------------------
    if length(cycles) == 1
        cycles = cycles*ones(size(freqs));
    elseif length(cycles) == 2
        if nargin == 4 && strcmpi(cycleinc, 'log') % cycleinc
            cycles = linspace(log(cycles(1)), log(cycles(2)), length(freqs));
            cycles = exp(cycles);
        else
            cycles = linspace(cycles(1), cycles(2), length(freqs));
        end
    end
    
    % compute wavelet
    wavelet = cell(1,length(freqs));
    for index = 1:length(freqs)
        
        % number of cycles depend on window size 
        % number of cycles automatically reduced if smaller window
        % note: as the number of cycle changes, the frequency shifts a little
        %       this has to be fixed
        
        winlen = cycles(index)*srate/freqs(index);
        winlenint = floor(winlen);
        if mod(winlenint,2) == 1, winlenint = winlenint+1; end; 
        winval = linspace(winlenint/2, -winlenint/2, winlenint+1);        
        
        if strcmpi(type, 'sinus') % Hanning
            win = exp(2i*pi*freqs(index)*winval/srate);
            wavelet{index} = win .* hanning(length(winval))';

        else % Morlet
            t = freqs(index)*winval/srate;
            p = 2*pi;
            s = cycles(index)/5;
            wavelet{index} = exp(j*t*p)/sqrt(2*pi) .* ...
                (exp(-t.^2/(2*s^2))-sqrt(2)*exp(-t.^2/(s^2)-p^2*s^2/4));
        end;    
    end
    
    
    return;
    
    


% syemtric hanning function
function w = hanning(n)
if ~rem(n,2)
   w = .5*(1 - cos(2*pi*(1:n/2)'/(n+1)));
   w = [w; w(end:-1:1)];
else
   w = .5*(1 - cos(2*pi*(1:(n+1)/2)'/(n+1)));
   w = [w; w(end-1:-1:1)];
end
