#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector< vector< bool > > array(6);
    for(size_t i = 0; i < array.size(); i++)
    {
        array[i].resize(2);
    }
    for(size_t i = 0; i < array.size(); i++)
    {
       for(size_t j = 0; j < 2; j++)
       {
           array[i][j] = (i+1)*(j+1);
       }
    }
    for(size_t i = 0; i < array.size(); i++)
    {
       for(size_t j = 0; j < 2; j++)
       {
           cout<<array[i][j];
       }
       cout<<endl;
    }    
}
