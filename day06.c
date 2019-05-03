#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tuple{
  int x;
  int y;
};

char** split(char* line, const char * delim, int cols){
  char** ret = malloc(cols * sizeof(char*));
  char* token = strtok(line, delim);
  for(int i = 0; token !=  NULL; i++){
    ret[i] = malloc(strlen(token));
    strcpy(ret[i], token);
    token = strtok(NULL, delim);
  }
  return ret;
}

int main(int argc, char** argv){
  FILE* fp = fopen(argv[1], "r");

  int instructions[300];
  struct Tuple starts[300];
  struct Tuple ends[300];

  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  const char * s = " ";
  int i = 0;
  while((read = getline(&line, &len, fp)) != -1){
    char** words = split(line, s, 5);
    int x, y;
    int num_words;
    if(strcmp(words[0], "turn") == 0){
      num_words = 5;
      if (strcmp(words[1], "on") == 0){
        instructions[i] = 1;
      } else {
        instructions[i] = 0;
      }
      sscanf(words[2], "%d,%d", &x, &y);
      struct Tuple t = {x, y};
      starts[i] = t;
      sscanf(words[4], "%d,%d", &x, &y);
      struct Tuple t2 = {x, y};
      ends[i] = t2;
    } else {
      num_words = 4;
      instructions[i] = 3;
      sscanf(words[1], "%d,%d", &x, &y);
      struct Tuple t = {x, y};
      starts[i] = t;
      sscanf(words[3], "%d,%d", &x, &y);
      struct Tuple t2 = {x, y};
      ends[i] = t2;
    }
    for (int x = 0; x < num_words; x++){
      free(words[x]);
    }
    free(words);
    i++;
  }
  int grid[1000][1000];
  for (int i = 0; i < 1000; i++){
    for (int j = 0; j < 1000; j++){
      grid[i][j] = 0;
    }
  }
  for (int inst = 0; inst < 300; inst++){

    struct Tuple start = starts[inst];
    struct Tuple end = ends[inst];
    for (int i = start.x; i <= end.x; i++){
      for (int j = start.y; j <= end.y; j++){
        if (instructions[inst] == 0){
          if (grid[i][j] > 0)
            grid[i][j] -= 1;
        } else if (instructions[inst] == 1){
          grid[i][j] += 1;
        } else {
          grid[i][j] += 2;
        }
      }
    }
  }
  int total = 0;
  for (int i = 0; i < 1000; i++){
    for (int j = 0; j < 1000; j++){
      total += grid[i][j];
    }
  }
  printf("%d\n", total);

}
