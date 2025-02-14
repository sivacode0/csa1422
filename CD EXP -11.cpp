#include <stdio.h>
#include <math.h>

int main() {
    double result;
    double a = 5, b = 3, c = 2;

    // Expression following PEMDAS: (5 + 3) * 2 - 3^2
    result = (a + b) * c - pow(b, 2);
    
    printf("Result: %.2f\n", result);
    return 0;
}
