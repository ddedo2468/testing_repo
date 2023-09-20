#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_s {
  int n;
  struct stack_s *next;
} stack_t;

stack_t *stack = NULL;

void push(int value) {
  stack_t *new_node = malloc(sizeof(stack_t));
  if (new_node == NULL) {
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
  }

  new_node->n = value;
  new_node->next = stack;
  stack = new_node;
}

void pall() {
  stack_t *current = stack;
  while (current != NULL) {
    printf("%d\n", current->n);
    current = current->next;
  }
}

void pint() {
  if (stack == NULL) {
    fprintf(stderr, "Error: stack empty\n");
    exit(EXIT_FAILURE);
  }

  printf("%d\n", stack->n);
}

void pop() {
  if (stack == NULL) {
    fprintf(stderr, "Error: stack empty\n");
    exit(EXIT_FAILURE);
  }

  stack_t *temp = stack;
  stack = stack->next;
  free(temp);
}

void swap() {
  if (stack == NULL || stack->next == NULL) {
    fprintf(stderr, "Error: stack too short\n");
    exit(EXIT_FAILURE);
  }

  int temp = stack->n;
  stack->n = stack->next->n;
  stack->next->n = temp;
}

void add() {
  if (stack == NULL || stack->next == NULL) {
    fprintf(stderr, "Error: stack too short\n");
    exit(EXIT_FAILURE);
  }

  stack->next->n += stack->n;
  pop();
}

void nop() {}

void processCommands(FILE *file) {
  char line[100];
  while (fgets(line, sizeof(line), file) != NULL) {
    char *opcode = strtok(line, " ");
    char *arg = strtok(NULL, " ");

    if (opcode == NULL || opcode[0] == '#') {
      continue;
    }

    if (strcmp(opcode, "push") == 0) {
      push(atoi(arg));
    } else if (strcmp(opcode, "pall") == 0) {
      pall();
    } else if (strcmp(opcode, "pint") == 0) {
      pint();
    } else if (strcmp(opcode, "pop") == 0) {
      pop();
    } else if (strcmp(opcode, "swap") == 0) {
      swap();
    } else if (strcmp(opcode, "add") == 0) {
      add();
    } else if (strcmp(opcode, "nop") == 0) {
      nop();
    } else {
      fprintf(stderr, "Error: unknown opcode: %s\n", opcode);
      exit(EXIT_FAILURE);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Error: could not open file: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  processCommands(file);
  fclose(file);

  return EXIT_SUCCESS;
}
