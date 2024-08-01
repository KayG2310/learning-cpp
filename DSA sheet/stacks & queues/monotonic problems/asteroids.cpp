class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0; i<asteroids.size(); i++){
            if(st.empty()) st.push(asteroids[i]);
            else if(asteroids[i]*st.top()>0){
                // meaning they are travelling in the same direction, they won't collide
                st.push(asteroids[i]);
            }
            else{
                // travelling in opposite directions
                if(st.top()<0 && asteroids[i]>0){
                    // meaning prev one is gone to left and new one is going to right, no collision
                    st.push(asteroids[i]);
                    continue;
                }
                while(!st.empty() && abs(asteroids[i])>abs(st.top()) && asteroids[i]*st.top()<0){
                    st.pop();
                }
                // after this loop ends, either abs asteroids[i] == abs[st.top] or smaller
                // if equal, check for signs
                if(st.empty() || asteroids[i]*st.top()>0) {st.push(asteroids[i]); continue;}
                // stack empty ho gyi toh you just gotta push and move to the next;
                // in case non empty, checking for the above conditions

                // considering abs are equal, there are two cases, the numbers are equal, or they are opposite in signs
                if(abs(asteroids[i])==abs(st.top())){
                    if(asteroids[i]==st.top()){
                        st.push(asteroids[i]);
                        continue;
                    }
                    else{
                        // they are opposite in signs
                        st.pop();
                        continue;
                    }
                }
            }
        }
        vector<int> ans(st.size(),0);
        for(int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
