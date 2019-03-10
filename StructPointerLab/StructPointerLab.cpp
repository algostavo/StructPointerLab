// StructPointerLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Create a simple structure for a person, including their name and age

Allow the user to set the name and age of 2 people

Create a pointer called p1 that points to Person 1 and pointer p2 that points to Person 2

Allow the user to do the following options using pointers:
Display the info for person 1 and person 2
Swap the 2 people and display the information
Set both people to person 1’s information and display
Set both people to person 2’s info and display
 */

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
struct person;
using namespace std;

struct person
{
	string name;
	int age;
};

void display_info(person *p1, person *p2)
{
	stringstream ss;
	ss << "\nPerson 1\nName: " + p1->name << "\nAge: " + to_string(p1->age) <<
		"\nPerson 2\nName: " + p2->name << "\nAge: " + to_string(p2->age) + "\n";
	cout << ss.str();
}

void swap_persons(person *p1, person *p2)
{
	person p3 = *p1;
	*p1 = *p2;
	*p2 = p3;
}

void set_to_person_one(person *p1, person *p2) { *p2 = *p1; }

void set_to_person_two(person *p1, person *p2) { *p1 = *p2; }

void pointer_operation(const int input, person *p1, person *p2)
{
	switch (input)
	{
	case 1:
		display_info(p1, p2);
		break;
	case 2:
		swap_persons(p1, p2);
		display_info(p1, p2);
		break;
	case 3:
		set_to_person_one(p1, p2);
		display_info(p1, p2);
		break;
	case 4:
		set_to_person_two(p1, p2);
		display_info(p1, p2);
		break;
	default:;
		break;
	}
}

void menu(person *p1, person *p2)
{
	int input_line;
	do
	{
		std::cout << "\n1. Display info for Person #1 and #2";
		std::cout << "\n2. Swap the two people and display the information";
		std::cout << "\n3. Set both people to person 1's information and display";
		std::cout << "\n4. Set both people to person 2's info and display";
		std::cout << "\n0. To exit the program.";
		cin >> input_line;
		pointer_operation(input_line, p1, p2);
	} while (input_line != 0);
}

void create_persons(person *p1, person *p2)
{
	string value;
	std::cout << "Enter the name for Person #1\n";
	getline(cin, p1->name);
	std::cout << "Enter the age for Person #1\n";
	getline(cin, value);
	static_cast<stringstream>(value) >> p1->age;

	std::cout << "Enter the name for Person #2\n";
	getline(cin, p2->name);
	std::cout << "Enter the age for Person #2\n";
	getline(cin, value);
	static_cast<stringstream>(value) >> p2->age;
}

int main()
{
	person person_one{};
	person *p1 = &person_one;
	person person_two{};
	person *p2 = &person_two;
	create_persons(p1,p2);
	menu(p1, p2);
}


