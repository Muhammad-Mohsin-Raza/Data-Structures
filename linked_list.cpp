#include<iostream>
using namespace std;
struct node
{
	node* prv;
	int data;
	node *next;
};

class linkedlist {

private :
	node* head;
	node* tail;
public:

	linkedlist()
	{
		head = NULL;
		tail = NULL;
	}

	void add(int i)
	{
		
		node *tmp= new node;
		tmp-> data = i;
		tmp->next = NULL;
		tmp->prv = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;

		}
		else
		{
			tmp->prv = tail;
			tail->next =tmp ;
          	tail = tmp;

		}
	}
	void disp()
	{
		node* n = head;
		while (n != NULL)
		{
			cout << n->data << endl;
			n = n->next;

		}


	}


	void push(int d)
	{

		node* nnode = new node;
		nnode->next = NULL;
		nnode->prv = NULL;

		if (head == NULL)
		{
			cout << "Fisrt enter values by option insert node at last :" << endl;
		}

		nnode->data = d;

		nnode->next = head;
			head->prv = nnode;
      
			head = nnode;
			
	}


	// Inserting Node at a particular location 

	void insertNodeAtPosition(int pos, int value)
	{

		node* pre = new node;
		node* tem = new node;
		node* post = new node;
		post = head;

		for (int i = 1; i < pos; i++)
		{
			pre= post;
			post = post->next;


		}

		tem->data = value;
		tem->next = post;
		tem->prv = pre;

		//head->next = tem;
		pre->next = tem;
		post->prv = tem;

	}

	//Deleting first item of the list
	int pop() 
	{
		int retval = 0;
		node* next_node = NULL;
		

		next_node = head->next;
		retval = head->data;

		delete head;
		head = next_node;
		head->prv = NULL;

		return retval;
	}

	//deleting last item
	int removeLast()
	{
		int retval = 0;
		/* if there is only one item in the list, remove it */
		if (head->next == NULL) {
			retval = head->data;
			delete head;
			return retval;
		}

		/* get to the second to last node in the list */
		node* current = head;
		while (current->next->next != NULL) {
			current = current->next;
		}

		/* now current points to the second to last item of the list, so let's remove current->next */
		retval = current->next->data;
		//node* q = new node;
		
		delete current->next;
		tail = current;
		current->next = NULL;
		return retval;
	}

	//removing at a specific Position
	int removeByIndex(int n) {
		int i = 0;
		int retval = -1;
		node* current = head;
		node* temp_node = NULL;

		if (n == 0) {
			cout << "Head Element" << endl;
			return 0;                          
		}

		for (i = 0; i < n - 1; i++) {
			if (current->next == NULL) {
				return -1;
			}
			current = current->next;
		}

		temp_node = current->next;
		retval = temp_node->data;
		
		current->next = temp_node->next;
		
		current->next ->prv = temp_node->prv; 

		
		delete temp_node;

		return retval;

	}

	
	


};
int main()
{
	
	linkedlist l;
	

	cout << "---Inserting Node at last---" << endl;
	l.add(1);
	l.add(2);
	l.add(3);
	l.add(4);
	l.disp();


	cout << "---Push Node-----" << endl;
			l.push(5);
			l.disp();


			

			cout << "---insert Node At Position---" << endl;
			l.insertNodeAtPosition(3, 34);
			l.disp();
		

			cout << "---Poped value is: " << l.pop() << endl;
			l.disp();

		
			cout << "---Remove at last---" << endl;
			cout << "Last : " << l.removeLast() << endl;
			l.disp();
		
			
			cout << "---Remove by index---" << endl;
			cout << "Value del is :" << l.removeByIndex(2) << endl; 
			l.disp();

		


	
	return 0;
}