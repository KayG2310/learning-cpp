// brute force solution tc = 2n, sc = n
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head == NULL || head->next == NULL) return head;
        multiset<int>s;
        Node* temp = head;
        while(temp != nullptr){
            s.insert(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(temp != nullptr){
            for(auto &val : s){
                temp->data = val;
                temp = temp->next;
            }
        }
        return head;
    }
};

// we're gonna use the 3 pointer technique to sort this one
// another solution for tc = 2n, sc = 1
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head == NULL || head->next == NULL) return head;
        int cnt0=0, cnt1=0, cnt2=0;
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data ==0) cnt0++;
            else if(temp->data ==2) cnt2++;
            else cnt1++;
            temp = temp->next;
        }
        temp = head;
        for(int i=0; i<cnt0; i++){
            temp->data = 0;
            temp = temp->next;
        }
        for(int i=0; i<cnt1; i++){
            temp->data = 1;
            temp = temp->next;
        }
        for(int i=0; i<cnt2; i++){
            temp->data = 2;
            temp = temp->next;
        }
        return head;
    }
};

// optimal solution -> we'll have 3 nodes, zerohead, onehead, twohead
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* zerohead = new Node(-1);
        Node* onehead = new Node(-1);
        Node* twohead = new Node(-1);
        Node* zero = zerohead;
        Node* one = onehead;
        Node* two = twohead;
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data ==0){
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->data ==1){
                one->next = temp;
                one = one->next;
            }
            else{
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        head = zerohead->next;
        zero->next = (onehead->next) ? (onehead->next):(twohead->next);
        one->next = twohead->next;
        two->next = nullptr;
        return head;
    }
}
