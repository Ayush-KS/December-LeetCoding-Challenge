// Linked List Random Node

class Solution {
public:

    ListNode* head;
    Solution(ListNode* head) {
        this -> head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        float scope = 1;
        int ans = 0;
        ListNode* curr = head;
        while(curr) {
            if(rand() < (RAND_MAX/scope))
                ans = curr -> val;
            scope++;
            curr = curr -> next;
        }
        return ans;
    }
};
