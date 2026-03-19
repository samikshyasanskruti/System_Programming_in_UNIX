// Factorial using Recursion
#include <stdio.h>

long long factorial(int n) {
      if (n==0 || n==1) // Base case
          return 1;
      return n*factorial(n-1);  // Recursive Case
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d" ,&n);
    
    if (n<0){
       printf("Factorial not defined for negative numbers.\n");
    }
    else {
    printf("%d!=%lld\n",n,factorial(n));
    }
    return 0;
 }  
