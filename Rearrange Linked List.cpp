#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
            delete next;
    }
};

Node<int> *reverseList(Node<int> *head)
{
    Node<int> *prev = nullptr, *curr = head, *next = nullptr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node<int> *rearrangeList(Node<int> *head)
{
    if (!head || !head->next)
        return head;

    Node<int> *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node<int> *head2 = slow->next;
    slow->next = nullptr;
    head2 = reverseList(head2);

    Node<int> *dummy = new Node<int>(0), *curr = dummy;
    while (head || head2)
    {
        if (head)
        {
            curr->next = head;
            head = head->next;
            curr = curr->next;
        }
        if (head2)
        {
            curr->next = head2;
            head2 = head2->next;
            curr = curr->next;
        }
    }
    return dummy->next;
}
