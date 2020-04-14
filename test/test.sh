#!/bin/sh
# run the result_test.ini in the network. This is not an unit test.
pwd
make -C ../quisp cleanall
make -C ../quisp BATCH=true QCONFIG=../quisp/network/ all
# These are creating all simulations HACK
# if we set quisp as ./quisp/..., may be error because of existance of the same name binary 
cd ../quisp && ./out/clang-release/quisp  -u Cmdenv -c Test_Realistic_Layer2_Simple  -f ./networks/test.ini > ../test/testresults.txt
echo "here at $(pwd)"
# On docker
g++ -std=c++11 ./quisp_test.cpp -I../../omnetpp/include -I../../clibrary/googletest/googletest/include -L../../clibrary/googletest/build/lib/ -pthread -lgtest_main -lgtest
# remove used results
echo "test done"
