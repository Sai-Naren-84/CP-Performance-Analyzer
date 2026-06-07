# CP Performance Analyzer

## About this project

CP Performance Analyzer is a C++ command-line tool that analyzes competitive programming practice data from a CSV file. It helps users understand their progress, strengths, weaknesses, and dataset structure.

The project focuses on simple but meaningful analytics instead of just displaying raw data.

---

## Features

- Load and analyze CP problem data from CSV
- Performance report (user-based analytics)
- Weak topic detection
- Strong topic detection
- Problem recommendations
- Search problems by name
- Dataset summary (data overview)
- Interactive terminal-based menu system

---

## CSV File Format

The program reads data in the following format:

name,rating,topic,solved

### Example:

Two Sum,800,Arrays,1  
Binary Search,1200,Search,1  
Sliding Window,1300,Arrays,0  
DP Knapsack,1900,DP,0  
Graph BFS,1100,Graphs,1  
Graph DFS,1400,Graphs,0  

### Field Description:
- name: Problem name
- rating: Difficulty rating of the problem
- topic: Category of the problem (Arrays, DP, Graphs, etc.)
- solved: 1 if solved, 0 if not solved

---

## How to Run

### Step 1: Compile the program

Run the following command in the project folder:

g++ main.cpp Analyzer.cpp -o app

---

### Step 2: Run the program

On Windows:

app.exe

or

./app

On Linux / Mac:

./app

---

## How to Use

1. Run the program
2. Load a CSV file (example: problems.csv)
3. Choose an option from the menu
4. View analysis results

---

## Menu Options

1. Load CSV file  
2. Performance Report  
3. Weak Topics  
4. Strong Topics  
5. Recommendations  
6. Search Problem  
7. Dataset Summary  
8. Help  
9. Exit  

---

## What Each Feature Means

### Performance Report
Shows user performance based on solved problems:
- total problems
- solved and unsolved count
- success rate
- skill score (average rating of solved problems)

---

### Weak Topics
Shows topics where performance is low based on success rate.

---

### Strong Topics
Shows topics where performance is high based on success rate.

---

### Recommendations
Suggests unsolved problems based on difficulty level.

---

### Dataset Summary
Shows structure of dataset:
- total problems
- total topics
- most frequent topic
- hardest problem
- easiest problem

This section is not about user performance, but about understanding the dataset itself.

---

## How to Create CSV File

If you don’t already have a CSV file:

1. Open Excel or Google Sheets
2. Create columns: name, rating, topic, solved
3. Enter your problem data
4. Export as .csv file
5. Place it in the project folder
6. Enter filename when prompted in the program

---


## Tech Stack

C++  
Standard Template Library (STL)  
File Handling  
Command Line Interface  

---


## Note

This project is a basic analytics tool for competitive programming practice tracking. It is designed to be simple, interactive, and extendable for future improvements like better recommendation systems or platform integrations.