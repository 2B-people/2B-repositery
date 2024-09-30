#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;
std::string FindRangeString(const std::string &input)
{
    int max = -1, min = 10;
    int max_index = 0, min_index = 0;
    int i = 0;
    for (char c : input)
    {
        if (isdigit(c))
        {
            int num = c - '0';
            if (num > max)
            {
                max = num;
                max_index = i;
            }
            if (num < min)
            {
                min = num;
                min_index = i;
            }
        }
        i++;
    }

    if (max_index - min_index == 1 || max_index - min_index == -1)
    {
        return "";
    }
    else if (max_index > min_index)
    {
        return input.substr(min_index + 1, max_index-min_index-1);
    }
    else if (max_index < min_index)
    {
        return input.substr(max_index + 1, min_index-max_index-1);
    }
}


int main()
{
    string input;
    getline(cin,input);
    auto result = FindRangeString(input);
    printf("%s\n", result.c_str());
    return 0;
}