#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int m, n;
    vector<vector<int>> dp;
    int state[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int>> &matrix, int i, int j)
    {
        if (dp[i][j])
        {
            return dp[i][j];
        }
        dp[i][j] = 1;
        for (auto s : state)
        {
            int x = i + s[0];
            int y = j + s[1];
            if (x >= 0 && x < n && y >= 0 && y < m
            && matrix[i][j] < matrix[x][y])
                dp[i][j] = max(dp[i][j],dfs(matrix,x,y) + 1);
        }
        return dp[i][j];
    }
    int solve(vector<vector<int>> &matrix)
    {
        // write code here
        n = matrix.size();
        if(n == 0)
            return 0;
        m = matrix[0].size();
        if(m == 0)
            return 0;
        dp.reserve(n,vector<int>(m,0));
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res = max(res,dfs(matrix,i,j));
            }
        }
        return res;
    }
};