h=0.1;                                             % step size
x = 0:h:60;                                        
%y(1) = [-0.5;0.3;0.2];
 
F_xy = @(t) -2*cos(t/2) + 2*sin(t/2) + 2;                    

y = F_xy(x)



y = @(x) x
dy =@(x) -(1/4)*x+1/2


y0 = [0 1];
tspan = 0:h:60
yx = ode4([y dy], tspan, y0);
f = y - yx'
plot(x,y)