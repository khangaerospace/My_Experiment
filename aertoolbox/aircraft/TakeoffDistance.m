%find the landing diatance 
T = 32500; %thurst
Clg = 0.8; % ground Coefficient of lift
rho = 1.225; % density
Cl_max = 2.2; % max coeff of lift due to the air foil
W = 88300; % aircraft weight
S = 29.2; % wing span
v_lo = sqrt((1.44*2*W)/(rho*S*Cl_max)); % velocity lift off
v_ave = v_lo / sqrt(2); % average velovitu
mu = 0.02; % coefficient of drag
theta = 0.796; % drag coeffient 
AR = 8.99; 
eff = 0.85; % aircraft efficientcy 
C_Do = 0.02; 
L = Clg*0.5*rho*(v_ave^2)*S;
disp("Average Lift:")
disp(L);
R = mu*(W - L);
disp("R:");
disp(R);
D = 0.5*rho*(v_ave^2)*S *(C_Do + theta*((Clg^2)/(pi*AR*eff)));
disp("Avergage drag:");
disp(D);
% find the distance
d = (1.44*W^2)/(9.8*(rho)*Cl_max*S*(T-R-D));
disp("distance");
disp(d)