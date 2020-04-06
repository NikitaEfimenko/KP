#include "stdio.h"
#include <string.h>


typedef struct person person;

struct person {
  char first_name[32];
  char second_name[32];
  unsigned short int age;
  char gender;
  person* mom;
  person* dad;
};

union Data {
  int i;
  double d;
  char str[20];
};

int main() {
  person p;
  person p1;
  person students[30];
  union Data data;

  // p.first_name = "John"; ERROR
  strcpy(p.first_name, "John");
  // p.second_name = "Frustiante"; ERROR
  strcpy(p.second_name, "Frusciante");
  p.age = 50;
  // without init - ERROR
  person replica_p = { .first_name = "John", .second_name = "Frusciante", .age = 50 };
  
  person * p1 = &p;

  printf("%d == %d\n",(*p1).age, p1->age);

  printf("%s %s %d age\n", p.first_name, p.second_name, p.age);
  printf("%s %s %d age\n", replica_p.first_name, replica_p.second_name, replica_p.age);

  
  data.i = 3;
  printf( "data.i : %d\n", data.i);
  data.d = 2342.43;
  printf( "data.d : %lf\n", data.d);
  strcpy(data.str, "Frusciante");
  printf( "data.str : %s\n", data.str);
  printf( "data.d : %lf\n", data.d);

  return 0;
}