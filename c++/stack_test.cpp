#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
  stack<int> s;
  s.push(1);
  cout << s.top();
  return 0;
}
