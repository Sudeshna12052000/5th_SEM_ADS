#include <bits/stdc++.h>
#include<inttypes.h>
using namespace std;

class node
{
 public:
 int data;
 node *npx;
};

node *XOR (node *a,node *b)
{
  return (node*)((uintptr_t) (a) ^  (uintptr_t) (b));
}

void insert(node **head,int key)
{
 node *new_node=new node();
 new_node->data=key;
 new_node->npx=*head;
 if(*head!=NULL)
 {
 (*head)->npx=XOR(new_node,(*head)->npx);
 }
*head=new_node;
}

node *deleteb(node *head)
{
 if(head == NULL)
  return NULL;
 node *temp=XOR(head->npx,NULL);
 temp->npx=XOR(head,temp->npx);
 free(head);
 return temp;

}

void print(node *head)
{
 node *curr=head;
 node *prev=NULL;
 node *next;
 cout<<"The Linked List as follows: "<<endl;
 while(curr!=NULL)
 {
  cout<<curr->data<<" ";
 next=XOR(prev,curr->npx);
 prev=curr;
 curr=next;
 }
}

int main()
{
 node *head=NULL;
 cout<<"Inserting from the Begining"<<endl;
  insert(&head,4);
 insert(&head,5);
 insert(&head,6);
 print(head);
 cout<<endl;
 cout<<"Deletion from the begining"<<endl;
 head=deleteb(head);
 print(head);
 cout<<endl;
 return 0;
}
