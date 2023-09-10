//len -> std::abs(point)
// theta = std::arg(point) = atan2(point.real(),point.image) => [-pi,+pi]
// define PI
// a dot b = |a||b|cos(theta)
// using Point = complex<double>
inline double dot(const Point &a, const Point &b){
    return a.real() * b.real() + a.imag() * b.imag();
}
// a cross b = |a||b|sin(theta)
inline double cross(const Point &a, const Point &b){
    return a.real() * b.imag() - a.imag() * b.real();
}

inline Point rotate(const Point &p, const double &theta){
    return Point(cos(theta) * p.real() - sin(theta) * p.imag(),
                 sin(theta) * p.real() + cos(theta) * p.imag());
}

inline double Radian2Degree(const double &radian){return radian * 180.0 / PI;}
inline double Degree2Radian(const double &Degree){return Degree * PI / 180.0;}
