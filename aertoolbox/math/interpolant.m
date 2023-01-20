% Khang Nguyen code
file = load("_YOUR_DATA_");
x = file(:,1);
y = file(:,2);
a = 4/8001;
M = 0:a:4;
p = zeros(8001,1);
ptrue = zeros(8001,1);
error = zeros(8001,1);
for i=1:length(M)
    p(i) = mach2pressure_pwl(M(i));
    ptrue(i) = (1+ ((1.4-1)/2)*M(i)^2)^(-(1.4)/(1.4-1));
    error(i) = abs(p(i) - ptrue(i));
end
plot(M,p);
hold on;
figure(1)
scatter(x,y)
ylabel("Pressure")
xlabel("Mach Number")
title("Pressure vs Mach Number")
% find the error
hold off;
figure(2)
plot(M,error);
ylabel("Error")
xlabel("Mach Number")
title("Error vs Mach Number")

function p = mach2pressure_pwl(file, M)
    % read the data
    x = file(:,1);
    y = file(:,2);
    % find where the Mach number is on the series
    i = find(x(2:end) >= M,1,"first");
    % do the interpolaion
    p =y(i) + ((y(i+1)-y(i))./(x(i+1)-x(i))).*(M - x(i));
end
