% question b
clear all; clc;
syms x
sum = 0
% find the cosine series with calculation
pi =3.14
f = []
% using n=3
for n = 1:3
    sum = sum + ((4*(-1)^n)/(pi^2*n^2))*cos(n*x*pi)
end

ezplot(x,sum+1/3,[-1,2])
grid on;hold on;
% using n = 30
sum_2 = 0
for n = 1:30
    sum_2 = sum_2 + ((4*(-1)^n)/(pi^2*n^2))*cos(n*x*pi)
end
ezplot(x,sum_2+1/3,[-1,2])
grid on;hold on;
%using n = 300
sum_3 =0
for n = 1:300
    sum_3 = sum_3 + ((4*(-1)^n)/(pi^2*n^2))*cos(n*x*pi)
end
ezplot(x,sum_3+1/3,[-1,2])
grid on;hold on;
% compute the real value just to measure with the estimated value.
y = x^2
ezplot(x,y,[0,1])
title('Fourier Series of x^2')
xlabel('y value') 
ylabel('x value') 
legend({'n = 3','n=30','n=300' 'y=x^2'},'Location','southwest')
hold off

%find Maximum diffrent
maxdiff1 = abs(y-sum)
maxdiff2 = abs(y-sum2)
maxdiff3 = abs(y-sum3)
disp(maxdiff1,maxdiff2maxdiff3)




