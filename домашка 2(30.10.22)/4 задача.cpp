#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
using namespace std;

void main()
{
	int a, r;
	cin >> a >> r;
	double a2 = a / 2.;
	double ans;
	if (r <= a2) ans = r * r * 3.1416;
	else if (r > a * sqrt(2) / 2) ans = a * a;
	else {
		double t = 2 * acos(a / 2. / r);
		ans = 3.1416 * r * r - 2 * r * r * (t - sin(t));
	}
	cout << fixed << setprecision(3) << ans;
}