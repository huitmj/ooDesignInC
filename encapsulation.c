#include <stdio.h>

typedef struct {
  int x;
	int y;
} Shape;

void Shape_constructor(Shape* const me, int x, int y) {
  me->x = x;
	me->y = y;
};

void Shape_moveBy(Shape* const me, int x, int y) {
  me->x += x;
	me->y += y;
};

void Shape_printLocation(Shape* const me) {
  printf("%d %d\n",me->x, me->y);
}

int main(void) {
  Shape s1, s2;
	
	Shape_constructor(&s1,0,1);
	Shape_printLocation(&s1);
	Shape_printLocation(&s2);
	
	Shape_constructor(&s2,1,2);
	Shape_printLocation(&s1);
	Shape_printLocation(&s2);
	
	Shape_moveBy(&s1,9,9);
	Shape_printLocation(&s1);
	Shape_printLocation(&s2);
	
  return 0;
}

