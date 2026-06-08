#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>

#include "Problem.h"
#include "Analyzer.h"

using namespace std;

/* ================= COLORS ================= */
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

/* ================= LOADER ================= */
vector<Problem> loadData(string file) {

    ifstream f(file);
    vector<Problem> v;

    if (!f.is_open()) {
        cout << RED << "Error opening file!\n" << RESET;
        return v;
    }

    string line;
    getline(f, line);

    while (getline(f, line)) {

        if (line.empty())
            continue;

        stringstream ss(line);

        Problem p;

        string rating, solved;

        getline(ss, p.name, ',');
        getline(ss, rating, ',');
        getline(ss, p.topic, ',');
        getline(ss, solved, ',');
        getline(ss, p.date);

        try {
            p.rating = stoi(rating);
        }
        catch (...) {
            p.rating = 0;
        }

        try {
            p.solved = stoi(solved);
        }
        catch (...) {
            p.solved = 0;
        }

        v.push_back(p);
    }

    return v;
}

/* ================= SAFE INPUT ================= */
int getChoice() {

    string input;

    getline(cin, input);

    if (input.empty())
        return -1;

    try {
        return stoi(input);
    }
    catch (...) {
        return -1;
    }
}

/* ================= PAUSE ================= */
void pauseScreen() {

    cout << "\nPress Enter to continue...";
    cin.get();
}

/* ================= HEADER ================= */
void header() {

    cout << CYAN;
    cout << "\n====================================\n";
    cout << "  CP PERFORMANCE ANALYZER PRO\n";
    cout << "====================================\n";
    cout << RESET;
}

/* ================= MENU ================= */
void menu() {

    cout << BLUE;
    cout << "\n----------- MENU -----------\n";
    cout << RESET;

    cout << "1. Load CSV\n";
    cout << "2. Performance Report\n";
    cout << "3. Weak Topics\n";
    cout << "4. Strong Topics\n";
    cout << "5. Smart Recommendations\n";
    cout << "6. Search Problem\n";
    cout << "7. Dataset Summary\n";
    cout << "8. Difficulty Distribution\n";
    cout << "9. Generate Study Plan\n";
    cout << "10. Export Report\n";
    cout << "11. Estimated Rating\n";
    cout << "12. Help\n";
    cout << "13. Exit\n";
}

/* ================= HELP ================= */
void showHelp() {

    cout << "\n====================================\n";
    cout << "               HELP\n";
    cout << "====================================\n";

    cout << "\nCSV Format:\n";
    cout << "name,rating,topic,solved,date\n\n";

    cout << "Example:\n";
    cout << "Two Sum,800,Arrays,1,2026-06-01\n";
    cout << "DP Knapsack,1900,DP,0,2026-06-02\n";
    cout << "Dijkstra,1800,Graphs,1,2026-06-03\n\n";

    cout << "Meaning:\n";
    cout << "name   = Problem name\n";
    cout << "rating = Difficulty rating\n";
    cout << "topic  = Topic name\n";
    cout << "solved = 1 if solved, 0 otherwise\n";
    cout << "date   = YYYY-MM-DD\n\n";

    cout << "How to create CSV:\n";
    cout << "1. Use Excel / Google Sheets\n";
    cout << "2. Save as CSV\n";
    cout << "3. Put file in project folder\n";
    cout << "4. Load using option 1\n\n";

    cout << "====================================\n";
}

/* ================= MAIN ================= */
int main() {

    vector<Problem> problems;

    string file = "problems.csv";

    header();

    showHelp();

    while (true) {

        menu();

        cout << CYAN << "\nEnter choice: " << RESET;

        int choice = getChoice();

        if (choice == -1) {

            cout << RED << "Invalid input!\n" << RESET;
            continue;
        }

        if (choice == 13) {

            cout << GREEN << "Goodbye!\n" << RESET;
            break;
        }

        else if (choice == 1) {

            cout << "Enter file name: ";

            getline(cin, file);

            problems = loadData(file);

            if (!problems.empty()) {
                cout << GREEN
                    << "Loaded "
                    << problems.size()
                    << " problems successfully!\n"
                    << RESET;
            }

            pauseScreen();
        }

        else if (choice == 2) {

            Analyzer::showReport(problems);

            pauseScreen();
        }

        else if (choice == 3) {

            Analyzer::showWeakTopics(problems);

            pauseScreen();
        }

        else if (choice == 4) {

            Analyzer::showStrongTopics(problems);

            pauseScreen();
        }

        else if (choice == 5) {

            Analyzer::recommend(problems);

            pauseScreen();
        }

        else if (choice == 6) {

            string key;

            cout << "Enter keyword: ";

            getline(cin, key);

            Analyzer::searchProblem(
                problems,
                key
            );

            pauseScreen();
        }

        else if (choice == 7) {

            Analyzer::datasetSummary(problems);

            pauseScreen();
        }

        else if (choice == 8) {

            Analyzer::difficultyDistribution(problems);

            pauseScreen();
        }

        else if (choice == 9) {

            Analyzer::generateStudyPlan(problems);

            pauseScreen();
        }

        else if (choice == 10) {

            Analyzer::exportReport(problems);

            pauseScreen();
        }

        else if (choice == 11) {

            Analyzer::estimatedRating(problems);

            pauseScreen();
        }

        else if (choice == 12) {

            showHelp();

            pauseScreen();
        }

        else {

            cout << RED
                 << "Invalid choice!\n"
                 << RESET;
        }
    }

    return 0;
}