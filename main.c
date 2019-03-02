#include "include/libhex.h"

int main(int argc, char *argv[]){
  int opt;
  FILE *file;
  while ((opt = getopt(argc, argv, "hf:")) != -1){
    switch (opt){
      case 'h':
        exit(usage());
      case 'f':
        file = fopen(optarg, "rb");
        dump(file);
        break;
    }
  }
  return 0;
}
