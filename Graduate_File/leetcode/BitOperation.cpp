#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  // 67
  string addBinary(string a, string b) {
    if (a.size() < b.size()) return addBinary(b, a);

    int m = a.size(), n = b.size();
    int carry = 0;
    for (int i = 0; i < m; i++) {
      if (n - 1 - i < 0) {
        if (carry == 0) break;
      } else {
        carry += b[n - 1 - i] - '0';
      }
      carry += a[m - 1 - i] - '0';
      a[m - 1 - i] = '0' + (carry % 2);
      carry >>= 1;
    }
    return carry ? '1' + a : a;
  }
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
      uint32_t temp = n & (32 - 1 - i);
      res |= (temp << i);
    }
    return res;
  }

  int hammingWeight(int n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
      if (n & (1 << i)) count++;
    }
    return count;
  }
  int hammingWeight2(int n) {
    int count = 0;
    while (n)
    {
      n & n-1;
      count++;
    }
    
    return count;
  }
};

int main(int argc, char const *argv[]) {
  string a = "1010";
  string b = "1011";
  int n = 231414;
  Solution s;
  cout << s.addBinary(a, b) << endl;
  cout << s.reverseBits(n) << endl;
  return 0;
}
