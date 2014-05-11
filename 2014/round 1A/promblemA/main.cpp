// my first program in C++
#include <iostream>
#include <string>

string solve() {

  int i, l, n, t;

  cin >> n >> l;

  int outlets[n][l];
  int inputs[n][l];

  for (i = 0 ; i < n*l ; i++) {
    cin >>t;
    outlets[i%n][i%l] = t;
  }
  for (i = 0 ; i < n*l ; i++) {
    cin >>t;
    inputs[i%n][i%l] = t;
  }


}


int main()
{
  int i, n;
  cin >> n;
  for (i = 1 ; i <= n ; i++) {
    cout << "Case #" << i << ":" << solve();
  }
}
