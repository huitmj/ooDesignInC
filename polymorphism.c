#include <stdio.h>
#include <assert.h>

//
// Shape Class
//

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

//
// Rectangle Class
//

typedef struct {
  Shape super;
	int width;
	int height;
} Rectangle;

static int Rectangle_area_ (Shape* const me){
  // Explicit downcast
  Rectangle* const me_ = (Rectangle*) me;
	return me_->width * me_->height;
};
static void Rectangle_draw_ (Shape* const me){
};

void Rectangle_Constructor(Rectangle* const me, int x, int y, int width, int height) {
  static struct ShapeVtbl const vtbl = {
	  &Rectangle_area_,
		&Rectangle_draw_
	};
	me->super.vptr = &vtbl;
	
	me->width=width;
	me->height=height;
}

int main(void) {
  Shape s1;
	Rectangle r1;
	
	Shape_Constructor(&s1,1,2);
	Rectangle_Constructor(&r1,1,2,3,4);
	
  return 0;
}