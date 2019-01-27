#include <map>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

class KetTest
{
private:
string name_;
public:
    KetTest(string name):name_(name){};
    virtual ~KetTest() =default;
    void test(){
        cout<< name_ <<endl;
    }
};

int main()
{
    map<string,KetTest> maptest;
    KetTest key1("1111");
    KetTest key2("2222");
    maptest.insert(pair<string,KetTest>("1",key1));
    maptest.insert(pair<string,KetTest>("2",key2));

    map<string,KetTest>::iterator iter;
    for(iter = maptest.begin() ;iter != maptest.end();iter++)
    {
        cout << iter->first<<endl;
        iter->second.test();
    }
    
    return 0;
}