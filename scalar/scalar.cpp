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
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

int n, m;



int main( )
{
	int  i,j,t, tt,nbItems;
    ll tmp; 
    vi a,b;
	cin >> tt;

	for( t = 1; t <= tt; ++ t )
	{
		cout << "Case #" << t <<": " ;
        cin >> nbItems;
        fo(i,0,nbItems){
            cin >> tmp;
            a.pb(tmp);
            }
         fo(i,0,nbItems){
            cin >> tmp;
            b.pb(tmp);
            }
            tmp = 0;
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
           fo(i,0,nbItems){
            tmp+= a.at(i)*b.at(nbItems-1-i);
            }       
                cout << tmp << endl;
            a.clear();
            b.clear();
    }
       
	

	return 0;
}
