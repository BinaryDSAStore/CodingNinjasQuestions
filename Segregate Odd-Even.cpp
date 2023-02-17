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

Node *segregateOddEven(Node *head)
{
    Node *oddHead = NULL;
    Node *oddTail = NULL;
    Node *evenHead = NULL;
    Node *evenTail = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = temp;
                evenTail = temp;
            }
            else
            {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = temp;
                oddTail = temp;
            }
            else
            {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }
        temp = temp->next;
    }
    if (oddHead == NULL)
        return evenHead;
    oddTail->next = evenHead;
    if (evenHead != NULL)
        evenTail->next = NULL;
    return oddHead;
}