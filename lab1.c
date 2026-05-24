#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  size_t bufsize = 0;
  ssize_t nread;

  while (1) {
    printf("Please enter some text: ");

    nread = getline(&buffer, &bufsize, stdin);

    if (nread == -1) {
      printf("\nExit\n");
      break;
    }

    if (buffer[nread - 1] == '\n') {
      buffer[nread - 1] = '\0';
    }

    printf("Tokens:\n");

    char *saveptr;
    char *token = strtok_r(buffer, " ", &saveptr);

    while (token != NULL) {
      printf("  %s\n", token);
      token = strtok_r(NULL, " ", &saveptr);
    }
  }

  free(buffer);
  return 0;
}
