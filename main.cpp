#include "Header.h"
#include <clocale>
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	while (true) {

		setlocale(LC_ALL, "ru");

		ifstream file;
		file.open("tasks.txt", ifstream::in);
		try {
			filePrint(file);
		}
		catch(const runtime_error& e) {
			cout << e.what() << endl;
			break;
		}
			
		file.close();

		cout << endl;
		char dec = {}; //decision
		int i = 0;
		while (dec - '0' > 4 || dec - '0' < 1) {
			if (i > 0) {
				cout << "введите цифру от 1 до 3" << endl;
			}

			cout << "1 - добавить задачу" << endl
				<< "2 - изменить статус задачи" << endl
				<< "3 - удалить задачу из списка" << endl
				<< "4 - сохранить и выйти" << endl;
			cin >> dec;

			i++;
		}

		if (dec == '1') {
			Task* newTask = new Task;
			
			string taskName = "";
			int i = 0;
			cout << "введите название задачи" << endl;
			while (taskName.length() == 0 || taskName.length() > 50) {
				if (i > 0) {
					cout << "введите от 1 до 50 символов" << endl;
				}

				cin >> taskName;
			}

			newTask->name = taskName;
			//has not done
		}

	}
	return 1;
}