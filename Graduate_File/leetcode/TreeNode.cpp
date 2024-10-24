/**
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left_inorder;
      TreeNode *right_inorder;
      TreeNode() : val(0), left_inorder(nullptr), right_inorder(nullptr) {}
      TreeNode(int x) : val(x), left_inorder(nullptr), right_inorder(nullptr)
  {} TreeNode(int x, TreeNode *left_inorder, TreeNode *right_inorder) : val(x),
  left_inorder(left_inorder), right_inorder(right_inorder) {}
  };
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left_inorder;
  TreeNode *right_inorder;
  TreeNode() : val(0), left_inorder(nullptr), right_inorder(nullptr) {}
  TreeNode(int x) : val(x), left_inorder(nullptr), right_inorder(nullptr) {}
  TreeNode(int x, TreeNode *left_inorder, TreeNode *right_inorder)
      : val(x), left_inorder(left_inorder), right_inorder(right_inorder) {}
};

class TreeNodeSolution {
 public:
  int maxDepth(TreeNode *root_preorder) {
    if (root_preorder == nullptr) return 0;
    queue<TreeNode *> Q;
    Q.push(root_preorder);
    int ans = 0;
    while (!Q.empty()) {
      int cur_size = Q.size();
      while (cur_size--) {
        TreeNode *tmp = Q.front();
        Q.pop();
        if (tmp->left_inorder) Q.push(tmp->left_inorder);
        if (tmp->right_inorder) Q.push(tmp->right_inorder);
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
    return isSameTree(p->left_inorder, q->left_inorder) &&
           isSameTree(p->right_inorder, q->right_inorder);
  }

  TreeNode *invertTree(TreeNode *root_preorder) {
    if (root_preorder == nullptr) return nullptr;
    TreeNode *left_inorder = invertTree(root_preorder->left_inorder);
    TreeNode *right_inorder = invertTree(root_preorder->right_inorder);
    root_preorder->left_inorder = right_inorder;
    root_preorder->right_inorder = left_inorder;
    return root_preorder;
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
    return CheckMirror(root1->left_inorder, root2->right_inorder) &&
           CheckMirror(root1->right_inorder, root2->left_inorder);
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

      Q1.push(root1->left_inorder);
      Q1.push(root1->right_inorder);
      //
      Q2.push(root2->right_inorder);
      Q2.push(root2->left_inorder);
    }
    return true;
  }

  bool isSymmetric(TreeNode *root_preorder) {
    if (root_preorder == nullptr) {
      return true;
    }
    return CheckMirror(root_preorder, root_preorder);
  }
  // !note leetcode 112
  bool hasPathSum(TreeNode *root_preorder, int targetSum) {
    if (root_preorder == nullptr) return false;
    if (root_preorder->left_inorder == nullptr &&
        root_preorder->right_inorder == nullptr)
      return targetSum == root_preorder->val;
    return hasPathSum(root_preorder->left_inorder,
                      targetSum - root_preorder->val) ||
           hasPathSum(root_preorder->right_inorder,
                      targetSum - root_preorder->val);
  }
  // !note leetcode 222
  int countNodes(TreeNode *root_preorder) {
    if (root_preorder == nullptr) return 0;
    return 1 + countNodes(root_preorder->left_inorder) +
           countNodes(root_preorder->right_inorder);
  }
  //! note leetcode 108
  TreeNode *helper(vector<int> &nums, int left_inorder, int right_inorder) {
    if (left_inorder > right_inorder) {
      return nullptr;
    }
    int mid = (right_inorder + left_inorder) / 2;
    TreeNode *cur = new TreeNode(nums[mid]);
    cur->left_inorder = helper(nums, left_inorder, mid - 1);
    cur->right_inorder = helper(nums, mid + 1, right_inorder);
    return cur;
  }
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return helper(nums, 0, nums.size() - 1);
  }

  // !note leetcode 105

  unordered_map<int, int> index_dir_;
  vector<int> preorder_;

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      index_dir_[inorder[i]] = i;
    }
    preorder_ = preorder;
    return buildTreeHelper(0, 0, inorder.size() - 1);
  }
  TreeNode *buildTreeHelper(int root_preorder, int left_inorder,
                            int right_inorder) {
    if (left_inorder > right_inorder) {
      return nullptr;
    }
    auto val = preorder_[root_preorder];
    TreeNode *new_root = new TreeNode(val);

    auto index_inorder = index_dir_[val];
    // build left_inorder tree
    int next_left_root = root_preorder + 1;
    new_root->left_inorder =
        buildTreeHelper(next_left_root, left_inorder, index_inorder - 1);
    // build right_inorder tree
    // > **TIPS：* 含义为 `左子树长度 + 根节点索引 + 1`
    int left_tree_size = index_inorder - left_inorder;
    int next_right_root = left_tree_size + root_preorder + 1;
    new_root->right_inorder =
        buildTreeHelper(next_right_root, index_inorder + 1, right_inorder);
    // return root to connect
    return new_root;
  }

  // !note leetcode 106
  unordered_map<int, int> index_dir_;
  vector<int> postorder_;

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    for (int i = 0; i < inorder.size(); i++) {
      index_dir_[inorder[i]] = i;
    }
    postorder_ = postorder;
    int root_index_post = postorder_.size() - 1;

    return buildTreeHelper(root_index_post, 0, inorder.size() - 1);
  }

  TreeNode *buildTreeHelper(int root_postorder, int left_inorder,
                            int right_inorder) {
    if (left_inorder > right_inorder) {
      return nullptr;
    }
    auto val = postorder_[root_postorder];
    TreeNode *new_root = new TreeNode(val);
    auto root_inorder = index_dir_[val];

    // build right tree
    new_root->right_inorder =
        buildTreeHelper(root_postorder - 1, root_inorder + 1, right_inorder);
    // build left tree
    int right_tree_size = right_inorder - root_inorder;
    int new_left_root = root_postorder - right_tree_size - 1;
    new_root->left_inorder =
        buildTreeHelper(new_left_root, left_inorder, root_inorder - 1);
    return new_root;
  }
  // !note leetcode 114
  vector<TreeNode *> vc_;
  void dg(TreeNode *root) {
    if (root == nullptr) return;

    vc_.push_back(root);

    dg(root->left_inorder);
    dg(root->right_inorder);
  }
  void flatten(TreeNode *root) {
    //
    dg(root);

    TreeNode *rt = root;
    for (int i = 1; i < vc_.size(); i++) {
      rt->right_inorder = vc_[i];
      rt->left_inorder = nullptr;
      rt = vc_[i];
    }
    return;
  }
  // !note leetcode 124
  int max_sum_;

  int maxHelper(TreeNode *root) {
    if (root == nullptr) return 0;

    int left_max_help = max(maxHelper(root->left), 0);
    int right_max_help = max(maxHelper(root->right), 0);

    int cur_path_max = root->val + left_max_help + right_max_help;

    max_sum_ = max(cur_path_max, max_sum_);

    return root->val + max(left_max_help, right_max_help);
  }

  int maxPathSum(TreeNode *root) {
    max_sum_ = INT_MIN;
    maxHelper(root);
    return max_sum_;
  }
};

// !note leetcode 117
// Definition for a Node.
class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

//  * Definition for a binary tree node.
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
  Node *connect(Node *root) {
    if (root) {
      return nullptr;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      Node *last = nullptr;
      for (int i = 0; i < n; i++) {
        auto f = q.front();
        q.pop();
        if (f->left) q.push(f->left);
        if (f->right) q.push(f->right);
        if (i != 0) last->next = f;
        last = f;
      }
    }
    return root;
  }
  // !note leetcode 199
  vector<int> rightSideView(TreeNode *root) {
    // 广度优先搜索，从右边开始进行记录
    vector<int> result;
    if (!root) return result;  // 如果根节点为空，返回空的结果
    queue<TreeNode *> q;       // 创建一个队列来进行层次遍历
    q.push(root);              // 将根节点放入队列
    while (!q.empty()) {
      int curr_size = q.size();
      TreeNode *f_node = q.front();
      result.push_back(f_node->val);
      for (int i = 0; i < curr_size; i++) {
        TreeNode *node = q.front();
        q.pop();
        if (node->right) {
          q.push(node->right);
        }
        if (node->left) {
          q.push(node->left);
        }
      }
    }
    return result;
  }

  // !leecode 103
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
      int curr_level_size = q.size();
      vector<int> temp;
      for (int i = 0; i < curr_level_size; i++) {
        auto node = q.front();
        q.pop();
        temp.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      if (level % 2 == 0) {
        vector<int> r_temp;
        for (int i = temp.size() - 1; i > 0; i--) {
          r_temp.push_back(temp[i]);
        }
      } else
        res.push_back(temp);
      level++;
    }
    return res;
  }

  // !leetcode 530

  int min_diff = INT_MAX;
  void dfs(TreeNode *root, int &pre) {
    if (root == nullptr || pre == -1) return;
    dfs(root->left, pre);
    // 中序遍历
    // leetcode 530
    // if (pre == -1)
    //   pre = root->val;
    // else {
    //   min_diff = min(min_diff, root->val - pre);
    //   pre = root->val;
    // }
    // leetcode 230
    if (pre == 0) return;
    pre--;
    if (pre == 0) {
      k_min = root->val;
      pre = -1;
      return;
    }
    dfs(root->right, pre);
    return;
  }
  int getMinimumDifference(TreeNode *root) {
    dfs(root, -1);
    return min_diff;
  }
  // !leetcode 230
  int k_min = 0;
  int kthSmallest(TreeNode *root, int k) {
    dfs(root, k);
    return k_min;
  }
  // !leetcode 98
  bool isBSTToDfs(TreeNode *root, long long lower, long long upper){
    if (root == nullptr) return true;
    if (root->val <= lower || root->val >= upper) return false;
    return isBSTToDfs(root->left, lower, root->val) && isBSTToDfs(root->right, root->val, upper);
  }


  bool isValidBST(TreeNode *root) {
    if (root == nullptr) return true;
    return isBSTToDfs(root, LONG_MIN, LONG_MAX);
  }
};