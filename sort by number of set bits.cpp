// leetcode question
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>> m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int x = arr[i];
            int ans=0;
            while(arr[i]){
                arr[i] = arr[i]&(arr[i]-1);
                ans++;
            }
            m[ans].push_back(x);
            //map is created
        }
        vector<int>answer;
        for(auto it = m.begin(); it!=m.end(); it++){
            auto list = it->second;
            sort(list.begin(), list.end());
            for(auto &val: list){
                answer.push_back(val);
            }
        }
        return answer;
        
    }
};
