#include "GPACalc.h"

using namespace std;

int main() {
    // create gpaCalc variable to call functions in GPACalc.h
    GPACalc gpaCalc;

    // create vectors for calculation and calculate gpa
    gpaCalc.setGPADataVector();
    gpaCalc.setReportCardVector();
    gpaCalc.setGPA();

    // print report card to console and inform user of new file "ReportCard.txt"
    gpaCalc.printResults();
    gpaCalc.openReportCard();
    gpaCalc.writeReportCard();

    return 0;
}
