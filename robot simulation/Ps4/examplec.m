close all; clear; clc;
%Diagonal Matrix C
 %Define Variables
 c = 10;
 n = 2;
C = diag(func(1:n));
%Definition of Functions
f_sq = @(x) transpose(x)*C*x;
f_hole = @(x) 1-exp(transpose(x)*C*x);
%Plot and Label the graph of f_sq
figure()
ezsurf(@(x_1,x_2) f_sq([x_1;x_2]), [-1,1,-1,1])
title('f_{sq}(x)')
xlabel('x_1')
ylabel('x_2')
zlabel('f_{sq}')
%Plot and Label the graph of f_hole
figure()
ezsurf(@(x_1,x_2) f_hole([x_1;x_2]), [-1,1,-1,1])
title('f_{hole}(x)')
xlabel('x_1')
ylabel('x_2')
zlabel('f_{hole}')
%Definition of Diagonal Matrix C
function c_func = func(i)
 %Define Variables
 c = 10;
 n = 2;
 c_func = c.^((i-1)/(n-1));
end