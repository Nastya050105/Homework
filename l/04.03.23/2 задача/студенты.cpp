#include"real.cpp"

int main()
{
	students mas[10];
	string familia;
	string imya;
	string otchestvo;
	int group;
	double bal;
	int countstudents = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << "input familia" << endl;
		cin >> familia;
		cout << "input imya" << endl;
		cin >> imya;
		cout << "input otchestvo" << endl;
		cin >> otchestvo;
		cout << "input group" << endl;
		cin >> group;
		cout << "input bal" << endl;
		cin >> bal;

		if (bal >= 4.2) {
			mas[countstudents++] = students(familia, imya, otchestvo, group, bal);
		}
	}
	if (countstudents == 0) {
		cout << "this students are stupid" << endl;
		return 0;
	}

	bubblesort(mas, countstudents);
	for (int i = 0; i < countstudents; i++) {
		mas[i].getINFO();
	}
 
}
