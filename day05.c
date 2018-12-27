#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  FILE* fp = fopen(argv[1], "r");
  char line[16];
  char vowels[5] = "aeiuo";
  int nice = 0;
  int nice2 = 0;
  while(fscanf(fp, "%s", line) != EOF){
    int vowel_count = 0;
    int dub = 0;
    int acceptible = 1;
    int sep_by_1 = 0;
    int dub_dub = 0;
    for (int i = 0; i < strlen(line); i++){

      //part1
      if (i){
        if (line[i] == 'b' && line[i-1] == 'a')
          acceptible = 0;
        if (line[i] == 'd' && line[i-1] == 'c')
          acceptible = 0;
        if (line[i] == 'q' && line[i-1] == 'p')
          acceptible = 0;
        if (line[i] == 'y' && line[i-1] == 'x')
          acceptible = 0;
        if (line[i] == line[i-1])
          dub = 1;
      }
      for(int x = 0; x < 5; x++){
        if (line[i] == vowels[x]){
          vowel_count++;
        }
      }

      //part2
      if (i >= 3){
        for (int x = 1; x < i - 1; x++){
          if (line[x-1] == line[i-1] && line[x] == line[i]){
            dub_dub = 1;
          }
        }
      }
      if (i > 1){
        if (line[i] == line[i-2]){
          sep_by_1 = 1;
        }
      }
    }
    if ((vowel_count > 2) && dub && acceptible){
      nice++;
    }
    if (sep_by_1 && dub_dub)
      nice2++;
  }
  printf("%d\n", nice);
  printf("%d\n", nice2);
  return 0;
}
