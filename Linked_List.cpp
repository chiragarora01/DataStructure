//
// Created by panda on 27-03-2021.
//

#include <iostream>

using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head);

void printlistrecurrsive(Node *head);

int search(Node *head, int x);

int searchrecurrsive(Node *head, int x);

Node *insertatbegning(Node *head, int x);

Node *insertatend(Node *head, int x);
Node *deletebegning(Node *head);
Node *deletelast(Node *head);
Node *InsertPos(Node *head,int x,int pos);
void printMiddle(Node *head);
Node *sortedinsert(Node *head,int x);
void printNth(Node *head,int N);

int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printlistrecurrsive(head);
    cout << endl;
    //  cout << searchrecurrsive(head, 30);
    head = insertatbegning(head, 5);
    cout << endl;
    printlistrecurrsive(head);
    head = insertatend(head, 80);
    cout << endl;
    printlistrecurrsive(head);
    head= deletebegning(head);
    cout<<endl;
    head= deletelast(head);
    printlistrecurrsive(head);
    head = InsertPos(head,25,3);
    cout<<endl;
    printlistrecurrsive(head);
    cout<<endl;
    printMiddle(head);
    cout<<endl;
    head=sortedinsert(head,27);
    printlistrecurrsive(head);
    cout<<endl;
}

void printlist(Node *head) {
    Node *curr = head;
    cout<<endl;
    while (curr != NULL) {
        cout << curr->data << "    ";
        curr = curr->next;
    }
    cout<<endl;
}

void printlistrecurrsive(Node *head) {
    if (head == NULL)
        return;

    cout << head->data << "   ";
    printlistrecurrsive(head->next);
}

int search(Node *head, int x) {
    if (head == NULL)
        return -1;
    int pos = 1;
    Node *curr = head;
    while (curr != NULL) {
        if (curr->data == x)
            return pos;
        curr = curr->next;
        pos++;
    }
}

int searchrecurrsive(Node *head, int x) {
    if (head == NULL)
        return -1;
    if (head->data == x)
        return 1;
    else {
        int res = searchrecurrsive(head->next, x);
        if (res == -1) return -1;
        return res + 1;
    }
}


Node *insertatbegning(Node *head, int x) {
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

Node *insertatend(Node *head, int x) {
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;
    Node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

Node *deletebegning(Node *head) {
    if (head == NULL)
        return NULL;
    else
        {
        Node *temp =head;
        head=head->next;
        delete temp;
        return head;
    }
}

Node *deletelast(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *curr = head;
    while(curr->next->next !=NULL)
    {
        curr=curr->next;
    }
    delete curr->next;
    curr->next=NULL;
    return head;
}

Node *InsertPos(Node *head,int x,int pos)
{
    Node *temp=new Node(x);
    Node *curr = head;
    int i=1;
    if (pos==1)
    {
        temp->next=head;
        return temp;
    }
    while( i<pos-1 && curr !=NULL)
    {
        curr=curr->next;
        i++;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

Node *sortedinsert(Node *head,int x)
{
    Node *temp=new Node(x);
    if (head == NULL)
        return NULL;
    Node *curr = head;
    if (x<head->data)
    {
        temp->next=head;
        return temp;
    }
    while (curr->next!=NULL && curr->next->data<x)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

void printMiddle(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    if (head == NULL)
        return ;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout << slow->data;
}

void printNth(Node *head,int N)
{
    if (head==NULL)
        return;
    Node *first=head;
    for(int i=0;i<N;i++)
    {
        if(first==NULL)
            return;
        first=first->next;
    }
    Node *second=head;
    while (first!=NULL)
    {
        second=second->next;
        first=first->next;
    }
    cout<< second->data;
}
