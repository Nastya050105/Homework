#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<functional>


using namespace std;

struct Segment {
	int minX;

	int minY;

	int maxX;

	int maxY;
};

int main() {
	int rectMaxX, rectMaxY;
	scanf(" % d % d", &rectMaxX, &rectMaxY);
	int rectminX = 0;
	int rectMinY = 0;

	int n;
	scanf(" % d", &n);
	vector<Segment>segs;
	for (int i = 0; i < n; i++) {
		int minX, minY, maxX, maxY;
		scanf(" % d % d % d % d", &minX, &minY ,& maxX, &maxY);
		if (minX > maxX) {
			swap(minX, maxX);
		}
		if (minY > maxY) {
			swap(minY, maxY);
		}
		if (minX == maxX && minY == maxY) {
			continue;
		}
		assert((minX == maxX && minY < maxY) || (minX < maxX && minY == maxY));
		segs.push_back(Segment{ minX,minY,maxX,maxY });
	}
	vector<int> xs;
	vector<int> ys;
	xs.push_back(-10001);
	xs.push_back(rectminX);
	xs.push_back(rectMaxX);
	xs.push_back(10001);
	ys.push_back(-10001);
	ys.push_back(rectMinY);
	ys.push_back(rectMaxY);
	ys.push_back(10001);
	for (Segment s : segs) {
		xs.push_back(s.minX);
		xs.push_back(s.maxX);
		ys.push_back(s.minY);
		ys.push_back(s.maxY);
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());

	rectMinX = int(lower_bound(xs.begin(), xs.end(), rectMinX) - xs.begin());
	rectMaxX = int(lower_bound(xs.begin(), xs.end(), rectMaxX) - xs.begin());
	rectMinY = int(lower_bound(ys.begin(), ys.end(), rectMinY) - ys.begin());
	rectMaxY = int(lower_bound(ys.begin(), ys.end(), rectMaxY) - ys.begin());
	assert(rectMinX < rectMaxX);
	assert(rectMinY < rectMaxY);

	for (Segment& s : segs) {
		s.minX = int(lower_bound(xs.begin(), xs.end(), s.minX) - xs.begin());
		s.maxX = int(lower_bound(xs.begin(), xs.end(), s.maxX) - xs.begin());
		s.minY = int(lower_bound(ys.begin(), ys.end(), s.minY) - ys.begin());
		s.maxY = int(lower_bound(ys.begin(), ys.end(), s.maxY) - ys.begin());

	}

	vector<vector<bool>>borderXP(xs.size() - 1, vector<bool>(ys.size() - 1, false));
	vector<vector<bool>>borderXM(xs.size() - 1, vector<bool>(ys.size() - 1, false));
	vector<vector<bool>>borderYP(xs.size() - 1, vector<bool>(ys.size() - 1, false));
	vector<vector<bool>>borderYM(xs.size() - 1, vector<bool>(ys.size() - 1, false));

	for (int x = rectMinX; x < rectMaxX; x++) {
		borderYM[x][rectMinY] = true;
		borderYP[x][rectMinY-1] = true;
		borderYM[x][rectMaxY] = true;
		borderYP[x][rectMaxY-1] = true;
	}
	for (int y = rectMinY; y < rectMaxY; y++) {
		borderXM[rectMinX][y] = true;
		borderXP[rectMinX - 1][y] = true;
		borderXM[rectMaxX][y] = true;
		borderXP[rectMaxX - 1][y] = true;
	}
	for (Segment s : segs) {
		if (s.minX == s.maxX) {
			assert(s.minY < s.maxY);
			for (int y = s.minY; y < s.maxY; y++) {
				borderXM[s.minX][y] = true;
				borderXP[s.minX - 1][y] = true;
			}
		}
		else {
			assert(s.minY == s.maxY);
			assert(s.minX < s.maxX);
			for (int x = s.minY; x < s.maxY; x++) {
				borderYM[x][s.minY] = true;
				borderYP[x][s.minY - 1] = true;
			}
		}
	}
	vector<vector<bool>>painted(xs.size() - 1, vector<bool>(ys.size() - 1, false));
	vector<int>areas;
	for (int x = rectMinX; x < rectMaxX; x++) {
		for (int y = rectMinY; y < rectMaxY; y++) {
			if (!painted[x][y]) {
				int area = 0;
				function<void(const int x, const int y)> paint = [&](const int x, const int y) {
					if (painted[x][y]) {
						return;
					}
					painted[x][y] = true;
					area += (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]);
					if (!borderXP[x][y]) {
						paint(x + 1, y);
					}
					if (!borderXM[x][y]) {
						paint(x - 1, y);
					}
					if (!borderYP[x][y]) {
						paint(x, y + 1);
					}
					if (!borderYM[x][y]) {
						paint(x, y - 1);
					}
				};
				paint(x, y);

				areas.push_back(area);

			}
		}
	}
	sort(areas.rbegin(), areas.rend());
	for (int area : areas) {
		printf("%d\n", area);
	}
}