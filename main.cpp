#include "Header.h"
#include <clocale>
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");

	ifstream file;
	file.open("tasks.txt", ifstream::in);
	filePrint(file); //try - catch
	file.close();

	cout << endl;
	char dec = {}; //decision
	int i = 0;
	while (dec - '0' > 3 || dec - '0' < 1) {
		if (i > 0) {
			cout << "введите цифру от 1 до 3" << endl;
		}

		cout << "1 - добавить задачу" << endl
			<< "2 - изменить статус задачи" << endl
			<< "3 - удалить задачу из списка" << endl;
		cin >> dec;

		i++;
	}
	
	return 1;
}