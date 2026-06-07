# CP Performance Analyzer (C++)

## Overview
A C++ project that analyzes competitive programming performance using CSV data.

## Features
- Reads problem data from CSV
- Calculates total problems solved
- Computes average rating
- Finds hardest problem
- Topic-wise analysis
- Finds strongest topic

## Tech Stack
- C++
- STL (vector, map)
- File handling

## Project Structure
- main.cpp → loads data
- Analyzer.cpp → analytics logic
- Problem.h → data model

## How to Run
```bash
g++ main.cpp Analyzer.cpp -o app
./app