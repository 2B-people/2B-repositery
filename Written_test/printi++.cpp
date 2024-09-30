#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 0,s = 0;
    do
    {
        if (i%2==0) 
        {
            i++;
            continue;
        }
        i++;
        s = s + i;
        
    } while (i<7);
    cout << s << endl;
    return 0;
}
