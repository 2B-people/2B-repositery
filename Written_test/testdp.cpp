#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canFill(int N, const vector<int>& toys, int c) {
    // 使用一个一维动态规划数组，dp[j] 表示容量为 j 的箱子能否被填满
    vector<bool> dp(N + 1, false);
    dp[0] = true; // 容量为0的箱子可以被填满

    // 遍历每个玩具
    for (int i = 0; i < toys.size(); ++i) {
        for (int j = N; j >= toys[i]; --j) {
            dp[j] = dp[j] || dp[j - toys[i]];
        }
    }

    // 考虑填充物
    for (int i = 1; i <= c; ++i) {
        for (int j = N; j >= 1; --j) {
            dp[j] = dp[j] || dp[j - 1];
        }
    }

    return dp[N];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, n, c;
        cin >> N >> n >> c;
        vector<int> toys(n);
        for (int i = 0; i < n; ++i) {
            cin >> toys[i];
        }
        if (canFill(N, toys, c)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}