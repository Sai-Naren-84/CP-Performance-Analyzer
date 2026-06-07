#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
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

        if (line.empty()) continue;

        stringstream ss(line);
        Problem p;
        string rating, solved;

        getline(ss, p.name, ',');
        getline(ss, rating, ',');
        getline(ss, p.topic, ',');
        getline(ss, solved, ',');

        try { p.rating = stoi(rating); }
        catch (...) { p.rating = 0; }

        try { p.solved = stoi(solved); }
        catch (...) { p.solved = 0; }

        v.push_back(p);
    }

    return v;
}

/* ================= SAFE INPUT ================= */
int getChoice() {
    string input;
    getline(cin, input);

    if (input.empty()) return -1;

    try {
        return stoi(input);
    } catch (...) {
        return -1;
    }
}

/* ================= PAUSE FIXED ================= */
void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

/* ================= UI ================= */
void header() {
    cout << CYAN << "\n====================================\n";
    cout << "     CP PERFORMANCE ANALYZER        \n";
    cout << "====================================\n" << RESET;
}

void menu() {
    cout << BLUE << "\n----------- MENU -----------\n" << RESET;
    cout << "1. Load CSV\n";
    cout << "2. Performance Report\n";
    cout << "3. Weak Topics\n";
    cout << "4. Strong Topics\n";
    cout << "5. Recommendations\n";
    cout << "6. Search Problem\n";
    cout << "7. Dataset Summary\n";
    cout << "8. Help\n";
    cout << "9. Exit\n";
}

void showHelp() {

    cout << "\n====================================\n";
    cout << "               HELP               \n";
    cout << "====================================\n";

    cout << "\nHow to create your CSV file:\n";
    cout << "Format: name,rating,topic,solved\n\n";

    cout << "Example:\n";
    cout << "Two Sum,800,Arrays,1\n";
    cout << "DP Knapsack,1900,DP,0\n\n";

    cout << "Steps:\n";
    cout << "1. Open Excel or Google Sheets\n";
    cout << "2. Enter your problems in columns\n";
    cout << "3. Export as CSV file\n";
    cout << "4. Place file in project folder\n\n";

    cout << "Read README for more info.\n";

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

        if (choice == 9) {
            cout << GREEN << "Goodbye!\n" << RESET;
            break;
        }

        if (choice == 1) {

            cout << "Enter file name: ";
            getline(cin, file);

            problems = loadData(file);

            if (!problems.empty())
                cout << GREEN << "Loaded successfully!\n" << RESET;

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
            Analyzer::searchProblem(problems, key);
            pauseScreen();
        }

        else if (choice == 7) {
            Analyzer::datasetSummary(problems);
            pauseScreen();
        }

        else if (choice == 8) {
            showHelp();
            pauseScreen();
        }
    }

    return 0;
}