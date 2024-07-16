class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // eg 1 2 3 4
        // k = 5-1 = 4
        vector<pair<int,int>> ans;
       //unordered_map<int,int>m;
       Node* start = head;
       Node* end = head;
       while(end->next != nullptr){
           end = end->next;
       }
       while(start != nullptr && end != nullptr && start != end && start->prev != end){
           if(start->data + end->data == target){
               ans.push_back({start->data, end->data});
               start = start->next;
               end = end->prev;
           }
           else if(start->data + end->data <= target){
               start = start->next;
           }
           else{
               end = end->prev;
           }
       }
       return ans;
    }
};
// above is tc of 2n
