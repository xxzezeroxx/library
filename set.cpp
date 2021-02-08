#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  map<int,string> m;
  map<string,int> n;
  set<int> st;
  queue<int> q;
  priority_queue<int> pq;
  q.push(10);
  q.push(9);
  q.push(6);
  pq.push(10);
  pq.push(5);
  pq.push(120);
  m[34]="kenko";
  m[74]="satosi";
  m[54]="dai";
  n["a"]=10;
  n["b"]=12;
  cout << n["a"] << endl;
  cout << n["c"] << endl; 
  cout << m[34] << endl;
  cout << m[0] << endl;//make empty string
  printf("----------------\n");
  cout << n.count("a") << endl;// count(key) find key
  cout << n.count("z") << endl;
  printf("====================\n");
  for (auto w: m){
      cout << w.first << " " << w.second << endl;
  }
  for (auto q: n){      
      cout << q.first << " " << q.second << endl;
  }
  st.insert(1);//insert(val)
  st.insert(2);
  st.insert(3);
  st.insert(3);
  auto itr=st.begin();
  cout << *itr << endl;
  itr=st.end();
  cout << *itr << endl;
  st.erase(3);
  itr=st.begin();
  printf("-------------------\n");
  while(itr !=st.end()){
      cout << *itr << endl;
      itr++;
  }
  rep(i,3){
      cout << q.front() << endl; q.pop();
  }
  rep(i,3){
      cout << pq.top() << endl; pq.pop();
  }

  return 0;
}

