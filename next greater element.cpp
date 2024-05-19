// solution in video
#include<bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> &v){
    vector<int> nge(v.size());
    stack<int> st;
    for(int i= 0; i<v.size(); i++){
        while(!st.empty() && v[i]>v[st.top()]){
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
    
        
}

int main(){
   int n;
   cin>>n;
   vector<int>v;
   for(int i= 0; i<n; i++){
       
       cin>>v[i];
       
   }
   vector<int> nge = NGE(v);
   for(int i= 0; i<n; i++){
       cout<<v[i]<<" "<<(nge[i] == -1 ? -1 : v[nge[i]])<<endl;
   }
}



/* my idea, don't know what's wrong with it
#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        
        if(st.empty()){st.push(num);}
        else{
            while(true){
                if(num>st.top()){
                     v.push_back(num);
                     st.pop();
                } else{
                    st.push(num);
                    break;
                }
                
            }
            st.push(num);
        }
    }
    
    for(auto &value:v){
        cout<<value<<endl;
    }
} 
*/
