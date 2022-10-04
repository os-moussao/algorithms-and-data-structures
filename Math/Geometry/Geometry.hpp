#pragma once

// rectangle class
struct Rect {
	int x1, y1, x2, y2;
	Rect(int x1=0, int y1=0, int x2=0, int y2=0) : x1(x1), x2(x2), y1(y1), y2(y2) {}
	int area() { return w()*h(); }
	int w() { return x2-x1; }
	int h() { return y2-y1; }
	Rect inter(Rect r) {
		int lx, rx, ly, ry;
		lx = max(x1, r.x1), rx = min(x2, r.x2);
		ly = max(y1, r.y1), ry = min(y2, r.y2);
		if (rx>lx && ry>ly) return Rect(lx, ly, rx, ry);
		return Rect();
	}
};


template<class T>
double sqr(const T &x) {
	return x*x;
}

template<class T1, class T2>
double _dist(const T1 &a, const T2 &b) {
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z));
}

// 3d Point/Vector
class Vec {
public:
	double x, y, z;
	Vec(double x=0, double y=0, double z=0) : x(x), y(y), z(z) {}
	Vec(const Vec &v) : x(v.x), y(v.y),z(v.z) {}
	Vec operator + (const Vec &v) { return Vec(x+v.x, y+v.y, z+v.z); };
	Vec operator - (const Vec &v) { return Vec(x-v.x, y-v.y, z-v.z); };
	Vec operator / (double f) { return Vec(x/f, y/f, z/f); };
	double mag() { return _dist(*this, Vec(0,0,0)); }
	Vec unity() { return *this/mag(); }
	Vec operator * (double f) { return Vec(x*f, y*f, z*f); };
	double operator * (const Vec &v) { return x*v.x + y*v.y + z*v.z; } // dot
	Vec normalize() { return *this = unity(); }
};