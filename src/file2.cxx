#include <iostream>
#include <file2.h>

template <class A>
void MyClass2::serialize(A &ar, const unsigned v)
{
  using namespace cereal;
  ar(cereal::base_class<MyClass0>(this));
  ar & make_nvp("x", x);
  ar & make_nvp("y", y);;
}

template void MyClass2::serialize(cereal::XMLOutputArchive &, unsigned);
template void MyClass2::serialize(cereal::XMLInputArchive &, unsigned);
template void MyClass2::serialize(cereal::PortableBinaryOutputArchive &, unsigned);
template void MyClass2::serialize(cereal::PortableBinaryInputArchive &, unsigned);

CEREAL_REGISTER_DYNAMIC_INIT(file2);

void main2() {
  std::cout << "main2\n";
}
