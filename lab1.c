
#include <stdio.h>
#include <stdlib.h>
int main() {
  char *sentence = NULL; // Buffer pointer
  size_t len = 0;        // Buffer size
  ssize_t read;          // Number of characters read
  printf("Enter a line: ");
  read = getline(&sentence, &len, stdin);
  char *word = "";
  if (read != -1) {

    for (size_t i = 0; i < len; i++) {
      if (sentence[i] == ' ') {
        printf("%s \n", word);
        word = "";
      } else if (i == len - 1) {
        printf("%s \n", word);
        word = "";
      } else {
        word += sentence[i];
        continue;
      }
    }
    printf("You entered: %s", sentence);
  } else {
    printf("Error reading input\n");
  }
  free(sentence); // Prevent memory leaks
  return 0;
}
