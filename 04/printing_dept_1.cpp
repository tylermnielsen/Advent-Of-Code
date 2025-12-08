#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_grid(vector<vector<char>> map) {
  for (auto y : map) {
    for (auto x : y) {
      cout << x;
    }
    cout << endl;
  }
}

int main() {
  vector<vector<char>> map;

  string line;
  while (getline(cin, line)) {
    vector<char> row;
    for (char c : line) {
      row.push_back(c);
    }
    map.push_back(row);
  }

  int count = 0;

  // print_grid(map);
  for (int y = 0; y < (int)map.size(); y++) {
    for (int x = 0; x < (int)map[0].size(); x++) {
      if (map[y][x] == '@') {
        // check around
        int filled_spaces = -1;  // account for middle that shouldn't count
        for (int y_mod = y - 1; y_mod <= y + 1; y_mod++) {
          for (int x_mod = x - 1; x_mod <= x + 1; x_mod++) {
            if (y_mod >= 0 && y_mod < (int)map.size() && x_mod >= 0 &&
                x_mod < (int)map[0].size() && map[y_mod][x_mod] == '@')
              filled_spaces++;
          }
        }
        if (filled_spaces < 4) count++;
      }
    }
  }

  cout << "Accessible rolls = " << count << endl;

  return 0;
}