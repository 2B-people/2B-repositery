#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // leetcode 228
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int left = 0, right = 0;
        int n = nums.size();
        if (n == 0) {
            // res.push_back("");
            return res;
        }
        if (n == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }

        while (right < n) {
            left = right;
            while (right < n - 1) {
                if (nums[right + 1]  == 1+ nums[right])
                // 有稿子，nums[i]-nums[i-1] 这个地方， 那个2^31-(-2^31) 是谁tm搞出来的测试用例....
                    right++;
                else
                    break;
            }
            if (right - left == 0) {
                res.push_back(to_string(nums[left]));
            } else {
                res.push_back(to_string(nums[left]) + "->" +
                              to_string(nums[right]));
            }
            right++;
        }
        return res;
    }
};