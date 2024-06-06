#include<bits/stdc++.h>
using namespace std;


int main(){
    //int t;
    //cin>>t;
    //while(t--){
        
        int n;
        cin>>n;
        vector<int>v1;
        vector<int>v(n);
        for(int i=0; i<n;i++){
            int x;
            cin>>x;
            auto k = find(v1.begin(), v1.end(), x);
            if(k==v1.end()){
                v1.push_back(x);
            }
            
            v[i]=x;
            
        }
        int num1,num2;
        sort(v1.begin(), v1.end());
        num1=v1[0];
        if(v1.size()!=1){
            num2=v1[1];
            // our answer must not be greater than the second smallest number
        // if the diff between it is > 1 
        
        vector<vector<int>>nest;
        auto it1 = find(v.begin(), v.end(), num1);
        int index1 = distance(v.begin(), it1);
        auto it2 = find(v.begin(), v.end(), num2);
        int index2 = distance(v.begin(), it2);
        
        while(it1!=v.end() && it2!=v.end()){
            vector<int>short_array;
           
            
            for(int i=min(index1,index2); i<=max(index1,index2);i++){
                short_array.push_back(v[i]);
            }
            nest.push_back(short_array);
            v.erase(it1);
            v.erase(it2);
            auto it1 = find(v.begin(), v.end(), num1);
            int index1 = distance(v.begin(), it1);
            auto it2 = find(v.begin(), v.end(), num2);
            int index2 = distance(v.begin(), it2);
            // initialising them again
        
        } // end of while loop, nest is created
        vector<int>size;
        for(auto &m:nest){
            size.push_back(m.size());
        }
        for(int y=0; y<nest.size();y++){
            if()
        }
        if(short_array.size()==2){
            cout<<num2-1<<endl;
        }
        else{
            int maxx = *max_element(short_array.begin(), short_array.end());
            cout<<maxx-1<<endl;
        }
        }
        }
        else{
            cout<<0<<endl;
        }
        
            
}
