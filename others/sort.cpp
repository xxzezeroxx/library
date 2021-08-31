#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
vector<int> v(5);
vector<pair<string,int>> w;

bool compair(pair<string,int> a,pair<string,int> b){
    if (a.second != b.second) return a.second > b.second;//降順
    else return a.first < b.first;//昇順
}

bool less_mod5(int lhs, int rhs) {
  if ((lhs - rhs) % 5 != 0)
    return lhs % 5 < rhs % 5;
  else // 5で割った余りが等しいなら普通に大小比較する
    return lhs < rhs;
}


void disp(){
    for (int i=0;i < 5; i++){
        cout << v[i]  << " ";
    }
    cout << endl;
}
void d(){
    for (auto e:w){
        cout << e.first << " " << e.second << endl;
    }

}

int main(){
  pair<string,int> p;
  w.push_back(make_pair("tourist",4100));
  w.push_back(make_pair("zezero",419));
  w.push_back(make_pair("beet",2400));
  w.push_back(make_pair("beeet",82));
  for (int i=0;i < 5;i++){
      v[i] = i+1;
  }
  sort(v.begin(),v.end(),greater<int>());//降順
  disp();// 5 4 3 2 1
  sort(v.begin(),v.end());
  disp();// 1 2 3 4 5 
  sort(v.begin(),v.end(),less_mod5);
  disp();// 5 1 2 3 4 
  d();
  printf("===============\n");
  sort(w.begin(),w.end());
  d();
  printf("===============\n");
  sort(w.begin(),w.end(),compair);
  d();
  /*tourist 4100
    beet 2400
    zezero 419
    beeet 82
  */
  return 0;
}

