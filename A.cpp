#include "A.h"

A::A(int X0, int Y0, int X1, int Y1)
{
  x0 = X0;
  y0 = Y0;
  x1 = X1;
  y1 = Y1;
}

A::~A()
{
}

int A::getLength()
{
  return (x1 - x0);
}

int A::getHeight()
{
  return (y1 - y0);
}

int A::getArea()
{
  return (x1 - x0) * (y1 - y0);
}

void A::move(int dx, int dy)
{
  x0 += dx;
  y0 += dy;
  x1 += dx;
  y1 += dy;
}

void A::init(){}
void A::dele(){}
void A::inc(){}
void A::dec(){}
