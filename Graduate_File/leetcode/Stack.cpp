#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> st;
    for (char c : s) {
      if (c == '(' || c == '[' || c == '{')
        st.push(c);
      else {
        if (st.empty()) return false;
        if (c == ')' && st.top() != '(') return false;
        if (c == ']' && st.top() != '[') return false;
        if (c == '}' && st.top() != '{') return false;
        st.pop();
      }
    }
    return st.empty();
  }
  string simplifyPath(string path) {
    std::stack<string> st;
    int n = path.size();
    for (int i = 0; i < n; i++)
    {
      if (path[i] == '/'){
        
      }
    }
    
};