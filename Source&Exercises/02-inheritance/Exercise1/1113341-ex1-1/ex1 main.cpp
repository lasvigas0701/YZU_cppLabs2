#include <iostream>
#include "Person.cpp"
#include "Student.cpp"
#include "Teacher.cpp"
int main() {
	Student s("Lin Jia-Hao", 23, "52 Lide Street", 9.0);
	s.display();

	Teacher t("Chen Zhu-Wei", 35, "12 ShongShan Road", 42000);
	t.display();
	return 0;
}