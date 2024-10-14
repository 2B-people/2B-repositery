// !note leetcode 1702

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string maximumBinaryString(string binary) {
    int n = binary.size();
    int j = 0;
    if (binary.find("0") == string::npos) return binary;

    for (int i = 0; i < n; i++) {
      if (binary[i] == '0') {
        while (j <= i || (binary[j] == '1' && j < n)) {
          j++;
        }
        if (j < n) {
          binary[i] = '1';
          binary[i + 1] = '0';
          binary[j] = '1';
        }
      }
    }
    return binary;
  }
};