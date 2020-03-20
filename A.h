class A{
    private :
      double **data;
    public:
      int x0, y0, x1, y1;
      A(int x0, int y0, int x1, int y1);
      ~A();
      int getLength();
      int getHeight();
      int getArea();
      void move(int dx, int dy);
      void init();
      void dele();
      void inc();
      void dec();
      double get();
};
