#include <iostream>
#include <vector>
#include <algorithm>

#define all(c) c.begin(), c.end()
#define tr(container, it) \
  for(typeof((container).begin()) it = (container).begin(); it != (container).end(); it++)

using namespace std;

int main(void)
{
  // vector<int> v;

  // for (int i = 0; i < 3; i++)
    // v.push_back(i);
  string v = "hello";

  vector<int>::iterator it;
  do {
    tr(v, it)
    {
      cout << *it << " ";
    }
    cout << endl;
  } while (next_permutation(all(v)));
}
