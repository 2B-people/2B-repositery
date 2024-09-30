#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, int> left_count;
    unordered_map<int, int> right_count;
    int result = 0;

    left_count[a[0]]++;
    for (int k = 2; k < n; k++)
    {
        right_count[a[k]]++;
    }
    
    for (int j = 1; j < n-1; j++)
    {
        auto it = a[j]-1;
        if (left_count[it] > 0 && right_count[it] > 0)
        {
            result += left_count[it] * right_count[it];
        }
        left_count[a[j]]++; 
        right_count[a[j]]--;
    }
    

    cout << result << endl;
    return 0;
}