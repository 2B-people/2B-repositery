#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int up = 0, down = matrix.size() - 1, left = 0,
        right = matrix[0].size() - 1;
    int state = 0;
    int step = 0;
    while (up < down && left < right) {
      switch (state) {
        // l->r
        case 0:
          res.push_back(matrix[up][step]);
          if (step == right) {
            state = 1;
            up++;
            step = up;
          } else {
            step++;
          }
          break;
        // u->d
        case 1:
          res.push_back(matrix[step][right]);
          if (step == down) {
            state = 2;
            right--;
            step = right;
          } else {
            step++;
          }
          break;
        // r->l
        case 2:
          res.push_back(matrix[down][step]);
          if (step == left) {
            state = 3;
            down--;
            step = down;
          } else {
            step--;
          }
          break;
        // d->u
        case 3:
          res.push_back(matrix[step][left]);
          if (step == up) {
            state = 0;
            left++;
            step = left;
          } else {
            step--;
          }
          break;
        default:
          break;
      }
      if (up > down || left > right) break;
    }

    return res;
  }
};