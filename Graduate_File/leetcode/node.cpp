#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
// Definition for a Node
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  // leetcode 138
  unordered_map<Node*, Node*> cache_nodes;
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;

    if (!cache_nodes.count(head)) {
      Node* new_node = new Node(head->val);
      cache_nodes[head] = new_node;
      new_node->next = copyRandomList(head->next);
      new_node->random = copyRandomList(head->random);
    }
    return cache_nodes[head];
  }
  // leetcode 92
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    
  }
};