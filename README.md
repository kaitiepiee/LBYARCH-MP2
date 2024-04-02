# LBYARCH MP2
Created by S15 Group 6 :
- Coo, Hans
- Tighe, Kaitlyn
  
Given: 
Write the kernel in (1) C program and (2) an x86-64 assembly language. The kernel is to perform DAXPY (A*X + Y) function.

Input: Scalar variable n (integer) contains the length of the vector; Scalar variable A is a double-precision float. Vectors X, Y and Z are double-precision float.

*Required to use functional scalar SIMD registers

*Required to use functional scalar SIMD floating-point instructions

Process: Z[i] = A*X[i] + Y[i] Example:

A --> 2.0

x -> 1.0, 2.0, 3.0

y -> 11.0, 12.0, 13.0

(answer) z--> 13.0, 16.0, 19.0

Output: store result in vector Z. Display the result of 1st ten elements of vector Z for all versions of kernel (i.e., C and x86-64).

# Comparative Execution Time & Analysis of the Kernels
Shown below are the execution times of 30 iterations using N = 2^28 (2^29 and 2^30 performed too slow for our machines) for the C and x86-64 assembly kernels:

![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/106811041/9c79f686-5c2d-4030-887a-5a4efd5d38cb)
![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/106811041/1f8e0409-f988-4f2b-b3d7-7802b57c3916)
![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/106811041/228efa4b-cb4c-454d-bf0c-195ff7d83dd5)

Further analysis of our project was done through Python Notebook here: https://deepnote.com/workspace/lbyarch-mp2-5be9dd01-b938-4333-a8ce-d0e7b14114e1/project/LBYARCH-Analysis-b4c9400c-efc7-4860-b7b0-154956f5f035/notebook/Notebook%201-afa73227d0cc448393b7b3a902373fdd
![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/fbf4867a-6151-4130-8d9b-fc3bc40b42ab)

It was observed that the Asm kernel was faster for every single iteration than the C kernel. The difference in execution time between the C and Assembly processes likely stems from the setup and optimization. Assembly typically runs faster due to its efficient use of resources and direct access to machine instructions. Conversely, C may perform slower because it's not as finely tuned and introduces additional overhead. Factors such as system load and environmental conditions can further influence performance. 

![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/3e602ea2-8df8-4a60-bbd7-2663b8811cc6)

Furthermore, when averaging the time taken by both C and Assembly, it's clear that C ran slower than Assembly. C took 0.5877 seconds on average, while Assembly only took 0.4054 seconds. The difference may be more evident when increasing the N to 2^29 or 2^30

# Correctness of Code Output (C & x84x64)
As proof of the correctness of the output, here is the given example from Canvas:

![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/106811041/56a679cf-fdbc-444c-a233-b37ecaedf027)

![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/106811041/ec2ed6cf-a09f-424f-99ab-55a3abbd1044)

![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/106811041/f0afc536-f904-44a5-a312-75a023494ce2)

And here are the matching values for C and ASM for randomized inputs:

![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/106811041/45f79431-076d-4287-8344-448640ecb396)
