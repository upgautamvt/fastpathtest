//
// Created by upgautam on 3/13/24.
//

#include <stdio.h>
#include <unistd.h>

int main() {
    int n, i, sum=0;
    for (i=0; i<1000000; i++) {
        n=getpid();
        sum=sum+n;
    }
    printf("Answer is %d\n", sum);
    return 0;
}