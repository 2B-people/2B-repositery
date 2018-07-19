function [volime] = pillar(Do,Di,height)
if nargin == 2
    height = 1;
end
volime = abs(Do.^2-Di.^2).*height*pi/4;
