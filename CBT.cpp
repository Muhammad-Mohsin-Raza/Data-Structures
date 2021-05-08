//Implementing CBT
#include<iostream>
#include<cmath>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

class CBT {

private:
	node *root;

public:
    CBT() {
		root = NULL;
		
	}


	



	node* Create(int data) {
		node *Node = new node();
		Node->data = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}

	void Insertion(node *temp, int data) {
		//cout<<"In "<<endl;
		int level=0,en=0,left_tree_node_count=0;
		int right_tree_node_count=0;
		if (root == NULL) {
			
			root = Create(data);
			//cout<<"Root created";
			return;
		}
	
	level=find_h(temp->left);
	 en = pow(2, level) - 1;
	 //cout<<en<<endl;
	 left_tree_node_count = count_nodes(temp->left);
	 
	 //cout<<"left_tree_node_count :"<<left_tree_node_count<<endl;
	 right_tree_node_count = count_nodes(temp->right);
	 //cout<<"right_tree_node_count :"<<right_tree_node_count<<endl;

	if(left_tree_node_count==right_tree_node_count){
		if(level==0){
		//	cout<<"Inserted in 0 "<<endl;
		temp->left=Create(data);
		}
		else
		{
		//	cout<<"Call ->left"<<endl;
			Insertion(temp->left,data);
		}

		return;
	}
	else if(en!=left_tree_node_count){
		if(temp->left==NULL){
			temp->left=Create(data);
		}
		else
		Insertion(temp->left,data);
	}	

	else if(temp->right==NULL){
		temp->right=Create(data);
		return;
	}

	else if(en!=right_tree_node_count){
		if(temp->left==NULL){
			temp->left=Create(data);
		}
		else
		Insertion(temp->right,data);
	}
	

	}

	node *Get_Root() {
		return root;
	}

	void print(node *temp) {
		if (temp == NULL)
			return;
		print(temp->left);
		cout << temp->data << " ";
		print(temp->right);
	}

  
    //---------- Count nodes------------
    int count_nodes(node* tmp) {
        int x=1;
		if(tmp==NULL){
			return 0;
		}
        if(tmp->left==NULL && tmp->right==NULL){
            return 1;
        }
        else{
            if(tmp->left!=NULL){
				//x++;
                x=x+count_nodes(tmp->left);
				//cout<<"in left :"<<"x "<<x<<endl;
            }
            if(tmp->right!=NULL){
        //    x++;
             x=x+count_nodes(tmp->right);
			 //cout<<"In right :"<<"x "<<x<<endl;
            }
		}
        
        return x;
    }

	//-------------Find Height-------------------
		int find_h(node* temp){

		int t=1;
		if(temp==NULL){
			return 0;
		}
		if(temp!=NULL){
			
		    temp=temp->left;
		t=t+find_h(temp);
		}

		return t;
	}


 
};

int main() {
	CBT cbt;
	cbt.Insertion(cbt.Get_Root(), 8);
     cbt.Insertion(cbt.Get_Root(), 5);
       cbt.Insertion(cbt.Get_Root(), 4);
	  cbt.Insertion(cbt.Get_Root(), 6);
	   cbt.Insertion(cbt.Get_Root(), 1);
        cbt.Insertion(cbt.Get_Root(), 20);
      cbt.Insertion(cbt.Get_Root(), 10);
     cbt.Insertion(cbt.Get_Root(), 12);
	 cbt.Insertion(cbt.Get_Root(), 120);
	 cbt.Insertion(cbt.Get_Root(), 99);
	 cbt.Insertion(cbt.Get_Root(), 990);
	 cbt.Insertion(cbt.Get_Root(), 33);
	 cbt.Insertion(cbt.Get_Root(), 13);
    cbt.print(cbt.Get_Root());
    //cout<<"Count Node :"<<endl;
	// cout<<endl;
    //  cout<<"Right"<<cbt.count_nodes(cbt.Get_Root()->right);
	//  cout<<endl;
	//  cout<<"left"<<cbt.count_nodes(cbt.Get_Root()->left);

	// cout<<"Height "<<	cout<<cbt.find_h(cbt.Get_Root())<<endl;
	
}