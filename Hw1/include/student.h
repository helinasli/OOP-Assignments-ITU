/* @Author
 * Student Name:  Helin Aslı Askoy
 */

#include <iostream>
#include <cstdio>
#include <cstdio>
#include <string.h>

using namespace std;

class Student
{
private:
    string name;
    double GPA;
    double GRE;
    double TOEFL;
    mutable int appNum;

public:
    // constructor
    Student();                         // constructor default
    Student(string, double, int, int); // constructor with parameter
    Student(const Student &);          // copy constructor

    // Getter method
    string getName() const;
    double getGPA() const;
    double getGRE() const;
    double getTOEFL() const;
    int getAppNum() const;
    // Setter method
    void set_name(string);
    // void setGPA(double);
    // void setGRE(double);
    // void setTOEFL(double);
    void setAppNum(int) const;

    // Deconstructor
    ~Student();
};