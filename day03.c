#include <stdio.h>
#include <stdlib.h>

struct Tuple{
  int x;
  int y;
};

int main(int argc, char const *argv[]) {
  const char* filename = argv[1];
  FILE* fp = fopen(filename, "r");
  int santa_x = 0;
  int santa_y = 0;
  int robo_x = 0;
  int robo_y = 0;
  struct Tuple *seen = (struct Tuple*) malloc(sizeof(struct Tuple));
  int index = 0;
  int visited = 0;
  char c;
  int curr = 0;
  while((c = fgetc(fp)) != EOF){
    int curr_x = 0;
    int curr_y =0;
    if (curr % 2 == 0){
      if (c == '^')
        santa_y += 1;
      else if (c == '<')
        santa_x -= 1;
      else if (c == 'v')
        santa_y -= 1;
      else if (c == '>')
        santa_x += 1;
      curr_x = santa_x;
      curr_y = santa_y;
    } else {
      if (c == '^')
        robo_y += 1;
      else if (c == '<')
        robo_x -= 1;
      else if (c == 'v')
        robo_y -= 1;
      else if (c == '>')
        robo_x += 1;
      curr_x = robo_x;
      curr_y = robo_y;
    }
    int s = 1;
    for (int i = 0; i < index; i++){
      struct Tuple t = seen[i];
      if ((t.x == curr_x) && (t.y == curr_y)){
        s = 0;
        break;
      }
    }
    if (s){
      visited += 1;
      struct Tuple t = {curr_x, curr_y};
      seen[index] = t;
      index++;
    }
    curr++;

  }
  printf("%d\n", visited);
  free(seen);
  return 0;
}
