#include <stdio.h>
int main(){
    int age;
    float height;
    char initial;
    
    printf("=== Personal Info Collector ===\n");
    
    printf("Enter your age: ");
    scanf("%d",&age); // Reads integer input into 'age'
    
    printf("Enter your heights(m): ");
    scanf("%f",&height); // Reads float input into 'age'
    
    printf("Enter your first initial: ");
    scanf(" %c",&initial); // Space before %c skips leftover newline
    
    printf("\n---Summary---\n");
    
    printf("Age:%d years\n",age);
    printf("Height:%.2f meters\n", height);  //.2 two decimal places
    printf("Initial: %c\n",initial);
    
    return 0;
    
   }
