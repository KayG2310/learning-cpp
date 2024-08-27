class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        int one = 0, two = 0, five = 0, ten = 0, twenty = 0, fifty = 0, hund = 0, twoh = 0, fiveh = 0, twok = 0;
        twok = N/2000;
        N = N%2000;
        fiveh = N/500;
        N = N%500;
        twoh = N/200;
        N = N%200;
        hund = N/100;
        N = N%100;
        fifty = N/50;
        N = N%50;
        twenty = N/20;
        N = N%20;
        ten = N/10;
        N = N%10;
        five = N/5;
        N = N%5;
        two = N/2;
        N = N%2;
        one = N/1;
        for(int i = 0; i<twok; i++){
            ans.push_back(2000);
        }
        for(int i = 0; i<fiveh; i++){
            ans.push_back(500);
        }
        for(int i = 0; i<twoh; i++){
            ans.push_back(200);
        }
        for(int i = 0; i<hund; i++){
            ans.push_back(100);
        }
        for(int i = 0; i<fifty; i++){
            ans.push_back(50);
        }
        for(int i = 0; i<twenty; i++){
            ans.push_back(20);
        }
        for(int i = 0; i<ten; i++){
            ans.push_back(10);
        }
        for(int i = 0; i<five; i++){
            ans.push_back(5);
        }
        for(int i = 0; i<two; i++){
            ans.push_back(2);
        }
        for(int i = 0; i<one; i++){
            ans.push_back(1);
        }
        return ans;
    }
};
