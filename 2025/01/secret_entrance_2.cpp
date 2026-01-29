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

    // save last
    int old_pos = pos;

    // handle full rotations
    count += change / DIAL_MOD;
    change %= DIAL_MOD;  // remove that movement

    // align sign with direction
    if (rot[0] == 'L') {
      change = -change;
    }

    // make remaining change
    pos += change;

    // if we're "out of bounds" that is another click
    // this will never be a full rotation
    if (((pos + DIAL_MOD) % DIAL_MOD) != 0 &&  // lands are not crosses
        old_pos != 0 &&                        // lands are not crosses
        (pos < 0 || pos > DIAL_MOD - 1)        // out of bounds after change
    ) {
      count++;
    }

    // return to bounds
    pos = (pos + DIAL_MOD) % DIAL_MOD;

    // if we're on 0 that's a click
    if (pos == 0) {
      count++;
    }
  }

  cout << "Password: " << count << endl;

  return 0;
}