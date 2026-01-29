#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class JunctionBox {
 public:
  int x;
  int y;
  int z;
  int circuit;
  JunctionBox(int x, int y, int z, int circuit)
      : x(x), y(y), z(z), circuit(circuit) {}
  JunctionBox() : x(0), y(0), z(0), circuit(0) {}

  string toString() const {
    return to_string(this->x) + ", " + to_string(this->y) + ", " +
           to_string(this->z) + ", " + to_string(this->circuit);
  }
};

double distance(JunctionBox* a, JunctionBox* b);

class JunctionPair {
 public:
  JunctionBox* a;
  JunctionBox* b;
  double dist;
  JunctionPair(JunctionBox* a, JunctionBox* b)
      : a(a), b(b), dist(distance(a, b)) {}

  bool operator<(const JunctionPair& other) const {
    return other.dist < this->dist;
  }

  string toString() const {
    return this->a->toString() + ", " + this->b->toString() +
           " Dist=" + to_string(this->dist);
  }
};

double distance(JunctionBox* a, JunctionBox* b) {
  return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
}

#define CONNECTIONS 10

int main() {
  vector<JunctionBox> boxes;

  string line;
  while (getline(cin, line)) {
    stringstream ss(line);

    JunctionBox b;
    char comma;
    ss >> b.x >> comma >> b.y >> comma >> b.z;
    boxes.push_back(b);
  }

  // vector of vectors of box pointers - merge 2 vectors

  // brute force approach

  // find all possible distances
  priority_queue<JunctionPair> pq;

  for (JunctionBox& a : boxes) {
    for (JunctionBox& b : boxes) {
      // if they point to the same box, skip
      if (&a == &b) continue;

      // otherwise create entry
      pq.emplace(&a, &b);
    }
  }

  // circuit history
  vector<JunctionBox*> hist;

  unordered_map<int, int> counts;
  int circuit_id = 1;
  for (int i = 0; i < CONNECTIONS; i++) {
    cout << "CONNECTION " << i << endl;
    // find the closest pair of boxes
    JunctionPair jp = pq.top();
    pq.pop();

    hist.push_back(jp.a);
    hist.push_back(jp.b);

    // merge their circuits
    if (jp.a->circuit == 0 && jp.b->circuit == 0) {
      jp.a->circuit = circuit_id;
      jp.b->circuit = circuit_id;
      counts[circuit_id] = 2;
      circuit_id++;
    } else if (jp.a->circuit == 0) {
      jp.a->circuit = jp.b->circuit;
      counts[jp.a->circuit]++;
    } else if (jp.b->circuit == 0) {
      jp.b->circuit = jp.a->circuit;
      counts[jp.b->circuit]++;
    } else {
      for (size_t j = 0; j < hist.size(); j++) {
        counts.erase(jp.b->circuit);
        if (hist[j]->circuit == jp.b->circuit) {
          hist[j]->circuit = jp.a->circuit;
          counts[jp.a->circuit]++;
        }
        jp.b->circuit = jp.a->circuit;
        counts[jp.a->circuit]++;
      }
    }
  }

  vector<pair<int, int>> circuit_counts;
  for (auto c : counts) {
    circuit_counts.emplace_back(c.first, c.second);
  }

  sort(circuit_counts.begin(), circuit_counts.end(),
       [](const pair<int, int>& a, const pair<int, int>& b) {
         return a.second < b.second;
       });

  for (auto c : circuit_counts) {
    cout << c.first << " " << c.second << endl;
  }

  return 0;
}