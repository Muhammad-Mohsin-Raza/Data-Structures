#include<iostream>

using namespace std;

struct node{
    string data;
    node* next;
};

class List{
    private:
        node *head;
    public:
        List(){
            head = NULL;
        }
    
    node * get_new_node(string data){
        node* link_node = new node();
        link_node->data=data;
        link_node->next=NULL;
        return link_node;
    }

    void add_link_node_to_head(string data){
        if(head==NULL){
            head = get_new_node(data);
            return;
        }
        node* data_node = get_new_node(data);
        data_node->next = head;
        head = data_node;
    }

    void add_link_node_to_tail(string data){
        if(head==NULL){
            head = get_new_node(data);
           
            return;
        }
       
        node* data_node = get_new_node(data);
        node *tail = get_tail(head);
        tail->next = data_node;
       
    }

    node* get_head(){
        return head;
    }

    node* get_tail(node* head){
        node* tail_hunter =head;
        while(tail_hunter->next!=NULL)
        tail_hunter = tail_hunter->next;
        return tail_hunter;
    }

    // Task solution

    string get_data(node* random_node){
        if (random_node==NULL)
            return 0;
        else return random_node->data;
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

    void print(){
        node* itera = head;
        while(itera){
            cout<<itera->data<<" ";
            itera = itera->next;
        }
    }
    void min_max(){
        //Your code here
        node* tmp=head;
        int c=0,c1=0;

        //node* find=tmp->data;
        
        while(tmp!=NULL)
        {
            c++;
            tmp=tmp->next;
        }

        tmp=head;
        int *p=new int [c];
        int i=0;
        while(tmp!=NULL)
        {
            *(p+i)=tmp->data.length();
            tmp=tmp->next;
            i++;
        }

        int max=*p;
        while(c1!=c)
        {
            if(max<*(p+c1))
            {
                max=*(p+c1);
            }
            c1++;
        }
        
        tmp=head;
        int min=*p;
        int c2=0;
        while(c2!=c)
        {
            if(min>*(p+c2))
            {
                min=*(p+c2);
            }
            c2++;
        }

        cout<<"min"<<min<<endl;

        tmp=head;
        while(tmp!=NULL)
        {
            if(max==tmp->data.size())
            {
                cout<<"Max is :"<<max<<" "<<"And string is :"<<tmp->data<<endl;
            }
         
            tmp=tmp->next;
        }

         tmp=head;
        while(tmp!=NULL)
        {
            if(min==tmp->data.size())
            {
                cout<<"Min is :"<<min<<" "<<"And string is :"<<tmp->data<<endl;
            }
            tmp=tmp->next;
        }
    }
};

int main(){
    List l1;
    // "devops aiopss bell in is"

    l1.add_link_node_to_tail("devops");
    l1.add_link_node_to_tail("aiopss");
    l1.add_link_node_to_tail("bell");
    l1.add_link_node_to_tail("in");
    l1.add_link_node_to_tail("is");
     l1.add_link_node_to_tail("devops");
    l1.add_link_node_to_tail("aiopss");
    l1.add_link_node_to_tail("bell");
    l1.add_link_node_to_tail("in");
    l1.add_link_node_to_tail("is");
    

    l1.print();

    l1.min_max();
}