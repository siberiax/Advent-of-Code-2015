#include<stdio.h>

int main(int argc, char** argv){
  FILE* fp = fopen(argv[1], "r");
  int total, print, second = 0;
  char buf[256];
  while(fgets(buf, 256, fp) != NULL){
    char prev = 0;
    int len = strlen(buf) - 1;
    int i;
    int curr = 0;
    total += len;
    for (i = 0; i < len; i++){
      if (prev == '\\'){
        if (buf[i] == 'x'){
          prev = buf[i + 2];
          i += 2;
        } else if (buf[i] == '\\'){
          prev = 0;
        } else {
          prev = buf[i];
        }
      } else {
        prev = buf[i];
        curr++;
      }
    }
    print += curr - 2;

    int j;
    for (j = 0; j < len; j++){
      if (buf[j] == '\\' || buf[j] == '\"'){
        second += 2;
      } else {
        second++;
      }
    }
    second += 2;
  }
  printf("%d\n", total - print);
  printf("%d\n", second - total);
}
