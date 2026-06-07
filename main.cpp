#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Problem.h"
#include "Analyzer.h"

using namespace std;

vector<Problem> loadData(string filename) {

    ifstream file(filename);
    vector<Problem> problems;

    if (!file.is_open()) {
        cout << "Could not open file!" << endl;
        return problems;
    }

    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {

        stringstream ss(line);
        Problem p;
        string rating;

        getline(ss, p.name, ',');
        getline(ss, rating, ',');
        getline(ss, p.topic, ',');

        p.rating = stoi(rating);
        problems.push_back(p);
    }

    return problems;
}

int main() {

    vector<Problem> problems = loadData("problems.csv");

    Analyzer::showStats(problems);

    return 0;
}