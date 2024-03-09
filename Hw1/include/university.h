/* @Author
 * Student Name:  Helin Aslı Askoy
 */

#include <iostream>
#include <cstdio>
#include <cstdio>
#include <string.h>
#include "student.h"

using namespace std;

class University
{
private:
    string uniName;
    double weight[3];
    double bias;
    string country;

public:
    // Constructors
    University();                                               // Default Constructors
    University(string, double, double, double, double, string); // Parameter Constructors
    University(string, double, double, double, double);         // Parameter Constructors Overload
    University(const University &);                             // Copy Constructors

    // Getter Method
    string getUniName();
    double *getWeight();
    double getBias();
    string getCountry();

    // Setter methods
    // void setUniName(string);
    // void setweight(double, double, double);
    // void setBias(double);
    // void setCountry(string);

    void evaluate_student(const Student &student);

    // Deconstructor
    ~University();
};
