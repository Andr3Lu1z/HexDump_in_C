#include "../include/libhex.h"

int usage(void){
  printf("Usage:\n\
      ./hexdump [FILE] [OPTIONS]\n");
  return 1;
}

int dump(FILE *f){
  char word[16];
  int i, recvF, count = 0;
  while (!feof(f)){
    printf("%08X  ", count );
    recvF = fread(word, sizeof(char), 16, f);
    for (i = 0; i <recvF;i++)
      printf ("%02X ", 0xFF & word[i]);
    if (recvF < 16){
      for (i = 0; i < 16 - recvF ;i++)
        printf("   ");
    }
    printf("|");
    for (i = 0; i < recvF;i++){
      if(isgraph(word[i]))
        printf("%c", word[i]);
      else
        printf(".");
    }
    printf("|\n");
    count+= 0x10;
  }
  return 0;
}
