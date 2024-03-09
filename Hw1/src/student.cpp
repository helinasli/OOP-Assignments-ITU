/* @Author
 * Student Name:  Helin Aslı Askoy
 */

#include <iostream>
#include <cstdio>
#include <cstdio>
#include <string.h>
#include <student.h>

using namespace std;

Student::Student()
{
    this->name = "";
    this->GPA = 0;
    this->GRE = 0;
    this->TOEFL = 0;
    this->appNum = 0;
}

Student::Student(string name, double GPA, int GRE, int TOEFL)
{
    this->name = name;
    this->GPA = GPA;
    this->GRE = GRE;
    this->TOEFL = TOEFL;
    this->appNum = 0;
    cout << name << " logged in to the system." << endl;
}

Student::Student(const Student &student)
{
    this->name = student.name;
    this->GPA = student.GPA;
    this->GRE = student.GRE;
    this->TOEFL = student.TOEFL;
    this->appNum = student.appNum;
    cout << name << " logged in to the system." << endl;
}

string Student::getName() const
{
    return this->name;
}

double Student::getGPA() const
{
    return this->GPA;
}

double Student::getGRE() const
{
    return this->GRE;
}

double Student::getTOEFL() const
{
    return this->TOEFL;
}

int Student::getAppNum() const
{
    return this->appNum;
}

void Student::set_name(string name)
{
    this->name = name;
}

// void Student::setGPA(double GPA)
// {
//     this->GPA = GPA;
// }

// void Student::setGRE(double GRE)
// {
//     this->GRE = GRE;
// }

// void Student::setTOEFL(double TOEFL)
// {
//     this->TOEFL = TOEFL;
// }

void Student::setAppNum(int appNum) const
{
    this->appNum = appNum;
}

Student::~Student()
{
    cout << this->getName() << " logged out of the system with " << this->getAppNum() << " application(s)." << endl;
}