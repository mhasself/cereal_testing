This is (probably) the "ultra-minimal" branch of
https://github.com/mhasself/cereal_testing.

The code here seems to work properly under gcc and clang but fails in
icpc.  It compiles without warning or error in all cases.

This branch uses a vanilla cereal-1.3.0, which should be downloaded
and expanded in the root directory::

  wget https://github.com/USCiLab/cereal/archive/v1.3.0.tar.gz
  tar -xzf v1.3.0.tar.gz

Then build and run using gcc::

  mkdir build-gcc
  cd build-gcc
  CXX=g++ CC=gcc cmake ..
  make
  ./run_test2

Or build and run using icc::

  mkdir build-icc
  cd build-icc
  CXX=icpc CC=icc cmake ..
  make
  ./run_test2


The gcc form should produce no output to terminal, but will create
file ``out.xml`` with the following contents::

  <?xml version="1.0" encoding="utf-8"?>
  <cereal>
        <value0>
                <polymorphic_id>2147483649</polymorphic_id>
                <polymorphic_name>MyClass1</polymorphic_name>
                <ptr_wrapper>
                        <id>2147483649</id>
                        <data>
                                <cereal_class_version>0</cereal_class_version>
                                <value0>
                                        <cereal_class_version>0</cereal_class_version>
                                        <z>7</z>
                                </value0>
                                <x>11</x>
                        </data>
                </ptr_wrapper>
        </value0>
  </cereal>


In contrast the icpc executable will exit with error and the text::

  terminate called after throwing an instance of 'cereal::Exception'
    what():  Trying to save an unregistered polymorphic type (MyClass1).
  Make sure your type is registered with CEREAL_REGISTER_TYPE and that the archive you are using was included (and registered with CEREAL_REGISTER_ARCHIVE) prior to calling CEREAL_REGISTER_TYPE.
  If your type is already registered and you still see this error, you may need to use CEREAL_REGISTER_DYNAMIC_INIT.
  Aborted
