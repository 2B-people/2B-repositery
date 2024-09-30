#include <iostream>
#include <vector>
using namespace std;

string ro_name("UDRLFB");

int rotation[12][24] = {
    {5,6,3,4,9,10,7,8,14,13,11,12,1,2,15,16,17,18,19,20,21,22,23,24},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {17,2,19,4,5,6,7,8,9,10,11,12,13,14,15,16,23,18,21,20,1,22,3,24},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {17,2,19,4,5,6,7,8,9,23,11,21,13,14,15,16,1,18,3,20,12,22,10,24},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};


vector<char> ro(vector<char> cube, int step) {
    vector<char> res = cube;
    for (int i = 0; i < 24; i++) {
        res[i] = cube[rotation[step][i]-1];
    }
    return res;
}

int main() {
    // 状态
    vector<char> cube(24, 'w');
    vector<int> steps;

    string input;
    // 处理魔方
    getline(cin, input);
    for (int i = 0; i < input.size(); i++) {
        cube[i] = input[i];
    }
    // 处理操作
    getline(cin, input);
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '\'') {
            continue;
        } else if (input[i + 1] == '\'') {
            int step = ro_name.find(input[i]);
            step += 6;
            steps.push_back(step);
        } else {
            int step = ro_name.find(input[i]);
            steps.push_back(step);
        }
    }

    for (int i = 0; i < steps.size(); i++) {
        cube = ro(cube, steps[i]);
    }
    for (int i = 0; i < cube.size(); i++) {
        cout << cube[i];
    }

}


// 64 位输出请用 printf("%lld")