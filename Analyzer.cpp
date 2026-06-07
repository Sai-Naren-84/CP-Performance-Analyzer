#include "Analyzer.h"
#include <iostream>
#include <map>

using namespace std;

/* ================= COLORS ================= */
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

/* ================= PERFORMANCE REPORT ================= */
void Analyzer::showReport(const vector<Problem>& problems) {

    cout << "\n==============================\n";
    cout << "     PERFORMANCE REPORT      \n";
    cout << "==============================\n\n";

    if (problems.empty()) {
        cout << RED << "No data loaded.\n" << RESET;
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

    cout << "Total Problems : " << total << endl;
    cout << "Solved         : " << solved << endl;
    cout << "Unsolved       : " << (total - solved) << endl;
    cout << "Success Rate   : " << successRate * 100 << "%\n";
    cout << "Skill Score    : " << skillScore << endl;
}

/* ================= WEAK TOPICS ================= */
void Analyzer::showWeakTopics(const vector<Problem>& problems) {

    cout << "\n==============================\n";
    cout << "        WEAK TOPICS          \n";
    cout << "==============================\n\n";

    if (problems.empty()) {
        cout << RED << "No data loaded.\n" << RESET;
        return;
    }

    map<string, int> total, solved;

    for (auto &p : problems) {
        total[p.topic]++;
        if (p.solved == 1)
            solved[p.topic]++;
    }

    string weakTopic;
    double worst = 1.0;

    for (auto &t : total) {

        int s = solved[t.first];
        int tot = t.second;

        double ratio = (double)s / tot;

        cout << WHITE << t.first << RESET << " -> "
             << ratio * 100 << "% (" << s << "/" << tot << ")\n";

        if (ratio < worst) {
            worst = ratio;
            weakTopic = t.first;
        }
    }

    cout << RED << "\nWeakest Topic: " << WHITE << weakTopic << RESET << endl;
}

/* ================= STRONG TOPICS ================= */
void Analyzer::showStrongTopics(const vector<Problem>& problems) {

    cout << "\n==============================\n";
    cout << "       STRONG TOPICS         \n";
    cout << "==============================\n\n";

    if (problems.empty()) {
        cout << RED << "No data loaded.\n" << RESET;
        return;
    }

    map<string, int> total, solved;

    for (auto &p : problems) {
        total[p.topic]++;
        if (p.solved == 1)
            solved[p.topic]++;
    }

    string strongTopic;
    double best = 0.0;

    for (auto &t : total) {

        int s = solved[t.first];
        int tot = t.second;

        double ratio = (double)s / tot;

        cout << WHITE << t.first << RESET << " -> "
             << ratio * 100 << "% (" << s << "/" << tot << ")\n";

        if (ratio > best) {
            best = ratio;
            strongTopic = t.first;
        }
    }

    cout << GREEN << "\nStrongest Topic: " << WHITE << strongTopic << RESET << endl;
}

/* ================= RECOMMENDATIONS ================= */
void Analyzer::recommend(const vector<Problem>& problems) {

    cout << "\n==============================\n";
    cout << "      RECOMMENDATIONS        \n";
    cout << "==============================\n\n";

    if (problems.empty()) {
        cout << RED << "No data loaded.\n" << RESET;
        return;
    }

    bool found = false;

    for (auto &p : problems) {
        if (p.solved == 0 && p.rating <= 1400) {
            cout << "- " << p.name
                 << " (" << p.rating << ", " << p.topic << ")\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No recommendations found.\n";
    }
}

/* ================= SEARCH ================= */
void Analyzer::searchProblem(const vector<Problem>& problems, string key) {

    cout << "\n==============================\n";
    cout << "        SEARCH RESULTS       \n";
    cout << "==============================\n\n";

    if (problems.empty()) {
        cout << RED << "No data loaded.\n" << RESET;
        return;
    }

    bool found = false;

    for (auto &p : problems) {
        if (p.name.find(key) != string::npos) {
            cout << p.name << " (" << p.rating << ", " << p.topic << ")\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No match found.\n";
    }
}

/* ================= DATASET SUMMARY ================= */
void Analyzer::datasetSummary(const vector<Problem>& problems) {

    cout << "\n==============================\n";
    cout << "      DATASET SUMMARY        \n";
    cout << "==============================\n\n";

    if (problems.empty()) {
        cout << RED << "No data loaded.\n" << RESET;
        return;
    }

    map<string, int> topicCount;

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

    cout << "Total Problems : " << problems.size() << endl;
    cout << "Total Topics   : " << topicCount.size() << endl;

    string topTopic;
    int maxCount = 0;

    for (auto &t : topicCount) {
        if (t.second > maxCount) {
            maxCount = t.second;
            topTopic = t.first;
        }
    }

    cout << "Most Frequent Topic : " << topTopic << endl;
    cout << "Hardest Problem     : " << hardest << endl;
    cout << "Easiest Problem     : " << easiest << endl;
}