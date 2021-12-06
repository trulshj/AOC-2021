#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<int> read_data() {
  ifstream infile("input.txt");

  vector<int> data;
  int x;
  while (infile >> x) {
    data.push_back(x);
  }
  return data;
}

int part1(vector<int> const &data) {
  int increasing = 0;

  for (size_t i = 1; i < data.size(); ++i) {
    if (data[i - 1] < data[i])
      increasing++;
  }

  return increasing;
}

int part2(vector<int> const &data) {
  int increasing = 0;

  int a, b;

  for (size_t i = 4; i <= data.size(); ++i) {
    a = accumulate(data.begin() + i - 4, data.begin() + i - 1, 0);
    b = accumulate(data.begin() + i - 3, data.begin() + i, 0);
    if (a < b)
      increasing++;
  }

  return increasing;
}

int main() {
  cout << "--- AOC 2021 Day 01 ---" << endl;

  vector<int> data = read_data();
  cout << "Part 1: " << part1(data) << endl;
  cout << "Part 2: " << part2(data) << endl;
}
