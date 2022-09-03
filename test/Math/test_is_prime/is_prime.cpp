#include <iostream>
using namespace std;

template <typename T>
bool is_prime(T x){
    if (x < 2) return false;
    for (T i = 2; i*i <= x;i++){
        if (x%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    long long x;
    cin >> x;
    cout << is_prime(x) << endl;;
}