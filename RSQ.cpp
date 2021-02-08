#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RSQ {
    //using 0-indexed!!
public:
	vector<long long> dat;
	const long long MAX_VAL = (1LL << 31) - 1;
	int bekisize;

	RSQ(int sz) {
		bekisize = 1;
		while (bekisize < sz) bekisize *= 2;
		dat.resize(2 * bekisize - 1);
		for (int i = 0; i < 2 * bekisize - 1; i++) dat[i] = 0;
	}

	int datsize() {
		return bekisize;
	}

	void update(int k, long long a) {
		k += (bekisize - 1);
		dat[k] += a;
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
		}
	}
	//intial k=0,l=0,r=bekisize
    //call [a,b) getsum(a,b) 
    //using 0-indexed!!
	long long getsum(int a, int b, int k=0, int l=0, int r = -1) {
		if (r == -1) r = bekisize;
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return dat[k];
		else {
			long long vl = getsum(a, b, k * 2 + 1, l, (l + r) / 2);
			long long vr = getsum(a, b, k * 2 + 2, (l + r) / 2, r);
			return vl + vr;
		}
	}
};



int main() {
	int n, q;
	cin >> n >> q;
	RSQ seg(n);
	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 0) {
            x--;
			seg.update(x, y);
		}
		else {
            x--;
			cout << seg.getsum(x, y) << endl;
		}
	}
	return 0;
}
