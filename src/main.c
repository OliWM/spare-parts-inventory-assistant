// main.c
// inform user if the tools they need are in our inventory or not.

#include <stdio.h>
#include <string.h>
#define MAX_INPUT 100
int main() {
  const char part1[] = "hydraulic pump";
  const char part2[] = "PLC module";
  const char part3[] = "servo motor";
  const char special1[] = "Do you actually have any parts?";
  const char special2[] = "Is there anything in stock at all?";
  char userPart[MAX_INPUT] = "";

  puts("Hej. Welcome to the spare parts inventory!");
  while (1) {
    puts("Which part do you need?");
    fgets(userPart, sizeof(userPart), stdin);
    userPart[strcspn(userPart, "\n")] = '\0';
    if ((strcmp(userPart, part1) == 0) || (strcmp(userPart, part2) == 0) ||
        (strcmp(userPart, part3) == 0)) {
      printf("I have got %s here for you 😊. Bye!\n", userPart);
      break;
    } else if ((strcmp(userPart, special1) == 0) ||
               (strcmp(userPart, special2) == 0)) {
      printf("We have {part_count} part(s)!%s\n%s\n%s\n", part1, part2,
             part3); // lav rent faktisk et part count
    } else {
      printf("I am afraid we don’t have any %s in the inventory 😔\n",
             userPart);
    }
  }
  return 0;
}
