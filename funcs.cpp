#include "Header.h"
#include <vector>
#include <stdexcept>
#include <iostream>

void ToDoList::addTask(Task* actual) {
	if (actual != nullptr) {
		tasks.push_back(*actual);
	}
	else {
		throw std::invalid_argument("task hasn't been found");
	}
}

void ToDoList::renameTask(Task& actual, string newName) {
	size_t size = newName.size();
	if (size <= 50 && size != 0) {
		actual.name = newName;
	}
	else {
		if (size == 0) {
			throw std::invalid_argument("cannot add empty name");
		}
		else {
			throw std::invalid_argument("cannot add name longer than 50 symbols");
		}
	}
}

void ToDoList::switchTask(Task& actual) {
	actual.completed = !actual.completed;
}

void filePrint(ifstream& file) {
	if (!file.is_open()) {
		throw std::runtime_error("file hasn't been opened");
	}

	string currentS;
	while (getline(file, currentS)) {
		cout << currentS << endl;
	}
}

void setName(Task* task) {
	string taskName = "";
	int i = 0;
	cout << "введите название задачи" << endl;
	while (taskName.length() == 0 || taskName.length() > 50) {
		if (i > 0) {
			cout << "введите от 1 до 50 символов" << endl;
		}
		i++;
		cin >> taskName;
	}

	task->name = taskName;

	string desc = "";
	i = 0;
	cout << "добавьте описание задачи" << endl;
	while (desc.length() == 0) {
		if (i > 0) {
			cout << "введите хотя бы 1 символ" << endl;
		}
		i++;
		cin >> desc;		
	}
	task->description = desc;
	return;
}

char choose() {
	cout << endl;
	char dec = {}; //decision
	int i = 0;
	while (dec - '0' > 4 || dec - '0' < 1) {
		if (i > 0) {
			cout << "введите цифру от 1 до 4" << endl;
		}

		cout << "1 - добавить задачу" << endl
			<< "2 - изменить статус задачи" << endl
			<< "3 - удалить задачу из списка" << endl
			<< "4 - сохранить и выйти" << endl;
		cin >> dec;

		i++;
	}
	return dec;
}