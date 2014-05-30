
#include <iostream>
#include <string>

using namespace std;
int n, l;

int check(bool outlets[], bool  inputs[],int  index) {

  // first make the switch
  int i,j;
  bool table[n];
  index--;
  if ( index > 0) {}
  for (i = 0; i < n; i++ ){
    outlets[i*l+index] = !outlets[i*l+index];
  }



}

void solve() {

  int i, tmp;
  char t;

  cin >> n >> l;

  bool outlets[n*l];
  bool inputs[n*l];

  // read the data
  for (i = 0 ; i < n*l ; i++) {
    std::cin >> t;
    outlets[i] = (t == 1 ? true : false);
  }

  for (i = 0 ; i < n*l ; i++) {
    std::cin >>t;
    inputs[i] = (t == 1 ? true : false);
  }

  // brute force
  for (i = 0 ; i <= l ; i++) {
    tmp = check(outlets,inputs,i);
    if (tmp >= 0) {
      std::cout << tmp << endl;
      return;
    }
  }

  std::cout << "NOT POSSIBLE" << endl;

}


int main()
{
  int i, n;
  cin >> n;
  for (i = 1 ; i <= n ; i++) {
    std::cout << "Case #" << i << ":";
    solve();
  }
}
