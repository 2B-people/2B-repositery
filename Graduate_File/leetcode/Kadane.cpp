#include <iostream>
#include <vector>

using namespace std;

// 简要说明：（如过当前值比前面的局部最大值+当前值还大，那么就从当前值开始继续计算局部最大值）

class Solution {
 public:
  // 53. Maximum Subarray
  int maxSubArray(vector<int>& nums) {
    int local_max = nums[0], global_max = nums[0];
    nums.erase(nums.begin());
    for (auto&& x : nums) {
      local_max = max(x, local_max + x);
      global_max = max(local_max, global_max);
    }

    return global_max;
  }
  // 918. Maximum Sum Circular Subarray
  int maxSubarraySumCircular(vector<int>& nums) {
    int local_max = nums[0], global_max = nums[0];
    int local_min = nums[0], global_min = nums[0];
    int sum = nums[0];
    nums.erase(nums.begin());
    for (auto&& x : nums) {
      sum += x;
      local_min = min(x, local_min + x);
      global_min = min(local_min, global_min);
      local_max = max(x, local_max + x);
      global_max = max(local_max, global_max);
    }
    if (global_max < 0) return global_max;  // 如果所有数都是负数，返回最大值
    return max(global_max, sum - global_min);
    // 返回“不跨越头尾的最大子数组和”和“跨越头尾的最大子数组和”中的较大者
  }
};