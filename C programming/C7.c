// 3.Union Usage Example
#include<stdio.h>

union NumericData {
     int integer;
     float floating;
     double precise;
 };
 int main(){
     union NumericData data;
     data.integer=42;
     printf("As integer:%d\n",data.integer);
     
     data.floating=3.14159f;
     printf("As float:%.5f\n",data.floating);
     printf("As integer(overwritten):%d\n",data.integer);
     
     data.precise=2.718281828;
     printf("As double:%.9f\n",data.precise);
     printf("Size of union:%lu bytes\n",sizeof(data));
     
   return 0;
 }
