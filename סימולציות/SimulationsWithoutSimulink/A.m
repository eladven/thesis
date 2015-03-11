function a = A(omega)
global R mif J Dp L
 a = [-R/L   omega   0       0;
      -omega -R/L  -mif/L    0;
       0     mif/J -Dp/J     0;
       0      0      1       0];