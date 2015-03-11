function b = B(delta)
global Rl
 b = [Rl*cos(delta)   -Rl*sin(delta)     0       0;
      Rl*sin(delta)    Rl*cos(delta)     0       0;
       0                0                0       0;
       0                0               -1       0];