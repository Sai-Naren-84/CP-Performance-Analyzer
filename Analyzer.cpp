#include "Analyzer.h"
#include <iostream>
#include <map>
#include <fstream>
#include <cmath>
#include <algorithm>

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
    cout << "        WEAK TOPICS\n";
    cout << "==============================\n\n";

    if(problems.empty()){
        cout << RED << "No data loaded.\n" << RESET;
        return;
    }

    map<string,int> total, solved;

    for(auto &p : problems){
        total[p.topic]++;
        if(p.solved)
            solved[p.topic]++;
    }

    string weakest;
    double worstScore = -1;

    for(auto &t : total){

        int tot = t.second;
        int sol = solved[t.first];

        double solveRate = (double)sol / tot;

        double weakness =
            (1.0 - solveRate) *
            log(tot + 1);

        cout << t.first
             << " -> Weakness Score: "
             << weakness
             << " (" << sol
             << "/" << tot
             << ")\n";

        if(weakness > worstScore){
            worstScore = weakness;
            weakest = t.first;
        }
    }

    cout << RED
         << "\nWeakest Topic: "
         << weakest
         << RESET
         << "\n";
}

/* ================= STRONG TOPICS ================= */
void Analyzer::showStrongTopics(const vector<Problem>& problems) {

    cout << "\n==============================\n";
    cout << "       STRONG TOPICS\n";
    cout << "==============================\n\n";

    if(problems.empty()){
        cout << RED << "No data loaded.\n" << RESET;
        return;
    }

    map<string,int> total, solved;

    for(auto &p : problems){
        total[p.topic]++;
        if(p.solved)
            solved[p.topic]++;
    }

    string strongest;
    double bestScore = 0;

    for(auto &t : total){

        int tot = t.second;
        int sol = solved[t.first];

        double solveRate =
            (double)sol / tot;

        double experience =
            min(tot / 20.0, 1.0);

        double score =
            0.7 * solveRate +
            0.3 * experience;

        cout << t.first
             << " -> Strength Score: "
             << score * 100
             << "\n";

        if(score > bestScore){
            bestScore = score;
            strongest = t.first;
        }
    }

    cout << GREEN
         << "\nStrongest Topic: "
         << strongest
         << RESET
         << "\n";
}

/* ================= RECOMMENDATIONS ================= */
void Analyzer::recommend(const vector<Problem>& problems) {

    cout << "\n==============================\n";
    cout << "    SMART RECOMMENDATIONS\n";
    cout << "==============================\n\n";

    if(problems.empty()){
        cout << RED << "No data loaded.\n" << RESET;
        return;
    }

    int solvedCount = 0;
    int totalRating = 0;

    for(auto &p : problems){
        if(p.solved){
            solvedCount++;
            totalRating += p.rating;
        }
    }

    int avgRating =
        solvedCount ?
        totalRating / solvedCount :
        1200;

    cout << "Current Skill Level ~ "
         << avgRating
         << "\n\n";

    bool found = false;

    for(auto &p : problems){

        if(!p.solved &&
           p.rating >= avgRating &&
           p.rating <= avgRating + 200){

            cout << "- "
                 << p.name
                 << " ("
                 << p.rating
                 << ", "
                 << p.topic
                 << ")\n";

            found = true;
        }
    }

    if(!found){
        cout << "No suitable recommendations found.\n";
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

void Analyzer::difficultyDistribution(
    const vector<Problem>& problems)
{
    if(problems.empty()){
        cout << "No data loaded.\n";
        return;
    }

    map<string,int> bucket;

    for(auto &p : problems){

        if(p.rating < 1000)
            bucket["800-999"]++;

        else if(p.rating < 1200)
            bucket["1000-1199"]++;

        else if(p.rating < 1400)
            bucket["1200-1399"]++;

        else if(p.rating < 1600)
            bucket["1400-1599"]++;

        else if(p.rating < 1800)
            bucket["1600-1799"]++;

        else
            bucket["1800+"]++;
    }

    cout << "\nDifficulty Distribution\n\n";

    for(auto &b : bucket){

        cout << b.first << " ";

        for(int i=0;i<b.second;i++)
            cout << '#';

        cout << " (" << b.second << ")\n";
    }
}

void Analyzer::generateStudyPlan(
    const vector<Problem>& problems)
{
    cout << "\n========== STUDY PLAN ==========\n\n";

    cout << "Week 1 : Solve 5 problems from weakest topic\n";
    cout << "Week 2 : Solve 5 medium difficulty problems\n";
    cout << "Week 3 : Solve 5 problems from strongest topic\n";
    cout << "Week 4 : Attempt 2 contest simulations\n";
}

void Analyzer::exportReport(
    const vector<Problem>& problems)
{
    ofstream out("report.txt");

    if(!out){
        cout << "Could not create report.\n";
        return;
    }

    int solved = 0;

    for(auto &p : problems)
        solved += p.solved;

    out << "CP PERFORMANCE REPORT\n";
    out << "=====================\n\n";

    out << "Total Problems: "
        << problems.size()
        << "\n";

    out << "Solved: "
        << solved
        << "\n";

    out << "Unsolved: "
        << problems.size()-solved
        << "\n";

    out.close();

    cout << GREEN
         << "report.txt created successfully.\n"
         << RESET;
}

void Analyzer::estimatedRating(
    const vector<Problem>& problems)
{
    int solved = 0;
    int totalRating = 0;

    for(auto &p : problems){

        if(p.solved){
            solved++;
            totalRating += p.rating;
        }
    }

    if(solved == 0){
        cout << "Not enough data.\n";
        return;
    }

    int estimated =
        totalRating / solved;

    cout << "\nEstimated Rating : "
         << estimated
         << "\n";

    cout << "Projected Rating : "
         << estimated + 150
         << "\n";
}