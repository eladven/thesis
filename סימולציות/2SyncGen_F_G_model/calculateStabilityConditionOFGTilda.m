function [result] = calculateStabilityConditionOFGTilda(Rtot,Rl,Dp,Ltot,id0,iq0)
result = (16*(Rtot+Rl)*Dp > Ltot^2*(id0^2+iq0^2));