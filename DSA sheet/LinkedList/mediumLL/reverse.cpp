// using stacks - tc = 2n, sc = n
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int>els;
        ListNode* temp = head;
        while(temp != nullptr){
            els.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != nullptr){
            temp->val = els.top();
            els.pop();
temp = temp->next;
        }
        return head;
    }
};

// in  place to optimise this, play around with the links, tc=n, sc=1

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;

    }
};

// recursive approach, tc = n, sc=n
Node* reverse_recursion(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* newhead = reverse_recursion(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}

