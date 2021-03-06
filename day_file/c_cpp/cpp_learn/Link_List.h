#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

#include <stddef.h>

template <typename T>
struct ListNode
{
    T data;
    ListNode<T> *next;
};

template <typename T>
class OneWayList
{
public:
    OneWayList();
    OneWayList(T first_data);

    ~OneWayList();

    size_t GetSize();
    ListNode<T> *GetpHand();

    bool Insert(T in_data);
    bool InsertSort(T in_data);
    ListNode<T> *Find(T find_data);
    bool Delete(T del_data);

    void Destroy();
    void Sort();
    void Print();

private:
    ListNode<T> *phand_;
    size_t size_;
};

#endif //__LINK_LIST_H__