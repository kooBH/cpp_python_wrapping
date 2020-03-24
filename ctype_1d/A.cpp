#include <stdio.h>

class A{
  private:
    int n;
    double * data;
  public:
    A(int);
    void Set(double*);
    void Op();
    void Get(double*);
    void Print();
};

A::A(int n_){
  n = n_;
  data = new double[n];
  printf("Init\n");

}

void A::Set(double* d){
  printf("Set %d\n",n);
  for(int i=0;i<n;i++){
    data[i] = d[i];
    printf("%lf = %lf\n",data[i],d[i]);
  }

}

void A::Op(){
  for(int i=0;i<n;i++)
    data[i]*=3;
}

void A::Get(double*d){
  printf("Get %d\n",n);
  for(int i=0;i<n;i++)
    d[i]=data[i];
}
void A::Print(){
  for(int i=0;i<n;i++)
    printf("[%d] : %lf\n",i,data[i]);

}

extern "C"{
    A* A_new(int n) {return new A(n);}
    void A_Set(A* foo,double * d) {foo->Set(d);}
    void A_Op(A* foo){foo->Op();}
    void A_Get(A* foo,double * d) {foo->Get(d);}
    void A_Print(A* foo) {foo->Print();}
}

