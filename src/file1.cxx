#include <iostream>
#include <file1.h>

template <class A>
void MyClass1::serialize(A &ar, const unsigned v)
{
  using namespace cereal;
  ar(cereal::base_class<MyClass0>(this));
  ar & make_nvp("x", x);
  ar & make_nvp("y", y);;
}

template void MyClass1::serialize(cereal::XMLOutputArchive &, unsigned);
template void MyClass1::serialize(cereal::XMLInputArchive &, unsigned);
template void MyClass1::serialize(cereal::PortableBinaryOutputArchive &, unsigned);
template void MyClass1::serialize(cereal::PortableBinaryInputArchive &, unsigned);

void main1() {
  std::cout << "main1\n";
}

