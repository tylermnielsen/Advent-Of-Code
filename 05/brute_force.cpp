#include <stdint.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define debug(x) \
  if (true) {    \
    x            \
  }

int main() {
  debug(cout << "Reading ranges from File" << endl;);

  ifstream f("input.txt");

  if (!f.is_open()) return 1;

  vector<pair<uint64_t, uint64_t>> ranges;

  string line;
  getline(f, line);
  while (line != "") {

    stringstream ss(line);

    uint64_t start, stop;
    char dash;

    ss >> start >> dash >> stop;
    ranges.emplace_back(start, stop);

    getline(f, line);
  }

  debug(cout << "Range count: " << ranges.size() << endl;);

  uint64_t count = 0;
  uint64_t num;
  while (getline(f, line)) {
    num = stoull(line); 
    for (const pair<uint64_t, uint64_t>& range : ranges) {
      if (num > range.first && num < range.second) {
        count++;
        break;
      }
    }
  }

  cout << "Total fresh IDs: " << count << endl;

  return 0;
}