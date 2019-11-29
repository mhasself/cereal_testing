#include <cereal/cereal.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/xml.hpp>

#include <fstream>
#include <iostream>

class MyClass0 {
 public:
  int z;
  MyClass0() : z(7) {};
  template <class A> void serialize(A &ar, const unsigned v) {
    ar & cereal::make_nvp("z", z);
  }
  virtual void sayType() = 0;
};

typedef std::shared_ptr<MyClass0> BasePtr;

class MyClass1 : public MyClass0 {
 public:
  int x;
  MyClass1() : MyClass0(), x(0) {};
  MyClass1(int x_) : MyClass0(), x(x_) {};
  template <class A> void serialize(A &ar, const unsigned v) {
    ar(cereal::base_class<MyClass0>(this));
    ar & cereal::make_nvp("x", x);
  }
  void sayType() {
    std::cout << "MyClass1\n";
  }
};

template void MyClass0::serialize(cereal::XMLOutputArchive &, unsigned);
template void MyClass1::serialize(cereal::XMLOutputArchive &, unsigned);

CEREAL_REGISTER_TYPE(MyClass0);
CEREAL_REGISTER_TYPE(MyClass1);
CEREAL_REGISTER_POLYMORPHIC_RELATION(MyClass0, MyClass1);

int main()
{
  auto a1 = BasePtr(new MyClass1(11));
  
  {
    std::ofstream file( "out.xml" );
    cereal::XMLOutputArchive archive(file);
    archive(a1);
  }

  return 0;
}
