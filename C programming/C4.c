// Fibonacci Series(Iterative)
#include <stdio.h>
int main(){
    int n;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    
    if(n<=0){
       printf("Please enter a positive integer.\n");
       return 1;
     }
    printf("Fibonacci Series: ");
    int first =0, second=1, next;
    
   if(n==1)
      printf("%d",first);
   if(n==2)
       printf("%d,%d",first,second);
   else
   {
       printf("%d,%d",first,second);
       for(int i=2;i<n;i++)
       {
       next= first+ second;
       printf(",%d,",next);
       first=second;
       second=next;
       }
    }
}
