#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// Approach 2: Using Hashing

bool detectCycle2(Node *head)
{
    unordered_set<Node *> s;
    while (head != NULL)
    {
        if (s.find(head) != s.end())
            return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}