/*
逆元の求め方（合成数）
ax + bM = 1 <=> ax = 1 mod M 
x が逆元となる
x は負となる可能性あり
extgcd(a,m,x,y)　
*/

template<typename T >
T extgcd(T a, T b, T &x, T &y){
  if (b == 0){
    x = 1;
    y = 0;
    return a;
  }
  T d = extgcd(b,a%b,y,x);
  y -= a/b*x;
  return d;
}
