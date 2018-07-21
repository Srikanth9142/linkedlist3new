#include<iostream>
using namespace std;
class Chain;
class Chainnode
{
    friend class Chain;
    private:
     int data;
     Chainnode *link;
    public:
     Chainnode(int d=0,Chainnode *next=0)
     {
        data=d;
        link=next;
     }
     
};
class Chain
{
    private:
     Chainnode *head;
    public:
    Chain(){head=NULL;}
    void insert(int item)
     {
        Chainnode *newnode =new Chainnode(item);
        Chainnode *tmp=NULL;
        tmp=head;
        if(head==NULL){
          head=newnode;
          return;  
        }
          
        while(tmp->link!=NULL)
        {
            tmp=tmp->link;
        }
        tmp->link=newnode;
     }
     void insertAfter(int item,int p)
     {
        Chainnode *newnode =new Chainnode(item);
        Chainnode *tmp;
        tmp=head;
        while(tmp&&tmp->data!=p)
        {
            tmp=tmp->link;
        }
        if(tmp)
        {
            newnode->link=tmp->link;
            tmp->link=newnode;
        }
        else
            cout<<item<<"is not found in the list,can't insert"<<p<<endl;
     }  
     void display()
     {
         Chainnode *trav=head;
         cout<<"list contains:";
         while(trav!=NULL)
         {
             cout<<trav->data<<" ";
             trav=trav->link;
         }
         cout<<endl;
     }
    
};
int main()
{
    int item,n,p;
    cout<<"give your size of list:";
    cin>>n;
    Chain c1;
    cout<<"enter values in list:"<<endl;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        c1.insert(t);
    }
    cout<<"Enter item which you to want to be place"<<endl;
    cin>>item;
    cout<<"Which item value after you want to place:"<<endl;
    cin>>p;
    c1.insertAfter(item,p);
    c1.display();
    return 0; 

}
