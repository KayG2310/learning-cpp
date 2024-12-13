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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = lists.size();
        for(int i=0; i<n; i++){
            ListNode* temp = lists[i];
            while(temp != nullptr){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        while(!pq.empty()){
            int x = pq.top();
            ListNode* temp = new ListNode(x);
            pq.pop();
            dummy->next = temp;
            dummy = temp;
        }
        return ans->next;

    }
}; 

// tc = n*len of each*log (total) sc = total els *2
