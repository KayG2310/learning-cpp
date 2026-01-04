using namespace std;
vector‹int › zMatch(string s) { 
    vector‹int› z(s.size(), 0);
    int l = 0, r = 0;
    for (int i = 1; i ‹ s.size(); it+) {
        if (i < r) {
            z［i］= z［i -l］；
            // Handle case of z[i] reaching for characters
            // beyond what we have seen at r
            if (i + z[i] > r) z［i］=r-i；
        }
        while(i+z[i] < s.size() && s[z[i]] == s[i+ z[i]]) z[i]++; // characters matching beyond boundary and then reset boundary 
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
} 

int main(){
    string finall = needle + "$" + haystack; 
    vector<int>zarray = zMatch(finall); 
    // wherever zarray[i] == needle.length() ans 
}
