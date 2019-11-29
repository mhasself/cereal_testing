#include <file0.h>
#include <iostream>

template <class A>
void MyClass0::serialize(A &ar, const unsigned v)
{
  using namespace cereal;
  ar & make_nvp("z", z);
}

template void MyClass0::serialize(cereal::XMLOutputArchive &, unsigned);
template void MyClass0::serialize(cereal::XMLInputArchive &, unsigned);

void ArchiveWriter::put(BasePtr x)
{
  stuff.push_back(x);
}

void ArchiveWriter::write()
{
  std::ofstream file( "out.xml" );
  cereal::XMLOutputArchive archive(file);
  for (auto x: stuff)
    archive(x);
}

template <class A>
void MyClass1::serialize(A &ar, const unsigned v)
{
  using namespace cereal;
  ar(cereal::base_class<MyClass0>(this));
  ar & make_nvp("x", x);
}

template <class A>
void MyClass2::serialize(A &ar, const unsigned v)
{
  using namespace cereal;
  ar(cereal::base_class<MyClass0>(this));
  ar & make_nvp("y", y);;
}

template void MyClass1::serialize(cereal::XMLOutputArchive &, unsigned);
template void MyClass1::serialize(cereal::XMLInputArchive &, unsigned);

template void MyClass2::serialize(cereal::XMLOutputArchive &, unsigned);
template void MyClass2::serialize(cereal::XMLInputArchive &, unsigned);

CEREAL_REGISTER_DYNAMIC_INIT(file0);
