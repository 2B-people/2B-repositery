#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int len_;
  vector<int> temp_;
  vector<vector<int>> res_;

 public:
  // leetcode 77 : 组合
  void dfs(int cur, int n, int k) {
    // 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的
    // temp
    if (temp_.size() + (n - cur + 1) < k) return;
    if (temp_.size() == k) {
      res_.push_back(temp_);
      return;
    }
    if (cur == n + 1) return;
    // 选
    temp_.push_back(cur);
    dfs(cur + 1, n, k);
    // 不选
    temp_.pop_back();
    dfs(cur + 1, n, k);
  }
  vector<vector<int>> combine(int n, int k) {
    dfs(1, n, k);
    return res_;
  }
  // leetcode 46 : 全排列
  void dfs(int cur, vector<int>& nums) {
    if (cur == len_) {
      res_.push_back(temp_);
      return;
    }
    for (int i = cur; i < len_; i++) {
      swap(nums[cur], nums[i]);
      dfs(cur + 1, nums);
      swap(nums[cur], nums[i]);
    }
  }
  vector<vector<int>> permute(vector<int>& nums) { len_ = nums.size(); 
    dfs(0, nums);
    return res_;
  }
};