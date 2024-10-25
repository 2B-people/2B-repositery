#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
 public:
  // leetcode 122
  int maxProfit(vector<int> prices) {
    int min_price = prices[0],max_difference = 0;
    for (auto &&cur_price : prices)
    {
      min_price = min(cur_price,min_price);
      max_difference = max(max_difference,cur_price-min_price);
    }
    return max_difference;
  }


};