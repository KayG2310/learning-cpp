// optimal pge tc = 2n, sc = 2n
 class StockSpanner {
public:
    stack<pair<int,int>>st;
    int InitialIndex = -1;
    StockSpanner() {
        InitialIndex = -1;
        while(!st.empty()) st.pop();
    }
    
    int next(int price) {
        // now that we have an element, can increase the ind
        InitialIndex +=1;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans = InitialIndex - (st.empty() ? -1 : st.top().second);
        st.push({price, InitialIndex});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// brute force, tc = no. of calls ^2
class StockSpanner {
public:
    vector<int>v;
    StockSpanner() {
        v = {};
        // it should always be reinitialised
    }
    
    int next(int price) {
        v.push_back(price);
        int cnt = 1;
        for(int i=v.size()-2; i>=0; i--){
            if(v[i]<=price) {cnt++; continue;}
            else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
