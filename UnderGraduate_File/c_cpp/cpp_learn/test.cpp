#include <string>
#include <iostream>
#include <vector>
#include "timer/timer.h"

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
    vector<int> arr;

    arr.resize(2);
    arr[0] = 1;
    cout << arr[0] << endl;

    return 0;
}
