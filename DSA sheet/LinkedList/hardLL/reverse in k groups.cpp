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
private:
    ListNode* getk(ListNode* temp, int k){
        k-=1;
        while(temp != NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverselinked(ListNode *head){
        ListNode* temp = head;  
        ListNode* prev = NULL;  
        while(temp != NULL){  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = front; 
        }
        return prev;  
    }   

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;
        while(temp != NULL){
            ListNode* kth = getk(temp,k);
            if(kth == NULL){
                if(prevlast) prevlast->next = temp;
                break;
            }
            ListNode* nextnode = kth->next;
            kth->next = NULL;
            reverselinked(temp);
            if(temp==head){
                head = kth;
            }
            else{
                prevlast->next = kth;
            }
            prevlast = temp;
            temp = nextnode;
        }
        return head;
    }
};
/*
dry run 1 2 3 4 5, k=2
output = 21 43 5
temp = 1
prevlast = null
kth = 2->x
reverse = 
*/
