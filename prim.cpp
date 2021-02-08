  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>
  #include <utility>
  using namespace std;
  typedef long long ll;
  #define rep(i,n) for (int i=0;i < (int)(n);i++)
  const int INF = 1e9+7;
  int cost[301][301];
  int mincost[301];
  bool used[301];
  int V;

  ll prim(){
    for (int i = 0;i < V;i++){
      mincost[i] = INF;
      used[i] = false;
    }
    mincost[0] = 0;
    ll res = 0;

    while(1){
      int v  = -1;
      for (int u = 0;u < V;u++){
        if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
      }
      if (v == -1) break;
      used[v] = true;
      res+=mincost[v];
      for (int u = 0;u < V;u++){
        mincost[u] = min(mincost[u],cost[v][u]);
      }
      rep(i,V){
        if (used[i]) cout << 1;
        else cout << 0;
      }
      cout << endl;
      for(int i = 0;i < V;i++){
        cout << mincost[i] << " ";
      }
      cout << endl;
    }
    return res;
  }

  int main(){
    cin >> V;
    rep(i,V){
      rep(j,V){
        cin >> cost[i][j];
        if (i == j) cost[i][j] == INF;
      }
    }
    ll ans;
    ans  = prim();
    //rep(i,V) cout << mincost[i] << " ";
    cout << ans << endl;



      
}
