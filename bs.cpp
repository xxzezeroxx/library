#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

const int INF=1e9+7;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  ll under=0LL;
  ll top=0LL;
  ll ans=0LL;
  for (int i=0;i<n;i++){
    int r=n,l=-1;
    while(r-l > 1){
      int mid=(r+l)/2;
      if (a[mid] >= b[i]){
        r=mid;
      }
      else{
        l=mid;
      }
    }
    top=l+1;
    int ub=n,lb=-1;
    while(ub-lb > 1){
        int mid=(ub+lb)/2;
        if (c[mid] > b[i]){
          ub=mid;
        }
        else{
          lb=mid;
        }
    }
    under=n-ub; 
    ans+=(top*under);
  } 
  cout << ans << endl;
}