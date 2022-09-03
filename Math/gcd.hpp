template <typename T>
T GCD(T a, T b){//gcd a>b lcm(a,b)=a*b/gcd(a,b) ... a*b=gcd(a,b)*lcm(a,b)
    return b ? GCD(b,a%b):a; 
}