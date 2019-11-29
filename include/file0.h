#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <cereal/cereal.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/polymorphic.hpp>
#include <fstream>

class MyClass0 {
 public:
  int z;
  template <class A> void serialize(A &ar, const unsigned v);
  virtual void sayType() = 0;
};

typedef boost::shared_ptr<MyClass0> BasePtr;

class ArchiveWriter {
 public:
  void put(BasePtr x);
  void write();
 private:
  std::vector<BasePtr> stuff;
};

class MyClass1 : public MyClass0 {
 public:
  int x;
  template <class A> void serialize(A &ar, const unsigned v);
  MyClass1() : MyClass0(), x(0) {};
  MyClass1(int x_) : MyClass0(), x(x_) {};
  void sayType() {
    std::cout << "MyClass1\n";
  }
};

class MyClass2 : public MyClass0 {
 public:
  int y;
  template <class A> void serialize(A &ar, const unsigned v);
  MyClass2() : MyClass0(), y(3) {};
  MyClass2(int y_) : MyClass0(), y(y_) {};
  void sayType() {
    std::cout << "MyClass2\n";
  }
};

// Without this register, cereal complains at run time.
CEREAL_REGISTER_TYPE(MyClass1);
CEREAL_REGISTER_TYPE(MyClass2);

CEREAL_FORCE_DYNAMIC_INIT(file0);

