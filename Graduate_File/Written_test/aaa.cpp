#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> boysColors, girlColors;
    vector<int> boys(n), girls(n);
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        boysColors[a]++;
        boys[i] = a;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b;
        girlColors[b]++;
        girls[i] = a;
    }
    
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        int boyColor = boys[i];
        count += n - girlColors[boyColor];
    }
    
    
    cout << count << endl;
    return 0;
}