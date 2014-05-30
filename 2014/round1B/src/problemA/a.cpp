#include <iostream>
#include <string>
#include <limits>

using namespace std;

int removeDuplicates(string small, string other) {
 //   aabc
 //   abcc
    int i = 0, j = 0, delta = 0;

    while (j < other.length()) {
       // cout << i << " " << j << " " << small[i] << other[j] << " " << delta << endl;
        if (small[i] != other[j]) {
            if (i == 0) {
                return -1;
            } else if (small[i - 1] == other[j]) {
                j++;
                delta++;
            } else if (other[j - 1] == small[i]) {
                i++;
                delta++;
            } else
                return -1;
        } else {
            i++;
            j++;
        }

    }
    return delta;
}

void solve() {

    int i, n, max = std::numeric_limits<int>::min(), tmp, t = 0, tPos = 0;
    cin >> n;
    string values[n];

    for (i = 0; i < n; i++) {
        cin >> values[i];
        tmp = values[i].length();
        if (i == 0) {
            t = tmp;
        } else if (tmp < t) {
            t = tmp;
            tPos = i;
        }
    }
 //   std::cout << "tPos " << tPos << " " << values[tPos] << endl;
    for (i = 0; i < n; i++) {
        if (i != tPos) {
            t = removeDuplicates(values[tPos], values[i]);
            if (t == -1) {
                std::cout << "Fegla Won" << endl;
                return;
            }
            else if (t > max)
                max = t;
        }
    }

    std::cout << (max) << endl;

}

int main() {
    int i, n;
    cin >> n;
    for (i = 1; i <= n; i++) {
        std::cout << "Case #" << i << ": ";
        solve();
    }
}
