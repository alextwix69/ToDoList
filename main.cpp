#include "Header.h"
#include <clocale>
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	
	ToDoList* list = new ToDoList;

	ifstream file;
	file.open("tasks.txt", ifstream::in);
	try {
		filePrint(file);
	}
	catch(const runtime_error& e) {
		cout << e.what() << endl;
	}
			
	file.close();

	char dec = choose();

	if (dec == '1') {
		Task* newTask = new Task;
		setName(newTask);
		list->addTask(newTask);
	}
	
	return 1;
}
//salam salman)))))))))))
//salam sanya))))
//salam popalam, test
