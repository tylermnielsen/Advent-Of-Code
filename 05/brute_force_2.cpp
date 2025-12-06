#include <stdint.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define debug(x) \
  if (true) {    \
    x            \
  }

int main(int argc, char ** argv) {
  debug(cout << "Reading ranges from File" << endl;);

  ifstream f(argv[1]);

  if (!f.is_open()) return 1;

  vector<pair<int64_t, int64_t>> ranges;

  string line;
  getline(f, line);
  while (line != "") {

    stringstream ss(line);

    int64_t start, stop;
    char dash;

    ss >> start >> dash >> stop;
    ranges.emplace_back(start, stop);

    getline(f, line);
  }

  debug(cout << "Range count: " << ranges.size() << endl;);

  // sort ranges by start 
  sort(ranges.begin(), ranges.end(), [](const pair<int64_t, int64_t>& a, const pair<int64_t, int64_t>& b) {
    return a.first < b.first; 
  });

  int64_t base = 0; 
  int64_t count = 0; 

  // iterate add ranges
  for(size_t i = 0; i < ranges.size(); i++){
    // cout << "Range: " << ranges.at(i).first << " " << ranges.at(i).second << " (Base = " << base << ")" << endl;
    int64_t start = ranges.at(i).first; 
    int64_t stop = ranges.at(i).second; 

    // catch entire range already passed 
    if(stop < base){
      continue; // useless range 
    }

    int64_t comp = 0; 
    // catch overlap 
    if(base > start) {
      start = base; 
    } else {
      // if no overlap compensate to make inclusive 
      comp = 1; 
    }

    // cout << "\tadding range of " << stop - start << endl; 
    count += stop - start + comp;
    // cout << "\ttotal range " << count << endl; 
    
    base = stop; 
  }

  cout << "Total IDs in fresh ranges: " << count << endl;

  return 0;
}