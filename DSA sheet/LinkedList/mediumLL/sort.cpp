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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        multiset<int>nos;
        ListNode* temp = head;
        while(temp != nullptr){
            nos.insert(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != nullptr){
            for(auto &val: nos){
                temp->val = val;
                temp = temp->next;
            }
        }
        return head;
    }
};


// optimal code
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
    ListNode* findmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge2(ListNode* list1, ListNode* list2) {
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next; // Update temp to the next node
        }
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        ListNode* result = dummynode->next;
        delete dummynode; // Free the dummy node
        return result;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* middle = findmiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;
        left = sortList(left);
        right = sortList(right);
        return merge2(left, right);
    }
};
