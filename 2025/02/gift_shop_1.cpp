#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int64_t scan_repeats(int64_t start, int64_t stop) {
  int64_t sum = 0;
  for (int64_t i = start; i <= stop; i++) {
    string num = to_string(i);
    if (num.substr(0, num.length() / 2) == num.substr(num.length() / 2)) {
      sum += i;
    }
  }
  return sum;
}

int main() {
  vector<pair<int64_t, int64_t>> ranges;

  while (cin.peek() != EOF) {
    char dash, comma;
    int64_t first, second;
    cin >> first >> dash >> second >> comma;
    ranges.emplace_back(min(first, second), max(first, second));
  }

  cout << "Range Count: " << ranges.size() << endl;

  // sort ranges by start
  sort(ranges.begin(), ranges.end(),
       [](const pair<int64_t, int64_t>& a, const pair<int64_t, int64_t>& b) {
         return a.first < b.first;
       });

  int64_t base = 0;
  int64_t count = 0;

  // iterate add ranges
  for (size_t i = 0; i < ranges.size(); i++) {
    // cout << "Range: " << ranges.at(i).first << " " << ranges.at(i).second <<
    // " (Base = " << base << ")" << endl;
    int64_t start = ranges.at(i).first;
    int64_t stop = ranges.at(i).second;

    // catch entire range already passed
    if (stop < base) {
      continue;  // useless range
    }

    // catch overlap
    if (base > start) {
      start = base;
    }

    // cout << i << "/" << ranges.size() << " " << start << " " << stop << "
    // Searching range of " << stop - start << " = " << endl;
    count += scan_repeats(start, stop);
    // cout << "\t" << count << endl;

    base = stop + 1;
  }

  cout << "Invalid ID count: " << count << endl;

  return 0;
}