#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
  char name[16];
  int opt;
  FILE *f;
  f = fopen(argv[1], "rb");
  while (!feof(f)){
    fread(name, sizeof(char), 1, f);
    printf("%c", name[0]);
  }
  
  return 0;
}
