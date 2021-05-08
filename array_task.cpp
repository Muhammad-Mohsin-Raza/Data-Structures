#include <iostream>
using namespace std;
int main() {

  int a[6] = {2,4,5,6,7,8};
  int *p=NULL;
  int *p1=NULL;
  
  p=a;
  p1=a;
  
   int l = sizeof(a)/sizeof(a[0]);
   

  int y;

  cout<<"Enter targeted value :"<<endl;
  cin>>y;

 
for(int x=0;x<l;x++)
{
    for(int h=1;h<l;h++)
  {
       if(*(p+x)+*(p1+h)==y)
      {
         cout<<"Numbers are :"<<*(p+x)<<","<<*(p+h)<<endl;

      }
      
  }
  
}


   return 0;


}