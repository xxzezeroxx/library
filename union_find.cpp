#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

class union_find {
public:
vector<int> par,rank,lsize;
union_find(int n): par(n),rank(n),lsize(n){
   for (int i=0;i < n;i++){
      par[i]=i;
      rank[i]=0;
      lsize[i]=1;
   }
}

int find(int x){
   if (par[x]==x){
      return x;
   }
   else{
      return par[x] = find(par[x]); 
   }
}

void unite(int x ,int y){
   x=find(x);
   y=find(y);
   if (x==y) return;
   if (rank[x] < rank[y]){
      lsize[y] += lsize[x];
      lsize[x] = -1;
      par[x] = y;
   }else{
      lsize[x] += lsize[y];
      lsize[y] = -1;
      par[y]=x;
      if (rank[x]==rank[y]) rank[x]++;
   }   
}

bool same(int x, int y){
   return find(x) == find(y);
}

int size(int x){
   if (lsize[x] == -1){
      x=find(x);
   }
   return lsize[x];
}

int groups(){
   int res = 0;
   for (int i = 0;i < par.size();i++){
      if (i == par[i]) res++;
   }
   return res;
}

};

vector<int> ans(100010);
int main(){
      int n,q;
      cin >> n >> q;
      union_find tree(n+1);
      int id=0;
      rep(i,q){
         int c,x,y;
         cin >> c >> x >> y;
         if (c==0){
            tree.unite(x,y); 
         }
         else{
            ans[id]=tree.same(x,y);
            id++;
         }
      }
      rep(i,id){
         cout << ans[i] << endl;
      }
   return 0;
}
