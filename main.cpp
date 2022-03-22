#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countStudents(vector<int> &students, vector<int> &food) {
    int hungry_count = 0;
    auto front = students.begin();
    for (int f: food) {
      auto iter = find(front, students.end(), f);
      iter = (students.end() != iter) ? iter : find(students.begin(), front, f);
      if (*iter == f) {
        *iter = -1;
        front = next(iter);
      } else {
        auto last = partition(students.begin(), students.end(), [](int p) {
          return -1 != p;
        });
        hungry_count = distance(students.begin(), last);
        break;
      }
    }

    return hungry_count;
  }
};

void TestCountStudents() {
  Solution s;
  {
    vector<int> students{1, 1, 0, 0};
    vector<int> sandwiches{0, 1, 0, 1};
    assert(0 == s.countStudents(students, sandwiches));
  }
  {
    vector<int> students{1, 1, 1, 0, 0, 1};
    vector<int> sandwiches{1, 0, 0, 0, 1, 1};
    assert(3 == s.countStudents(students, sandwiches));
  }
  {
    vector<int> students{1, 1};
    vector<int> sandwiches{0, 1};
    assert(2 == s.countStudents(students, sandwiches));
  }
}

int main() {
  TestCountStudents();
  std::cout << "Ok!" << std::endl;
  return 0;
}
