#include <file0.h>
// #include <file1.h>
// #include <file2.h>

template <class A>
void MyClass0::serialize(A &ar, const unsigned v)
{
  using namespace cereal;
  ar & make_nvp("z", z);
}

template void MyClass0::serialize(cereal::XMLOutputArchive &, unsigned);
template void MyClass0::serialize(cereal::XMLInputArchive &, unsigned);
template void MyClass0::serialize(cereal::PortableBinaryOutputArchive &, unsigned);
template void MyClass0::serialize(cereal::PortableBinaryInputArchive &, unsigned);

/*
void ArchiveWrapper::write(MyClass1 &x, MyClass2 &y)
{
  std::ofstream file( "out.xml" );
  cereal::XMLOutputArchive archive(file);
  archive(x, y);
}
  
std::pair<MyClass1,MyClass2> ArchiveWrapper::read()
{
  std::ifstream file("out.xml");
  cereal::XMLInputArchive archive(file);
  MyClass1 x;
  MyClass2 y;
  archive(x);
  archive(y);
  return std::make_pair(x, y);
}
*/
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
