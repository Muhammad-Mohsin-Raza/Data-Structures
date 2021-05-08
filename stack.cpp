//stack using linked list
#include <iostream>
using namespace std;
struct node {

	int data;
	node* next;

};
class stack {

	node* pt;
public:
	stack();
	void create(int a);
	int pop();

	void printList();
};
stack::stack()
{
	pt = NULL;

}
void stack::create(int a)
{
	node  *temp;
	temp = new node;
	temp->data = a;
	temp->next = NULL;

	if (pt == NULL)
	{
		pt = temp;
	}
	else
	{
		temp->next = pt;
		pt = temp;
	}

	
 }
int stack::pop()
{
	if (pt == NULL)
	{
		cout << "stack is empty :" << endl;
	}
	else
	{
		node  *new_node;
		new_node = new node;
		int value=0;
		value = pt->data;
		new_node = pt->next;

		delete pt;
		pt = new_node;
		return value;
	}

}



void stack:: printList() {
	node* current = pt;

	while (current != NULL) {
		cout << current->data << endl;
		current = current->next;
	}
}


int main()
{

	stack s;
	s.create(1);
	s.create(2);
	s.create(3);

	s.printList();
	cout << endl;
	cout << "Value popoed is :"<<s.pop() << endl;
	s.printList();

	return 0;
}
