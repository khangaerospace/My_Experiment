clear all
clc
% Aircraft parameter
u = 235.9;
h = 12121;
b = 59.64;
S = 511;
W = 2.83e6;
c = 8.324;
Ixx = 0.247e8;
Iyy = 0.449e8;
Izz = 0.673e8;
Ixz = -0.212e7;
theta = 0; % straint level flight
% natural parameter
g = 9.81;
m = W/g;
% The dimensional stability derivatives
Xu = -2000;
Xw = 4000;
Xq = 0;
Xdw = 0;
Xdu = 0;
Zu = -26000;
Zw = -90000;
Zq = -450000;
Zdw = 2000;
Mu = 16000;
Mw = -160000;
Mq = -1.5e7;
Mdw = -17000;
Mdu = 0;
Mdq = 0;
Zdu = 0;
Zdq = 0;


% Createing M1 and M2 matrix [1a]
M1 = [-Xu, -Xw, -Xq, m*g*cos(theta);
    -Zu, -Zw, -(m*u+Zq), m*g*sin(theta);
    -Mu, -Mw, -Mq, 0;
    0,0,-1,0];
M2 = [(m-Xdu), -Xdw, -Xq, 0;
    -Zdu, (m-Zdw), -Zdq, 0;
    -Mdu, -Mdw, (Iyy - Mdq),0;
    0,0,0,1];

% A matrix for ongitudinal equations [1b]
Atest = -M2^-1*M1;
A = [Xu/m, Xw/m, Xq/m, -g*cos(theta);
    Zu/(m-Zdu), Zw/(m-Zdw), (Zq+m*u)/(m-Zdw), -(m*g*sin(theta)/(m-Zdw));
    (Mu+Zu*Mdw/(m-Zdw))/Iyy, (Mw + Zw*Mdw/(m-Zdw))/Iyy,  (Mq + (Zq+m*u)*Mdw/(m-Zdw))/Iyy, 0;
    0,0,1,0];

%question 1a
% Find Eighenvalue and Eighenvector
[V,D] = eig(A);
% Normalize Eighenvector
lamda1 = V(:,1)/V(end,1);
lamda2 = V(:,2)/V(end,2);
lamda3 = V(:,3)/V(end,3);
lamda4 = V(:,4)/V(end,4);

figure(1)
plot(lamda1,'*');
hold on
plot(lamda2,'*');
plot(lamda3,'*');
plot(lamda4,'*');
grid on
xlabel('Real part');
ylabel('Imaginary part')
hold off

pertur = 0.0125*(real(lamda1)+real(lamda2)+real(lamda3)+real(lamda4));
V_norm = [lamda1, lamda2, lamda3, lamda4];
C = V_norm\pertur;
% now we set X_e
X_e =@(t) u*t + sum(integral(@(t)C.*V_norm(1,:)'.*exp(diag(D)*t),0,t,"ArrayValue",true));
t_at4 = fsolve(@(t) X_e(t) - 40000,150);
t_at2 = fsolve(@(t) X_e(t) - 2000,150);
time4k = real(t_at4);
time2k = real(t_at2);
% solve for Ze, theta, and alpha

Ze = @(t) sum(integral(@(t) -u.*C.*V_norm(4,:)'.*exp(diag(D)*t),0,t,"ArrayValue",true)) + sum(integral(@(t) C.*V_norm(2,:)'.*exp(diag(D)*t),0,t,"ArrayValue",true));

theta = @(t) sum(C.*V_norm(4,:)'.*exp(diag(D)*t));

alpha =@(t) sum(C.*V_norm(2,:)'.*exp(diag(D)*t));

% Setting the time array
 
time_at4k = linspace(0,time4k,1000);
time_at2k = linspace(0,time2k,1000);

Ze_values = zeros(length(time_at4k));
theta_values = zeros(length(time_at4k));
alpha_values = zeros(length(time_at4k));
Xe_values = zeros(length(time_at4k));
% now pass eveything into the graph
for i = 1:length(time_at4k)
    Xe_values(i) = X_e(time_at4k(i));
    Ze_values(i) = Ze(time_at4k(i));
    %
    alpha_values(i) = alpha(time_at4k(i));
    theta_values(i) = theta(time_at4k(i));
end
inverseZe = -1.*Ze_values;
figure(2)
plot(Xe_values(:,1),inverseZe(:,1));
xlabel("X_{E}");
ylabel("Altitude Z_{E}")
title("−Z_{E} vs. X_{E} ")

figure(3)
plot(Xe_values(:,1),theta_values(:,1));
xlabel("X_{E}");
ylabel("\theta")
title("\theta vs. X_{E} ")

figure(4)
plot(Xe_values(:,1),alpha_values(:,1));
xlabel("X_{E}");
ylabel("\alpha")
title("\alpha vs. X_{E}")


