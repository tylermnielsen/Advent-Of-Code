#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int64_t joltage = 0;
  string num;
  while (cin >> num) {
    // start with last 12 digits
    int digits[12];

    for (size_t i = 0; i < 12; i++) {
      digits[i] = num[num.length() - (12 - i)] - '0';
    }

    // for(auto d : digits){
    //   cout << d;
    // }
    // cout << endl;

    // go backward to find better if it exists
    for (int i = num.length() - 13; i >= 0; i--) {
      // find the max and then the biggest after that
      int curr = num[i] - '0';
      // cout << "\t at = " << curr << endl;
      // if we can replace the first digit
      if (curr >= digits[0]) {
        // do so and then chain others
        for (size_t j = 0; j < 12; j++) {
          if (curr >= digits[j])
            swap(curr, digits[j]);
          else
            break;
        }
      }
    }

    // check
    int index = 0;
    for (size_t i = 0; i < num.length(); i++) {
      if (digits[index] == (num[i] - '0')) {
        index++;
      }
      if (index == 12) break;
    }
    if (index != 12) {
      cout << "error on " << index << endl;
      cout << "\t" << num << endl;

      int64_t local_jolt = 0;
      for (size_t i = 0; i < 12; i++) {
        local_jolt += digits[i] * pow(10, 12 - 1 - i);
      }
      joltage += local_jolt;
      cout << "\t> "
           << "+" << local_jolt << " = " << joltage << endl;
      break;
    }

    int64_t local_jolt = 0;
    for (size_t i = 0; i < 12; i++) {
      local_jolt += digits[i] * pow(10, 12 - 1 - i);
    }
    joltage += local_jolt;
    // cout << "\t> " << "+" << local_jolt << " = " << joltage << endl;
  }

  cout << "Joltage = " << joltage << endl;

  return 0;
}