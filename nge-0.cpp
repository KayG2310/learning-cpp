/*
question link - https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbVRORFF4bUtLS0JReFBCZDNwNXJJeHRKc0VxZ3xBQ3Jtc0tsWWdrbG91NmhCWmpZMXVZNjV4YXAwMU81cWVCcWhmVUp0ZTJrck9uSkFxV3ZsMnFfTjRveVFPQV94d2NwT1UwYTdTdzY2UWduVkFjLXNzcVNHYldhYm1wUDB1a195NnJ5N3FKQkhCbXpJX1ZjeGVsdw&q=https%3A%2F%2Fwww.hackerrank.com%2Fcontests%2Fsecond%2Fchallenges%2Fnext-greater-element%2Fproblem&v=T-E3hWEPWWU
*/

#include<bits/stdc++.h>
using namespace std;
// we will create a map of number of elements n, where each number's nge will be mapped to itself
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n;i++){
        cin>>v[i];
    }
    
    unordered_map<int, int>m2;
    stack<int>st;
    
    for(int j=0; j<n; j++){
        
        if(st.empty())
        {st.push(v[j]);} 
        
        else{
            // 4 5 2 25 7 8
            // 4 gets pushed, moving to 5
            // 5 goes to else, satisfies while, {4,5}
            // stack now has 5, moving to 2
            // 2 not while gets pushed, stack is now 2 5, moving to 25
            // 25 goes to else, is bigger to both 5 and 2 and should be in map {4,5}, {2,25}, {5,25} while breaks, 25 gets pushed
            // going to 7, it goes to else goes to while doesn't satisfy gets pushed stack is 7 25
            // goes to 8 
            // else, while {4,5}, {2,25}, {5,25}, {7,8} 
            // stack is 8 25 , we exit for loop
            while(!st.empty() && v[j]> st.top() ){
                m2.insert({st.top(), v[j]});
                st.pop();
            }
            st.push(v[j]);
        } // end of else
    } // end for loop
        while(!st.empty()){
            m2.insert({st.top(), -1});
            st.pop();
        }
        // now our map is ready, we now display it in the way we want
        int count = 0;
        int i=0;
        while(count<n){
            auto it = m2.find(v[i]);
            cout<<it-> first << " " << it-> second<<endl;
            count++;
            i++;
        }
        
    
    
}
