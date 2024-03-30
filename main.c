#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define N 10000000 // TODO: idk what value we set this too
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
void measureTime(struct timespec *start, struct timespec *end, long long *total_sec, long long *total_nanosec) {
    long sec = end->tv_sec - start->tv_sec;
    long nanosec = end->tv_nsec - start->tv_nsec;
    if (nanosec < 0) {
        sec--;
        nanosec += 1000000000L;
    }
    *total_sec += sec;
    *total_nanosec += nanosec;
}

// Function to print kernel time
void printKernelTime(const char *kernel_name, long long total_sec, long long total_nanosec) {
    double average_time = (total_sec + total_nanosec / 1e9) / (double)ITERATIONS;
    printf("Avg %s Kernel Time: %f seconds\n", kernel_name, average_time);
}

int main() {
    long long int n = N;
    double A = 0; // scalar value
    double *array1 = (double*)malloc(n *sizeof(double));
    double *array2 = (double*)malloc(n *sizeof(double));
    double *resultASM = (double*)malloc(n *sizeof(double));
    double *resultC = (double*)malloc(n *sizeof(double));
    struct timespec start_time, end_time; // time measurement
    long long total_sec_c = 0;
    long long total_sec_asm = 0;
    long long total_nanosec_c = 0;
    long long total_nanosec_asm = 0;
    

    A = ((float)rand()) / RAND_MAX;
    for (int i = 0; i < n; i++) {
        array1[i] = ((float)rand()) / RAND_MAX;
        array2[i] = ((float)rand()) / RAND_MAX;
        resultC[i] = 0;
        resultASM[i] = 0;
    }

    for (int i = 0; i < ITERATIONS; i++) {
        // For C
        timespec_get(&start_time, TIME_UTC); // Get time before executing C kernel
        daxpy(n, A, array1, array2, resultC);
        timespec_get(&end_time, TIME_UTC); // Get time after executing C kernel
        measureTime(&start_time, &end_time, &total_sec_c, &total_nanosec_c); // Measure time for C kernel
        printf("Iteration #%d C Kernel Time:   %ld.%09ld seconds\n", i + 1, total_sec_c, total_nanosec_c);

        // For Asm
        timespec_get(&start_time, TIME_UTC); // Get time before executing ASM kernel
        asm_main(n, A, array1, array2, resultASM); 
        timespec_get(&end_time, TIME_UTC); // Get time after executing ASM kernel
        measureTime(&start_time, &end_time, &total_sec_asm, &total_nanosec_asm); // Measure time for ASM kernel
        printf("Iteration #%d Asm Kernel Time: %ld.%09ld seconds \n", i + 1, total_sec_asm, total_nanosec_asm);
    }

    // Print average kernel times
    printf("\n");
    printKernelTime("C", total_sec_c, total_nanosec_c);
    printKernelTime("ASM", total_sec_asm, total_nanosec_asm);
    return 0;
}
