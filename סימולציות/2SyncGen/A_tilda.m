function result = A_tilda()
global Rtot w0 Ltot mif Dp 
result = [-Rtot w0*Ltot 0;-w0*Ltot -Rtot -mif; 0 mif -Dp];