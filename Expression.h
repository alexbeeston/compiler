#include <iostream>

struct Expression
{
  virtual bool isCV() = 0;
  virtual int CV() = 0;
//  virtual Register emit() = 0;
//  virtual void print() = 0;
};

struct Constant : Expression
{
  bool isCV() {return true;}
  int CV(){return value;}
  int value;
  Constant(int value):value(value){}
};

//struct Add : Expression
//{
//  bool isCV() {return false;};
//  int CV(){throw "fit";}
//  Expression* a;
//  Expression* b;
//  print() {a->print(); std::cout << " + "; b->print();}
//  static op int(int a,int b){return a+b;}
//};

//template<typename T>
//Expr* binOp ( Expr* a, Expr* b  )
//{
//  if(a->isCV() && b->isCV())
//  {
//	auto result = new Const(T::op(a->CV(),b->CV()));
//	delete a;
//	delete b;
//	return result;
//  }
//  return new T(a,b);
//}
//
//{$$ = binOp<Add>($1,$3}
//{$$ = binOp<Sub>($1,$3,[](int a,int b){return a-b;});}
//
