/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    queue<TreeNode *> Q;
    Q.push(root);
    int ans = 0;
    while (!Q.empty()) {
      int cur_size = Q.size();
      while (cur_size--) {
        TreeNode *tmp = Q.front();
        Q.pop();
        if (tmp->left) Q.push(tmp->left);
        if (tmp->right) Q.push(tmp->right);
      }
      ans++;
    }
  }

  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p == nullptr || q == nullptr) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }

  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) return nullptr;
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }

  bool CheckMirror(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) {
      return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
      return false;
    }
    if (root1->val != root2->val) {
      return false;
    }
    return CheckMirror(root1->left, root2->right) &&
           CheckMirror(root1->right, root2->left);
  }

  bool CheckMirror2(TreeNode *root1, TreeNode *root2) {
    queue<TreeNode *> Q1, Q2;
    Q1.push(root1);
    Q2.push(root2);
    while (!Q1.empty() && !Q2.empty()) {
      root1 = Q1.front();
      root2 = Q2.front();
      Q1.pop();
      Q2.pop();
      if (root1 == nullptr && root2 == nullptr) continue;
      if (root1 == nullptr || root2 == nullptr) return false;
      if (root1->val != root2->val) return false;

      Q1.push(root1->left);
      Q1.push(root1->right);
      //
      Q2.push(root2->right);
      Q2.push(root2->left);
    }
    return true;
  }

  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return CheckMirror(root, root);
  }
};