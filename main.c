#include <stdio.h>
#include <omp.h>

#define N 1000000000

int main() {
    long long sumStatic = 0;
    long long sumDynamic = 0;

    double inicioStatic = omp_get_wtime();

    #pragma omp parallel for schedule(static) reduction(+:sumStatic)
    for (long long i = 1; i <= N; i++) {
        if (N % i == 0) {
            sumStatic += i;
        }
    }
    double fimStatic = omp_get_wtime();

    double inicioDynamic = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic) reduction(+:sumDynamic)
    for (long long i = 1; i <= N; i++) {
        if (N % i == 0) {
            sumDynamic += i;
        }
    }
    double fimDynamic = omp_get_wtime();

    printf("Somatorio usando for estatico: %lld, tempo: %lf\n", sumStatic, fimStatic - inicioStatic);
    printf("Somatorio usando for dinamico: %lld, tempo: %lf\n", sumDynamic, fimDynamic - inicioDynamic);

    return 0;
}