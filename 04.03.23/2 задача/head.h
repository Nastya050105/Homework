#include<iostream>
using namespace std;

class students {
private:
	string f;
	string i;
	string o;
	double bal;
public:
	int group;
	students();
	students(string f, string i, string o, int group, double bal);
	void getINFO();
};

void bubblesort(students *mas, int size);