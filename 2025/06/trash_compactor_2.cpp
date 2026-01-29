#include <stdint.h>

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

  int64_t full_sum = 0;
  char op = ' ';
  int64_t sum = 0;
  for (size_t i = 0; i < lines.at(0).size(); i++) {
    if (lines.at(lines.size() - 1).at(i) != ' ') {
      if (lines.at(lines.size() - 1).at(i) == '*')
        sum = 1;
      else
        sum = 0;
      op = lines.at(lines.size() - 1).at(i);
      // cout << "op = " << op << endl;
    }

    string col = "";
    for (size_t j = 0; j < lines.size() - 1; j++) {
      if (lines.at(j).at(i) != ' ') col += lines.at(j).at(i);
    }

    // cout << col << endl;

    if (col == "") {
      full_sum += sum;
      // cout << "+" << sum << " = " << full_sum << endl;
      sum = 0;
    } else {
      int num = stoi(col);
      if (op == '*')
        sum *= num;
      else
        sum += num;
    }
  }

  // catch last
  full_sum += sum;

  cout << "Answer = " << full_sum << endl;

  return 0;
}