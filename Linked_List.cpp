#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    struct node  *link;
};
struct node* createNode(){
struct node *n;
n = (struct node *)malloc(sizeof(struct node));
return(n);
}
int k=0;
struct node *start=NULL;
int insertNode(){
    int p=0;
    struct node *temp, *t;
    cout<<"Enter number of member you want enter"<<endl;
    cin>>p;
    cout<<"Enter element"<<endl;
    for(int i=0;i<p;i++)
    {
        k++;
     temp = createNode();
        cin>>temp->data;
        temp->link=NULL;
       if(start == NULL)
    start = temp;
    else
    {
         t=start;
     while(t->link!=NULL)
         t=t->link;
         t->link = temp;
    }
    }
}
void deleteNode()
{
    k--;
    struct node *r;
    if(start ==  NULL)
    cout<<"List is empty"<<endl;
    else
    {
        r=start;
        start = start->link;
        free(r);
    }
}
void viewList()
{
    struct node *t;
    t=start;
    cout<<"LIST: "<<endl;
    while(t!=NULL)
    {
       cout<<t->data<<"-->";
       t=t->link;
    }
    cout<<"NULL"<<endl;
}
void length()
{
    cout<<"List Length: "<<k;
}
int menu()
{
   int ch;
   cout<<"--------------LINKED LIST OPERATIONS-------------"<<endl;
    cout<<"1.INSERT MEMBER"<<endl;
   cout<<"2.DELETE FIRST MEMBER"<<endl;
   cout<<"3.GET LENGTH"<<endl;
   cout<<"4.VIEW LINKED LIST"<<endl;
   cout<<"5.ROTATE  LINKED LIST"<<endl;
   cout<<"6.EXIT"<<endl;
   cin>>ch;
   return ch;
}
void Rotate()
{
    struct node *p,*q,*new_head;
    int k=1,count=1;
    cout<<"Enter steps"<<endl;
    cin>>k;
    p=start;
    while(p!=NULL)
    {
        if(k==count)
        break;
        p=p->link;
        count++;
    }
    new_head=p->link;
    p->link=NULL;
    q=new_head;
    while(q->link!=NULL)
    {
    q=q->link;
    }
    q->link=start;
    start=new_head;
}
int main()
{
    while(1)
    {
        system("CLS");
        switch(menu())
        {
        case 1:
            insertNode();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            length();
            break;
        case 4:
            viewList();
            break;
        case 5:
            Rotate();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"wrong options"<<endl;
        }
        getch();
    }
}

