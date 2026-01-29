#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> lines;

  // read in column
  string line;
  while (getline(cin, line)) {
    lines.push_back(line);
  }

  vector<string> operators;
  string op;
  stringstream last(lines[lines.size() - 1]);
  while (last >> op) {
    operators.push_back(op);
  }

  vector<int64_t> sums(operators.size(), 0);
  for (size_t i = 0; i < sums.size(); i++) {
    if (operators.at(i) == "*") sums.at(i) = 1;
  }
  // iterate through all but the last line
  for (size_t i = 0; i < lines.size() - 1; i++) {
    stringstream ss(lines.at(i));
    int num;
    int j = 0;
    while (ss >> num) {
      if (operators.at(j) == "*") {
        sums.at(j) *= num;
      } else {  // == "+"
        sums.at(j) += num;
      }
      j++;
    }
  }

  int64_t full_sum = 0;
  for (size_t i = 0; i < sums.size(); i++) {
    // cout << sums[i] << " ";
    full_sum += sums.at(i);
  }
  // cout << endl;

  cout << "Answer = " << full_sum << endl;

  return 0;
}