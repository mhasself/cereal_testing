#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <cereal/cereal.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <fstream>

class MyClass0 {
 public:
  int z;
  template <class A> void serialize(A &ar, const unsigned v);
  virtual void sayType() = 0;
};

//class ArchiveWrapper {
//public:
//  void write(MyClass1 &x, MyClass2 &y);
//  std::pair<MyClass1,MyClass2> read();
//};
typedef boost::shared_ptr<MyClass0> BasePtr;

class ArchiveWriter {
 public:
  void put(BasePtr x);
  void write();
 private:
  std::vector<BasePtr> stuff;
};

CEREAL_FORCE_DYNAMIC_INIT(file1);
CEREAL_FORCE_DYNAMIC_INIT(file2);
