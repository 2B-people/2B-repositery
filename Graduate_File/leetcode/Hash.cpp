#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size()) return false;

    int mp[26];
    for (char c : magazine) {
      mp[c - 'a']++;
    }

    for (char c : ransomNote) {
      if (--mp[c - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }

  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, char> s2t;
    unordered_map<char, char> t2s;

    for (int i = 0; i < s.size(); i++) {
      if (s2t.count(s[i]) && s2t[s[i]] != t[i] ||
          t2s.count(t[i]) && t2s[t[i]] != s[i]) {
        return false;
      }
      s2t[s[i]] = t[i];
      t2s[t[i]] = s[i];
    }

    return true;
  }
  void MySplit(string s, vector<int> &res, char temp) {
    int start = 0, end = 0;
    int index = 0;
    unordered_map<string, int> hash_map;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == temp) {
        end = i;
        string sub = s.substr(start, end - start);
        if (hash_map.find(sub) == hash_map.end()) {
          res.push_back(index);
          hash_map[sub] = index;
          index++;
        } else {
          res.push_back(hash_map[sub]);
        }
        start = i + 1;
      }
      if (i == s.size() - 1) {
        end = i + 1;
        string sub = s.substr(start, end - start);
        if (hash_map.find(sub) == hash_map.end()) {
          res.push_back(index);
          hash_map[sub] = index;
          index++;
        } else {
          res.push_back(hash_map[sub]);
        }
      }
    }
    return;
  }
  bool wordPattern(string pattern, string s) {
    vector<int> words;
    MySplit(s, words, ' ');
    if (words.size() != pattern.size()) return false;
    unordered_map<char, int> p2w;
    unordered_map<int, char> w2p;
    for (int i = 0; i < pattern.size(); i++) {
      if (p2w.count(pattern[i]) && p2w[pattern[i]] != words[i] ||
          w2p.count(words[i]) && w2p[words[i]] != pattern[i]) {
        cout << p2w[pattern[i]] << " " << words[i] << endl;
        cout << w2p[words[i]] << " " << pattern[i] << endl;
        return false;
      }
      p2w[pattern[i]] = words[i];
      w2p[words[i]] = pattern[i];
    }
    return true;
  }

  // !note leetcode 202.isHappy
  vector<int> detachNum(int n) {
    vector<int> res;
    while (n / 10 != 0) {
      res.push_back(n % 10);
      n = n / 10;
    }
    res.push_back(n);
    return res;
  }
  bool isHappy(int n) {
    int sum = n;
    unordered_map<int, int> hash_map;
    while (sum != 1) {
      vector<int> res = detachNum(sum);
      sum = 0;
      for (int i = 0; i < res.size(); i++) {
        sum += res[i] * res[i];
      }
      if (hash_map.count(sum)) {
        return false;
      } else {
        hash_map[sum]++;
      }
    }
    return true;
  }
  // !note leetcode 219 重复元素2
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> hash_map;
    for (int i = 0; i < nums.size(); i++) {
      if (hash_map.count(nums[i]) && i - hash_map[nums[i]] <= k) {
        return true;
      }
      hash_map[nums[i]] = i;
    }
    return false;
  }
  // !note leetcode 242
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, int> s2t;
    for (char &c : s) {
      s2t[c]++;
    }
    for (int i = 0; i < t.size(); i++) {
      s2t[t[i]]--;
      if (s2t[t[i]] < 0) return false;
    }
    return true;
  }
  // !note leetcode 49
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> m;
    for (auto &str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      m[key].push_back(str);
    }
    vector<vector<string>> res;
    for (auto &item : m) {
      res.push_back(item.second);
    }
    return res;
  }
  //!note leetcode 58
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> s;
    int max_count = 0;
    for (auto &num : nums) {
      s.insert(num);
    }
    for (int i = 0; i < nums.size(); i++) {
      if (!s.count(nums[i] - 1)) {
        int count = 1;
        int cur_num = nums[i];
        while (s.count(cur_num + 1)) {
          cur_num++;
          count++;
        }
        max_count = max(max_count, count);
      }
    }
    return max_count;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string s1 = "dog cat cat dog";
  string pattern = "abba";
  vector<string> res;
  int n = 2;
  cout << s.wordPattern(pattern, s1) << endl;
  cout << s.isHappy(n) << endl;

  return 0;
}
