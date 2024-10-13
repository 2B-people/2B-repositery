#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumVisitedCells(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0 || dp[i][j] == INT_MAX) continue;

        int limit_x = min(grid[i][j] + i, m - 1);
        int limit_y = min(grid[i][j] + j, n - 1);
        int start;
        if (i > 1 && dp[i][j] == dp[i - 1][j])  // 剪枝
          start = grid[i - 1][j] + i;
        else
          start = i + 1;
        for (int x = start; x <= limit_x; x++) {
          dp[x][j] = min(dp[i][j] + 1, dp[x][j]);
        }
        if (j > 1 && dp[i][j] == dp[i][j - 1])  // 剪枝
          start = grid[i][j - 1] + j;
        else
          start = j + 1;

        for (int y = start; y <= limit_y; y++) {
          dp[i][y] = min(dp[i][j] + 1, dp[i][y]);
        }
      }
    }
    if (dp[m - 1][n - 1] == INT_MAX) return -1;
    return dp[m - 1][n - 1];
  }
};