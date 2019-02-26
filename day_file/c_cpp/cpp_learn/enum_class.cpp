
#include <vector>
#include <array>
#include <map>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include <stdio.h>

using namespace std;

enum class test
{
    a,
    b,
    c,
};

class enum_class
{
private:
    int grade_;
    test type_;
public:
    typedef shared_ptr<enum_class> Ptr;
    enum_class(test type):type_(type),grade_(1)
    {};
    ~enum_class() = default;
};


int main()
{
    const int a=0;
    array<test,3> wa;
    get<a>(wa);
    test name = test::a;
        cout<<"a";
    return 0;
}