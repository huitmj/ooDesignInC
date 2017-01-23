#include <stdio.h>

typedef struct {
  void (*func)(void);
} struct_fns_type;

void print_hello(void) { printf("Hello "); }

void print_world(void) { printf("World!\n"); }

struct_fns_type fns[2] = { print_hello, print_world };

int main(void) {
  fns[0].func();
  fns[1].func();
}

