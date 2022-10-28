clear all;
% construc array
x = [1;1]
C = diag([1,10])
distance = x + 10
max = 100000 % Maxnumber for integration
error = 0.00000001 % some very small value
% function
delf_sq = @(x) 2*C*x;
alpha = -0.05
i = 0

tic
while(norm(distance-x)>error && i<max)
    distance = x
    x = distance + alpha*delf_sq(distance)
    disp(x)
    i = i+1
end
tot_time = toc
disp(i)
time_per_int = tot_time / i

% Set up Newton Method
x = [1;1]
C = diag([1,10])
distance = x + 10

hess_fsq = @(x) 2*C
j = 0
tic
while(norm(distance-x)>error && i<max)
    distance = x
    x = distance - inv(hess_fsq(distance))*delf_sq(distance)
    j = j +1
end
tot_time = toc
disp(j)
time_per_int = toc/j





