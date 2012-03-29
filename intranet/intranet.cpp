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
int ni() {
	int a;
	scanf("%d", &a);
	return a;
}
double nf() {
	double a;
	scanf("%lf", &a);
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

ll solve(int l) {

	int i,j,tmp;
	int solutions =0;


	int windows[l][2];

	fo(i,0,l){
	cin >> tmp;
	windows[i][0] = tmp;
	cin >> tmp;
	windows[i][1] = tmp;
	}
		

	fo(i,0,l-1){
		fo(j,i+1,l){
			if( (windows[i][0] > windows[j][0] && windows[i][1] < windows[j][1]) ||
				(windows[i][0] < windows[j][0] && windows[i][1] > windows[j][1]) ){
				solutions++;}}}


	return solutions;
}


int main() {
   
	int i,t,l;
	cin >> t;
	fo(i,0,t){
		cin >> l;
      cout << "Case #" << i+1 << ": " <<  solve(l) << endl;
	}
    

	return 0;
}

