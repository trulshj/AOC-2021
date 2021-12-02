#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<pair<string, int>> read_data() {
  ifstream infile("input.txt");

  vector<pair<string, int>> data;
  string op;
  int val;
  while (infile >> op >> val) {
    data.push_back(make_pair(op, val));
  }
  return data;
}

int part1(vector<pair<string, int>> data) {
  int horizontal = 0;
  int depth = 0;

  for (auto x : data) {
    if (x.first == "forward") {
      horizontal += x.second;
    } else if (x.first == "down") {
      depth += x.second;
    } else {
      depth -= x.second;
    }
  }
  return horizontal * depth;
}

int part2(vector<pair<string, int>> data) {
  int horizontal = 0;
  int depth = 0;
  int aim = 0;

  for (auto x : data) {
    if (x.first == "forward") {
      horizontal += x.second;
      depth += x.second * aim;
    } else if (x.first == "down") {
      aim += x.second;
    } else {
      aim -= x.second;
    }
  }
  return horizontal * depth;
}

int main() {
  cout << "--- AOC 2021 Day 02 ---" << endl;

  vector<pair<string, int>> data = read_data();
  cout << "Part 1: " << part1(data) << endl;
  cout << "Part 2: " << part2(data) << endl;
}
