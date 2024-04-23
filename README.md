# RTDS-MMC-MPC-Control-Application
This repository contains RSCAD/RTDS model and developed Model Predictive Control (MPC) during the PhD work. 

The theory and result of these models are provided in following papers: 

1. A. Shetgaonkar, A. Leki ́c, J.L. Rueda Torres, P. Palensky, “Microsecond enhanced
indirect model predictive control for dynamic power management in MMC units,”
Energies, vol. 14, no. 11, pp. 3318, 2021, MDPI.
2. A. Shetgaonkar, L. Liu, A. Leki ́c, M. Popov, P. Palensky, “Model predictive control
and protection of MMC-based MTDC power systems,” International Journal of
Electrical Power & Energy Systems, vol. 146, pp. 108710, 2023, Elsevier.
3. L. Liu, A. Shetgaonkar, A. Leki ́c, “Interoperability of classical and advanced
controllers in MMC based MTDC power system,” International Journal of
Electrical Power & Energy Systems, vol. 148, pp. 108980, 2023, Elsevier.
4. A. Shetgaonkar, M. Popov, P. Palensky, A. Leki ́c, “Zero-sequence current
suppression control for fault current damper based on model predictive control,”
Electric Power Systems Research, vol. 223, pp. 109592, 2023, Elsevier.
5. A. Shetgaonkar, T. Karmokar, M. Popov, A. Leki ́c, “Enhanced Real-Time
Multi-Terminal HVDC Power System Benchmark Models with Performance
Evaluation Strategies,” Cigre Science & Engineering, vol. 32, February 2024, pp. 29,
2024, Cigre

   
%%%%%%%%%%%%%%%%%%  General Info %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
1. 'Inner_IPST has inner MPC': This folder has Model Predictive Control (MPC) strategy for zero sequence suppression control. This MPC is placed at the inner current control loop. 
2. 'Inner_lauguree_MPC': This folder has a Lauguree MPC controller. This MPC is placed at the inner current control loop. 
3. 'Outer_MPC_Control': This system uses an MPC for Vdc-link control and can also be used for Vac-f control.
%%%%%%%%%%%%%%%%%% Importing to RSCAD %%%%%%%%%%%%%%%%%%%%%%%%%%%%
Please follow the conversion tutorial from Simulink to RSCAD in the RSCAD help menu
%%%%%%%%%%%%%%%%%% RSCAD and Simulink version %%%%%%%%%%%%%
RSCAD V2
Simulink R2019b
