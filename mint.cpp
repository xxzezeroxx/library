#include <iostream>
#include <vector>
using namespace std;
const long long mod =(1e9)+7LL;
typedef long long ll;
class mint {
public:
	ll x; // typedef long long ll;
	mint(ll x = 0) :x((x%mod + mod) % mod) {}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const {
		mint res(*this);
		return res *= a;
	}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}
	// for prime mod
	mint inv() const {
		return pow(mod - 2);
	}
	mint& operator/=(const mint a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint a) const {
		mint res(*this);
		return res /= a;
	}
};
ostream &operator<< (ostream &os, const mint &obj){
	    os << obj.x;
		return os;
	}

class combination {
public:
	vector<mint> fact, ifact;
	combination(int n) :fact(n + 1), ifact(n + 1) {
		fact[0] = 1;
		for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
		ifact[n] = fact[n].inv();
		for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
	}
	mint operator()(int n, int k) const { //return nCk
		if (k < 0 || k > n) return 0;
		return fact[n] * ifact[k] * ifact[n - k];
	}
	mint p(ll n,ll k) const{ //return nPk
		if (k < 0 || k > n ) return 0;
		return fact[n]*ifact[n-k];
	}
	mint h(ll n,ll k) const { //return n+k-1Ck
		if (k < 0 || k > n) return 0;
		return fact[n+k-1]*ifact[n-1]*ifact[k];
	}
	mint choose(ll n ,ll a) const{// k <= 1e5 n <= 1e9
	    if (a < 0 || a > n) return 0;
		mint x=1,y=1;
		for(ll i=0;i < a; i++){
			x*=n-i;
			y*=i+1;
		}
		return x / y; 
	}
	mint perm(ll n, ll a) const { // k <= 1e5
	if (a < 0 || a > n) return 0;
	   mint x=1,y=1;
	   for (ll i=0;i < a;i++){
		   x*=n-i;
	   }
	   return x;
	}
}comb(100000);

int main(){
	mint r;
	r=2;
	r=r.pow((ll)3);
	cout << r.x << endl;
	mint ca;
	ca=comb(4,2);
	ca=comb.perm(4,2);
	cout << ca.x << endl;
	ca=comb.p(4,2);
	cout << ca.x << endl;
	cout << r << endl;
	ca=comb.fact[10]*comb.fact[100];
	cout << ca << endl;

}