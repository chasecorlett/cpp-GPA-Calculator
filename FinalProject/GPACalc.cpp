//
// Created by Chase on 8/9/2020.
//

#include "GPACalc.h"

// print introduction and give instructions for inputting grades
GPACalc::GPACalc() {
    cout << "Please enter your name:";
    getline(cin, name);
    cout << endl;

    cout << "Welcome to the GPA calculator, " << getName() << "!" << endl;
    cout << "Please enter the percentage you earned in a class and then the "
            "credit hours that class is worth when prompted." << endl << endl;

    cout << "When you have entered your last class and would like to calculate "
            "your GPA, enter -1 for Class Grade." << endl << endl;
}

// receive input for grades and credit hours into a vector to be used for the calculation
void GPACalc::setGPADataVector() {
    bool test = true;
    int count = 0;

    while (test) {
        cout << "Class grade:";
        cin >> inGrade;

        if (inGrade != -1) {
            cout << "Class weight:";
            cin >> inWeight;
            GPADataVector.resize(count + 1);
            GPADataVector.at(count).classGrade = inGrade;
            GPADataVector.at(count).classWeight = inWeight;
            count++;
        }
        else {
            test = false;
        }
    }
}

// change values for grades from data vector to grade points and put into new vector
void GPACalc::setReportCardVector() {
    for (int i=0; i<GPADataVector.size(); i++) {
        reportCardVector.resize(i+1);

        // take in percentage values and assign them point values
        // then put them into new vector at same index
        if (GPADataVector.at(i).classGrade < 60) {
            reportCardVector.at(i).classGrade = 0;
        }
        else if ((GPADataVector.at(i).classGrade > 60) && (GPADataVector.at(i).classGrade < 66.5)) {
            reportCardVector.at(i).classGrade = 1;
        }
        else if ((GPADataVector.at(i).classGrade >= 66.5) && (GPADataVector.at(i).classGrade < 70)) {
            reportCardVector.at(i).classGrade = 1.3;
        }
        else if ((GPADataVector.at(i).classGrade >= 70) && (GPADataVector.at(i).classGrade < 72.5)) {
            reportCardVector.at(i).classGrade = 1.7;
        }
        else if ((GPADataVector.at(i).classGrade >= 72.5) && (GPADataVector.at(i).classGrade < 76.5)) {
            reportCardVector.at(i).classGrade = 2;
        }
        else if ((GPADataVector.at(i).classGrade >= 76.5) && (GPADataVector.at(i).classGrade < 80)) {
            reportCardVector.at(i).classGrade = 2.3;
        }
        else if ((GPADataVector.at(i).classGrade >= 80) && (GPADataVector.at(i).classGrade < 82.5)) {
            reportCardVector.at(i).classGrade = 2.7;
        }
        else if ((GPADataVector.at(i).classGrade >= 82.5) && (GPADataVector.at(i).classGrade < 86.5)) {
            reportCardVector.at(i).classGrade = 3;
        }
        else if ((GPADataVector.at(i).classGrade >= 86.5) && (GPADataVector.at(i).classGrade < 90)) {
            reportCardVector.at(i).classGrade = 3.3;
        }
        else if ((GPADataVector.at(i).classGrade >= 90) && (GPADataVector.at(i).classGrade < 92.5)) {
            reportCardVector.at(i).classGrade = 3.7;
        }
        else {
            reportCardVector.at(i).classGrade = 4;
        }

        // copy credit hours to new vector
        reportCardVector.at(i).classWeight = GPADataVector.at(i).classWeight;
    }
}

// calculate GPA by multiplying grade points by credit hours then summing total
// quality points and dividing by total credit hours
void GPACalc::setGPA() {
    for (int i=0; i<GPADataVector.size(); i++) {
        pointsAvail += reportCardVector.at(i).classWeight;
        gradePoints += reportCardVector.at(i).classWeight * reportCardVector.at(i).classGrade;
    }
    gpa = (gradePoints / pointsAvail);
}

// return name
string GPACalc::getName() {
    return name;
}

// return gpa
double GPACalc::getGPA() {
    return gpa;
}

// open report card file
void GPACalc::openReportCard() {
    reportCard.open("ReportCard.txt");
    if (!reportCard.is_open()) {
        cerr << "ReportCard.txt did not open" << endl;
    }
}

// write results of calculation to report card file and inform user it exists
void GPACalc::writeReportCard() {
    openReportCard();

    // print top of report card
    reportCard << " ********************" << endl;
    reportCard << "| " << left << setw(19) << getName() << "|" << endl;
    reportCard << "|                    |" << endl;

    // print each class and its grade and weight
    for(int i=0; i<GPADataVector.size(); i++) {
        reportCard << "| Class #" << setw(12) << i+1 << "|" << endl;
        reportCard << "| Grade: " << setw(12) << GPADataVector.at(i).classGrade << "|" << endl;
        reportCard << "| Credit Hours: "  << setw(5) << GPADataVector.at(i).classWeight << "|" << endl;
        reportCard << "|                    |" << endl;
    }

    // print total data, gpa and bottom of report card
    reportCard << "| Total Hours: " << setw(6) << pointsAvail << "|" << endl;
    reportCard << "| Qual Points: " << setw(6) << gradePoints << "|" << endl;
    reportCard << "| GPA: " << setw(14) << setprecision(2)<< getGPA() << "|" << endl;
    reportCard << " ********************" << endl;

    closeReportCard();
    cout << "You can now find your report card in ReportCard.txt!" << endl << endl;
}

// close report card file
void GPACalc::closeReportCard() {
    reportCard.close();
}

// print results of calculation in easily readable way to console
void GPACalc::printResults() {
    cout << endl;

    // print top of report card
    cout << " ********************" << endl;
    cout << "| " << left << setw(19) << getName() << "|" << endl;
    cout << "|                    |" << endl;

    // print each class and its grade and weight
    for(int i=0; i<GPADataVector.size(); i++) {
        cout << "| Class #" << setw(12) << i+1 << "|" << endl;
        cout << "| Grade: " << setw(12) << GPADataVector.at(i).classGrade << "|" << endl;
        cout << "| Credit Hours: "  << setw(5) << GPADataVector.at(i).classWeight << "|" << endl;
        cout << "|                    |" << endl;
    }

    // print total data, gpa and bottom of report card
    cout << "| Total Hours: " << setw(6) << pointsAvail << "|" << endl;
    cout << "| Qual Points: " << setw(6) << gradePoints << "|" << endl;
    cout << "| GPA: " << setw(14) << getGPA() << "|" << endl;
    cout << " ********************" << endl << endl;
}



