#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *addtoempty(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr ->next = ptr;
    ptr->next = NULL;
    return ptr;
}

struct node *addatend(struct node *head , int data)
{
    struct node *ptr;
    struct node *p=head;
    ptr=(struct node *)malloc(sizeof(struct node));
    while(p->next !=NULL)
    {
        p=p->next;
    }
   ptr->data=data; 
   p->next = ptr;
   ptr->next =NULL;
   return head;

}

struct node *createlist(struct node *head)
{
    int i , n , data;
    printf("Enter the number of node in list: ");
    scanf("%d",&n);

    if(n == 0){
        return head;
    }
    printf("Enter the element 1: ");
    scanf("%d",&data);
    head = addtoempty(data);
    for (i = 1; i < n; i++)
    {
    printf("Enter the element %d: ",i+1);
    scanf("%d",&data);
    head = addatend(head ,data);
    }
    return head;
}
void traversal(struct node *head)
{
   struct node *ptr = head;
   if (ptr == NULL)
   {
    printf("No node in list");
   }
   while (ptr != NULL)
   {
    printf(" %d ",ptr->data);
    ptr = ptr->next;
   }
   printf("\n");
}
int main()
{
    struct node *head = NULL;
    head = createlist(head);
    traversal(head);
    return 0;
}