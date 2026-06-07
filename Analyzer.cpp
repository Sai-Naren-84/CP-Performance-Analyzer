#include "Analyzer.h"
#include <iostream>
#include <map>

using namespace std;

void Analyzer::showStats(const vector<Problem>& problems) {

    if (problems.empty()) {
        cout << "No data found!" << endl;
        return;
    }

    cout << "\n========== CP PERFORMANCE ANALYZER ==========\n";

    // Total problems
    cout << "\nTotal Problems Solved: " << problems.size() << endl;

    // Average rating
    int total = 0;
    for (auto &p : problems)
        total += p.rating;

    cout << "Average Rating: " << (double)total / problems.size() << endl;

    // Hardest problem
    Problem hardest = problems[0];
    for (auto &p : problems)
        if (p.rating > hardest.rating)
            hardest = p;

    cout << "\nHardest Problem:\n";
    cout << hardest.name << " (" << hardest.rating << ")\n";

    // Topic count
    map<string, int> topicCount;

    for (auto &p : problems)
        topicCount[p.topic]++;

    cout << "\nTopic Statistics:\n";
    for (auto &e : topicCount)
        cout << e.first << " : " << e.second << endl;

    // Strongest topic
    string bestTopic;
    int maxCount = 0;

    for (auto &e : topicCount) {
        if (e.second > maxCount) {
            maxCount = e.second;
            bestTopic = e.first;
        }
    }

    cout << "\nStrongest Topic: " << bestTopic
         << " (" << maxCount << " problems)\n";
}