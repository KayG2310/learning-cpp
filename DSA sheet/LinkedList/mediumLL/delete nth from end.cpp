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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;

        int i=0;
        ListNode* temp = head;
        while(temp != nullptr){
            temp = temp->next;
            i++;
        }
        // we have count of LL
        // node to be deleted = 
        if(i==n){
            // head is to be removed
            ListNode* newhead = head->next;
            delete (head);
            return newhead;
        }

        int k = i-n;
        temp = head;
        while(temp!=nullptr){
            k--;
            if(k==0) break;
            temp = temp->next;
        }
        ListNode* deleted = temp->next;
        temp->next = temp->next->next;
        deleted->next = nullptr;
        delete (deleted);
        return head;
    }
};

// optimal approach as above can take 2n, sc = 1
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        if(fast==NULL) return head->next;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* deleted = slow->next;
        slow->next = slow->next->next;
        delete (deleted);
        return head;
    }
};
// tc = n/2, sc=1
