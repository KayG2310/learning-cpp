class Solution {
public:
    bool rotateString(string s, string goal) {
        int k=1;
        if(s==goal) return true;
        while(k<=s.size()){
            char temp=s[0];
            for(int i=1; i<s.size(); i++){
                s[i-1] = s[i];
            }
            s[s.size()-1]=temp;
            if(s==goal) return true;
            k+=1;
        }
        return false;
    }
};

// above can take O(n2) 0ms on leetcode
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string f=s+s; //abcdabcd
        int found = f.find(goal);
        if(found==-1) return false;
        return true;
    }
};

// optimal, linear
class Solution {
public:
    bool rotateString(string s, string goal) {
    int i=0,j=0;
    int n=s.length();
    int matched=0;
    int k=0;
    while(i<n && j<2*n){
        //cout<<i<<" "<<j<<" "<<matched<<" "<<k<<endl;
        if(s[i]==goal[j%n]){
            i++;
            j++;
            matched++;
            if(matched==1) k=j;
        }
        else{
            if(i==0){
                j++;
            }
            else{
                j=k;
            }
            i=0;
            //j=j+k+1;
            matched=0;
        }
    }
    if(matched==n) return true;
    else return false;
}
};

//s=bbbacddceeb
//g=ceebbbbacdd

//i=0,j=0,n=11,m=0,k=0 ---INITIAL
//i=0,j=1,m=0
//i=0,j=2,m=0
//i=0,j=3,m=0
//i=1,j=4,m=1,k=4
//i=2,j=5,m=2,k=4
//i=3,j=6,m=3,k=4
//i=0,j=4,m=0,k=4
