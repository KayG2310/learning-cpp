// brute
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
 #include<deque>
class Solution {
public:

    bool isPalindrome(ListNode* head) {
        ListNode* last = head;
        if(head->next == nullptr) return true;
        deque<int>q;
        while(last != nullptr){
            q.push_back(last->val);
            last = last->next;
        }
        while(q.size() != 0){
            if(q.front() != q.back()){
                return false;
            }
            q.pop_front(); // front is removed;
            if(q.size() !=0) q.pop_back();
        }
        return true;
    }
};

// optimal - using hare tortoise algorithm, find the middle, tc = 2n, sc=1
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
 #include<deque>
class Solution {
private:
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
public:

    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            // we need to stop fast at the second last element
            // we'll try to reverse the second half of the linked list
        }
        ListNode* newhead = reverse(slow->next);
        ListNode* first = head;
        ListNode* second = newhead;
        // slow is now at the mid
        while(second != NULL){
            if(first->val != second->val){
                reverse(newhead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverse(newhead); // to maintain the inputted linked list
        return true;
    }
};
