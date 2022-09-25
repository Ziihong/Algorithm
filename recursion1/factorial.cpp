#include <iostream>

using namespace std;

long long factorial(int n) {
  if (n == 0)
    return 1;
  long long answer = n * factorial(n - 1) % 1000000;
  while (answer % 10 == 0) { // 0 제거
    answer /= 10;
  }
  return answer;
}

int main() {
  int t, n;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n;
    cout << factorial(n) % 1000 << endl;
  }
  return 0;
}