class MyStack {
  private:
    StackNode *head;

  public:
    void push(int x) {
        StackNode* el = new StackNode(x);
        if(head == nullptr) {head = el;}
        else{ el->next = head;
        head =el;
        }
    }

    int pop() {
        if(head==NULL ) return -1;
        int y = head->data;
        StackNode *temp = head;
        head = head->next;
        delete(temp);
        return y;
    }

    MyStack() { head = NULL; }
};
