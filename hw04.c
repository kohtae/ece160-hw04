#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3
} Mode;


typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  int year;
  int years_left;
} Student;


void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
    case MAJOR_AND_NAME:
      printf("%s %s %s\n", s.major, s.first_name, s.last_name);
      break;
    case YEAR_AND_NAME:
      printf("%d %s %s\n", s.year, s.first_name, s.last_name);
      break;
    case YEARS_LEFT_AND_NAME:
      printf("%d %s %s\n", s.years_left, s.first_name, s.last_name);
      break;
  }
}



int main(int argc, char* argv[]) { 

    char *filename = argv[1];
    char buffer[256];
    Student stu[266];
    File *fp = fopen (filename, "r");

    if (fp == NULL){
        printf("error %s\n", filename);
        return -1;
    }
    
    char *s;
    int count;
    count = 0;

    while((s = fgets(buffer, 255, fp)) != NULL){

        Student s;
        size_t length = strlen(buffer);
        size_t length_byte = (length + 1) * sizeof(char);
        s.first_name = malloc(length_byte);
        s.last_name = malloc(length_byte);
        s.major = malloc(length_byte);
        sscanf(buffer, "%s %s %s %d", s.first_name, s.last_name, s.major, &s.year);

        s.years_left = s.year - 2017;
        stu[count] = s;
        count = count + 1;
    }

  int i;
  while(1) {
      scanf("%d %d", &i, &m);
      print_student(i, stu[count]); 
  }
    
  fclose(fp);
  return 1;
}
