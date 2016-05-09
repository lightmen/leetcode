/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    do{
        if(!slow || !fast)
            return NULL;
        slow = slow->next;
        fast = fast->next;
        if(!fast)
            return NULL;
        fast = fast->next;
    }while(slow != fast);
    
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}
/*
soluton:
It is a famous known problem Hare and Tortoise Length of head to cycle started node: x

Length of the cycle: y

Let hare run two steps while tortoise runs one step

while both of them entered the cycle, the hare is definetly to overlap the tortoise at some node, we define it as m:

The hare totally runs: x + ky + m The tortoise totally runs: x + ty + m Thus, ky = 2ty + x + m we have (x + m) mod y = 0 We can conclude that if the hare run more x steps, it will reach the cycle's starting node.

details refer to: https://leetcode.com/discuss/396/is-there-any-better-answer-for-the-linked-list-cycle-ii 
answered by stackpop.
*/
