#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int n;
    scanf("%d", &n);
    long long A[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    long long K;
    scanf("%lld", &K);
    for (int i = 1; i < n; i++) {
        if ((A[i] % K) != (A[0] % K)) {
            printf("-1\n");
            return 0;
        }
    }
    qsort(A, n, sizeof(long long), cmp);
    long long median = A[n / 2];
    long long operations = 0;
    for (int i = 0; i < n; i++) {
        operations += llabs(A[i] - median) / K;
    }
    printf("%lld\n", operations);
    return 0;
}
