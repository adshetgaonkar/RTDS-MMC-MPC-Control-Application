
clear all;
clc;
%%% we have m inputs, q ouput and n1 states. 
%%% 

%% Prediction horizon and control horizon 
Np=32; % Prediction horizon  Np=20,25,30,32 works on RSCAD
Nc=1;  % Control horizon     Nc=1  works on RSCAD

%% MMC mxodel 
w = 1; 
%T =10e-3; %%only in simulink
T = 20e-6; %%%%% very important for simple circuit with 1e-6 it works %% 25e-6
Larm =  3.5;  %%% 1.5 
Rarm = 0.10/1000;  
Lf = 0.18;
Rf = 0.006;

R_ac_eq = Rf + Rarm/2;  
L_ac_eq = Lf + Larm/2; 
R_dc_eq = 2*Rarm; 
L_dc_eq = 2*Larm;

A_ac = [-Rarm/Larm 2*w 0 0 0; -2*w -Rarm/Larm 0 0 0; 0 0 -Rarm/Larm 0 0; ...
        0 0 0  -R_ac_eq/L_ac_eq -w; 0 0 0 w -R_ac_eq/L_ac_eq ]; 
B_ac = [-1/Larm 0 0 0 0; 0 -1/Larm 0 0 0; 0 0 -1/Larm 0 0;
         0 0 0 1/L_ac_eq 0 ; 0 0 0 0 1/L_ac_eq ];

[Na_r,Na_c] = size(A_ac); 
[Nb_r,Nb_c] = size(B_ac);
C_ac = eye(Na_r,Nb_r); 
D_ac = zeros(Na_r,Nb_c);

F = expm(A_ac*T); 
G = A_ac\((expm(A_ac*T)- eye([Na_r,Na_c]))*B_ac);

Ap = expm(A_ac*T); 
Bp = A_ac\((expm(A_ac*T)- eye([Na_r,Na_c]))*B_ac);
Cp = C_ac; 

Am = Ap;
Bm = Bp;
Cm = Cp;
%% rate based agumented model
[q,n1]=size(Cp);
[n1,m]=size(Bp);
A_e=eye(n1+q,n1+q);
A_e(1:n1,1:n1)=Ap;
A_e(n1+1:n1+q,1:n1)=Cp*Ap;
B_e=zeros(n1+q,m);
B_e(1:n1,:)=Bp;
B_e(n1+1:n1+q,:)=Cp*Bp;
C_e=zeros(q,n1+q);
C_e(:,n1+1:n1+q)=eye(q,q);
%%% matrix size %%% 
[n,n] = size(A_e);
[n,m] = size(B_e);
[q,n] = size(C_e);
n=n1+q;
%% Formulating multi prediction matrix 
h=C_e;
F=C_e*A_e;
for kk= q+1:q:Np*q
h=[h;h((kk-q):end,:)*A_e];
F = [F;F((kk-q):end,:)*A_e];
end
v=h*B_e;
Phi=zeros(Np*q,Nc*m); %declare the dimension of Phi
Phi(:,1:m)=v; % first column of Phi
for i = m+1:m: Nc*m   
Phi(:,i:i+m-1)=[zeros(i-1,m);v(1:Np*q-i+1,:)]; %Toeplitz matrix
end
Q = 1*eye(Np*q,Np*q);
R = 0.2*eye(Nc*m,Nc*m);

%%% Hessian 
H = Phi'*Q*Phi+R; 

%% plant inertilisation
xm=zeros(n1,1);
Xf=zeros(n,1);
N_sim=100; 
%%% reference signals pleas add number of r depending upon output. 
r1 = [zeros(10,1);zeros(N_sim-10,1)];
r2 = zeros(N_sim,1);
r3 = zeros(N_sim,1);
r4 = [zeros(2,1);1*ones(N_sim-2,1)];
r5 = zeros(N_sim,1);
r=[r1 r2 r3 r4 r5]';

u= zeros(m,1); % u(k-1) =0
y= zeros(q,1);

%% constraints formulation 

duMax=1*ones(m,1);  %input rate constraint
yMax=1000000*ones(1,1); %output constraint
uMax=50000*ones(m,1);  %input constraint

bduMax = [];
for i=1:Nc
    bduMax = [bduMax;duMax];
end  
bduMin=-bduMax;

Iu =[];
for i=1:Nc
    Iu = [Iu;eye(m,m)];
end 
uMin=-uMax;
yMin= -yMax;

A_tem = eye(q);                                            
N = Nc;                                                 
Ar_tem = repmat(A_tem, 1, N);                                  
Ac_tem = mat2cell(Ar_tem, size(A_tem,1), repmat(size(A_tem,2),1,N));   
Im = blkdiag(Ac_tem{:}) 

A_bigC=[];
for i=1:Nc
    A_bigC=[A_bigC; eye(m,m)] 
end 
bigIm = [];
for i=1:Nc
    if i == 1
        bigIm = A_bigC;
    end
    if i > 1 
    bigIm=[bigIm [zeros((i-1)*m,m);A_bigC((i-1)*m+1:end,:)]];
    end
end 

R_bar = []
for i=1:Np
    R_bar=[R_bar; eye(q,q)] 
end 

C_LHS=[Im;-Im;bigIm;-bigIm;Phi(159,:);-Phi(159,:)];
%C_LHS=[Im;-Im;bigIm;-bigIm];
up=zeros(m,1);
e = zeros(q,1);
PhiT_Q_R_bar= Phi'*Q*R_bar;
PhiT_Q_F = Phi'*Q*F;% -(D.Phi'*D.Q*(r-D.F*(D.Xf+Xf_old))); 
PhiT_Q_Ie = Phi'*Q*ones(Np*q,q);
%%
% XX = (H\PhiT_Q_F);
% AA = A_e - B_e*XX(1:5,:)
% ee = eig(A_e)
% e = eig(AA)
%    figure(1)
%      plot(real(ee),imag(ee),'r*') %   Plot real and imaginary parts
%      hold on 
%      plot(real(e),imag(e),'b*')
%      xlabel('Real')
%      ylabel('Imaginary')
%      t1 = ['Eigenvalues of a random matrix of dimension ' num2str(n)];
%      title(t1)
save('initial_qudratic_paper_traditional_MPC');
