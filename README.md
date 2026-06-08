# CP Performance Analyzer

A C++ command-line application for analyzing competitive programming practice data from CSV files.

The tool helps programmers track progress, identify strengths and weaknesses, discover practice gaps, and generate actionable insights from solved and unsolved problems.

---

## Features

* Load competitive programming datasets from CSV files
* Generate performance reports
* Identify strong and weak topics using topic-wise analysis
* Smart problem recommendations based on current skill level
* Search problems by name
* Dataset summary and statistics
* Difficulty distribution analysis
* Study plan generation
* Estimated rating calculation
* Export analysis reports to a text file
* Interactive menu-driven interface

---

## CSV Format

The application expects data in the following format:

```csv
name,rating,topic,solved,date
Two Sum,800,Arrays,1,2026-06-01
Binary Search,1200,Binary Search,1,2026-06-02
Dijkstra,1800,Graphs,0,2026-06-03
Knapsack,1700,DP,1,2026-06-04
```

### Fields

| Column | Description                  |
| ------ | ---------------------------- |
| name   | Problem name                 |
| rating | Problem difficulty           |
| topic  | Problem category             |
| solved | 1 = solved, 0 = unsolved     |
| date   | Date of attempt (YYYY-MM-DD) |

---

## Available Analytics

### Performance Report

Provides:

* Total problems
* Solved problems
* Unsolved problems
* Success rate
* Average solved difficulty

### Weak Topic Analysis

Identifies topics that require additional practice using performance-based scoring.

### Strong Topic Analysis

Highlights topics where the user consistently performs well.

### Smart Recommendations

Suggests unsolved problems near the user's current skill level.

### Dataset Summary

Displays:

* Total problems
* Total topics
* Most frequent topic
* Hardest problem
* Easiest problem

### Difficulty Distribution

Shows how problems are distributed across different difficulty ranges.

### Study Plan Generator

Creates a simple practice roadmap based on current performance.

### Estimated Rating

Estimates the user's current rating level from solved problem history.

### Export Report

Exports key analysis results into a text report.

---

## Building the Project

Compile using:

```bash
g++ main.cpp Analyzer.cpp -o app
```

Run:

### Windows

```bash
app.exe
```

or

```bash
./app
```

### Linux / macOS

```bash
./app
```

---

## Example Use Cases

* Track competitive programming progress
* Analyze practice history
* Find weak areas before contests
* Plan future problem-solving sessions
* Maintain a personal CP performance dataset

---

## Technologies Used

* C++
* STL (Vector, Map, String, Algorithms)
* File Handling
* Object-Oriented Programming
* CSV Data Processing

---

## Future Improvements

* Weekly and monthly performance tracking
* Progress trends using dates
* Contest performance analytics
* Advanced recommendation system
* Data visualization support

---

## Author

Sai Naren

GitHub: https://github.com/Sai-Naren-84
