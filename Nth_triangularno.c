#include <stdio.h>

int triangular(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + triangular(n-1);
    }
}

int main() {
    int n = 5; // calculate the 5th triangular number
    int result = triangular(n);
    printf("The %dth triangular number is %d\n", n, result);
    return 0;
}
