#include <iostream>
#include "Link_List.h"
#include <stddef.h>

using namespace std;

template <typename T>
OneWayList<T>::OneWayList() : size_(0)
{
    phand_ = new ListNode<T>;
    if (phand_ == nullptr)
    {
        cout << "error:Can't create hand" << endl;
        exit(-1);
    }
}

template <typename T>
OneWayList<T>::OneWayList(T first_data) : size_(1)
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
size_t OneWayList<T>::GetSize()
{
    return size_;
}

template <typename T>
ListNode<T> *OneWayList<T>::GetpHand()
{
    return phand_;
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
        size_++;
        return true;
    }
    else
    {
        insert_node->next = phand_->next;
        phand_->next = insert_node;
        size_++;
        return true;
    }
}

template <typename T>
bool OneWayList<T>::InsertSort(const T in_data)
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
        size_++;
        return true;
    }

    ListNode<T> *index_node = phand_;
    while (index_node->next != nullptr)
    {
        if (insert_node->data <= index_node->next->data
             && insert_node->data >= index_node->data)
        {
            ListNode<T> *temp = index_node->next;
            index_node->next = insert_node;
            insert_node->next = temp;
            size_++;
            return true;
        }
        index_node = index_node->next;
    }

    index_node->next = insert_node;
    size_++;
    return true;
}

template <typename T>
ListNode<T> *OneWayList<T>::Find(T find_data)
{
    if (phand_->next == nullptr)
    {
        cout << "warning: list is empty" << endl;
        return nullptr;
    }

    ListNode<T> *index_node = phand_->next;
    while (index_node != nullptr)
    {
        if (abs(find_data - index_node->data) <= 0.01)
        {
            return index_node;
        }
        index_node = index_node->next;
    }
    cout << "warning: Can't not find " << find_data << endl;
    return nullptr;
}

template <typename T>
bool OneWayList<T>::Delete(T del_data)
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
            size_--;
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
            ListNode<T> *temp = index_node->next;
            delete index_node->next;
            index_node->next = temp;
            size_--;
            return true;
        }
        index_node = index_node->next;
    }

    cout << "warning: can't find data what to del " << endl;
    return false;
}

template <typename T>
void OneWayList<T>::Destroy()
{
    
}

template <typename T>
void OneWayList<T>::Sort()
{

}

template <typename T>
void OneWayList<T>::Print()
{
    ListNode<T> *index_node = phand_->next;
    while (index_node != nullptr)
    {
        cout << index_node->data << endl;
        index_node = index_node->next;
    }
    return;
}

int main(int argc, char const *argv[])
{
    OneWayList<double> test_list;

    test_list.InsertSort(81.1);
    test_list.InsertSort(32.1);
    test_list.InsertSort(10.1);
    test_list.InsertSort(10.1);
    test_list.InsertSort(9.1);
    test_list.InsertSort(12.1);

    test_list.Print();

    ListNode<double> *aa = test_list.Find(9.1);
    if (aa != nullptr)
        cout << "test find:" << aa->data << endl;

    return 0;
}
