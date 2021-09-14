//
// Created by Chase on 8/9/2020.
//

#ifndef FINALPROJECT_GPACALC_H
#define FINALPROJECT_GPACALC_H
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "GPAData.h"

using namespace std;

// declare functions and variables used for calculation and interface
class GPACalc {
private:
    string name;
    double inGrade;
    double inWeight;
    double gradePoints;
    double pointsAvail;
    double gpa;
    ofstream reportCard;
    vector <GPAData> GPADataVector;
    vector <GPAData> reportCardVector;
public:
    GPACalc();
    void setGPADataVector();
    void setReportCardVector();
    void setGPA();
    string getName();
    double getGPA();
    void openReportCard();
    void writeReportCard();
    void closeReportCard();
    void printResults();
};


#endif //FINALPROJECT_GPACALC_H
