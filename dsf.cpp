#include <algorithm>
#include <vector>
#include <iostream>
int H=100,W=100;
char maze[H][W]; // グリッドグラフ 
vector<vector<int>> G; // グラフ 隣接リスト表現

void putin(){
    int n,m; //n:nodes,m:egdes
    cin >> a >> b;
    G[a].push_back(b);　//　隣接する要素を追加する
    // G[b].push_back(a);　無向グラフ
}
void putin(){//グリッド
    rep(i,h){
        rep(j,w){
            cin >> maze[i][j];
        }
    }
}
void dfs(vector<vector<int>> &G,int v){
    seen[v]=true;
    for (auto x : G[v]){
        if(seen[x]==true) continue;
        (G,x);
    }
}
// DFSは再帰関数またはスタック　stack<int> s
// BFSはqueue<int> q or deque<int> dq (0-1bfs)
