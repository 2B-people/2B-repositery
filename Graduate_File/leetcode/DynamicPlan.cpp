#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i <= n; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[n];
  }
  bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    int m = wordDict.size();
    vector<bool> dp(n + 1, false);
    for (int i = 0; i < m; i++) {
      int len = wordDict[i].size();
      if (s.substr(0, len) == wordDict[i]) {
        dp[len] = true;
      }
    }
    for (int i = 0; i < n; i++) {
      if (dp[i]) {
        for (int j = 0; j < m; j++) {
          int len = wordDict[j].size();
          if (i + len > n) continue;
          if (s.substr(i, len) == wordDict[j]) {
            dp[i + len] = true;
          }
        }
      }
      if (dp[n]) {
        return dp[n];
      }
    }
    return dp[n];
  }

  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, 0x3f3f3f3f);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      for (int m = 0; m < amount + 1; m++) {
        dp[m] = min(dp[m], m >= coins[i] ? dp[m - coins[i]] + 1 : 0x3f3f3f3f);
      }
    }
    return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
  }

  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2 & nums[1] > nums[0]) return 2;

    vector<int> dp(n + 1, 1);
    int maxlen = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i],dp[j] + 1);
        }
      }
      maxlen = max(maxlen, dp[i]);
    }

    return maxlen;
  }
};