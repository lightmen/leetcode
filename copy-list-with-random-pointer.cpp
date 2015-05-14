/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode root(0);
        RandomListNode *cur,*new_node,*start;

        map<RandomListNode *,RandomListNode *> mp;
        cur = &root;
        start = head;
        while(head){
            new_node = new RandomListNode(head->label);
            cur->next = new_node;
            cur = new_node;
            mp[head] = new_node;

            head = head->next;
        }
        
        cur = root.next;
        head = start;
        while(cur){
            if(head->random)
                cur->random = mp[head->random];
            else
                cur->random = NULL;
            cur = cur->next;
            head = head->next;
        }
        
        return root.next;
    }
};
