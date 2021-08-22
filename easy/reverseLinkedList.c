#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode {
  int val;
  struct ListNode * next;
}ListNode;

struct ListNode * createNode(const int val)
{
    struct ListNode * tmp=(ListNode *)malloc(sizeof(struct ListNode));
    if(tmp)
    {
        tmp->val=val;
        tmp->next=NULL;
    }
    return (tmp!=NULL)? tmp: NULL;
}    

void  addListNode(struct ListNode *  head, const int val)
{
   if(!head)
   {
        struct ListNode * tmp=createNode(val);
        head=tmp;
        return;
   }
   struct ListNode * tmp=createNode(val);
   struct ListNode * curr=head->next;
   while(curr)
   {
      if(curr->next)
        curr=curr->next;   
   }
   if(tmp)
   {
        curr->next=tmp;
   }
}

void deleteList(struct ListNode * head)
{
    if(head)
    {
        ListNode * curr=head;
        ListNode * tmp=NULL;
        while(curr)
        {
            tmp=curr;
            curr=curr->next;
            free(tmp);
        }
        head=NULL;
    }
}

void printList(struct ListNode * list)
{
    struct ListNode * temp=list;
    printf("List:\n[ ");
    if(temp){
        while(temp)
        {
            printf(" %d, ",temp->val);
            temp=temp->next;
        }
        printf(" ]\n");
    }
    printf("List is Empty!! ]\n");
}

int main(int argc, char * argv[]){

 ListNode * mylist=NULL;
 for(int numberX=0; numberX<5 ; ++numberX){
    addListNode(mylist,numberX);}
printList(mylist);
deleteList(mylist);
//printList(mylist);

   return 0;
}
