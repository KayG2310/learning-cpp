// brute force
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int i = 1;
        ListNode* temp = head;
        while(temp != nullptr){
            i++;
            temp = temp->next;
        }
        temp = head;
        int j=1;
        while(temp != nullptr){
            if(j==((i-1)/2)+1){
                return temp;
            }
            temp = temp->next;
            j++;
        }
        return temp;
    }
};

// two pointer method

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow =head;
        ListNode* fast=head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
