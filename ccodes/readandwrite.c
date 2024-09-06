#include <stdio.h>;
#include <stdlib.h>

struct dets {
  char name[50];
  char id[50];
};
int main(){
    FILE *stud,*rud;
  rud = fopen("ranesh.txt","r");

  if(rud == NULL){
    perror("Unable to open file named ranesh.txt");
    return EXIT_FAILURE;
  }
  // rud data
  char rudDta[100];
  if(fgets(rudDta,sizeof(rudDta),rud)==NULL){
    perror("Cannot read file name ranesh.txt");
    return EXIT_FAILURE;
  }

  struct dets st1 = {"MANVESH","6699FCK"};

  char studentFile[100];
  sprintf(studentFile , "%s%s.txt" , st1.name , st1.id);
  stud = fopen(studentFile,"w");
  if(stud == NULL){
    perror("Cannot open the file");
    return EXIT_FAILURE;
  }

  fprintf(stud,"Hello nice to meet you %s\n",st1.name);
  fprintf(stud,"%s",rudDta);
  
  fclose(rud);
  fclose(stud); 

  printf("Task completed");
  return 0;
}