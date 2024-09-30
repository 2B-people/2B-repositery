#include <iostream>
#include <string>

using namespace std;

int main()
{
    uint8_t robot_num_ =1;
    string datakey = "robot" + to_string(robot_num_) + "/local_plan/flag";
    cout<<datakey<<endl;
}