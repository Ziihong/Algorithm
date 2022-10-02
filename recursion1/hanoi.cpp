#include <iostream>
#define MAX_SIZE 10
using namespace std;

class Stack {
public:
  int idx;
  int stack[MAX_SIZE];

  void init() { idx = -1; }

  bool empty() { return (idx < 0); }

  void push(int n) { stack[++idx] = n; }

  int pop() {
    if (empty()) return 0;
    else return stack[idx--];
  }
  int top() {
    if (empty()) return 0;
    return stack[idx];
  }
};


Stack s;

void hanoi(int n, int a, int b, int c) {

  if (n > 0) {
    hanoi(n - 1, a, c, b);

    if (a == 3) {
      s.pop();
      cout << s.top() << " ";
    }
    if (c == 3) {
      s.push(n);
      cout << s.top() << " ";
    }
    hanoi(n - 1, b, a, c);
  }
}

int main() {
  int t, n;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n;
    s.init();
    hanoi(n, 1, 2, 3);
    cout << '\n';
  }
  return 0;
}
