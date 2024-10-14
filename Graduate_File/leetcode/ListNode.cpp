/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <climits>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
struct DListNode {
  int val;
  int key;
  DListNode *prev, *next;
  DListNode() : val(0), key(0), prev(nullptr), next(nullptr) {}
  DListNode(int x) : val(x), key(0), prev(nullptr), next(nullptr) {}
  DListNode(int x, int key) : val(x), key(key), prev(nullptr), next(nullptr) {}
  DListNode(int x, DListNode* next)
      : val(x), key(0), prev(nullptr), next(next) {}
  DListNode(int x, DListNode* next, DListNode* prev)
      : val(x), key(0), prev(prev), next(next) {}
  DListNode(int x, int key, DListNode* next, DListNode* prev)
      : val(x), key(key), prev(prev), next(next) {}
};

class Solution {
 public:
  bool deletelist(ListNode* head) {
    if (!head) return false;
    deletelist(head->next);
    delete head;
    return true;
  }
  void printList(ListNode* head) {
    cout << "list is: ";
    while (head) {
      cout << head->val << ";";
      head = head->next;
    }
    cout << endl;
    return;
  }
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* last = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
  }
  // !note leetcode 25
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* hair_ptr = new ListNode(-1, head);
    ListNode* cur_ptr = hair_ptr;
    while (cur_ptr->next) {
      ListNode* end_ptr = cur_ptr;
      // 往后推k个点
      for (int i = 0; i < k; i++) {
        end_ptr = end_ptr->next;
        // end k > len
        if (end_ptr == nullptr) {
          ListNode* new_head = hair_ptr->next;
          delete hair_ptr;
          return new_head;
        }
      }
      // 断链
      ListNode* k_head = cur_ptr->next;
      ListNode* k_end = end_ptr->next;
      cur_ptr->next = nullptr;
      end_ptr->next = nullptr;
      // 反转
      ListNode* new_head = reverseList(k_head);
      // 接回
      cur_ptr->next = new_head;
      k_head->next = k_end;
      // update cur_ptr in next k head
      cur_ptr = k_head;
    }
    // return head && delete hair_ptr
    ListNode* new_head = hair_ptr->next;
    delete hair_ptr;
    return new_head;
  }
  // !note leetcode 19
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> vec;
    if (!head) return head;
    if (!head->next) {
      delete head;
      return nullptr;
    }
    ListNode* hair_ptr = new ListNode(-1, head);
    vec.push_back(hair_ptr);
    int len = 0;
    while (vec.back()->next) {
      len++;
      vec.push_back(vec.back()->next);
    }
    if (len == n) {
      ListNode* new_head = vec[1]->next;
      delete vec[1];
      delete vec[0];
      return new_head;
    } else {
      int index = len - n + 1;
      vec[index - 1]->next = vec[index]->next;
      delete vec[index];
      delete vec[0];
      return head;
    }
  }
  // 20241013:!note leetcode 82 bug
  // 20241014:update fix
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* hair_ptr = new ListNode(-1000, head);
    ListNode *cur = head, *pre = hair_ptr;
    while (cur && cur->next) {
      if (cur->val == cur->next->val) {
        int x = cur->val;
        while (cur && cur->val == x) {
          auto temp = cur->next;
          delete cur;
          cur = temp;
        }
        pre->next = cur;
      } else {
        pre = cur;
        cur = cur->next;
      }
    }
    auto new_head = hair_ptr->next;
    delete hair_ptr;
    return new_head;
  }
  // !note leetcode 61
  ListNode* rotateRight(ListNode* head, int k) {
    if (k == 0 || !head || !head->next) return head;

    vector<ListNode*> ptr_list;
    ListNode* cur = head;

    while (cur) {
      ptr_list.push_back(cur);
      cur = cur->next;
    }
    // if k > n->k%n(n step list is original)
    int oper_k = k % ptr_list.size();
    if (oper_k == 0)
      return head;
    else {
      // new end
      ptr_list[ptr_list.size() - oper_k - 1]->next = nullptr;
      // link list
      ptr_list[ptr_list.size() - 1]->next = ptr_list[0];
      // new head
      return ptr_list[ptr_list.size() - oper_k - 1 + 1];
    }
  }
  // !note leetcode 86
  ListNode* partition(ListNode* head, int x) {
    ListNode* hair = new ListNode(-INT_MAX, head);
    ListNode *pre = hair, *cur = head;
    bool find_flag = false;
    ListNode *in_pre, *in_next;
    while (cur) {
      if (!find_flag)  // no find
      {
        if (cur->val >= x) {
          find_flag = true;
          in_pre = pre;
          in_next = cur;
        }
      } else  // find in_pre,in_next
      {
        if (cur->val < x) {
          pre->next = cur->next;
          cur->next = in_next;
          in_pre->next = cur;
          in_pre = cur;
        }
      }
      pre = cur;
      cur = cur->next;
    }
    auto new_head = hair->next;
    delete hair;
    return new_head;
  }
};

// !note leetcode 146 LRU
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
 private:
  int capacity_, size_;
  unordered_map<int, DListNode*> cache;
  DListNode *head_, *tail_;

  inline void addToHead(DListNode* node) {
    node->next = head_->next;
    node->prev = head_;
    head_->next->prev = node;
    head_->next = node;
  }
  inline void removeDNode(DListNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  inline void moveToHead(DListNode* node) {
    removeDNode(node);
    addToHead(node);
  }
  inline void removeTail(void) {
    DListNode* node = tail_->prev;
    removeDNode(node);
    cache.erase(node->key);
    delete node;
  }

 public:
  LRUCache(int capacity) : capacity_(capacity) {
    size_ = 0;
    head_ = new DListNode(-1);
    tail_ = new DListNode(-1);
    // link Dlist
    head_->next = tail_;
    tail_->prev = head_;
  }

  int get(int key) {
    if (cache.count(key)) {
      moveToHead(cache[key]);
      return cache[key]->val;
    } else
      return -1;
  }

  void put(int key, int value) {
    if (cache.count(key)) {
      cache[key]->val = value;
      moveToHead(cache[key]);
    } else {
      DListNode* new_node = new DListNode(value, key);
      cache[key] = new_node;
      addToHead(new_node);
      size_++;
      if (size_ > capacity_) {
        removeTail();
        size_--;
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  ListNode* head = new ListNode(1, nullptr);
  ListNode* curr = head;
  for (int i = 0; i < 4; i++) {
    curr->next = new ListNode(i + 2);
    curr = curr->next;
  }
  Solution s;
  // reverseList
  cout << "reverseList" << endl;
  head = s.reverseList(head);
  s.printList(head);
  // reverseKGroup
  cout << "reverseKGroup" << endl;
  curr = s.reverseKGroup(head, 2);
  s.printList(curr);
  // delete
  s.deletelist(head);

  return 0;
}
