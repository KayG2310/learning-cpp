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
    ListNode* oddEvenList(ListNode* head) {
        vector<int>odd,even;
        ListNode* temp = head;
        int i=1;
        while(temp != nullptr){
            if(i%2==1){
                odd.push_back(temp->val);
            }
            else{
                even.push_back(temp->val);
            }
            temp = temp->next;
            i++;
        }
        temp = head;
        while(temp != nullptr){
            int i=0;
            while(i<odd.size()){
                temp->val = odd[i];
                i++;
                temp = temp->next;
            }
            i=0;
            while(i<even.size()){
                temp->val = even[i];
                i++;
                temp = temp->next;
            }
        }
        return head;    
    }
};

// optimal to reduce sc to O(1), oddhead = head, evenhead = head->next
ListNode *SegregatetoOddEVen()
{
    // creating Heads of Odd and Even LinkedLists
    ListNode *oddHead = new ListNode(-1), *oddTail = oddHead;
    ListNode *evenHead = new ListNode(-1), *evenTail = evenHead;
    ListNode *curr = head, *temp;
    while (curr)
    {
        // Breaking the Link of the curr Node.
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        if (temp->val & 1) // If odd Node,append to odd LinkedList
        {
            oddTail->next = temp;
            oddTail = temp;
        }
        else // If Even Node,append to even LinkedList
        {
            evenTail->next = temp;
            evenTail = temp;
        }
    }
    evenTail->next = oddHead->next; 
    // Appending Odd LinkedList at end of EvenLinkedList
    return evenHead->next;
} 
