#include <iostream>
#include <vector>
//verify https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
using namespace std;

class Eratosthenes{
public:
    std::vector< bool > prime;

    Eratosthenes(int n){
        prime.resize(n+1,true);
        prime[0] = false;
        prime[1] = false;
	    for(int i = 2; i <= n ; i++){
		    if(prime[i]){
			    for(int j = i+i; j <= n; j+=i){
				    prime[j] = false;
			    }
		    }
	    }
    }
};

int main(){
    Eratosthenes p(100000000);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        if (p.prime[x]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;

}