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
    struct RandomListNode *pre;
    struct RandomListNode *new_node;

    root.next = head;
    while(head){
        new_node = malloc(sizeof(struct RandomListNode));
        new_node->next = head->next;
        new_node->label = head->label;
        head->next = new_node;
        head = head->next->next;
    }

    head = root.next;
    while(head){
        new_node = head->next;
        if(head->random)
            new_node->random = head->random->next;
        else
            new_node->random = NULL;

        head = head->next->next;
    }

    head = root.next;
    pre = &root;
    while(head){
        new_node = head->next;
        head->next = new_node->next;
        head = head->next;

        pre->next = new_node;
        pre = new_node;
    }

    pre->next = NULL;

    return root.next;
}
