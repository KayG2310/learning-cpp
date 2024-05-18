
#include <bits/stdc++.h>
using namespace std;
/* question is monk candy question. Monk finds N bags of candies. Bag Ai contains i candies
he picks up a bag, eats all the candies in it and drops it to the ground. But as soon as he drops the bag,
the number of candies in the bag increase magically. the bag that contained x candies, now contains [x/2] candies
he has to return home in k minutes.
in a single minute, monk can consume all the candies in a single bag. Find maximum number of candies monk can consume(aim)

input - N K
        A1, A2,....
output - print answer to each test case in a new line
*/


// imp to understand that we'll use multisets in this as no. of candies can be the same in two bags

int main() {
    int T;
    cin>>T;
    while(T--){
        long long N,K;
        cin>>N>>K;
        long long sum=0;
        long long k;
        multiset<long long>s;
        for(int i=0; i<N;i++){
            long long candies;
            cin>>candies;
            s.insert(candies);
        }
        for(long long i=0; i<K;i++){
            auto it = s.end();
            it--;
            k = (*it);
            sum+=k;
            s.erase(it);
            s.insert(k/2);
        }
        cout<<sum<<endl;
    }

}
