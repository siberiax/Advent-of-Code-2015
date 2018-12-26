#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  const char* filename = argv[1];
  FILE* file = fopen(filename, "r");
  int total = 0;
  int ribbon = 0;
  int read = 0;
  char* line;
  size_t size = 11;
  int nums[3];
  while(fscanf(file, "%dx%dx%d", &nums[0], &nums[1], &nums[2]) != EOF){
    int a = nums[0];
    int b = nums[1];
    int c = nums[2];
    int max = 0;
    for(int i = 0; i < 3; i++){
      if (nums[i] > max)
        max = nums[i];
    }
    for(int i = 0; i < 3; i++){
      if (nums[i] != max)
        ribbon += 2*nums[i];
    }
    total += 2*a*b + 2*a*c + 2*b*c;
    nums[0] = a*b;
    nums[1] = a*c;
    nums[2] = b*c;
    int min = 9999;
    for(int i = 0; i < 3; i++){
      if (nums[i] < min)
        min = nums[i];
    }
    total += min;
  }
  printf("%d\n", total);
  printf("%d\n", ribbon);
  return 0;
}
