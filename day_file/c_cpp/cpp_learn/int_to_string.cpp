#include <string>
#include <iostream>

using namespace std;

char* todata( &char b, &int a)
{
    string temp_str;
    temp_str = to_string(a);
    // printf("%s",temp_str.c_str());
    // cout<<endl;
    // cout<< temp_str.data()<<endl;
    return (char*)temp_str.data();
}

int main()
{
    string temp;
    char buf[1];
    char buf1[3];
    int a = 2;
    int b = 2;
    int c = 4;
    temp = to_string(a) + " " + to_string(b) + " " + to_string(c);
    char* sss = todata(buf,1);
//    todata(buf, 2);
    //buf[1] = '\0';

    // printf("%s", todata(buf, 2));
    cout << todata(buf, 2)<<endl;
    return 0;
}