#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  // scan tree
  vector<string> tree;
  vector<vector<int64_t>> tracking;

  string line;
  while (getline(cin, line)) {
    tree.push_back(line);
    tracking.emplace_back(line.length(), 0);
  }

  unordered_set<int> gen;

  int64_t splits = 0;
  // fire beam
  for (size_t i = 0; i < tree.at(0).length(); i++) {
    if (tree.at(0)[i] == 'S') {
      gen.insert(i);
      tracking.at(0).at(i) = 1;
      break;
    }
  }

  for (size_t y = 1; y < tree.size(); y++) {
    // propagate gen
    unordered_set<int> next_gen;

    for (int x : gen) {
      // no split
      if (tree.at(y)[x] != '^') {
        tree.at(y)[x] = '|';  // update tree
        tracking.at(y)[x] += tracking.at(y - 1)[x];
        next_gen.insert(x);  // add to next gen
      } else {               // split
        splits++;
        if (x - 1 >= 0) {
          tree.at(y)[x - 1] = '|';
          tracking.at(y)[x - 1] += tracking.at(y - 1)[x];
          next_gen.insert(x - 1);
        }
        if (x + 1 < (int)tree.at(0).size()) {
          tree.at(y)[x + 1] = '|';
          tracking.at(y)[x + 1] += tracking.at(y - 1)[x];
          next_gen.insert(x + 1);
        }
      }
    }

    gen = next_gen;
  }

  for (auto r : tree) {
    cout << r << endl;
  }
  cout << endl;

  cout << "Splits = " << splits << endl;

  for (auto r : tracking) {
    for (auto c : r) {
      cout << c << " ";
    }
    cout << endl;
  }
  cout << endl;

  int64_t timelines = 0;
  for (size_t i = 0; i < tracking.at(0).size(); i++) {
    timelines += tracking.at(tracking.size() - 1).at(i);
  }

  cout << "Timelines = " << timelines << endl;

  return 0;
}