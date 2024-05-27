/*
#include<bits/stdc++.h>
using namespace std;

void flip(vector <int> &v,int n){
    for(int i=0;i<n;i++){
        v[i]=1-v[i];
    }
}

int matrixScore(vector<vector<int>> grid) {
    int m = grid.size(); //rows
    int n = grid[0].size(); //columns
    for(auto &x: grid){
        if (x[0]==0){
            for(int i=0;i<n;i++){
                x[i]=1-x[i];
            }
        }
    }
    
    
    for(int i=0;i<n;i++){
        int count = 0;
        for(auto x:grid){
            if(x[i]==1) count++;
        }
        if (count<=m/2){
            for(auto &x:grid){
                x[i]=1-x[i];
            }
        }
    }
    int score=0;
    for(auto x:grid){
        for(int i=0;i<n;i++){
            score+=x[i]*(1<<(n-1-i));
        }
    }
    return score;
}
*/


#include<bits/stdc++.h>
using namespace std;

int matrixScore(vector<vector<int>> grid) {
    // we receive a grid in here
    // eg = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
    // [[1,1,0,0],[1,0,1,0],[1,1,0,0]] done
    // [[1,1,1,0],[1,0,0,0],[1,1,1,0]]
    // making last column all 1
    // [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
    int number_of_rows = grid.size();
    int number_of_columns = grid[0].size();
    
    // we can potentially make a bigger number if the starting bits are 1 as that would mean a bigger number
    for( auto &one_row:grid){
        // one_row contains each row
        if (one_row[0]==0){
            for(int i = 0; i< number_of_columns; i++){
                // iterating through the row
                one_row[i] = 1 - one_row[i];
                // makes 0s to 1s and 1s to zero
                // followed the example transformation 1
            }
        }
    } // converted all rows to starting with 1s
    
    // now we convert those columns who have more than have the values 0
    for(int j = 0; j< number_of_columns;j++){
        int zeros = 0;
        // we go through rows and jth column
        for(auto &one_row: grid){
            if(one_row[j]==0){
                zeros++;
            }
        }
        // we get total number of zeros in a j column
        if(zeros>number_of_rows/2){
            // we gotta convert those zeros to 1
            for(auto &one_row: grid){
                one_row[j] = 1 - one_row[j];
            }
        }
        
        }
        
    // now we just have to calculate the score
    int score = 0;
    for(auto &one_row: grid){
        for(int m=0; m<number_of_columns; m++){
            score = score + one_row[m]*pow(2, number_of_columns - 1-m);
        }
    }
    return score;
    }
    

int main(){
    vector<vector<int>> v = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout<< matrixScore(v);
}
