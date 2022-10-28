%finicon
x = [1;1]
C = diag([1,10])
error = 0.00000001
distance = x + 10
delf_sq = @(x) 2*C*x;
options.Tolx = error
tic
[x,fval,exitflag,output] = fmincon(delf_sq, x, [], [], [], [],[],[],[], options)
tot_time=toc
average = tot_time/i
disp(x)
disp(tot_time)
disp(average)