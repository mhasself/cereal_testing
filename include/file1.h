#pragma once

#include <file0.h>

class MyClass1 : public MyClass0 {
 public:
  int x;
  int y;
  template <class A> void serialize(A &ar, const unsigned v);
  MyClass1() : MyClass0(), x(0), y(1) {};
  MyClass1(int x_, int y_) : MyClass0(), x(x_), y(y_) {};
  void sayType() {
    std::cout << "MyClass1\n";
  }
};

// Without this register, cereal complains at run time.
CEREAL_REGISTER_TYPE(MyClass1);

// This is not needed in gcc.
//CEREAL_REGISTER_POLYMORPHIC_RELATION(MyClass0, MyClass1);

void main1();

