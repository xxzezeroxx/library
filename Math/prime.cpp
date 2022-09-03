#include <iostream>
#include <math.h>
#include <time.h>
#include <map>
#define N 100000
using namespace std;

int arr[N];
bool prime[N];

//エラトステネスの篩
void Eratosthenes(){
	for(int i = 0; i < N; i++){
		arr[i] = 1;
    }
	for(int i = 2; i < sqrt(N); i++){
		if(arr[i]){
			for(int j = 0; i * (j + 2) < N; j++){//jはｊ回目のiの倍数
				arr[i *(j + 2)] = 0;
			}
		}
	}

	for(int i = 2; i < N; i++){
		if(arr[i]){
			cout << i << endl;
		}
	}
}
// 愚直
void normal(){
	for(int i = 1; i <= N; i++){
		int count = 0;
		for(int j = 1; j <= i; j++){
			if(i % j == 0){
				count++;
			}
			if(count > 2){
				break;
			}
		}
		if(count == 2){
			cout << i << endl;
		}
	}
}

int GCD(int a, int b){//gcd a>b lcm(a,b)=a*b/gcd(a,b) ... a*b=gcd(a,b)*lcm(a,b)
    return b ? GCD(b,a%b):a; 
}

long long extgcd(long long a, long long b, long long &x, long long &y){
  if (b == 0){
    x = 1;
    y = 0;
    return a;
  }
  long long d = extgcd(b,a%b,y,x);
  y -= a/b*x;
  return d;
}
/*
逆元の求め方（合成数）
ax + bM = 1 <=> ax = 1 mod M 
x が逆元となる
x は負となる可能性あり
extgcd(a,m,x,y)　
*/

map<long long,int> prime_factor(long long n){
	 map<long long,int> ret;
	 for (long long i=2LL ;i*i <= n;i++){
		 while(n%i==0){
		 	if (n%i==0){
				 ret[i]++;
				 n/=i;
		 	}
		 }
	 }
	 if (n != 1) ret[n]=1;
	 return ret;
}

//素数
int main(int argc, char const *argv[]){
	clock_t start = clock();
	//normal();
	clock_t end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
	cout << "Eratosthenes" << endl;
	start = clock();
	Eratosthenes();
	end = clock();
	//cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    //cout << gcd(32,8) <<endl; 
	return 0;
}

// sn=sqrt(n)まででよいとは？
// n=pqとすると p <= sn q <= sn p < q　としたら　snまで調べればおけ 

