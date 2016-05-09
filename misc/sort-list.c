/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static int cmp(const void *a,const void *b)
{
    return (*(struct ListNode **)a)->val - (*(struct ListNode **)b)->val;
}
struct ListNode *sortList(struct ListNode *head) {
    struct ListNode **arr;
    struct ListNode *tmp;
    int cnt,i;
    cnt = 0;
    if(head == NULL)
        return head;
    tmp = head;
    while(tmp){
        cnt++;
        tmp = tmp->next;
    }
    arr = (struct ListNode **)malloc(sizeof(struct ListNode *) * cnt);
    tmp = head;
    for(i = 0; i < cnt; ++i){
        arr[i] = tmp;
        tmp = tmp->next;
    }
    qsort(arr,cnt,sizeof(struct ListNode *),cmp);
    for(i = 0; i < cnt-1; ++i)
        arr[i]->next = arr[i+1];
    arr[i]->next = NULL;
    head = arr[0];
    return head;
}
