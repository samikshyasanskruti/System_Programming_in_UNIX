// typedef Aliasing
#include<stdio.h>

//without typedef
struct Point3D {
     double x,y,z;
};

//with typedef
typedef struct {
     int hours,minutes,seconds;
}Time;

int main() {
    struct Point3D p={1.5,2.0,3.25};
    Time now={14,30,45};
    
    printf("Point: (%.2f,%.2f,%.2f)\n",p.x,p.y,p.z);
    printf("Time:%02d:%02d:%02d\n",now.hours,now.minutes,now.seconds);
    return 0;
  }
