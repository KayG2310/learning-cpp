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
    int len(ListNode* head){
        int i=1;
        ListNode* temp = head;
        while(temp != nullptr){
            temp = temp->next;
            i++;
        }
        return i-1;
    }
    // 1 2 3 4 5
    // i=1, temp =1
    // while yes, temp = 2, i=2
    // while 2yes, temp = 3, i=3
    //while 3yes, temp4, i=4
    // while 4yes, temp5, i=5
    //while 5yes, temp null, i=6
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int m = len(head); //m=5
        if(m==1 || m==0) return head; //no
        k = k%m;//k=2
        if(k==0) return head; //no
        int nodes_to_be_travelled = m-k; //3
        ListNode* temp = head; //temp = 1
        int i=1;
        while(i < nodes_to_be_travelled && temp != nullptr){
            temp = temp->next;
            i++;
        }
        // LL = 1 2 3 4 5
        // m = 5, k = 2%5 = 2
        // nodes = 3
        // i =1, temp = 1
        // while 1yes, temp = 2, i=2
        // while yes, temp = 3, i=3
        // now temp is at 3
        ListNode* toshift = temp->next; //4 
        temp->next = nullptr;
        ListNode* temp2 = toshift;
        while(temp2 != nullptr && temp2->next != nullptr){
            temp2 = temp2->next;
        }
        // temp2 = 5
        if(temp2)temp2->next = head;
        return toshift;
    }
};

// tc = n, while n-k, tc = 2n, sc=1
