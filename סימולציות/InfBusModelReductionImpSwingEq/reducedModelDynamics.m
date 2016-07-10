function [dx] = reducedModelDynamics(t,x)
global Ls J Dp mif Pm V wg Dwg

wg__ = wg;
if (t > 0.1)
    wg__ =  wg + Dwg;
end

dx = ImpSwingEq(...
    x(1), x(2),...
    Ls, J, Dp, mif, Pm,V,wg__);