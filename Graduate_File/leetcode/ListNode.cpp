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
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
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
  // leetcode 25
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
  // leetcode 19
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
