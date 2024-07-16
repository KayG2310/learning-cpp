class Solution
{
public:
    Node* removeDuplicates(Node* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node* temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            Node* nextnode = temp->next;
            
            while (nextnode != NULL && nextnode->data == temp->data)
            {
                Node* dup= nextnode;
                nextnode = nextnode->next;
                free(dup);
                
            }
            temp->next = nextnode;
            if(nextnode != NULL) nextnode->prev = temp;
            temp = temp->next;
        }
        return head;
    }
};
