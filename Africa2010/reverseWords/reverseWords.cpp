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
int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

int n, m;

int main( )
{
	int  t, tt,nbOfChars;
    string str;
	cin >> tt;
    getline(cin, str);
	for( t = 1; t <= tt; ++ t )
	{
		cout << "Case #" << t <<": " ;
        getline(cin, str);
        nbOfChars = 0 ;
        for (int stringPos = str.size() - 1; stringPos >= 0 ; stringPos--) {
            nbOfChars++;
            if( stringPos == 0) {
                cout << str.substr(stringPos,nbOfChars) << endl;
            }
            else if (str[stringPos] == ' '){
               cout << str.substr(stringPos + 1,nbOfChars -1) << " ";
                nbOfChars = 0;
            }
            
        }
       
	}

	return 0;
}
