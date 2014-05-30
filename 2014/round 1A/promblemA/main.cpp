
#include <iostream>
#include <string>

using namespace std;

int n, l;
vector<string> outlets, inputs;



string solve() {
    
    int i;
    string t;
    
    cin >> n >> l;
    
    for (i = 0 ; i < n ; i++) {
        cin >> outlets[i];
    }
    for (i = 0 ; i < n ; i++) {
        cin >> inputs[i];
    }

    sort(outlets.begin(), outlets.end());
    
    for (i = 0; i < n ; i++) {
        vector<string> d = outlets;
        
    }
    
    
}


int main()
{
    int i, j;
    cin >> j;
    for (i = 1 ; i <= j ; i++) {
        cout << "Case #" << i << ":" << solve();
    }
}
