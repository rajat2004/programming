#include <stdio.h>
#include "cuda.h"
int main() {
    cudaDeviceProp prop;
    cudaGetDeviceProperties(&prop, 0);
    printf("%d", prop.major * 10 + prop.minor);
}
