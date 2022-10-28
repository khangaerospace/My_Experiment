% Construct the matrix C
c = 10
n = 2
c = @(i).^((i-1)/(n-1))
C = diag(co(1:n));
% make function fsq = x'*C*x
fsq = @(x) x'*C*x
% plot fsq function
figure()
fsurf(@(x1,x2) fsq([x1;x2]), [-1 1 -1 1])
title("f_{sq}(x)")
xlabel('x_1')
ylabel('x_2')
zlabel('f_{sq}')