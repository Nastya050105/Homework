#include "first.cpp"


// функция для второй задачи
void secondFile() {
	cout <<"Вывод статической глобальной переменной из второго файла " << secondJob << endl;
}


// функция для третьей задачи
void thirdJob() {
	thirdJob1 = 1;
	thirdJob2 = 2;
	cout << "Третья задача " << thirdJob1 << " " << thirdJob2;
}

int main()
{
	setlocale(LC_ALL, "ru");


	// первая задача
	cout <<"Вывод глобальной переменной из второго файла " << firstJob << endl;;

	// вторая задача
	firstFile();
	secondFile();

	//третья задача
	thirdJob();
}

