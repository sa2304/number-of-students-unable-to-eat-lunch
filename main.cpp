#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int other(int s) {
    return (0 == s) ? 1 : 0;
  }

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
        int preference = other(f);
        hungry_count = count_if(students.begin(), students.end(), [preference](int p) {
          return p == preference;
        });
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
