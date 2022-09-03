#include <iostream>
#include <cmath>
#include <complex>
using namespace std;
using Point = complex<double>;

const double PI = acos(-1.0);
//len -> std::abs(point)
// theta = std::arg(point) = atan2(point.real(),point.image) => [-pi,+pi]
// define PI
// a dot b = |a||b|cos(theta)
inline double dot(const Point &a, const Point &b){
    return a.real() * b.real() + a.imag() * b.imag();
}
// a cross b = |a||b|sin(theta)
// if a cross b > 0  => 0 < theta < 180 
inline double cross(const Point &a, const Point &b){
    return a.real() * b.imag() - a.imag() * b.real();
}

inline Point rotate(const Point &p, const double &theta){
    return Point(cos(theta) * p.real() - sin(theta) * p.imag(),
                 sin(theta) * p.real() - cos(theta) * p.imag());
}

inline double Radian2Degree(const double &radian){return radian * 180.0 / PI;}
inline double Degree2Radian(const double &Degree){return Degree * PI / 180.0;}


//verify cross https://atcoder.jp/contests/abc266/tasks/abc266_c

int main(){
    Point a,b,c,d;
    double x,y;
    cin >> x >> y;
    a.real(x);
    a.imag(y);
    cin >> x >> y;
    b.real(x);
    b.imag(y);
    cin >> x >> y;
    c.real(x);
    c.imag(y);
    cin >> x >> y;
    d.real(x);
    d.imag(y);
    Point dx1 = c-a;
    Point dx2 = d-a;
    Point dy2 = b-a;
    if (cross(b-a,d-a) > 0 && cross(c-b,a-b) > 0 && cross(d-c,b-c) > 0 && cross(a-d,c-d) > 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}