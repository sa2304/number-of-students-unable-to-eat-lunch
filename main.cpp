#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    // FIXME
    return 0;
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
    assert(1 == s.countStudents(students, sandwiches));
  }
}

int main() {
  TestCountStudents();
  std::cout << "Ok!" << std::endl;
  return 0;
}
