#include <iostream>
using namespace std;
struct node{
  int info;
  node *pre,*next;
};

class dl{
  node *head,*tmp,*tmp1;  
  public:
  dl(){
    head=tmp=tmp1=NULL;  
  }
  
  void insert(int data){
      
      if(head==NULL){
          head=new node;
          head->next=head;
          head->pre=head;
          head->info=data;
      }
      else{
        
        tmp=head;
        tmp1=new node;
        tmp1->info=data;
        
        while(tmp->next!=head){
    
            tmp=tmp->next;
        }
        
        tmp->next=tmp1;
        tmp1->pre=tmp;
        tmp1->next=head;
        head->pre=tmp1;
        
    
      }
      
  }
  
  // after x node
    void after(int x,int y){
        
        int f=0;
        tmp=head;
        
        tmp1=new node;
        tmp1->info=y;
        
        while(tmp->next!=head){
            
            if(tmp->info==x){
            
            f=1;
                
                
            }
            
            if(f==0)
            {
                tmp=tmp->next;
            }
            else
            break;
            
            
        }
        
        
        // insetion before head
        if(tmp==head && tmp->info==x){
        
        
        
            tmp1->next=head;
            tmp1->pre=head->pre;
            head->pre->next=tmp1;
            head->pre=tmp1;
            head=head->pre;
            
            
        }
        
        
        // insertion after last node        
        else if(tmp->next==head && tmp->info==x){
            tmp1->next=tmp->next;
            tmp1->pre=tmp;
            tmp->next=head->pre=tmp1;
        }
        
        //insertion after nodes that are not head nor last node
        else if(tmp->info==x)
        {
            
            
        tmp1->next=tmp->next;
        tmp1->pre=tmp;
        tmp->next->pre=tmp1;
        tmp->next=tmp1;
        
        }
        else{
        
        cout<<"not found :"<<endl;    
        }
        
        
    }
    
    
    
    void del(int val){
        
        if(head == NULL){
            cout<<"Link list is empty :"<<endl;
        }
        
        else{
            
            int d=0;
            
            tmp=head;
            
            while(tmp->next!=NULL){
                if(tmp->info==val){
                    break;
                }
                tmp=tmp->next;
            }
            
            // deletion at head
            if(tmp==head && tmp->info==val){
                cout<<head->pre->info<<"b"<<endl;
                tmp->next->pre=head->pre;
                head->pre->next=tmp;
                head=head->next;
                
                d=tmp->info;
                delete tmp;
                tmp=NULL;
                cout<<"Deleted value is :"<<d<<endl;
                cout<<head->pre->info<<"after"<<endl;
                
            } 
            
             // deletion at last node
            else if(tmp->next==head && tmp->info==val){
                
                tmp1=tmp->pre;
                tmp1->next=head;
                head->pre=tmp1;
                d=tmp->info;
                cout<<"Deleted value is :"<<d<<endl;
                delete tmp;
                tmp=NULL;
            }
            
            else{
                
                tmp1=tmp;
                tmp1=tmp->pre;
                tmp1-> next=tmp->next;
                tmp->next->pre=tmp->pre;
                
                d=tmp->info;
                cout<<"Deleted value : "<<d<<endl;
                
                delete tmp;
                
                tmp=NULL;
                
            }
            
        }
        
        
    }
  
  void disp(){
      tmp=head;
      while(tmp->next!=head){
          cout<<tmp->info<<"->";
          tmp=tmp->next;
      }
      if(tmp->next == head){
          cout<<tmp->info;
      }
      cout<<endl;
      
    
      
  }
};


int main()
{
    dl d;
//     d.insert(2);
//   d.insert(3);
//     d.insert(4);
//     d.insert(5);
     d.insert(1);
    d.disp();
    
    //  insertion before head
    d.after(2,1);
   d.disp();
    // insertion after last node
    d.after(5,6);
    d.disp();
    
    // deletion at head
    
    d.del(1);
    d.disp();
    
    // deletion at last node
    
    // d.del(6);
    // d.disp();
      // deletion at random node
    // d.del(4);
    // d.disp();

    return 0;
}
