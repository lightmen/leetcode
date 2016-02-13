/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *merge_two_list(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode head;
    struct ListNode *cursor,*tmp;

    cursor = &head;

    while(l1 && l2){
        if(l1->val < l2->val){
            tmp = l1;
            l1 = l1->next;
        }else{
            tmp = l2;
            l2 = l2->next;
        }
        cursor->next = tmp;
        cursor = cursor->next;
    }

    cursor->next = NULL;

    if(l1)
        cursor->next = l1;
    if(l2)
        cursor->next = l2;

    return head.next;
}

struct ListNode* merge_list_range(struct ListNode **lists, int start, int end)
{
    struct ListNode *left, *right;
    int mid;

    if(start == end)
        return lists[start];

    mid = (start + end) / 2;

    left = merge_list_range(lists, start, mid);
    right = merge_list_range(lists, mid+1, end);

    return merge_two_list(left,right);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0)
        return NULL;
    return merge_list_range(lists, 0, listsSize-1);
}
