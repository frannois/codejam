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


float solve() {
    
    float ans = 0;
    int i =1,n;
    
    cin >> n;
    float b[n];
    
    cin >> b[0] >> b[1];
    
    while ( i < n -1 ) {
        cin >> b[i+1];
        ans = (b[i-1] + b[i+1]) /2;
        if ( ans < b[i] ) b[i] = ans;
        //cout << b[i] << endl;
        i++;
    }
    
    
    return b[i-1];
    }

int main() {

  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(6);
   int i, n = 0;
   cin >> n;
   fo(i,0,n) {
       cout << "Case #" << (i+1) << ": " << solve() << endl;
   }

	return 0;
}

