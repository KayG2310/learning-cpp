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


// optimal nlog k (same as divide and conquer) 
#define pii pair<int, ListNode*>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pii, vector<pii>, greater<pii>>minheap;
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        int n = lists.size();
        for(int i=0; i<n; i++) if(lists[i]) minheap.push({lists[i]->val, lists[i]});
        while(!minheap.empty()){
            head->next = minheap.top().second; 
            head = head->next; 
            minheap.pop();
            if(head->next){
                minheap.push({head->next->val, head->next});
            }
        }
        return dummy->next;
    }
};
