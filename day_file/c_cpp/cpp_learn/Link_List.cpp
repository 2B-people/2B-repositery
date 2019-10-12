#include <iostream>
#include "one_way_test.h"

using namespace std;

template <typename T>
OneWayList<T>::OneWayList()
{
    phand_ = new ListNode<T>;
    if (phand_ == nullptr)
    {
        cout << "error:Can't create hand" << endl;
        exit(-1);
    }
}

template <typename T>
OneWayList<T>::OneWayList(T first_data)
{
    phand_ = new ListNode<T>;
    
    if (phand_ == nullptr)
    {
        cout << "error:Can't create hand" << endl;
        exit(-1);
    }

    ListNode<T> *insert_node = new ListNode<T>;
    insert_node->data = first_data;
    insert_node->next = nullptr;
    phand_->next = insert_node;
}

template <typename T>
OneWayList<T>::~OneWayList()
{
    Destroy();
}

template <typename T>
bool OneWayList<T>::Insert(T in_data)
{
    ListNode<T> *insert_node = new ListNode<T>;
    if (insert_node == nullptr)
    {
        cout << "error:Can't insert node" << endl;
        return false;
    }

    insert_node->data = in_data;
    insert_node->next = nullptr;

    if (phand_->next == nullptr)
    {
        phand_->next = insert_node;
        return true;
    }
    else
    {
        insert_node->next = phand_->next;
        phand_->next = insert_node;
        return true;
    }
}

template <typename T>
bool OneWayList<T>::InsertSort(T in_data)
{
    
}

template <typename T>
ListNode<T> *OneWayList<T>::Find(T find_data)
{
    if (phand_->next == nullptr)
    {
        cout << "warning: list is empty" << endl;
        return nullptr;
    }

    ListNode<T> *index_node = phand_;
    while (index_node->next != nullptr)
    {
        if (index_node->data == find_data)
            return index_node;
    }
    cout << "warning: Can't not find " << find_data << endl;
    return nullptr;
}

template <typename T>
bool Delete(T del_data)
{
    if (phand_->next == nullptr)
    {
        cout << "warning: list is empty" << endl;
        return false;
    }
    if (phand_->next->next == nullptr)
    {
        if (phand_->next->data == del_data)
        {
            delete phand_->next;
            phand_->next = nullptr;
            return true;
        }
        else
        {
            cout << "warning: can't find data what to del" << endl;
            return false;
        }
    }
    ListNode<T> *index_node = phand_;
    while (index_node->next->next != nullptr)
    {
        if (index_node->next->data == del_data)
        {
            ListNode<T> *temp = index_node->next->next;
            delete index_node->next;
            index_node->next = temp;
            return true;
        }
    }

    cout << "warning: can't find data what to del " << find_data << endl;
    return false;
}
