#include <stdio.h>

class A{
  private:
    int n;
    double ** data;
  public:
    A(int);
    void Set(double**);
    void Op();
    void Get(double**);
    void Print();
};

A::A(int n_){
  n = n_;
  data = new double*[n];
  for(int i=0;i<n;i++)
     data[i] = new double[n];
  printf("Init\n");
}

void A::Set(double** d){
  printf("Set %d\n",n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    data[i][j] = d[i][j];
    }
  }
}

void A::Op(){
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      data[i][j]*=3;
      data[i][j]+=j;
    }
}

void A::Get(double**d){
  printf("Get %d\n",n);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      d[i][j]=data[i][j];
}
void A::Print(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      printf("%lf ",data[i][j]);
    printf("\n");
  }
}

extern "C"{
#if _WIN32
    __declspec(dllexport) A* A_new(int n) {return new A(n);}
    __declspec(dllexport) void A_Set(A* foo,double ** d) {foo->Set(d);}
    __declspec(dllexport) void A_Op(A* foo){foo->Op();}
    __declspec(dllexport) void A_Get(A* foo,double ** d) {foo->Get(d);}
    __declspec(dllexport) void A_Print(A* foo) {foo->Print();}
#else
  A* A_new(int n) { return new A(n); }
  void A_Set(A* foo, double** d) { foo->Set(d); }
  void A_Op(A* foo) { foo->Op(); }
  void A_Get(A* foo, double** d) { foo->Get(d); }
  void A_Print(A* foo) { foo->Print(); }
#endif
}

