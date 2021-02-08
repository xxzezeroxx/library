#include<iostream>
#include<cstdio>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;

int main(void){
    double pi=3.1415926535898;
    double kilopi=3141.5926525898;
    int a=1;
    int x=1024;

    cout<<"pi---------------"<<endl;
    cout<<"cout "<<pi<<endl;
    cout<<"cout (set(10))"<<std::setprecision(10)<<pi<<endl;
    cout<<"cout (fixed,set(10))"<<std::fixed<<pi<<endl;
    printf("printf %f\n",pi);
    printf("printf (%%.10f) %.10f\n",pi);

    cout<<std::defaultfloat<<std::setprecision(6);
    cout<<endl;

    cout<<"kilopi---------------"<<endl;
    cout<<"cout "<<kilopi<<endl;
    cout<<"cout (set(10))"<<std::setprecision(10)<<kilopi<<endl;
    cout<<"cout (fixed,set(10))"<<std::fixed<<kilopi<<endl;
    printf("printf %f\n",kilopi);
    printf("printf (%%.10f) %.10f\n",kilopi);
    printf("printf(%%06f) %06d\n",a);//0埋め
    printf("printf(%%26f) %26d\n",a);//
    printf("%#xd\n",x);// 16進数
    return 0;
}
// setprecision(10) で１０桁分出力　通常６桁
// cout << fixed << setprecision(10) << ans << endl;
// fix() 小数のみ
// defaultfloat でもとに戻る
// cout << defaultflort << endl;