#include <algorithm>
#include <iostream>
#include <unordered_map>
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
};

int main(int argc, char const *argv[]) {
  Solution s;
  string s1 = "dog cat cat dog";
  string pattern = "abba";
  vector<string> res;
  cout << s.wordPattern(pattern, s1) << endl;

  return 0;
}
