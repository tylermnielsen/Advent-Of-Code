#include <iostream>

using namespace std;

int main() {
  int64_t joltage = 0;
  string num;
  while (cin >> num) {
    // start with last 2 digits
    int first = num[num.length() - 2] - '0';
    int second = num[num.length() - 1] - '0';

    // go backward to find better if it exists
    for (int i = num.length() - 3; i >= 0; i--) {
      // find the max and then the biggest after that
      int curr = num[i] - '0';
      // cout << "\t at = " << curr << endl;
      if (curr >= first) {
        // see if first should become second
        if (first > second) second = first;
        // replace first
        first = curr;
      }
    }

    // check
    // int first_ind = -1;
    // int second_ind = -1;
    // for(size_t i = 0; i < num.length(); i++){
    //   if((first == (num[i] - '0')) && first_ind == -1) first_ind = i;

    //   if(second == (num[i] - '0')) second_ind = i;
    // }
    // if(first_ind >= second_ind){
    //   cout << "error on " << num << endl;
    //   cout << "\t" << first_ind << ", " << second_ind << endl;
    //   break;
    // }

    joltage += first * 10 + second;
    // cout << "\t> " << "+" << (first * 10 + second) << " = " << joltage <<
    // endl;
  }

  cout << "Joltage = " << joltage << endl;

  return 0;
}