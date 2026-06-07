#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "Student.h"

class CourseTest
{
	std::string m_name = "Course";
	std::vector<Student> m_students;

public:
	CourseTest() {}
	CourseTest(std::string name)
		: m_name(name)
	{

	}
	void addStudent(const Student& s)
	{
		m_students.push_back(s);
	}
	//const here means return on vector cannot be changed	//const will not change the class
	const std::vector<Student>& getStudents() const
	{
		return m_students;
	}

	void loadFromFile(const std::string& filename)
	{
		std::ifstream fin(filename);
		std::string first, last;
		int id;
		float avg;

		while (fin >> first)
		{
			fin >> last >> id>>avg;
			addStudent(Student(first, last, id, avg));
		}
	}
	void print() const
	{
		for (const auto& s : m_students)
		{
			s.print();
		}
	}
};

