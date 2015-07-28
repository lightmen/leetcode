/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *get_node(int label)
{
    struct RandomListNode *ret;

    ret = malloc(sizeof(struct RandomListNode *));
    ret->label = label;
    ret->next = NULL;
    ret->random = NULL;
}

void copyList(struct RandomListNode *head){
    struct RandomListNode *next_node;
    while(head){
        struct RandomListNode *new_node = get_node(head->label);
        next_node = head->next;
        head->next = new_node;
        new_node->next = next_node;
        head = next_node;
    }
}

void copyRandom(struct RandomListNode *head){
    while(head){
        if(head->random){
            head->next->random = head->random->next;
        }
        head = head->next->next;
    }
}

struct RandomListNode *spiltList(struct RandomListNode *head)
{
    struct RandomListNode *next_node;
    struct RandomListNode *new_node;
    struct RandomListNode root;

    root.next = head ? head->next : NULL;
    while(head){
        next_node = head->next->next;
        new_node = head->next;
        head->next = next_node;
        new_node->next = next_node ? next_node->next : NULL;
        head = next_node;
    }

    return root.next;
}

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    copyList(head);
    copyRandom(head);
    return spiltList(head);
}
