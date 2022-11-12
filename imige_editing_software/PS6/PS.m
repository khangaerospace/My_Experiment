% Khang Nguyen (1006943140)
% First read imige 
A = imread('FINCH.png');
% must change to 2d picture for SVD
Aray = rgb2gray(A); 
Aim = im2double(Aray);
imshow(Aim);
[U,D,V] = svd(Aim);
S=diag(D)
%root estimation 
nVs = 50;
% Construct the imige
B = zeros(size(Aray))
for i = 1: nVs
    B=B+S(i)*U(:,i)*V(:,i)';
end
%show imige
imshow(B)
