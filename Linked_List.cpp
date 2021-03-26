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

int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printlistrecurrsive(head);
    cout<<endl;
  //  cout << searchrecurrsive(head, 30);
    head=insertatbegning(head,5);
    cout <<endl;
    printlistrecurrsive(head);
    head=insertatend(head,80);
    cout <<endl;
    printlistrecurrsive(head);
}

void printlist(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << "    ";
        curr = curr->next;
    }
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


Node *insertatbegning(Node *head, int x)
{
    Node *temp=new Node(x);
    temp->next=head;
    return temp;
}

Node *insertatend(Node *head, int x)
{
    Node *temp=new Node(x);
    if (head==NULL)
        return temp;
    Node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

Node *deletebegning