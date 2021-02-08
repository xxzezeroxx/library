#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

char maze[51][51];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int d[51][51];

int sx,sy,gx,gy,h,w;

void input(){
  cin >> h >> w >> sx >> sy >> gx >> gy;
  for (int i=0; i < h; i++){
    for (int j=0; j < w;j++){
      cin >> maze[i][j];
    }
  }
  for (int i=0;i < h;i++){
      for (int j= 0; j < w;j++) d[i][j] = -1;
  }
}

int bfs(){
  queue<pair<int,int>> q;
  pair<int,int> p;
  p=make_pair(sx,sy);
  q.push(p);
  d[sx][sy]=0;
  while (!q.empty()){
    pair<int,int> e=q.front();q.pop();
    if(e.first==gx && e.second==gy) break;
    for (int i=0; i< 4;i++){
      int nx,ny;
      nx=e.first+dx[i];
      ny=e.second+dy[i];
      if (0 <= nx && nx < h && 0 <= ny && ny < w && maze[nx][ny]!='#' && d[nx][ny]==-1){
          pair<int,int> next;
          next=make_pair(nx,ny);
          q.push(next);
          d[nx][ny]=d[e.first][e.second]+1;
      }
    }
  }
  return d[gx][gy];
}
int main(){
  input();
  sx--;sy--;gy--;gx--;
  int res=bfs();
  cout << res << endl;
  
  return 0;
}