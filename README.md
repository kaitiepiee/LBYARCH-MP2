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
# Correctness of Code Output (C & x84x64)

