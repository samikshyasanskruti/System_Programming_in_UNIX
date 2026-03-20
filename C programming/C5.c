#include<stdio.h>

struct Student {
     int id;
     char name[50];
     float gpa;
     char department[30];
   };
   
int main() {
     struct Student s1={1001,"Samikshya Swain",8.9,"Computer Science"};
      printf("=== Student Record ===\n");
      printf("ID:%d\n",s1.id);
      printf("Name:%s\n",s1.name);
      printf("GPA:%.2f\n",s1.gpa);
      printf("Department:%s\n",s1.department);
      
      return 0;
    }
      
