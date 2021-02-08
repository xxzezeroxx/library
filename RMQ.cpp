#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RMQ {
public:
	vector<long long> dat;
	const long long MAX_VAL = (1LL << 31) - 1;
	int bekisize;

	RMQ(int sz) {
		bekisize = 1;
		while (bekisize < sz) bekisize *= 2;
		dat.resize(2 * bekisize - 1);
		for (int i = 0; i < 2 * bekisize - 1; i++) dat[i] = MAX_VAL;
	}

	int datsize() {
		return bekisize;
	}

	void update(int k, long long a) {
		k += (bekisize - 1);
		dat[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	//intial k=0,l=0,r=bekisize
    //call [a,b) getmin(a,b) 
	long long getmin(int a, int b, int k=0, int l=0, int r = -1) {
		if (r == -1) r = bekisize;
		if (r <= a || b <= l) return MAX_VAL;
		if (a <= l && r <= b) return dat[k];
		else {
			long long vl = getmin(a, b, k * 2 + 1, l, (l + r) / 2);
			long long vr = getmin(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}
};



int main() {
	int n, q;
	cin >> n >> q;
	RMQ seg(n);
	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 0) {
			seg.update(x, y);
		}
		else {
			cout << seg.getmin(x, y + 1) << endl;
		}
	}
	return 0;
}
