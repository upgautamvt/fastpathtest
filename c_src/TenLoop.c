#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    struct timespec start, end;
    long long delta_ns;

    clock_gettime(CLOCK_MONOTONIC, &start);


    int i;
    int a;

    for (i=0; i<10; i++) {
        //getpid(); //vDSO optimization gives false positive
        printf("\n"); //leads to system call
        a = 1;
    }


    clock_gettime(CLOCK_MONOTONIC, &end);

    delta_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    printf("Elapsed time: %lld nanoseconds\n", delta_ns);

    return 0;
}