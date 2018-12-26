#include <stdio.h>

int main(int argc, char const *argv[]) {
  const char* filename = argv[1];
  FILE* f = fopen(filename, "r");
  int floor = 0;
  char c;
  int part2 = 0;
  int part2_found = 1;
  while ((c = fgetc(f)) != EOF){
    if (part2_found && floor < 0){
      part2_found = 0;
      printf("%d\n", part2);
    }
    if (c == '(')
      floor++;
    else if (c == ')')
      floor--;
    part2++;
  }
  printf("%d\n", floor);
  return 0;
}
