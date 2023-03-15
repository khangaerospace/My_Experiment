clear all;
clc
fun = @(z) my_fun(z);
tol = 0.000001; 
x0 = [0;1]; % set starting point
[x,fmin,path] = my_newton_opt(fun,x0,tol);
xx = linspace(-1.25,1.25);
yy = linspace(-0.75,1.75);
[X,Y] = meshgrid(xx,yy);
% create value for z
f = zeros(size(xx));
for i = 1:length(xx)
    for j = 1:length(yy)
        Z = [X(i,j),Y(i,j)];
        f(i,j) = my_fun(Z);
    end
end
numlevels = 100;
figure();
contourf(X,Y,f,numlevels,'edgecolor','none')
colorbar
hold on;
plot(path(1,:),path(2,:),'o-r');
xlabel('x');
ylabel('y');
title('Contour plot of the Rosenbrock function ')



function [x,fmin,path] = my_newton_opt(fun,x0,tol)
    xi = x0;
    [f,df,ddf] = fun(xi);
    path = xi;
    count = [1:6];
    nor = zeros(0,6);
    i = 1;
    while norm(ddf\df) > tol
        [f,df,ddf] = fun(xi);
        xi = xi - (ddf\df);
        nor(i) = norm(ddf\df);
        path = [path,xi];
        fprintf('%d %.4e\n', i, norm(ddf\df));
        i = i+1;
    end
    plot(count,nor)
    x = xi;
    fmin = f;
    
end

function [f,df,ddf] = my_fun(z)
    x = z(1);
    y = z(2);
    a = 10;
    f = (1-x)^2 + a*(y-x^2)^2;
    df = [4*a*x^3 + (2-4*a*y)*x - 2; 2*a*(y-x^2)];
    ddf = [12*a*x^2 - 4*a*y + 2, -4*a*x; -4*a*x, 2*a];
end

