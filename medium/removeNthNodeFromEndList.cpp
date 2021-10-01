#include <iostream>

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
Given the head of a linked list, 
remove the nth node from the end of the list 
and return its head.
*/
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    int len = 0;
    ListNode *ptr(head);
    ListNode *temp;
    while(ptr) 
    {
        len++;
        ptr = ptr->next;
    }
    int target = len-n+1;
    ptr = head;
    temp=head;
    if (target ==1) head= head->next;
    while (target > 1)
    {
        temp = ptr;
        ptr = ptr->next;
        target--;
    }
    
    temp->next = ptr->next;
    delete(ptr);    
    return head;
}
