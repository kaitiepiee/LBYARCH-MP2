#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define N 268435456 // 268435456 is 2^28, you can try 2^29 or or 2^30 but its just too slow for me
#define ITERATIONS 30 // min 30, can be adjusted higher

// Assembly Function
extern void asm_main(long long int n, double A, double *X, double *Y, double *Z);

// Function for DAXPY operation
void daxpy(long long int n, double A, double *X, double *Y, double *Z) {
    for (int i = 0; i < n; i++) {
        Z[i] = A * X[i] + Y[i];
    }
}

// Function to measure time 
void measureTime(struct timespec* start, struct timespec* end, long long* sec, long long* nanosec) {
    *sec = end->tv_sec - start->tv_sec;
    *nanosec = end->tv_nsec - start->tv_nsec;

    // Check for negative nanoseconds and adjust if necessary
    if (*nanosec < 0) {
        (*sec)--; 
        *nanosec += 1000000000LL; // 
    }
}

// Function to print kernel time
void printKernelTime(const char *kernel_name, long long total_sec, long long total_nanosec) {
    double average_time = (total_sec + total_nanosec / 1e9) / (double)ITERATIONS;
    printf("Avg %s Kernel Time: %f seconds\n", kernel_name, average_time);
}

int main() {
    long long int n = N;
    struct timespec start_time, end_time; // time measurement
    long long sec_c, nanosec_c;
    long long sec_asm, nanosec_asm;

    double A = 0; // scalar value
    double* array1 = (double*)malloc(n* sizeof(double));
    double* array2 = (double*)malloc(n * sizeof(double));
    double* resultASM = (double*)malloc(n * sizeof(double));
    double* resultC = (double*)malloc(n * sizeof(double));
    
    // Random values init
    A = ((float)rand()) / RAND_MAX;
    for (int i = 0; i < n; i++) {
      array1[i] = ((float)rand()) / RAND_MAX;
      array2[i] = ((float)rand()) / RAND_MAX;
      resultC[i] = 0;
     resultASM[i] = 0;
    }

    //double A = 2.0;
    //for (int i = 0; i < 3; i++) {
    //    array1[i] = i % 3 + 1; // Will cycle through 1, 2, 3
    //    array2[i] = i % 3 + 11; // Will cycle through 11, 12, 13
    //    resultC[i] = 0.0; // Initialize to 0.0
    //    resultASM[i] = 0.0; // Initialize to 0.0
    //}


    for (int i = 0; i < ITERATIONS; i++) {
        // For C
        timespec_get(&start_time, TIME_UTC); // Get time before executing C kernel
        daxpy(n, A, array1, array2, resultC);
        timespec_get(&end_time, TIME_UTC); // Get time after executing C kernel
        measureTime(&start_time, &end_time, &sec_c, &nanosec_c); // Measure time for C kernel
        printf("Iteration #%d C Kernel Time:   %ld.%09ld seconds\n", i + 1, sec_c, nanosec_c);

        // For Asm
        timespec_get(&start_time, TIME_UTC); // Get time before executing ASM kernel
        asm_main(n, A, array1, array2, resultASM);
        timespec_get(&end_time, TIME_UTC); // Get time after executing ASM kernel
        measureTime(&start_time, &end_time, &sec_asm, &nanosec_asm); // Measure time for ASM kernel
        printf("Iteration #%d Asm Kernel Time: %ld.%09ld seconds \n", i + 1, sec_asm, nanosec_asm);
    }

    printf("\nSanity Check Answer Key");
    //printf("A = %.6f\n", A);
    //printf("X = ");
    //for (int i = 0; i < N; i++) {
    //     printf("%.2f ", array1[i]);
    //}
    //printf("\n");

    //printf("Y = ");
    //for (int i = 0; i < N; i++) {
    //    printf("%.2f ", array2[i]);
    //}
    printf("\n");
    printf("(First 10 elements of Z) C Result:\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", resultC[i]);
    }
    printf("\n");

    printf("(First 10 elements of Z) ASM Result:\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", resultASM[i]);
    }
    printf("\n");


    // Compare results if match (IF C == AMS)
    printf("\nComparison of C and ASM results:\n");
    for (int i = 0; i < 10; i++) {
        if (resultC[i] == resultASM[i]) {
            printf("Element %d: C=%.2f, ASM=%.2f (Match)\n", i, resultC[i], resultASM[i]);
        }
        else {
            printf("Element %d: C=%.2f, ASM=%.2f (Mismatch)\n", i, resultC[i], resultASM[i]);
        }
    }


    // Print average kernel times
    printf("\n");
    printKernelTime("C", sec_c, nanosec_c);
    printKernelTime("ASM", sec_asm, nanosec_asm);

    // Free allocated memory
    free(array1);
    free(array2);
    free(resultASM);
    free(resultC);

    return 0;
}

