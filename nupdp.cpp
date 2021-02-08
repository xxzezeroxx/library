#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
int dp[101][101];
int wight[101];
int v[101];
int n,w;


int rec(int i,int j){//O(2^n)
    int res;
    if (i==n){
        res=0;
    }
    else if (j < wight[i]){
        res = rec(i+1,j);

    }
    else {
        res = max(rec(i+1,j),rec(i+1,j-wight[i])+v[i]);
    }
    return res;
}

int rec2(int i,int j){//O(2^n)
    if (dp[i][j] >= 0) return dp[i][j];

    int res;
    if (i==n){
        res=0;
    }
    else if (j < wight[i]){
        res = rec(i+1,j);

    }
    else {
        res = max(rec(i+1,j),rec(i+1,j-wight[i])+v[i]);
    }
    dp[i][j]=res;
    return res;
}

//void zere_one_nap(){
//   for (int i=0;i < 101;i++){
//        for (int j=0;j < 101; j++){
//            dp[i][j]=-1;
//        }
//    }
//}

int main(){
    cin >> n >> w;
    for (int q=0; q < n;q++){
        cin >> wight[q];
        cin >> v[q];
    }
    clock_t start =clock();
    cout << rec(0,w) << endl;
    clock_t end = clock();
    //cout << double(end-start) << endl; 
}

