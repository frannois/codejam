#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>
#include <iomanip>
#include <sstream>

#define fo(a,b,c) for( a = ( b ); a < ( c );  a++ )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

using namespace std;
int ni() {
	int a;
	scanf("%d", &a);
	return a;
}

char sbuf[100005];
string ns() {
	scanf("%s", sbuf);
	return sbuf;
}
long long nll() {
	long long a;
	scanf("%lld", &a);
	return a;
}

typedef long long ll;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<char> sc;
typedef pair<int, int> pii;
typedef map<string, int> msi;


void solve() {

  int answer = 0;
  int n,m,i,j,k,l;
  cin >> n >> m;
  int grass[n][m];
  int max =1;
  bool isOKVert, isOKHor;
  for(i = 0 ; i < n; i++) {
      for (j = 0 ; j < m ; j++) {
          cin >> grass[i][j];
          //cout << grass[i][j] << " ";
          if(grass[i][j] > max) max = grass[i][j];
    }
//cout << endl;
  }
  
    for(i = 0 ; i < n ; i++) {
      for (j = 0 ; j < m ; j++) {

         if(grass[i][j] != max)
           {
               isOKVert = true;
               isOKHor = true;
                        //horizontal exit
            for(k = 0 ; k < m; k++) {
                if(grass[i][k] > grass[i][j]) isOKHor = false;
            }
                        //vertical exit
                for(k = 0 ; k < n; k++) {
                if(grass[k][j] > grass[i][j]) isOKVert = false;
            }
            
            if(!isOKVert && !isOKHor) {
            cout << "NO" ;
            return;
               }

    }
  }
}
  
  cout << "YES";
  return ;

}

int main() {
    int i,t;
	cin >> t;

	fo(i,0,t){
        cout << "Case #" << i+1 << ": ";
        solve();
		cout <<endl;
	}
	
	return 0;
}

