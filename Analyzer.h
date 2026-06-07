#ifndef ANALYZER_H
#define ANALYZER_H

#include <vector>
#include "Problem.h"

class Analyzer {
public:
    static void showReport(const vector<Problem>& problems);
    static void showWeakTopics(const vector<Problem>& problems);
    static void showStrongTopics(const vector<Problem>& problems);
    static void recommend(const vector<Problem>& problems);
    static void searchProblem(const vector<Problem>& problems, string key);
    static void datasetSummary(const vector<Problem>& problems);
};

#endif