#pragma once

#include <file0.h>

class MyClass2 : public MyClass0 {
 public:
  int x;
  int y;
  template <class A> void serialize(A &ar, const unsigned v);
  MyClass2() : MyClass0(), x(2), y(3) {};
  MyClass2(int x_, int y_) : MyClass0(), x(x_), y(y_) {};
  void sayType() {
    std::cout << "MyClass2\n";
  }
};

// Without this register, cereal complains at run time.
CEREAL_REGISTER_TYPE(MyClass2);

// This is not needed in gcc.
//CEREAL_REGISTER_POLYMORPHIC_RELATION(MyClass0, MyClass2);

void main2();

