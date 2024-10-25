#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int NumsDegree(vector<int> nums) {
  unordered_map<int, int> hash;
  int degree = 1;
  for (auto &&x : nums) {
    if (hash.count(x)) {
      hash[x]++;
      degree = max(degree, hash[x]);
    } else {
      hash[x]++;
    }
  }
  return degree;
}

int minNums(vector<int> nums) {
  int n = nums.size();
  if (n < 2) return n;

  int o_degree = NumsDegree(nums);
  int left = 0, right = n - 1;
  int res = 0;
  // left
  while (true) {
    auto first = nums.begin() + left;
    auto end = nums.begin() + right;
    vector<int> sub_nums(first, end);
    int sub_degree = NumsDegree(sub_nums);
    if (sub_degree < o_degree) {
      left--;
      break;
    } else {
      left++;
      res = sub_nums.size();
    }
  }
  // right
  while (true) {
    auto first = nums.begin() + left;
    auto end = nums.begin() + right;
    vector<int> sub_nums(first, end);
    int sub_degree = NumsDegree(sub_nums);
    if (sub_degree < o_degree) {
      right--;
      break;
    } else {
      right++;
      res = sub_nums.size();
    }
  }
  return res;
}

int main(int argc, char const *argv[]) {
  vector<int> nums;
  int temp;
  while (cin >> temp) {
    nums.push_back(temp);
  }

  auto res = minNums(nums);
  cout << res;

  return 0;
}
