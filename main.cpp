#include "symbol_table.hpp"
#include "Root.h"
#include <iostream>
#include <vector>

extern int yyparse();
extern Program program;

int main()
{
    std::cout << "####### BEGIN PROGRAM #########" << std::endl;
	symbol_table.enter_scope();
	yyparse();
//	for (Constant dog : program.constDVjjecl.constants)
//    {
//	    std::cout << dog.value << std::endl;
//    }
}


//struct Expr
//{
//    virtual bool isCV() = 0;
//    virtual int CV() = 0;
//    virtual Register emit() = 0;
//    virtual void print() = 0;
//};
//struct Const : Expr
//{
//  bool isCV() {return true;}
//  int CV(){return value;}
//  int value;
//  Const(int value):value(value){}
//  print() {cout << value;}
//}
//
//struct Add : Expr
//{
//  bool isCV() {return false};
//  int CV(){throw "fit";}
//  Expr* a;
//  Expr* b;
//  print() {a->print(); cout << " + "; b->print();}
//  static op int(int a,int b){return a+b;}
//}
//
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
