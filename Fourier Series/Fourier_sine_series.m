% question b
clear all; clc;
syms x n
sum = 0
% find the cosine series with calculation
pi =3.14
sum = 0 

% question c
for n = 1:3
    b_n = 2*int(sin(n*pi*x)*x^2,x,0,1)
    sum = sum + b_n*sin(n*pi*x)
end

ezplot(x,sum,[-1,2])
grid on;hold on;
sum2 = 0
for n = 1:30
    b_n2 = 2*int(sin(n*pi*x)*x^2,x,0,1)
    sum2 = sum2 + b_n2*sin(n*pi*x)
end
ezplot(x,sum2,[-1,2])
grid on;hold on;

sum3 = 0
for n = 1:300
    b_n2 = 2*int(sin(n*pi*x)*x^2,x,0,1)
    sum3 = sum3 + b_n2*sin(n*pi*x)
end
ezplot(x,sum3,[-1,2])
grid on;hold on;

% compute the real value just to measure with the estimated value.
y = x^2
ezplot(x,y,[-1,2])
title('Fourier Series of x^2')
xlabel('y value') 
ylabel('x value') 
legend({'n = 3','n=30','n=300' 'y=x^2'},'Location','southwest')
hold off

% % Find the value at each point
% [maxdiff1,index1] = max(abs(y-sum))
% [maxdiff2,index2] = max(abs(y-sum2))
% [maxdiff3,index3] = max(abs(y-sum3))
% disp(maxdiff1,maxdiff2maxdiff3)
