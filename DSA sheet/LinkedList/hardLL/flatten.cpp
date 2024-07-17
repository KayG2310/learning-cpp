// extreme naive solution -> traverse through all elements in a LL with its child nodes and put them in an array
//once you have the array, sort it and make a vertical linked list
/*
pseudocode 
arr = []
temp = head;
while(temp != NULL){
  t2 = temp;
  add temp
  while(t2 != NULL){
    add t2->data to arr
    t2 = t2->bottom
  }
  temp = next;
}
sort(arr);
head = convert(arr) and convert function can be created one by one
tc = n*m*2 + (n*m)log(n*m);
*/
// to optimise the above algo, we need to do stuff in place and use advantage of the fact that the vertical nodes are already sorted
// we create a dummy node and keep on adding stuff

/*
pseudcode for 2 such nodes with their child
merge2(list1, list2){
  dummnode = new node(-1);
  res = dummynode;
  while(list1 != NULL && list2 != NULL){
    if(list1->val < list2->val){
      res->child = list1;
      res = list1;
      list 1 next;
    }
    else{
      res->child = list2;
      res = list2;
      list 2 next;
  }
  res next = null;
}
// what if list1 still has some elements left or list2
if(list1) res->child = list1;
same for list 2
  return dummynode->child; tc = n1+n2
  */
// RECURSION BASED CODE
Node* merge(Node* list1, Node* list2){
    Node* dummynode = new Node(-1);
    Node* res = dummynode;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->bottom = list1;
            res = list1;
            list1 = list1->bottom;
        }
        else{
            res->bottom = list2;
            res = list2;
            list2 = list2->bottom;
        }
        res->next = NULL;
    }
    // while loop is over
    if(list1) res->bottom = list1;
    else res->bottom = list2;
    if(dummynode->bottom) dummynode->bottom->next = NULL;
    return dummynode->bottom;
}

Node *flatten(Node *head) {
    if(head == NULL || head->next == NULL) return head;
    // above was our base condition
    Node* mergehead = flatten(head->next);
    head = merge(head, mergehead);
    return head;
}
