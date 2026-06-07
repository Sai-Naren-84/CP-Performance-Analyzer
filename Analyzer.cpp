#include "Analyzer.h"
#include <iostream>
#include <map>

using namespace std;

void Analyzer::showReport(const vector<Problem>& problems) {

    if (problems.empty()) {
        cout << "No data loaded.\n";
        return;
    }

    int solved = 0;
    int totalRating = 0;

    for (auto &p : problems) {
        if (p.solved == 1) {
            solved++;
            totalRating += p.rating;
        }
    }

    int total = problems.size();
    double successRate = (double)solved / total;

    double skillScore = solved ? (double)totalRating / solved : 0;

    cout << "\n===== PERFORMANCE REPORT =====\n";
    cout << "Total Problems: " << total << endl;
    cout << "Solved: " << solved << endl;
    cout << "Unsolved: " << (total - solved) << endl;
    cout << "Success Rate: " << successRate * 100 << "%\n";
    cout << "Skill Score: " << skillScore << endl;
}

void Analyzer::showWeakTopics(const vector<Problem>& problems) {

    if (problems.empty()) {
        cout << "No data loaded.\n";
        return;
    }

    map<string, int> total, solved;

    for (auto &p : problems) {
        total[p.topic]++;
        if (p.solved == 1)
            solved[p.topic]++;
    }

    cout << "\n===== WEAK TOPICS =====\n";

    string weakTopic;
    double worst = 1.0;

    for (auto &t : total) {

        int s = solved[t.first];
        int tot = t.second;

        double ratio = (double)s / tot;

        cout << t.first << " -> "
             << ratio * 100 << "% ("
             << s << "/" << tot << " solved)" << endl;

        if (ratio < worst) {
            worst = ratio;
            weakTopic = t.first;
        }
    }

    cout << "\nWeakest Topic: " << weakTopic << endl;
}

void Analyzer::showStrongTopics(const vector<Problem>& problems) {

    if (problems.empty()) {
        cout << "No data loaded.\n";
        return;
    }

    map<string, int> total, solved;

    for (auto &p : problems) {
        total[p.topic]++;
        if (p.solved == 1)
            solved[p.topic]++;
    }

    cout << "\n===== STRONG TOPICS =====\n";

    string strongTopic;
    double best = 0.0;

    for (auto &t : total) {

        int s = solved[t.first];
        int tot = t.second;

        double ratio = (double)s / tot;

        cout << t.first << " -> "
             << ratio * 100 << "% ("
             << s << "/" << tot << " solved)" << endl;

        if (ratio > best) {
            best = ratio;
            strongTopic = t.first;
        }
    }

    cout << "\nStrongest Topic: " << strongTopic << endl;
}

void Analyzer::recommend(const vector<Problem>& problems) {

    if (problems.empty()) {
        cout << "No data loaded.\n";
        return;
    }

    cout << "\n===== RECOMMENDATIONS =====\n";

    for (auto &p : problems) {
        if (p.solved == 0 && p.rating <= 1400) {
            cout << "- " << p.name
                 << " (" << p.rating << ", " << p.topic << ")\n";
        }
    }
}

void Analyzer::searchProblem(const vector<Problem>& problems, string key) {

    if (problems.empty()) {
        cout << "No data loaded.\n";
        return;
    }

    cout << "\n===== SEARCH RESULTS =====\n";

    for (auto &p : problems) {
        if (p.name.find(key) != string::npos) {
            cout << p.name << " (" << p.rating << ", " << p.topic << ")\n";
        }
    }
}

void Analyzer::datasetSummary(const vector<Problem>& problems) {

    if (problems.empty()) {
        cout << "No data loaded.\n";
        return;
    }

    map<string, int> topicCount;
    map<string, int> ratingMap;

    int maxRating = -1, minRating = 1e9;
    string hardest, easiest;

    for (auto &p : problems) {

        topicCount[p.topic]++;

        if (p.rating > maxRating) {
            maxRating = p.rating;
            hardest = p.name;
        }

        if (p.rating < minRating) {
            minRating = p.rating;
            easiest = p.name;
        }
    }

    cout << "\n===== DATASET SUMMARY =====\n";
    cout << "Total Problems: " << problems.size() << endl;
    cout << "Total Topics: " << topicCount.size() << endl;

    cout << "Most Frequent Topic: ";

    string topTopic;
    int maxCount = 0;

    for (auto &t : topicCount) {
        if (t.second > maxCount) {
            maxCount = t.second;
            topTopic = t.first;
        }
    }

    cout << topTopic << " (" << maxCount << " problems)\n";

    cout << "Hardest Problem: " << hardest << endl;
    cout << "Easiest Problem: " << easiest << endl;
}