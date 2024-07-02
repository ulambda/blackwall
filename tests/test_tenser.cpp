#include "../include/blackwall/blackwall.hpp"
#include <iostream>
#include <cassert>

#define PRINT(x) std::cout << (x) << std::endl;



void test1(){
    BLKW::Tenser<int> t = BLKW::Tenser<int>::zeros({1});
    assert (t.size() == 1);
    int* res = t[{0}];
    //PRINT(*res);
    assert ((*res) == 0);
    PRINT("test 1 passed");
}

void test2(){
    BLKW::Tenser<int> t = BLKW::Tenser<int>::zeros({2,2});
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

void test3(){
    // BLKW::Tenser<double> t = BLKW::Tenser<double>::random({3,3});
    // assert (t.size() == 9);
    // //t.print();

    // std::cout << "\n";
    // std::cout << *t[{0,0}] << "\n";
    // std::cout << *t[{1,0}] << "\n";
    // std::cout << *t[{2,0}] << "\n";
    // std::cout << *t[{0,1}] << "\n";
    // std::cout << *t[{0,2}] << "\n";
    // std::cout << *t[{1,1}] << "\n";
    // std::cout << *t[{1,2}] << "\n";
    // std::cout << *t[{2,1}] << "\n";
    // std::cout << *t[{2,2}] << "\n";

    // PRINT("test 3 passed");
}

void test4(){
    BLKW::Tenser<int> t = BLKW::Tenser<int>::ones({2,2});
    BLKW::Tenser<int> t2 = BLKW::Tenser<int>::zeros({5,2,6,4});
    t2 = t;
    assert (t.size() == 4);
    assert (t2.size() == 4);

    assert ((*t[{0,0}]) == 1);
    assert ((*t2[{0,0}]) == 1);


    PRINT("test 4 passed");
}

void test5(){
    BLKW::Tenser<int> t = BLKW::Tenser<int>::ones({2,2});
    BLKW::Tenser<int> t2 = BLKW::Tenser<int>::ones({2,2});

    BLKW::Tenser<int> t3 = t;

    PRINT("test 5 passed");
}


void test6(){
    BLKW::Tenser<int> t = BLKW::Tenser<int>::ones({2,2});
    t.replace({0,1}, 248);
    assert ((*t[{0,1}]) == 248);
    assert ((*t[{0,0}]) == 1);
    PRINT("test 6 passed");
}


int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

}