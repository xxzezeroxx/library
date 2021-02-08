#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class dijkstra{
public:
struct edge{int to,cost;};
const int MAX_V = 100001;
vector< vector<edge> > G;
int d[100001];
int V = 0;
priority_queue < pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > que;
const int Inf = 1 << 30;

    dijkstra(int v){
        fill_n(d,v,Inf);
        //d.resize(v,Inf);
        G.resize(v);
        V = v;
    };

    void input(int r){
        for(int i = 0;i < r;i++){
            int x,y,z;
            cin >> x >> y >> z;
            edge e;
            e.to = y; e.cost = z;
            G[x].push_back(e);
            //printf("(x,y,z) =(%d,%d,%d)\n",x,y,z);
        }
    }
    void discover(int s){
        d[s] = 0;
        que.push({0,s});
        while(!que.empty()){
            pair<int,int> p = que.top();que.pop();
            int v = p.second;
            if (d[v] < p.first) continue;
            for (int i=0;i < G[v].size();i++){
                edge e=G[v][i];
                if (d[e.to] > d[v]+ e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push({d[e.to],e.to});
                }
            }
        }
        for (int j=0;j < V;j++){
            if (d[j] == Inf) cout << "INF" << endl;
            else cout << d[j] << endl;
        }

    }
};

int main(){
    int t,e,r;
    cin >> t >> e >> r;
    dijkstra pass(t);
    pass.input(e);
    pass.discover(r);
}