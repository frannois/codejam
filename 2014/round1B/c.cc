
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void solve() {
    int i,j,N, M, min,minPos, s, e;
    cin >> N >> M;
    int zips[N];
    vector<int> con[N];
    vector<int> travel;
    
    cin >> zips[0];
    min = zips[0];
    minPos = 0;
    for (i = 1 ; i < N ; i++) {
        cin >> zips[i];
        if(zips[i] < min) {
            minPos = i;
            min = zips[i];
        }
    }
    
    for ( i = 0 ; i < M ; i++) {
        cin >> s >> e;
        con[s-1].push_back(e-1);
        con[e-1].push_back(s-1);
    }
    
    travel.push_back(minPos);
    cout << zips[minPos];
    while (travel.size() > 0) {
        //look at what ine we are
        i = travel.top();
        if(con[i].size() == 0 ) travel.pop();
        else {
            minPos = -1;min = -1;
            for (j = 1 ; j < con[i].size() ; j++) {
                if(con[i][j] < min && ) {
                    minPos = jat;
                    min =
                }
            }
        }
        
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
