#include <iostream>
#include <string>

#define DIAL_MOD 100
#define STARTING_POSITION 50

using namespace std;

int main() {
  int pos = STARTING_POSITION;
  int count = 0;

  string rot;
  while (cin >> rot) {
    int change = stoi(rot.substr(1));
    // do rotation
    if (rot[0] == 'L') {
      pos -= change;
    } else {
      pos += change;
    }

    pos = (pos + DIAL_MOD) % DIAL_MOD;

    if (pos == 0) count++;
  }

  cout << "Password: " << count << endl;

  return 0;
}