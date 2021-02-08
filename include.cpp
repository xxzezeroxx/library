#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double EPS = 1e-9;
const ll mod = 1000000007;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)

int main(){
   int n;
   cin >> n;
   double x = n/(1.08);
   cout << fixed << setprecision(0) << x << endl;

    return 0;
}
