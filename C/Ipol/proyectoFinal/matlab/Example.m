close all
s=200;
img=zeros(s,s);

a=s/4;
b=s/2;
t = 0:0.05:2*pi;
x = round(a*cos(t))+b;
y = round(a*sin(t))+b;
P=[x' y'];

for i=1:length(t)
   img(x(i),y(i))=1;   
end

imshow(img)
imwrite(img,'circle200.png');

D = (bwdist(img,'euclidean'));
for i=1:s
    for j=1:s
        if ((i-b)^2+(j-b)^2)<a^2
       D(i,j)=-D(i,j);
        end
    end
end
figure
contour(D);
imwrite(D,'circle200Distance.png');


% GENERO CURVA DE ENTRADA
input=zeros(s,s);
center=[floor(s/2) s/2];
w=50;
h=50;

input(center(1)-w/2:center(1)+w/2,center(2)-h/2)=1;
input(center(1)-w/2:center(1)+w/2,center(2)+h/2)=1;
input(center(1)-w/2,center(2)-h/2:center(2)+h/2)=1;
input(center(1)+w/2,center(2)-h/2:center(2)+h/2)=1;

imshow(input)
imwrite(input,'rect200.png');

D2 = (bwdist(input,'euclidean'));

figure
imshow(D2);
imwrite(D2,'rect200Distance.png');


% [Gx,Gy]=gradient(D2);

wx=[-1 -2 -1; 0 0 0; 1 2 1];
wy=[-1 0 1; -2 0 2; -1 0 1];
Gx=conv2(double(D2),wx,'valid');
Gy=conv2(double(D2),wy,'valid');

% figure
% imshow(Gx);
% 
% figure
% imshow(Gy);

T=2000;
% V=[0.5*ones(T,2)];

Out=evolution(D,Gx,Gy,T);
for t=1:T

    aux = squeeze(Out(:,:,t));
    idx(:,:,t) = -0.01<aux<0.01;

end

matrix2avi(idx,'file','Out.avi','map','gray','fps',50);
%  T=fast_marching(P,[s s],1)
