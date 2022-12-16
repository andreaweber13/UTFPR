%% Andrea Mara Weber
%% 2079852
clear
x = [-2; -1.5; -1; -0.5; 0.5; 1; 2; 2.5; 3];
f = [51; 9.3125; -4; -3.9375; -1.1875; -6; -13; 4.3125; 56];
m = length(x);
g(1,:) = ones(1,m); %g1 =x^0
g(2,:) = [-2 -1.5 -1 -0.5 0.5 1 2 2.5 3];%g2 = x
g(3,:) = [4 2.25 1 0.25 0.25 1 4 6.25 9]; %g3 =x^2
g(4,:) = [-8 -3.375 -1 -0.125 0.125 1 8 15,625 27];%g4 =x^3
g(5,:) = [16 5.0625 1 0.0625 0.0625 1 16 39.0625 81];%g5 =x^4
n = 5;
%construcao do sistema
%matriz do sistema A
for i=1:n
    for j=1:n
        A(i,j)=0;
        for k=1:m
            A(i,j) = A(i,j)+g(i,k)*g(j,k);
        end
    end
end
%matriz B dos termos independentes
for i=1:n
    B(i)=0;
    for k=1:m
        B(i)=B(i)+g(i,k)*f(k);
    end
end
%resolucao do sistema
%triangularizacao 
for k=1:n-1
    for i=k+1:n
        m = A(i,k)/A(k,k);
        A(i,:)=A(i,:)- m*A(k,:);
        b(i) = b(i)- m*b(k);
    end
end
%substituir
for i=n:-1:1
    soma=b(1);
    for k=i+1:n
        soma = soma - A(i,k)*c(k);
    end
    c(i) = soma/A(i,i);
end
%graficos
delta = 0;
for k=1:n
    delta = delta + c(k)*g(k,:);
end
plot(x,f,'*',x,delta);