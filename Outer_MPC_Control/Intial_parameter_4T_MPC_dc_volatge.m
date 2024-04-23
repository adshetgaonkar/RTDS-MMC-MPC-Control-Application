clc; 
clear all;

% R = 0.1; 
% L = 5e-3;
Ts =0.040e-3;
% Rp = 100000; 
% Ceq = 0.0003; 
%%%%%%%%%%
% Ap=[-2/(Rp*Ceq)];
% Bp=[-2/Ceq];
Ap = [-1/(0.2*2.5)];
Bp = [1/2.5]
Cp=[1];
Dp=0;

[Na_r,Na_c] = size(Ap); 
[Nb_r,Nb_c] = size(Bp);
Cp = eye(Na_r,Nb_r); 
Dp = zeros(Na_r,Nb_c);

F = expm(Ap*Ts); 
G = Ap\((expm(Ap*Ts)- eye([Na_r,Na_c]))*Bp);

Ap_a = F; 
Bp_a = G; 
Cp_a = Cp; 
%%%% augmented model and phi function 
[m1,n1]=size(Cp_a);
[n1,n_in]=size(Bp_a);
A=eye(n1+m1,n1+m1);
A(1:n1,1:n1)=Ap_a;
A(n1+1:n1+m1,1:n1)=Cp_a*Ap_a;
B=zeros(n1+m1,n_in);
B(1:n1,:)=Bp_a;
B(n1+1:n1+m1,:)=Cp_a*Bp_a;
C=zeros(m1,n1+m1);
C(:,n1+1:n1+m1)=eye(m1,m1);
%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%closed-loop performance by calculating the feedback
% %%%%% gain matrix and closed-loop system matrix %%%%%%%%%%%%%%%%%%%%%
% [A1,L0]=lagd(a,N);
% K_mpc=L0'*(Omega\Psi);
% Acl=A-B*K_mpc;
% Pole_close=eig(Acl);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Set up the initial conditions for closed-loop simulation using constrained
%%%%%%%%% control. We also specify the limits for ?u and u.%%%%%%
Q=1*C'*C;
R=0.02*eye(n_in,n_in)
a=0.6*ones (n_in,1);
N=6*ones (n_in,1);
Np=20;
[Omega,Psi]= dmpc(A,B,a,N,Np,Q,R); 
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
u_min= -0.8*ones (n_in,1);
u_max= 0.8*ones (n_in,1);
deltau_min = -5 *ones (n_in,1);
deltau_max = 5 *ones (n_in,1);
up=zeros(n_in,1);
[M1,Lzerot]=Mdu(a,N,n_in,1);
M0=Mu(a,N,n_in,1);
M=[M0;-M0;M1;-M1];
Nc = 1; 
%gamma=[deltau_max*ones(Nc,1);-deltau_min*ones(Nc,1)];
save('4TDC_volatge');

% sim('siglephase_inverter_using_laugurre_v1'); 