function Out=evolution(D,Vx,Vy,T)

[w,h]=size(Vx);
Out=zeros(w+2,h+2,T);
Out(:,:,1)=D;


VxAux=zeros(w+2,h+2);
VxAux(2:w+1,2:h+1)=Vx;
VxAux(1,2:h+1)=Vx(1,:);
VxAux(w+2,2:h+1)=Vx(w,:);
VxAux(2:w+1,1)=Vx(:,1);
VxAux(2:w+1,h+2)=Vx(:,h);
VxAux(1,1)=VxAux(1,2);
VxAux(w+2,1)=VxAux(w+1,1);
VxAux(1,h+2)=VxAux(2,h+2);
VxAux(w+2,h+2)=VxAux(w+2,h+1);


VyAux=zeros(w+2,h+2);
VyAux(2:w+1,2:h+1)=Vy;
VyAux(1,2:h+1)=Vy(1,:);
VyAux(w+2,2:h+1)=Vy(w,:);
VyAux(2:w+1,1)=Vy(:,1);
VyAux(2:w+1,h+2)=Vy(:,h);
VyAux(1,1)=VyAux(1,2);
VyAux(w+2,1)=VyAux(w+1,1);
VyAux(1,h+2)=VyAux(2,h+2);
VyAux(w+2,h+2)=VyAux(w+2,h+1);
 
for t=1:T-1
    Out(:,:,t+1)=Out(:,:,t);
    for i=2:w+1
        for j=2:h+1
              Out(i,j,t+1)=Out(i,j,t+1)+0.01*(VyAux(i,j)*0.5*(Out(i+1,j,t)-Out(i-1,j,t))+VxAux(i,j)*0.5*(Out(i,j+1,t)-Out(i,j-1,t)));
            
        end
    end
end

% for t=1:T-1
%     Out(:,:,t+1)=Out(:,:,t);
%     for i=2:w+1
%         for j=2:h+1
%             
%             Out(i,j,t+1)=Out(i,j,t)+0.01*(Out(i+1,j,t)-Out(i-1,j,t));
%         end
%     end
% end