#include <file0.h>

int main()
{
  // main1();
  // main2();
  auto a1 = BasePtr(new MyClass1(11));
  auto a2 = BasePtr(new MyClass2(13));
  
  {
    ArchiveWriter aw;
    aw.put(a1);
    aw.put(a2);
    aw.write();
  }

  return 0;
}
