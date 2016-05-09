/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode root;
    struct RandomListNode *prev,*tmp,*p;
    struct RandomListNode **arr;
    int count = 0;
    int i;

    if(!head)
        return NULL;

    prev = &root;
    while(head){
        tmp = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
        tmp->label = head->label;
        tmp->next = NULL;
        prev->next = tmp;

        p = head->next;
        head->next = tmp;
        tmp->random = head;
        
        prev = tmp;
        head = p;
        count++;
    }
    
    arr = (struct RandomListNode **)malloc(sizeof(struct RandomListNode *) * count);
    i = 0;
    head = root.next;

    while(head){
        p = head->random;
        tmp = p->random;
        arr[i++] = p;
        head->random = tmp ? tmp->next : NULL;
        head = head->next;
    }
    
    for(i = 0; i < count-1; ++i)
        arr[i]->next = arr[i+1];

    arr[count-1]->next = NULL;
    head = arr[0];
    free(arr);

    return root.next;
}
