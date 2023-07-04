#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>


using namespace std;

struct Point {
	
	double x;

	double y;
};
struct Line {
	
	double a;

	double b;

	double c;
};

Line makeLine(const Point& p1, const Point& p2) {
	double a = p2.y - p1.y;
	double b = p1.x - p2.x;
	double c = p1.y * p2.x - p1.x * p2.y;
	double d = sqrt(a * a+ b* b);
	return Line{ a / d,b / d,c / d };
}
double distance(const Line& line, const Point& p) {
	return abs(line.a * p.x + line.b * p.y + line.c);
}

double getMaxDistance(const double x, const double y, const vector<Line>& lines) {
	Point p{ x,y };
	double dist = distance(lines[0], p);
	for (const Line& line : lines) {
		dist = max(dist, distance(line,p));
	}
	return dist;
}

double getMinDistance(const double x, const double y, const vector<Line>& lines) {
	Point p{ x,y };
	double dist = distance(lines[0], p);
	for (const Line& line : lines) {
		dist = min(dist, distance(line,p));
	}
	return dist;
}

double getMin(const double x, const vector<Line> &lines,double &y) {
	double minY = -1000;
	double maxY = 1000;
	for (int i = 0; i < 100; i++) {
		double minY1 = (minY * 2 + maxY) / 3;
		double maxY1 = (minY + maxY * 2) / 3;
		if (getMaxDistance(x, minY1, lines) < getMaxDistance(x, maxY1, lines)) {
			maxY = maxY1;
		}
		else {
			minY = minY1;
		}
	}
	y = (minY + maxY) / 2;
	return getMaxDistance(x, y, lines);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<Point> p(n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &p[i].x, &p[i].y);
	}
	vector<Line>lines(n);
	for (int i = 0; i < n; i++) {
		lines[i] = makeLine(p[i], p[(i + 1) % n]);
	}
	double minX = -1000;
	double maxX = 1000;
	for (int i = 0; i < 100; i++) {
		double minX1 = (minX * 2 + maxX) / 3;
		double maxX1 = (minX + maxX * 2) / 3;
		double ignor;
		if (getMin(minX1, lines, ignor) < getMin(maxX1, lines,ignor)) {
			maxX = maxX1;
		}
		else {
			minX = minX1;
		}

	}
	double x = (minX + maxX) / 2;
	double y;
	double minD= getMin(x, lines, y);
	double maxD = getMaxDistance(x,y,lines);
	const double EPS = 1e-13;
		if (maxD * (1 - EPS) <= minD && minD <= maxD * (1 + EPS)){
			printf("YES\n");
			printf("%.3f %.3f %.3f",(int)round(x*1000)/1000.0, (int)round(y * 1000) / 1000.0,maxD);
		}else {
			printf("NO");

	}
	return 0;
}