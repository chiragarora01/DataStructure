//
// Created by panda on 28-03-2021.
//

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};

Node *insertbegin(Node *head,int x);

int main()
{

}

Node *insertbegin(Node *head,int x)
{
    Node *temp= new Node(x);
    if (head==NULL)
        return temp;
    temp->next=head;
    head->prev=temp;
    return temp;
}

Node *insertatend(Node *head,int x)
{
    Node *temp= new Node(x);
    if (head==NULL)
        return temp;
    Node *curr=head;
    while (curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    temp->prev=curr;
    return temp;
}
