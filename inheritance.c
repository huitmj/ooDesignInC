#include <stdio.h>

typedef struct {
  int x;
  int y;
} Shape;

void Shape_constructor(Shape *const me, int x, int y) {
  me->x = x;
  me->y = y;
};

void Shape_moveBy(Shape *const me, int x, int y) {
  me->x += x;
  me->y += y;
};

void Shape_printLocation(Shape *const me) { printf("%d %d\n", me->x, me->y); }

typedef struct {
  Shape super;
  int width;
  int height;
} Rectangle;

void Rectangle_constructor(Rectangle *const me, int x, int y, int width,
                           int height) {
  Shape_constructor(&me->super, x, y);
  me->width = width;
  me->height = height;
}

int main(void) {
  Rectangle r1, r2;

  Rectangle_constructor(&r1, 0, 2, 10, 15);
  Shape_printLocation(&r1.super);
  Shape_printLocation(&r2.super);

  Rectangle_constructor(&r2, -1, 3, 5, 8);
  Shape_printLocation(&r1.super);
  Shape_printLocation(&r2.super);

  Shape_moveBy((Shape *)&r1, -2, 3);
  Shape_printLocation(&r1.super);
  Shape_printLocation(&r2.super);

  Shape_moveBy(&r2.super, 2, -1);
  Shape_printLocation(&r1.super);
  Shape_printLocation(&r2.super);

  return 0;
}