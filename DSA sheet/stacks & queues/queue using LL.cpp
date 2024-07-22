void MyQueue:: push(int x)
{
    QueueNode* el = new QueueNode(x);
    if(front == nullptr){
        front = el;
        rear = el;
    }
    else{
        rear->next = el;
        rear = rear->next;
    }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front == NULL) return -1;
    int y = front->data;
    QueueNode *temp = front;
    front = front->next;
    delete(temp);
    return y;
}
