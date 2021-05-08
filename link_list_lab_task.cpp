
// lab task  put a int after a given value
#include<iostream>

using namespace std;

struct node
{
	int data;
	node* next;
};

 class list
  {
    public:
    node *head, *curr;
    public:
    list()
    {
      head=NULL;
      curr=NULL;
    }
void createnode(int value)
    {
    	
      
      if(head==NULL)
      
      {	node *temp=new node;
      
      	 temp->data=value;
      temp->next=NULL;
      
        head=temp;
        curr=head;
        return;
      }
      
     
    
      
        node *temp=new node;
        
        temp->data=value;
        temp->next=NULL;
        
        
        curr->next=temp;
        curr=curr->next;
        
        
		
    }
    
    
    void add(int key, int val ){
  	curr=head;
  	if(head==NULL){
  		
  		return;
	  }
	  
	  while(curr!=NULL){
	  	if(curr->data == key){
	  		node *temp=new node;
	  		temp->data=val;
	  		temp->next=NULL;
	  		
	  		temp->next=curr->next;
	  		
	  		curr->next=temp;
	  	//	curr=curr->next;
	  		
	  		
	  		
		  }
		  curr=curr->next;
	  }
  }
  
  
  
     void display()
  {
    node *temp=new node;
    curr=head;
    while(curr!=NULL)
    {
      cout<<curr->data<<"\t";
      curr=curr->next;
    }
  } 
  
  void  del(int key){

  	curr=head;
  	node *temp1=new node;
  	if(head==NULL){

  		return;
  		
	  }
	  
	  while(curr!=NULL){
	  //	cout<<"hello";
	  
      cout<<"IN del";
	  if(curr->next->data==key){
	  	temp1->next=curr->next->next;
	  	temp1->data=curr->next->data;
	  	delete curr->next;
	  	curr->next=temp1->next;
	  	cout<<temp1->data;
	  }
	  	
	  
	  		

		  
		  curr=curr->next;
	  }
	  	
	  		
  }
  
  void del_first(){
  	curr=head;
  	node*temp1=new node;
  	temp1=head;
  	
  	if(head==NULL){

  		return;
	  }
	  cout<<endl;

	  head=head->next;
	  
	  
	  
	  delete temp1;
  }
  
  
  
  
	  };
	  
	  int main(){
	  	
	  	list l;
	  	
	  	cout<<"link list  ";
	  	l.createnode(5);
	  	l.createnode(6);
	  
	  	l.createnode(8);
	  	l.createnode(9);
	  	//	l.add(6,7);
	  	
	  	l.display();
	  	cout<<endl;
	  	cout<<"add  ";
	    l.add(6,7);
		l.display();
		cout<<endl;
		
		l.add(5,2);
		l.add(2,3);
		
	  			
	
	  			
	  			l.display();
	  	
	  	
	  	
	  	return 0;
	  	
	  	
	  	
	  }