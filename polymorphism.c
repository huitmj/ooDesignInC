#include <stdio.h>
#include <assert.h>

struct ShapeVtbl;
typedef struct {
  struct ShapeVtbl const *vptr;
	int x;
	int y;
} Shape;

struct ShapeVtbl {
  int (*area)(Shape* const me);
	void (*draw)(Shape* const me);
};

static int Shape_area_ (Shape* const me) {
  assert(0);
	return 0;
};
static void Shape_draw_ (Shape* const me){
  assert(0);
};

void Shape_Constructor(Shape* const me, int x, int y) {
  static struct ShapeVtbl const vtbl = {
	  &Shape_area_,
		&Shape_draw_
	};
	me->vptr = &vtbl;
	
	me->x;
	me->y;
}

int main(void) {
  Shape s1;
	
	Shape_Constructor(&s1,1,2);
  return 0;
}