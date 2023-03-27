#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

void insert(Node * ( & head), int n, int pos, int val) {
    Node *temp = head;

    if (pos == 0) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }

    while (pos > 1 && temp != NULL) {
        temp = temp->next;
        pos--;
    }

    if (temp == NULL) {
        return;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    return;
}