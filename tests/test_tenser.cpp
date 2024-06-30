#include "../include/blackwall/blackwall.hpp"
#include <iostream>
#include <cassert>

#define PRINT(x) std::cout << (x) << std::endl;

void test1(){
    BLKW::Tenser<int> t({1});
    assert (t.size() == 1);
    int* res = t[{0}];
    PRINT(*res);
    assert ((*res) == 0);
    PRINT("test 1 passed");
}

void test2(){
    BLKW::Tenser<int> t = new BLKW::Tenser<int>({2,2});
    assert (t.size() == 4);
    int* first = t[{0,0}];
    int* second = t[{0,1}];
    int* third = t[{1,0}];
    int* fourth = t[{1,1}];

    assert ((*first) == 0);
    assert ((*second) == 0);
    assert ((*third) == 0);
    assert ((*fourth) == 0);
    PRINT("test 2 passed");
}


int main(){
    test1();
    test2();
    return 0;
}