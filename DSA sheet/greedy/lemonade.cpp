class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>notes = {0,0};
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                notes[0]++;
            }
            else if(bills[i]==10){
                if(notes[0]>=1){
                    notes[0]--;
                    notes[1]++;
                }
                else{
                    return false;
                }
            }
            else{
                // its a 20 note
                if(notes[1] && notes[0]){
                    notes[0]--;
                    notes[1]--;
                }
                else if(notes[0]>=3){
                    notes[0] -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

//linear
