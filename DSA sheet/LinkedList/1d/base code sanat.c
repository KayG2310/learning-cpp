#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* root;

void access(struct node* root)
{
    struct node*temp;
    temp=root;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

struct node* insert_beg(struct node* root)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter number you want to insert at beginning: ");
    scanf("%d",&newnode->data);
    newnode->next=root;
    root=newnode;
    return root;
    free(newnode);
}

void insert_end(struct node*root)
{
   struct node* newnode,*temp;
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("Enter number you want to insert at end: ");
   scanf("%d",&newnode->data);
   newnode->next=NULL;
   temp=root;
   while(temp->next!=NULL)
   {
        temp=temp->next;
   }
   temp->next=newnode;
}

void insert_pos(struct node*root,int position)
{
    struct node*temp,*newnode;
    temp=root;
    for(int i=1;i<position-1;i++)
    {
        temp=temp->next;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter number you want to insert at position %d: ",position);
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
}

void del_elem(struct node*root)
{
    int elem;
    printf("Enter element you want to delete: ");
    scanf("%d",&elem);
    struct node*temp;
    temp=root;
    if(elem==temp->data)
    {
       root= temp->next;
       access(root);
       free(temp);
    }
    else
    {
        while(temp->next->data!=elem && temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        access(root);
    }
}

int length_wo_rec(struct node*root)
{
    int count=0;
    struct node*temp;
    temp=root;
    while(temp!=0)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

int length_w_rec(struct node* root)
{
    struct node*temp;
    temp=root;
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        return 1 + length_w_rec(temp->next);
    }
}

void print_rev(struct node*root)
{
    struct node *temp;
    temp=root;
    if(temp==NULL)
    {
        return;
    }
    else
    {
        print_rev(temp->next);
        printf("%d\n",temp->data);
    }
}

int middle(struct node*root)
{
    struct node *slow,*fast;
    slow=fast=root;
    if(root!=NULL)
    {
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow->data;
    }
    return 0;
}

struct node* reverse(struct node* root)
{
    struct node *prevnode,*currentnode,*nextnode;
    prevnode=0;
    currentnode=nextnode=root;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    root=prevnode;
    return root;
}

struct node* insertion_sorted(struct node* root,int num)
{
    struct node* temp,*newnode;
    temp=root;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if(root==NULL || num<root->data)
    {
        newnode->next=root;
        root=newnode;
        return root;
    }
    else
    {
        while(temp->next!=NULL && temp->next->data<num)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return root;
    }
}

void main()
{
    struct node p,q,r,s;
    struct node* root=&p;
    p.data=2;
    p.next=&q;
    q.data=3;
    q.next=&r;
    r.data=5;
    r.next=NULL;
    access(root);
    //INSERT AT BEGINNING
    root=insert_beg(root);
    access(root);
    //INSERT AT END
    insert_end(root);
    access(root);
    //INSERT AT POSITION
    int pos;
    printf("Enter the position at which you want to add the element: ");
    scanf("%d",&pos);
    if(pos==1)
    {
        root=insert_beg(root);
        access(root);
    }
    else
    {
        insert_pos(root,pos);
        access(root);
    }
    //DELETE AN ELEMENT
    del_elem(root);
    //LENGTH OF LIST
    int l1,l2;
    l1=length_wo_rec(root);
    printf("Length of Linked List = %d\n",l1);
    l2=length_w_rec(root);
    printf("Length of Linked List = %d\n",l2);
    //PRINT LIST BACKWARDS
    printf("The list printed backward is:\n");
    print_rev(root);
    //REVERSE LIST
    // root=reverse(root);
    // printf("Linked list reversed\n");
    // access(root);
    //SORTED INSERTION
    int num;
    printf("Enter number you want to insert: ");
    scanf("%d",&num);
    root=insertion_sorted(root,num);
    access(root);
    printf("Middle: %d",middle(root));
}
