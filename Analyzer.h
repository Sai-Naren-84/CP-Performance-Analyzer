#ifndef ANALYZER_H
#define ANALYZER_H

#include <vector>
#include <string>
#include "Problem.h"

class Analyzer {
public:

    // Core Analytics
    static void showReport(
        const std::vector<Problem>& problems
    );

    static void showWeakTopics(
        const std::vector<Problem>& problems
    );

    static void showStrongTopics(
        const std::vector<Problem>& problems
    );

    static void recommend(
        const std::vector<Problem>& problems
    );

    // Search
    static void searchProblem(
        const std::vector<Problem>& problems,
        std::string key
    );

    // Dataset Information
    static void datasetSummary(
        const std::vector<Problem>& problems
    );

    static void difficultyDistribution(
        const std::vector<Problem>& problems
    );

    // Planning & Reports
    static void generateStudyPlan(
        const std::vector<Problem>& problems
    );

    static void exportReport(
        const std::vector<Problem>& problems
    );

    // Rating Analytics
    static void estimatedRating(
        const std::vector<Problem>& problems
    );
};

#endif