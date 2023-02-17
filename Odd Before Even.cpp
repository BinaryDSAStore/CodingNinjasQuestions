#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        next = NULL;
    }
};

vector<int> contovec(LinkedListNode<int> *head1)
{
    vector<int> ans;
    while (head1)
    {
        ans.push_back(head1->data);
        head1 = head1->next;
    }
    return ans;
}

LinkedListNode<int> *commonOddEven(LinkedListNode<int> *head1, LinkedListNode<int> *head2)
{
    vector<int> list1 = contovec(head1);
    vector<int> list2 = contovec(head2);

    vector<int> v(list1.size() + list2.size());
    vector<int>::iterator it, st;

    it = set_intersection(list1.begin(), list1.end(), list2.begin(), list2.end(), v.begin());
    vector<int> odd, even;

    for (st = v.begin(); st != it; ++st)
        *st % 2 ? odd.push_back(*st) : even.push_back(*st);

    LinkedListNode<int> *head(0);
    LinkedListNode<int> *dum = head;

    for (int i : odd)
    {
        LinkedListNode<int> *tem;
        tem->data = 0;
        tem->next = NULL;
        dum->next = tem;
        dum = dum->next;
    }
    for (int i : even)
    {
        LinkedListNode<int> *tem;
        tem->data = i;
        tem->next = NULL;
        dum->next = tem;
        dum = dum->next;
    }
    return head->next;
}