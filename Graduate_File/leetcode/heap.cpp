#include <algorithm>
#include <iostream>
#include <priority_queue.hpp>
#include <vector>

using namespace std;

class Solution {
 public:
  //! leetcode 215:堆排序
  void MaxHeapify(vector<int>& nums, int start, int end) {
    int l = 2 * start + 1;
    int r = 2 * start + 2;
    int largest = start;
    if (l < end && nums[l] > nums[largest]) largest = l;
    if (r < end && nums[r] > nums[largest]) largest = r;
    if (largest != start) {
      swap(nums[start], nums[largest]);
      MaxHeapify(nums, largest, end);
    }
  }
  void buildHeap(vector<int>& nums) {
    int len = nums.size();
    for (int i = len / 2 - 1; i >= 0; i--) {
      MaxHeapify(nums, i, len);
    }
  }
  int findKthLargest(vector<int>& nums, int k) {
    // sort(nums.begin(),nums.end());
    // return nums[nums.size()-k];
    // heap sort
    buildHeap(nums);
    int heap_size = nums.size();

    for (int i = nums.size() - 1; i > nums.size() - k; i--) {
      swap(nums[0], nums[i]);
      heap_size--;
      MaxHeapify(nums, 0, heap_size);
    }
    return nums[0];
  }

  //! leetcode 373:最接近的K个数
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    auto cmp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
      auto cmp =
          nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
      return cmp;
    };
    int nums1_size = nums1.size();
    int nums2_size = nums2.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
        min_heap(cmp);

    for (int i = 0; i < min(k, nums1_size); i++) {
      min_heap.push({i, 0});
    }

    vector<vector<int>> res;
    for (int i = k; i > 0 && !min_heap.empty(); i--) {
      auto p = min_heap.top();
      min_heap.pop();
      res.push_back({nums1[p.first], nums2[p.second]});
      if (p.second + 1 < nums2_size) {
        min_heap.push({p.first, p.second + 1});
      }
    }
    return res;
  }
};