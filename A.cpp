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

void A::init(){
  data = new double*[2];
  data[0] = new double[2];
  data[1] = new double[2];

  data[0][0]=0.0;
  data[0][1]=0.0;
  data[1][0]=0.0;
  data[1][1]=0.0;
}
void A::dele(){
  delete[] data[0];
  delete[] data[1];
  delete[] data;
}
void A::inc(){
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      data[i][j] = data[i][j]+1;
    }
  }
}
void A::dec(){
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      data[i][j] = data[i][j]-1;
    }
  }
}
double A::get(){
  double sum = 0.0;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      sum +=data[i][j];
    }
  }
  return sum;
}
