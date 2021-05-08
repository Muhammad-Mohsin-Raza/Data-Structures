#include<iostream>
using namespace std;

struct node{
    char data;
    node *next;
};

class SinglyCircularLinkList{
    private:
        node* head;
    public:
        SinglyCircularLinkList(){
            head = NULL;
        }

        node* create_node(char data){
            node* link_node = new node();
            link_node->data = data;
            return link_node;
        }

        void add_node_to_tail(char data){
            if (head == NULL){
                head = create_node(data);
                head->next = head;
                return;
            }
            node* tail = get_tail();
            node* link_node = create_node(data);
            link_node->next = tail->next;
            tail->next = link_node;
        }

        node* get_tail(){
            node* iter = head;
            while(iter->next != head){
                iter = iter->next;
            }
            return iter;
        }

        void print(){
            node* iter = head;
            if (head == NULL) return;
            do{
                cout<<iter->data;
                iter = iter->next;
            }
            while(iter != head);
            cout<<endl;

        }

        node* search_node(char key){
            node* iter = head;
            while(iter->data !=key){
                iter = iter->next;
                if (iter == head) return NULL;
             }
             return iter;
        }

        void insert_at_value(char info, char key){
            if (head == NULL) return;
            node* search = search_node(key);
            node* link_node = create_node(info);
            link_node->next = search->next;
            search->next = link_node;

        }

        node* get_prev(node* random_node){
            node* temp_iter = head;
            if (random_node==NULL)
                    return NULL;
            if (random_node==head)return head;
            while(temp_iter->next!=random_node){
                temp_iter=temp_iter->next;
            }
            return temp_iter;
        }
        
        void  delete_node(char key){
            node* del_node = search_node(key);
            node* tail = get_tail();
            node * prev = get_prev(del_node);
            if (del_node == head){
                tail->next = del_node->next;
                if(head->next==head)head=NULL;
                else head = head->next;

                delete del_node;
                del_node = NULL;
            }
            else {
                prev->next = del_node->next;
                delete del_node;
                del_node = NULL;
            }
        }

        void reverse_word(int start_pos, int end_pos){
            // YOUR CODE GOES HERE
			 node* tmp=NULL;
			 tmp=head;
			 int c=0;
			 node* tail1=head;
			
					for(int i=1;i<=start_pos-1;i++)
				{
				
					tmp=tmp->next;

				}
			 
					cout<<"start ;"<<tmp->data<<endl;

			for(int j=1;j<=end_pos-1;j++)
			{
			
				tail1=tail1->next;
			}
				cout<<"end "<<tail1->data<<endl;
 
				node* iter1 = head;
            if (head == NULL) return;
            do{
                c++;
                iter1 = iter1->next;
            }
            while(iter1 != head);
          
		int l=0;
		node* space=NULL;
		node* tail2=tail1;
		node* head2=tmp;
			for(int a=start_pos;a<=end_pos;a++){

			if(head2->data==' '){

				l=a;
				space=head2;
			}
				head2=head2->next;
			}

			//	cout<<"Space"<<get_prev(space)->data<<endl;		
			// for(int p=start_pos;p<=end_pos;p++)
			// {
			// 	cout<<tail1->data;
			// 	tail1=get_prev(tail1);
				
				
			// 	if(p!=end_pos)
			// 	{
			// 		cout<<"->";
			// 	}

				
			// }

			// cout<<endl;

			for(int p=start_pos;p<l;p++)
			{
				cout<<get_prev(space)->data<<"->";
				
				
				
				
				space=get_prev(space);
			}
			
			space=head2;
			cout<<space->data<<endl;
				space=tail1;
				for(int q=l;q<end_pos;q++)
			{
				cout<<get_prev(space)->data<<"->";
				space=get_prev(space);
			}
			cout<<endl;
           // return;
        }

};
int main(){

    SinglyCircularLinkList Ring;

    Ring.add_node_to_tail('h');
    Ring.add_node_to_tail('e');
    Ring.add_node_to_tail('l');
    Ring.add_node_to_tail('l');
    Ring.add_node_to_tail('o');
    Ring.add_node_to_tail(' ');
    Ring.add_node_to_tail('e');
    Ring.add_node_to_tail('v');
    Ring.add_node_to_tail('e');
    Ring.add_node_to_tail('r');
    Ring.add_node_to_tail('y');
    Ring.add_node_to_tail('b');
    Ring.add_node_to_tail('o');
    Ring.add_node_to_tail('d');
    Ring.add_node_to_tail('y');
    Ring.add_node_to_tail(' ');
    Ring.add_node_to_tail('h');
    Ring.add_node_to_tail('o');
    Ring.add_node_to_tail('w');
    Ring.add_node_to_tail(' ');
    Ring.add_node_to_tail('a');
    Ring.add_node_to_tail('r');
    Ring.add_node_to_tail('e');
    Ring.add_node_to_tail(' ');
    Ring.add_node_to_tail('y');
    Ring.add_node_to_tail('o');
    Ring.add_node_to_tail('u');
    Ring.print();


    Ring.reverse_word(1,15);
    //Ring.reverse_word(7,15);

}
