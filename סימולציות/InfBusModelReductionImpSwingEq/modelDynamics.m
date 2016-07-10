function [dx] = modelDynamics(t,x)
global Ls J Dp mif Rs Pm V wg Dwg

wg__ = wg;
if (t > 0.1)
    wg__ = wg + Dwg;
end


dx = InfBusTmVarDynamics(...
    x(1), x(2), x(3), x(4),...
    Ls, J, Dp, mif, Rs, Pm,V,wg__);