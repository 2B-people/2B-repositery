#include <map>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

class KeyClassPtr : public std::enable_shared_from_this<KeyClassPtr>
{

  private:
    string name_;

  public:
    typedef shared_ptr<KeyClassPtr> Ptr;
    KeyClassPtr(string name) : name_(name){};
    virtual ~KeyClassPtr() = default;
    void test()
    {
        cout << name_ << endl;
    }
};

class Key2:public KeyClassPtr
{
public:
    Key2(string name):KeyClassPtr::KeyClassPtr(name){};
};


int main()
{
    map<string, KeyClassPtr::Ptr> maptest;
    maptest["1"] = make_shared<KeyClassPtr>("111");
    maptest["2"] = make_shared<KeyClassPtr>("222");
    maptest["3"] = make_shared<Key2>("3333");
    map<string, KeyClassPtr::Ptr>::iterator iter;
    for (iter = maptest.begin(); iter != maptest.end(); iter++)
    {
        cout << iter->first << endl;
        iter->second->test();
    }
}