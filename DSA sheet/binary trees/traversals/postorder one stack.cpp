while(cur != NULL || !st.empty()){
  if(cur != NULL) {
    st.push(cur);
    cur = cur->left;
  }
  else{
    temp = st.top()->right;
    if(temp == NULL){
      temp = st.top();
      st.pop();
      ans.push_back(temp->val);
      while(!st.empty() && temp == st.top()->right){
        temp = st.top(); st.pop();
        ans.push_back(temp->val);
      }
    }
    else cur = temp;
  }
}
