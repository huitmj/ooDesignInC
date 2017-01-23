#include <stdio.h>

typedef void (*func_ptr)(void);

void print_hello(void) { printf("Hello "); }

void print_world(void) { printf("World!\n"); }

int main(void) {
  func_ptr fptr;
  fptr = print_hello;
  fptr();
  fptr = print_world;
  fptr();
}
