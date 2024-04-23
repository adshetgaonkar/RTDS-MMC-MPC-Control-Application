%% the variable size array problem in RSCAD. 
N = [4;4;4;4;4]
n0=1;
n_in = 5;
ne=N(1);
R_para=zeros(20,20);
for i=1:n_in-1
R_para(n0:ne,n0:ne)= eye(N(i),N(i));
n0=n0+N(i);
ne=ne+N(i+1);
end