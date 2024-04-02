# LBYARCH MP2
Created by S15 Group 6 :
- Coo, Hans
- Tighe, Kaitlyn
  
# Specs
Write the kernel in (1) C program and (2) an x86-64 assembly language. The kernel is to perform DAXPY (A*X + Y) function.

Input: Scalar variable n (integer) contains the length of the vector; Scalar variable A is a double-precision float. Vectors X, Y and Z are double-precision float.

*Required to use functional scalar SIMD registers

*Required to use functional scalar SIMD floating-point instructions

Output: store result in vector Z. Display the result of 1st ten elements of vector Z for all versions of kernel (i.e., C and x86-64).

# Comparative Execution Time & Analysis of the Kernels
* Analysis and data collection for each version of N in release and debug mode for this project was done using Python Notebook that can be accessed here: https://deepnote.com/workspace/lbyarch-mp2-5be9dd01-b938-4333-a8ce-d0e7b14114e1/project/LBYARCH-Analysis-b4c9400c-efc7-4860-b7b0-154956f5f035/notebook/Notebook%201-afa73227d0cc448393b7b3a902373fdd

Shown below are the execution times of 30 iterations under Debug Mode using N = 2^28 
![Debug Release in 2^28](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/8f7b144d-25a9-4bed-a307-1bf9e03cbd76)
Figure 1. Sample Output of Program w/ Kernel Time (Debug Mode, 2^28)

# Debug Mode
![Debug Time](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/ac1ea6ee-5536-4550-9150-70cfec48ad6f)
Figure 2-4. Progression Chart of Debug Mode Kernel Time (N = 2^20, 2^24, 2^28, for 30 iterations)

* The line chart above illustrates the kernel times recorded for C and ASM at N = 2^20, 2^24, and 2^28. The Assembly language consistently performed quicker than C across all versions of N. We can notice a consistent line trend across all versions of N, with minor peaks in the iterations. A notable spike was observed at N = 2^28 at the beginning for both C and Assembly. This could suggest that the initialization process for both languages was particularly resource-intensive at this scale.


![C and ASM on versions](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/e1715772-51ee-4e16-b169-103930166849)
Figure 5.  Progression Chart of C and ASM Debug Kernel Time (30 iterations)

* In this version of the line chart, we showcase the time progression in 30 iterations across the 3 versions of N.

| N    | Average Debug C_Time | Average Debug ASM_Time |
|------|----------------------|------------------------|
| 2^20 | 0.002835953          | 0.001140280            |
| 2^24 | 0.044644207          | 0.018789627            |
| 2^28 | 0.587708583          | 0.405398533            |

Table 1.1 Average Kernel Time of C and Assembly for Debug Mode

![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/0f503852-fedc-4c28-8072-b00da39bc8b9)
Figure 6. Bar Chart of the Averages of Kernel Times of C and Assembly in Debug Mode

* In Table 1.1 and Figure 6., we can observe the exponential growth of the N versions through their average time across the 30 iterations. Assembly outperformed C in every version of N.


# Release Mode
* During the assessment in release mode, the team encountered a challenge with the Assembly code, which failed to execute correctly. Despite our efforts, we could not address this issue due to constraints. However, we acknowledge the potential causes, such as out-of-bounds access or variable mis-initialization. Consequently, for this phase, we analyzed the C language code exclusively.
  
![Release-Time incorrect](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/093e4ccf-0e25-409d-b9a6-2cec5213a5d6)

Figure 7. Release Mode of C and Assembly with Error

* In Figure 7, it was observed that only the initial iteration of C appeared to execute properly. Subsequently, the iteration count encountered errors and eventually entered a loop. Despite extensive debugging efforts, regrettably, this error could not be resolved.

![Release C](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/a865f09b-3912-4684-bb9b-ffd7c656ca8a)
Figure 8-10. Progression Chart of Release Mode Kernel Time (N = 2^20, 2^24, 2^28, for 30 iterations)

* Figure 8-10 shows a line chart progression of N versions within the C language. While the spikes in performance seem more pronounced, it's important to note that the actual time values remain relatively small. Notably, in the case of N^28, we observe a similar peak in the debug mode, suggesting a potentially significant initialization overhead.

|   N   | C_Avg_Time |
|-------|------------|
|  2^20 |   0.001227 |
|  2^24 |   0.017719 |
|  2^28 |   0.292758 |

Table 2.2 Average Kernel Time of C in Release Mode

![Release C charts](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/639ba89e-d842-447d-bfe0-0eaf77cc10fa)
Figure 11-12 Line Chart of Time Progression of C and Bar Graph of Average Kernal Time of C in Release Mode


* In Table 2.2 and Figure 11-12., we can observe the exponential growth of the N versions through their average time across the 30 iterations.

# Correctness of Code Output (C & x84x64)
* A correctness check was conducted, comparing the output of C and ASM for a given example from Canvas and through randomized inputs. Below is the example given from Canvas:
  
![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/106811041/56a679cf-fdbc-444c-a233-b37ecaedf027)

![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/106811041/ec2ed6cf-a09f-424f-99ab-55a3abbd1044)
* This function is used to initialize the variables for the defined Canvas input.
  
![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/d62b48d9-6d95-49ea-9d35-d6fa11313c34)
* This function is used to initialize randomized variables for the input.


# Debug Mode Correctness

![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/3c2a3b77-6779-4c76-a344-6577bb5ca12b)
* Using Canvas defined input and expected output.
  
![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/2f22871e-b838-466b-b458-e2fde96def61)
* Using randomized inputs and displaying the first 10 elements (0-9)

# Release Mode Correctness
![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/e371e699-b973-4600-8e3e-7c2ef365561b)
* Using Canvas defined input and expected output.

![image](https://github.com/kaitiepiee/LBYARCH-MP2/assets/79103680/0d2ecbd4-8e2f-469f-898c-4767ee074863)
* Using randomized inputs and displaying the first 10 elements (0-9)
