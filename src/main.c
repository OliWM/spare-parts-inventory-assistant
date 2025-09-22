// main.c
// inform user if the tools they need are in our inventory or not.

#include "stdbool.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100
int main(void) {
  const char *parts[] = {"hydraulic pump", "PLC module", "servo motor"};
  const char special1[] = "Do you actually have any parts?";
  const char special2[] = "Is there anything in stock at all?";
  char userPart[MAX_INPUT] = "";
  int partCount = sizeof(parts) / sizeof(parts[0]);
  bool found = false;
  puts("Hej. Welcome to the spare parts inventory!");

  while (found != true) {
    puts("Which part do you need?");
    fgets(userPart, sizeof(userPart), stdin);
    userPart[strcspn(userPart, "\n")] = '\0';

    if ((strcmp(userPart, special1) == 0) ||
        (strcmp(userPart, special2) == 0)) {
      printf("We have %d part(s)!\n", partCount);
      for (size_t n = 0; n < partCount; n++) {
        printf("%s\n", parts[n]);
      }
      continue;
    } else {
      for (size_t i = 0; i < partCount; i++) {
        if (strcmp(parts[i], userPart) == 0) {
          printf("I have got %s here for you 😊. Bye!\n", userPart);
          found = true;
          break;
        }
      }
    }
    if (found != true) {
      printf("I am afraid we don’t have any %s in the inventory 😔\n",
             userPart);
      continue;
    }
  }
  return 0;
}