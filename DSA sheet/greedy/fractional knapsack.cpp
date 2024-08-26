// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// this is my initial approach
// class Solution {
//   public:
//     // Function to get the maximum total value in the knapsack.
//     double fractionalKnapsack(int w, Item arr[], int n) {
//         double ratio[n];
//         for(int i=0; i<n; i++){
//             ratio[i] = (double)arr[i].value/(double)arr[i].weight;
//         }
//         multimap<int, Item>m;
//         for(int i=0; i<n; i++){
//             m.insert({ratio[i], arr[i]});
//         }
//         double totalValue = 0.0;

//         for (auto it = m.rbegin(); it != m.rend() && w > 0; ++it) {
//             Item currentItem = it->second;

//             if (currentItem.weight <= w) {
//                 totalValue += currentItem.value;
//                 w -= currentItem.weight;
//             } else {
//                 totalValue += it->first * w;
//                 w = 0;
//             }
//         }
//         return totalValue;
//     }
// };


// nlog n+n
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    public:
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
   // function to return fractionalweights
   double fractionalKnapsack(int W, Item arr[], int n) {

      sort(arr, arr + n, comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {

         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalue;

   }
};
