#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void use_bs(vector<int> &vec){
    for (int key = 0; key <= 10; ++key) {
        if (binary_search(vec.begin(), vec.end(), key)) {
            cout << key << ": " << "found" << std::endl;
        } else {
            cout << key << ": " << "not found" << std::endl;
        }
    }
}

void use_lb(vector<int> &vec){
    auto position = lower_bound(vec.begin(),vec.end(),3); //vector<int>::iterator
    int idx_lower = position-vec.begin();

    cout << *position << "\n ";//ポインタのようなもの
    cout << idx_lower << endl;//ソート後のインデックスを表示

}

int main(){
    vector<int> vec={3,1,4,6,5};
    // ソート：二分探索はソートされた配列に対して適用する
    sort(vec.begin(), vec.end());  // 1, 3, 4, 5, 6
    // 0 - 10 の整数が vec に含まれているか検索
    //use_bs(vec);
    use_lb(vec);
    int length=distance(vec.begin(),vec.end());
    int len = (vec.begin() - vec.end());
    int len2 = int(vec.rbegin()-vec.rend());
    int len3 = int(vec.end() - vec.begin());
    int len4 = (vec.end()-prev(vec.end()));
    printf("len = %d\n",len);
    printf("len2 = %d\n",len2);
    printf("len3 = %d\n",len3);
    printf("len4 = %d\n",len4);
    printf("len2 = %d\n",len2);
    
    printf("length = %d\n",length);
    return 0;
}
// upper_bound:探索したい値よりも大きい値が現れる
//             最初の位置のイテレータを取得
//lower_bound : 探索したい値以上の値が現れる
//              最初の位置のイテレータを取得
//要素が見つからないとき：配列の末尾イテレータを返す



