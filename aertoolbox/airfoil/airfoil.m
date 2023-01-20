% Khang Nguyen code
clear all;
file = load("_AIRFOIL_");
% make the data for air foil go counter clock wise
xup = file(end:-1:2,1);
xdown = file(:,1); % remove the second-to-last row to not repeat twice
yup = file(end:-1:2,3);
ydown = file(:,2);
xi = [xup; xdown];
yi = [yup; ydown];
% Use the spline function to fit the data points
li = arclength(xi,yi);
lp = linspace(0,li(end),10000);
xp = spline(li,xi,lp);
yp = spline(li,yi,lp);
plot(xi,yi, 'o', xp,yp); 
axis equal;


function li = arclength(xi,yi)
    % question c
    li(1) = 0;
    for  k = 2:length(xi)
        li(k) = li(k-1)+sqrt(((xi(k) - xi(k-1))^2)+(yi(k)-yi(k-1))^2);
    end
end

