int countNodesinLoop(struct Node *head)
{
    Node* slow = head;
    Node* fast = head;
    int cnt = 0;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow==fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            cnt = 1;
            slow = slow->next;
            while(slow != fast){
                slow = slow->next;
                cnt++;
            }
            break;
        }
    }
    return cnt;
}
