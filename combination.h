class combination {
public:
	vector<mint> fact, ifact;
	combination(int n) :fact(n + 1), ifact(n + 1) {
		fact[0] = 1;
		for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
		ifact[n] = fact[n].inv();
		for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
	}
	mint operator()(int n, int k) const {
		if (k < 0 || k > n) return 0;
		return fact[n] * ifact[k] * ifact[n - k];
	}
	mint p(ll n,ll k) const{
		if (k < 0 || k > n ) return 0;
		return fact[n]*ifact[n-k];
	}
	mint h(ll n,ll k) const {
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
}comb(100000);// plsese mint control!