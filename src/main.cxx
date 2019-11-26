#include <file0.h>
#include <file1.h>
#include <file2.h>

int main()
{
  // main1();
  // main2();
  auto a1 = BasePtr(new MyClass1(11,12));
  auto a2 = BasePtr(new MyClass1(13,14));
  
  {
    ArchiveWriter aw;
    aw.put(a1);
    aw.put(a2);
    aw.write();
  }
  // {
  //   ArchiveWrapper aw;
  //   auto xy = aw.read();
  //   std::cout << xy.first.x << " " << xy.second.y << "\n";
  // }

  return 0;
}
