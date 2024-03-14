#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    struct timespec start, end;
    long long delta_ns;

    clock_gettime(CLOCK_MONOTONIC, &start);


    int n, i, sum=0;
    for (i=0; i<10; i++) {
        n=getpid();
        sum=sum+n;
    }
    printf("Answer is %d\n", sum);





    clock_gettime(CLOCK_MONOTONIC, &end);

    delta_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
    printf("Elapsed time: %lld nanoseconds\n", delta_ns);

    return 0;
}