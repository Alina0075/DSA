#include<iostream>
using namespace std;

class shape{
public:
	virtual void area() = 0;
};

class circle :public shape {
private:
	float radius;
public:
	circle(float r) {
		radius = r;
	}
	void area() {
		float a = radius * 3.14;
		cout << "Area of the circle is: " << a << endl;
	}
};

class rectangle :public shape {
private:
	int length;
	int width;
public:
	rectangle(int l, int w) {
		length = l;
		width = w;
	}
	void area() {
		int a = length * width;
		cout << "Area of the rectangle is: " << a;
	}
};
int main() {
	circle c(1);
	c.area();

	rectangle r(2, 2);
	r.area();
	return 0;
}
