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

int* solve(int ccVal, int nbItems){

    int i,j,k;
    int a[nbItems];
    fo(i,0,nbItems)
    cin >> a[i];
    
    int *b = new int[3];
    b[0] = ccVal;
    b[1] = -1;
    b[2] = -1;

    fo(i,0,nbItems){
        fo(j,i+1,nbItems){
            k = ccVal - a[i] - a[j];
            if( k >= 0 && k < b[0] ) {
            b[0] = k;
            b[1] = i+1;
            b[2] = j+1;
            }
            
        }
    }
            
    return b;
}

int main( )
{
	int  i,t, tt,ccVal,nbItems;
    int* a;
    string str;
	cin >> tt;

	for( t = 1; t <= tt; ++ t )
	{
		cout << "Case #" << t <<": " ;
        cin >> ccVal;
        cin >> nbItems;
        a = solve(ccVal, nbItems);
        cout << a[1] << " " << a[2] << endl;
    }
       
	

	return 0;
}
