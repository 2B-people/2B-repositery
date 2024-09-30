#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    if (n < 2 && nums[0] == target) return 0;
    int left_index = 0, right_index = n - 1;
    while (left_index <= right_index)
    {
        int mid = (left_index + right_index) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left_index = mid + 1;
        else right_index = mid - 1;
    }
    return left_index;
    
  }
};