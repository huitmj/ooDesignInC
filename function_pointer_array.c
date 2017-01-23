#include <stdio.h>

typedef void (*func_ptr)(void);

void print_hello(void) { printf("Hello "); }

void print_world(void) { printf("World!\n"); }

func_ptr a[] = { print_hello, print_world };

int main() {
  a[0]();
  a[1]();
}

