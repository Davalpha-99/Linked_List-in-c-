#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class node{
public:
	ll data;
	node *next;

	node(ll d){
		data=d;
		next=NULL;
	}
};

//merge function accepts two linked list's head(s),and then merge the two sorted linked list.
//and returns the merged linked list's head.
node *merge(node *head1,node *head2){
	if(head1==NULL)
		return head2;
	else if(head2==NULL)
		return head1;
	node *c;
	if(head1->data<head2->data){
		c=head1;
		c->next=merge(head1->next,head2);
	}
	else{
		c=head2;
		c->next=merge(head1,head2->next);
	}
	return c;
}

//function that return the k-th node from the end.
node *searchk(node *head,ll k){
	if(head==NULL|| head->next==NULL){
		return head;
	}
	node *f=head;node *slow=head;
	while(k>0 && f!=NULL){
		k-=1;
		f=f->next;
	}
	while(f!=NULL){
		slow=slow->next;
		f=f->next;
	}
	return slow;
}


//function to return the mid-point in a linked list.
node *mid(node *head){
	if(head==NULL || head->next==NULL){
		cout<<head->data<<endl;
	}
	node *slow=head;
	node *fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

//add node at the end.
void addatend(node *&head,ll d){
	node *n=new node(d);
	if(head==NULL){
		head=n;
		return;
	}
	node *i=head;
	while(i->next!=NULL){
		i=i->next;
	}
	i->next=n;
}

//continuous data entry in the linked list, given that the sequence of numbers terminate with a -1.
void linkedlist(node* &head){
	ll d;
	cin>>d;
	while(d!=-1){
		addatend(head,d);
		cin>>d;
	}
}

//function to print the linked list.
void print(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

//for multiple inputs from cin in the main,operator overloading might be done using a pointer of <istream or ostream>type.
ostream& operator <<(ostream &os,node *&head){
	print(head);
	return os;
}

istream& operator >>(istream &is,node *&head){
	linkedlist(head);
	return is;
}

int main()
{
	node *head1=NULL;
	node *head2=NULL;
	cin>>head1>>head2;
	/*cout<<mid(head1)->data<<endl;
	cout<<searchk(head1,4)->data<<endl;*/
	node *head3=merge(head1,head2);
	cout<<head3<<endl;
	return 0;
}