#include <iostream>
using namespace std;
#define SIZE 20
struct Node
{
	int data;
	struct Node* next;
};
Node* insertAtBeg(Node *start,int data)
{
	Node *head=new Node();
	head->data=data;
	head->next=NULL;
	if(start==NULL)
	{
		return head;
	}
	else
	{
		head->next=start;
		return head;
	}
}
bool search(Node *start,int data)
{
	Node *head=start;
	while(head!=NULL)
	{
		if(head->data==data)
			return true;
		head=head->next;
	}
	return false;
}
void print(Node *start)
{
	while(start!=NULL)
	{
		cout<<start->data<<" ";
		start=start->next;
	} 
	cout<<endl;
}
int hashFunc(int key)
{
	return key%SIZE;
}
void choice()
{
	cout<<"Press\n1: Insert\n2: Search\n3: Print\n0: Exit\nEnter: ";
}
int main()
{
	int n;
	Node *arr[SIZE]={NULL};
	do
	{
		choice();
		cin>>n;
		switch(n)
		{
		case 0:
		break;
		case 1:
			char ch;
			do
			{
				int data;
				cout<<"Enter key: ";
				cin>>data;
				int hash=hashFunc(data);
				arr[hash]=insertAtBeg(arr[hash],data);
				cout<<"Do you want to continue(Y\\N): ";
				cin>>ch;
			} while(ch!='n');
		break;
		case 2:
			int s,sh;
			cout<<"Enter Key: ";
			cin>>s;
			sh=hashFunc(s);
			if(search(arr[sh],s))
				cout<<"Key Found"<<endl;
			else
				cout<<"Key not Found"<<endl;
		break;
		case 3:
			int p;
			cout<<"Enter key: ";
			cin>>p;
			p=hashFunc(p);
			print(arr[p]);
		break;
		default:
			cout<<"Invalid Choice"<<endl;		
		}	
	} while(n!=0);				
	return 0;
}
