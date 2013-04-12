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

/*
4
B 5'11" 6'2"
G 5'11" 6'2"
B 3'4" 3'4"
G 1'1" 1'0"
*/


float solve() {
    char s,t;
    int ff,fi,mf,mi,r,bim, bis, bi;

    cin >> s;
    cin >> mf >> t >>mi >> t >> ff >> t >> fi >> t;
    //cout << s << " " << mf << " " << mi << " " << ff << " " << fi;
    
    bi = (mf*12) + (ff*12) + mi + fi;
    
    if (s == 'B') bi += 5; else bi -= 5;

   // cout << bi << endl;
    
    bim = bi / 2;

    if(bi % 2 != 0) {
        bis = bim -3;
    }
    else 
    bis = bim -4;

    bim = bim + 4;
    
    cout << (bis/12) << "'" << (bis%12) << "\"" << " to " << (bim/12) << "'" << (bim%12) << "\"" << endl;
    

    }

int main() {

  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(6);
   int i, n = 0;
   cin >> n;
   fo(i,0,n) {
      cout << "Case #" << (i+1) <<": ";
      solve();
   }

	return 0;
}

