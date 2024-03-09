/* @Author
 * Student Name:  Helin Aslı Askoy
 */

#include <iostream>
#include <cstdio>
#include <cstdio>
#include <string.h>
#include "University.h"

using namespace std;

University::University()
{
    this->uniName = "";
    this->country = "";
    this->weight[0] = rand();
    this->weight[1] = rand();
    this->weight[2] = rand();
    this->bias = rand();
}

University::University(string name, double wGPA, double wGRE, double wTOEFL, double bias, string country)
{
    this->uniName = name;
    this->country = country;
    this->weight[0] = wGPA;
    this->weight[1] = wGRE;
    this->weight[2] = wTOEFL;
    this->bias = bias;
}

University::University(string name, double wGPA, double wGRE, double wTOEFL, double bias)
{
    this->uniName = name;
    this->weight[0] = wGPA;
    this->weight[1] = wGRE;
    this->weight[2] = wTOEFL;
    this->bias = bias;
}

University::University(const University &university)
{
    this->uniName = university.uniName;
    this->weight[0] = university.weight[0];
    this->weight[1] = university.weight[1];
    this->weight[2] = university.weight[2];
    this->country = university.country;
}

string University::getUniName()
{
    return this->uniName;
}

double *University::getWeight()
{
    return weight;
}

double University::getBias()
{
    return this->bias;
}

string University::getCountry()
{
    return this->country;
}

// void University::setUniName(string name)
// {
//     this->uniName = name;
// }
// void University::setweight(double wGPA, double wGRE, double wTOEFL)
// {
//     this->weight[0] = wGPA;
//     this->weight[1] = wGRE;
//     this->weight[2] = wTOEFL;
// }
// void University::setBias(double bias)
// {
//     this->bias = bias;
// }
// void University::setCountry(string country)
// {
//     this->country = country;
// }

void University::evaluate_student(const Student &student)
{
    double z;
    z = (student.getGPA() * this->getWeight()[0]) + (student.getGRE() * this->getWeight()[1]) + (student.getTOEFL() * this->getWeight()[2]) + this->getBias();
    if (z > 0)
    {
        cout << student.getName() << " is admitted to " << this->getUniName() << "." << endl;
    }
    else
    {
        cout << student.getName() << " is rejected from " << this->getUniName() << "." << endl;
    }
    student.setAppNum(student.getAppNum() + 1);
}

University::~University()
{
}