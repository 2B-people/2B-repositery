#include <string>
#include <iostream>

using namespace std;

string test(string *data)
{
    cout<<data<<endl;    
    string te = "ssss";
    *data = te;
    cout<<data<<endl;
    return te;
}

int main(int argc, char const *argv[])
{
    string data ;
    string data1;
    data="dadad";
    cout<<&data<<endl;
    data= test(&data1);
    cout<<&data<<endl;
    cout<<data1<<endl;
    return 0;
}
