// reverse the LL, add 1 with the carry over concept, then reverse again
// if we don't want to reverse, but have to backtrack, we choose recursion
class Solution
{
    private:
        int helper(Node* temp){
            if(temp==NULL){
                return 1;
            }
            int carry = helper(temp->next);
            temp->data = temp->data + carry;
            if(temp->data <10 ) return 0;
            temp->data = 0;
            return 1;
        }
    public:
        Node* addOne(Node *head) 
        {
            int carry = helper(head);
            if(carry == 1){
                Node* newnode = new Node(1);
                newnode->next = head;
                head = newnode;
            }
            return head;
        }
// 1->2->9
/*
head = 1, carry = helper(1)
inside helper, carry = helper(2)
                carry = helper(9)
                
*/
};
