#include <stdio.h>
#include <string.h>

#define MAX_LINES 5
#define MAX_LENGTH 1000

int main(void) {
  char lines[MAX_LINES][MAX_LENGTH];
  int count = 0;
  char input[MAX_LENGTH];

  while (1) {
    printf("Enter input: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
      break;
    }

    input[strcspn(input, "\n")] = '\0';
    strcpy(lines[count % MAX_LINES], input);
    count++;

    if (strcmp(input, "print") == 0) {
      int num_lines = (count < MAX_LINES) ? count : MAX_LINES;
      int start;

      if (count < MAX_LINES) {
        start = 0;
      } else {
        start = count % MAX_LINES;
      }

      for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[(start + i) % MAX_LINES]);
      }
    }
  }

  return 0;
}
