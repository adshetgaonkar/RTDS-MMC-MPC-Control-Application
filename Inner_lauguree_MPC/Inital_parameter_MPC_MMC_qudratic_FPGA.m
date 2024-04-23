%%% discrete model of MMC for MPC impelmentation %%%%%%%%% 
%%% convertion is power flown from DC to Ac %%%%%%%%%%
%% initial parameters
clear all;
clc; 

w = 1; 
%T =10e-3; %%only in simulink
T = 20e-6; %%%%% very important for simple circuit with 1e-6 it works
Larm =  3.5;  %%1.5
Rarm = 0.10/1000; %%%0.10/1000;
Lf = 0.18;
Rf = 0.006;
%%
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

Ap_ac = F; 
Bp_ac = G; 
Cp_ac = C_ac; 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
[m1,n1]=size(Cp_ac);
[n1,n_in]=size(Bp_ac);
A=eye(n1+m1,n1+m1);
A(1:n1,1:n1)=Ap_ac;
A(n1+1:n1+m1,1:n1)=Cp_ac*Ap_ac;
B=zeros(n1+m1,n_in);
B(1:n1,:)=Bp_ac;
B(n1+1:n1+m1,:)=Cp_ac*Bp_ac;
C=zeros(m1,n1+m1);
C(:,n1+1:n1+m1)=eye(m1,m1);

%%
Q=1*C'*C;
% Q(6,6) = 100;
% Q(7,7)= 100;
% Q(8,8) = 100;
% Q(9,9) = 100;
% Q(10,10)= 100;
%Q=[0 0 0 0; 0 0 0 0; 0 0 100 0;  0 0 0 100]; %% check for effect of Q 
R=0.2*eye(n_in,n_in)
%R=0.9*eye(n_in,n_in)
a=0.75*ones (n_in,1);
N=4*ones (n_in,1); %you can increase N
%Np=45;
Np=30;
[Omega,Psi,C_Phi,C_F]= dmpc1(A,B,C,a,N,Np,Q,R); 
%%%
%%
xm=zeros(n1,1);
N_sim = 300;
y=zeros(m1,1);
u=zeros(n_in,1);
xm=zeros(n1,1);

%%%%%%%%%%refrence %%%%%%%

r = zeros(m1,1)
Xf=[xm;(y-r)]
%u_min= -0.14*ones (n_in,1);
u_min = [-0.0095; -0.032; -0.032; -0.14 ; -0.14];
%u_max= 0.14*ones (n_in,1);
u_max = [0.0095; 0.032; 0.032; 0.14 ; 0.14];
deltau_min = -0.5*ones (n_in,1);
deltau_max = 0.5*ones (n_in,1);
up=zeros(n_in,1);

%yMax=[ones((Np*m1),1)];
%yMax = yMax(149:150,:);
%yMax = 0;
%yMin = -yMax;
%[M,Lzerot]=Mdu(a,N,n_in,1); %% for contrain on the rate
%[M0]= Mu(a,N,n_in,2); %%% for contrain on the amplitude 
%% contrain on both rate and amplitude
[M1,Lzerot]=Mdu(a,N,n_in,1);
M0=Mu(a,N,n_in,1);
%M=[M0;-M0;M1;-M1;C_Phi(4,:);-C_Phi(4,:) ];
M=[M0;-M0;M1;-M1];
%C_F=C_F(4,:); 
save('initial_qudratic_paper_FPGAv2');