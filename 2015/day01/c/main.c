#include <stdio.h>

int part1(char *line) {
  int floor = 0, i = 0;

  while (line[i] != '\0' && line[i] != '\n') {
    floor += line[i++] == '(' ? 1 : -1;
  }

  return floor;
}

int part2(char *line) {
  int floor = 0, i = 0;

  while (line[i] != '\0' && line[i] != '\n') {
    floor += line[i++] == '(' ? 1 : -1;
    if (floor < 0) {
      return i;
    }
  }

  return -1;
}

int main() {
  FILE *file = fopen("../input.txt", "r");
  if (file == NULL) {
    printf("could not open file\n");
    return 1;
  }

  char line[8192];
  if (fgets(line, sizeof(line), file) != NULL) {
    printf("%d\n", part1(line));
    printf("%d\n", part2(line));
  }

  fclose(file);
  return 0;
}