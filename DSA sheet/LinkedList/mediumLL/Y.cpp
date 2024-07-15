// count length of each and the difference is the distance travelled by the longer list
// optimal approach is traversing through the two heads till one of them is at the last 
// whoever reaches last node first direct it towards the other head;
// then move temp2 and do the same then keep moving one and one step till they intersect
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // create a hashmap of the visited nodes
        if(headA == NULL || headB == NULL){
            return NULL;}
            ListNode* temp1 = headA;
            ListNode* temp2 = headB;
            while(temp1 != temp2){
                temp1 = temp1->next;
                temp2 = temp2->next;
                if(temp1 == temp2) return temp1;
                if(temp1 == NULL) temp1 = headB;
                if(temp2 == NULL) temp2 = headA;
            }
        return temp1;
    }
};
