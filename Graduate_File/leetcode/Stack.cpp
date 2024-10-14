#include <climits>
#include <iostream>
#include <stack>
#include <string>
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

  // !note leetcode 71
  string simplifyPath(string path) {
    std::stack<string> st;
    int n = path.size();
    int i = 0;
    // push stack
    while (true) {
      if (i >= n) break;
      if (path[i] == '/') {
        while (path[i] == '/') i++;
        if (i >= n) break;
        int j = i;
        while (j < n - 1 && path[j + 1] != '/') j++;
        string s = path.substr(i, j - i + 1);
        if (s == ".") {
          i = j + 1;
        } else if (s == "..") {
          if (!st.empty()) st.pop();
          i = j + 1;
        } else {
          st.push(s);
          i = j + 1;
        }
      }
    }

    // output simple path
    if (st.empty()) return "/";
    string res = "";
    while (!st.empty()) {
      // FILO stack
      res = "/" + st.top() + res;
      st.pop();
    }
    return res;
  }

  // !note leetcode 150
  int evalRPN(vector<string>& tokens) {
    std::stack<int> st;
    for (auto&& token : tokens) {
      if (token == "+") {
        int res = 0;
        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();
        res = num2 + num1;
        st.push(res);
      } else if (token == "-") {
        int res = 0;
        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();
        res = num2 - num1;
        st.push(res);
      } else if (token == "/") {
        int res = 0;
        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();
        res = num2 / num1;
        st.push(res);
      } else if (token == "*") {
        int res = 0;
        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();
        res = num2 * num1;
        st.push(res);
      } else {
        st.push(stoi(token));
      }
    }
    int res = st.top();
    st.pop();
    return res;
  }
};

//!note !note leetcode 155
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
 private:
  std::stack<int> st;
  std::stack<int> min_st;

 public:
  MinStack() { min_st.push(INT_MAX); }

  void push(int val) {
    st.push(val);
    min_st.push(min(min_st.top(), val));
  }

  void pop() {
    if (!st.empty()) {
      st.pop();
      min_st.pop();
    }
  }

  int top() { return st.top(); }

  int getMin() { return min_st.top(); }
};