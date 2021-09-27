#include <iostream>
#include<string>
using namespace std;
struct Student {
	string name;
	string surname;
	int scores[3];
};
void Show(Student*, int);
void Sort(Student* (&), int);
int BestScore(Student(&), int);
int main() {
	setlocale(LC_ALL, "rus");
	int size;
	cout << "������� ������ �������(>5): "; cin >> size;
	while (size >5) {
		cout << "������� ������ �������(������ 5): "; cin >> size;
	}
	Student* students = new Student[size];
	for (int i{ 0 }; i < size; i++) {
		cout << "������� � " << i + 1 << endl;
		cout << "������� ��� ��������: ";
		cin >> students[i].name;
		cout << "������� ������� ��������: ";
		cin >> students[i].surname;
		cout << "������� ������ ��������: " << endl;
		for (int j{ 0 }; j < 3; j++) {
			cout << "������ " << j + 1 << ": ";
			cin >> students[i].scores[j];
		}
	}
	Sort(students, size);
	Show(students, size);
	delete[] students;
	students = nullptr;
	return 0;
}
void Show(Student* obj, int size) {
	for (int i{ 0 }; i < size; i++) {
		cout << "\n������� � " << i + 1 << endl;
		cout << "��� ��������: "; cout << obj[i].name << endl;
		cout << "������� ��������: "; cout << obj[i].surname << endl;
		cout << "������ ��������: ";
		for (int j{ 0 }; j < 3; j++) {
			cout << "\n������ " << j + 1 << ": ";
			cout << obj[i].scores[j];
		}
	}
}
int BestScore(Student(&obj), int size) {
	int result{ 0 };
	for (int i = { 0 }; i < 3; i++) {
		if (obj.scores[i] > result) {
			result = obj.scores[i];
		}
	}
	return result;
}
// ������ ������� ������� ������ ������ ������ �� �������� � ���������� � Sort ��� �� ��� (int *BestScore(Student&obj),int size)
void Sort(Student* (&obj), int size) {
	Student intermediate;
	for (int i{ 1 }; i < size; i++) {
		for (int j = i; BestScore(obj[j], size) >= BestScore(obj[j - 1], size) && j > 0; j--) {
			intermediate = obj[j - 1];
			obj[j - 1] = obj[j];
			obj[j] = intermediate;
		}
	}
}