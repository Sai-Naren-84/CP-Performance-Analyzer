#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Problem.h"
#include "Analyzer.h"

using namespace std;

vector<Problem> loadData(string file) {

    ifstream f(file);
    vector<Problem> v;

    if (!f.is_open()) {
        cout << "Error: Cannot open file!\n";
        return v;
    }

    string line;
    getline(f, line); // header

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

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    string temp;
    getline(cin, temp);
}

void showHelp() {

    cout << "\n====================================================\n";
    cout << " HOW TO CREATE YOUR CSV FILE\n";
    cout << "====================================================\n";

    cout << "Format:\n";
    cout << "name,rating,topic,solved\n\n";

    cout << "Example:\n";
    cout << "Two Sum,800,Arrays,1\n";
    cout << "DP Knapsack,1900,DP,0\n\n";

    cout << "Steps:\n";
    cout << "1. Open Excel or Google Sheets\n";
    cout << "2. Add your problems\n";
    cout << "3. Export as CSV\n";
    cout << "4. Place file in project folder\n\n";

    cout << "Read README for more info.\n";

    cout << "====================================================\n";
}

void menu() {

    cout << "\n==============================\n";
    cout << "   CP ANALYTICS ENGINE\n";
    cout << "==============================\n";

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

int main() {

    vector<Problem> problems;
    string file = "problems.csv";

    showHelp();

    int choice;

    while (true) {

        menu();

        cout << "\nEnter choice: ";

        string input;
        getline(cin, input);

        if (input.empty()) continue;

        choice = stoi(input);

        if (choice == 9) break;

        if (choice == 1) {

            cout << "Enter CSV file name: ";
            getline(cin, file);

            problems = loadData(file);

            if (!problems.empty())
                cout << "Data loaded successfully!\n";

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