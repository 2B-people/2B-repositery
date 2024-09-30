#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int maxScore(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j == 1) {
                dp[i][j] = gcd(nums[i - 1], dp[i - 1][j]);
            } else {
                dp[i][j] = std::max(dp[i - 1][j - 1] + nums[i - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[n][k];
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    std::cout << "Max Score: " << maxScore(nums, k) << std::endl;
    return 0;
}