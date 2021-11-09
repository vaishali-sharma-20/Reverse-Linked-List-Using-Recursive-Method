//Reversing A Linked List Using Recursion Method
#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* head;
	node* next;
	node(int val)
	{
		data = val;
		next = NULL;
	}
};
void InsertAtTail(node*& head, int val)
{
	node* n = new node(val);
	if (head == NULL)
	{
		head = n;
		return;
	}
	node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
}
void display(node* head)
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " " << "->" << " ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}
node* Reverse(node*& head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node* newhead = Reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return newhead;
}
int main()
{
	node* head = NULL;
	InsertAtTail(head, 10);
	InsertAtTail(head, 20);
	InsertAtTail(head, 30);
	InsertAtTail(head, 40);
	display(head);
	node* newhead = Reverse(head);
	display(newhead);
	return 0;
}