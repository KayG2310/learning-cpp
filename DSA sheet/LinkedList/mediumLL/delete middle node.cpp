/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // edge case
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is at middle now
        fast = head;
        while(fast->next !=  slow){
            fast = fast->next;
        }
        // fast is at one behind slow 
        fast->next = fast->next->next;
        delete(slow);
        return head;
    }
};

// brute force would mean calculate length first and then find half-1 node
// in optimal code to the above one, we will move slow to its next alternatively
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // edge case
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        fast = fast->next->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is at middle now
        ListNode* deleted = slow->next;
        slow->next = slow->next->next;
        delete(deleted);
        return head;
    }
};
// done in one pass only
