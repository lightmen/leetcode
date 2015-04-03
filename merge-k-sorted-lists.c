/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = head;
    while(list1 && list2){
        if(list1->val > list2->val){
            cur->next = list2;
            list2 = list2->next;
        }else{
            cur->next = list1;
            list1 = list1->next;
        }
        cur = cur->next;
    }
    
    if(list1){
        cur->next = list1;
    }else{
        cur->next = list2;
    }
    
    return head->next;
}
struct ListNode *merge(struct ListNode *lists[],int beg,int end){
    if(beg > end)
        return NULL;
    if(beg == end)
        return lists[beg];
        
    int mid = (beg + end) / 2;
    struct ListNode *left = merge(lists,beg,mid);
    struct ListNode *right = merge(lists,mid+1,end);
    
    return mergeTwoLists(left,right);
}
struct ListNode *mergeKLists(struct ListNode *lists[], int k) 
{
    return merge(lists,0,k-1);
}
