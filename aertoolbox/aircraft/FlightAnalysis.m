% Question 1
% this will calculate the drag on an airfoil

clear all;
W = 88300;
altitude = [0; 2500; 5000; 7500; 10000; 12500; 15000];
rho = [1.225; 0.9582; 0.7364; 0.5579; 0.4125; 0.3042; 0.1948];
temp = [288.15; 271.91; 255.68; 239.46; 223.15; 219.95; 216.69];
v_inf = 0:0.1:670;
drag = zeros(length(rho),length(v_inf));
for i = 1:length(rho)
    for j = 1:length(v_inf)
        drag(i, j) = 0.292*rho(i)*v_inf(j)^2 + 22245391/(rho(i)*v_inf(j)^2);
    end
    
end
figure(1);
for k = 1:length(rho)
    plot(v_inf,drag(k,:));
    hold on
end
axis([0 600 0 70000]);
legend({'0', '2500', '5000', '7500', '10000','12500'},'Location','northwest');
xlabel("Velocity (m/s)");
ylabel("Drag (N)");
title("Velocity vs Drag")
hold off;
figure(2);
loverd = W./drag;
for k = 1:length(rho)
    plot(v_inf,loverd(k,:));
    hold on;
end
legend({'0', '2500', '5000', '7500', '10000','12500'});
xlabel("Velocity (m/s)");
ylabel("ML/D");
title("L/D vs Drag")
hold off;

airspeed = sqrt(1.4*297.*temp);
Mach = v_inf ./ airspeed;

MLoverD = loverd.*Mach;

figure(3)
for k = 1:length(rho)
    plot(v_inf,MLoverD(k,:));
    hold on;
end
legend({'0', '2500', '5000', '7500', '10000','12500'},'Location','northwest');
xlabel("Velocity (m/s)");
ylabel("ML/D");
title("ML/D vs Drag")
hold off;

%%Question 2

%thurst avalible
T_sl = 32500;
Ta = (rho/rho(1))*T_sl;
amax = zeros(1,7);
min = zeros(1,7);
for i = 1:length(altitude)
    amax(i) = find(drag(i,:)  < Ta(i),1,'last');
    min(i) = find(drag(i,:) < Ta(i),1,'first');
end
vamax = zeros(1,7);
vmin = zeros(1,7);
for i = 1:length(altitude)
    vamax(i) =  v_inf(amax(i));
    vmin(i) = v_inf(min(i));
end
% find V stall
vstall = sqrt(W./(0.5.*rho*29.2*1.6));
figure(4);
scatter(altitude, vamax);
hold on;
scatter(altitude, vmin);
hold on;
plot(altitude, vstall);
hold on;
legend({'minimum speed','maximum speed', 'stall speed'});
xlabel("Altitude");
ylabel("Speeds");
%question 3 

% first the amax velocity at each 
vd = zeros(7, length(v_inf));

for i = 1:length(rho)
    for j = 1:length(v_inf)
        vd(i,j) = v_inf(j)*drag(i,j);
    end
end
vt = Ta.*v_inf;
vd(isnan(vd))=0;
vclime = zeros(1,7);
for i = 1:length(rho)
    vclime(i) = max(vt(i,:) - vd(i,:));
end
ROC = vclime / W;
figure(5);
plot(altitude,ROC);
% maximum 
xlabel("Altitude (m)");
ylabel("Rate of Climb");
title("Altitude vs Rate of Climb(ROC)")

