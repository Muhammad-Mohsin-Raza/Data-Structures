#include<iostream>
using namespace std;
struct node {

	int data;
	node* next;
};

class link {

	node* head;
	node* tail;
public:
	link()
	{
		head = NULL;
		tail = NULL;
	}
	void add_node(int n)
	{
		node* tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
	}
	void display()
	{
		node* temp = new node;
		temp = head;
        cout<<"Values are :"<<endl;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}

    void task(int x)
    {
     node *tmp1=new node;
        tmp1=head;
        int count=0,sub=0;
        bool a=false;
        if(head!=NULL)
    {
            while(tmp1!=NULL)
       {
         
          
      

          if(tmp1->data==x)
          {
              cout<<"X "<<x;
           a=true;
           break;
          }

          if(a==false)
         {
             tmp1=tmp1->next;
         }
        
      }
        tmp1=head;
      while(tmp1!=NULL)
      {
        count++;
        tmp1=tmp1->next;

      }
      sub=count;
      int copy[count];
        int copy2[count];
        for(int i=0;i<count;i++)
        {
             copy[count]=0;
         copy2[count]=0;
        

        }
      tmp1=head;
      
      count=0;

      while(tmp1!=NULL)
      {
         copy[count]=tmp1->data;
        tmp1=tmp1->next;
     
      
         count++;

     }
     
   

       int con=1,result=0,inner=0;

       
        while(con!=2)
        {

            x++;
          
            for(int p=0;p<sub;p++)
        {
            if(x==copy[p])
            {
                con=2;
                result=x;
                break;
            }
            else 
            {
                if(x>=copy[p] )
                {
                    if( inner == sub)
                   {
                    cout<<"Not found num "<<endl;
                    con=2;
                    break;
               
                   } 
                   inner++;
                 }

            }
          


        }
     
        if(con==2)
        {
            break;

        }

        }
        cout<<"NUM "<<result<<endl;


    }
        
    }      



};
int main()
{

	link a;
    int c=0,x=0, v=0,opt=0;
    char c1='y';
    while(c1=='y' ||c1=='Y')
    {
        cout<<"Press 1 For inserting node :"<<endl;
        cout<<"Prss 2 to find the next successor number from the list :"<<endl;
        
        cin>>opt;
        if(opt==1)
        {
            cout<<"Enter value :"<<endl;
            cin>>v;
	        a.add_node(v);
	        a.display();
        }
        if(opt==2)
        {
        cout<<"Enter value for finding successor :"<<endl;
        cin>>x;
        a.task(x);

        }
     cout<<"For again press y or press any key to exit :"<<endl;
     cin>>c1;
    }

	

	return 0;
}