//
// Created by panda on 28-03-2021.
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

Node *deletebegin(Node *head);

Node *insertAtbegin_naive(Node *head,int x,int data);

Node *insertAtbegin_good(Node *head,int x,int data);

int main()
{
    Node *curr;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    Node *temp=head->next->next->next;
    temp->next=head;
    //    curr= head->next->next->next;
//    curr->next=head;
    printlist(head);
}


void printlist(Node *head)
{
    if(head==NULL)
        return;
    Node *curr=head;
    do{
        cout << curr->data<<"    ";
        curr=curr->next;
    }
    while(curr!=head);
}

Node *insertAtbegin_naive(Node *head,int x,int data)
{
    Node *curr=head;
    Node *temp=new Node(data);
    while (curr->next!=head)
    {
        curr=curr->next;
    }
    temp->next=head;
    curr->next=temp;
    return temp;
}


Node *insertAtbegin_good(Node *head,int x,int data)
{
    Node *temp=new Node(data);
    temp->next=head->next;
    head->next=temp;
    int curr=head->data;
    temp->data=head->data;
    head->data=curr;
    return head;
}

// Insert and delete at end is same both
// delete Kth node
Node *deletebegin(Node *head)
{

}