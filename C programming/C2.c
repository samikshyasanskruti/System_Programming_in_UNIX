// Calculator using switch case
#include <stdio.h>
int main() {
    double num1,num2,result;
    char op;
    
    printf("Simple Calculator\n");
    printf("Enter expression (e.g;15.5*3):");
    
    if(scanf("%lf %c %lf",&num1,&op,&num2)!=3){
       printf("Invalid input format!\n");
       return 1;
    }
    
    switch(op) {
    case'+':result=num1+num2;break;
    case'-':result=num1-num2;break;
    case'*':result=num1*num2;break;    
    case'/':
          if(num2==0){
               printf("Error:Division by zero!\n");
               return 1;
           }
           result=num1/num2;
           break;
    default:
          printf("Unsupported Operator:'%c'\n",op);
          return 1;
    }
    
    printf("Result: %.2f %c %.2f= %.2f\n",num1,op,num2,result);
    return 0;
  }
