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




int main() {

	int t,i,j,a,b,k,h,n;
	ll answer,tmp,tmpmod;
	cin >> t;
	set<int> found;
	fo(i,0,t){
		cin >> a >> b;

		answer = 0;
		for(j = a ; j <=b; j++){
					k = 10;
			while( j / k > 0) {
				tmp = j / k;
				tmpmod = j % k;
				h = 10;
				n=1;
				while(tmp/h >0){n++;h*=10;}
				tmp =  pow(10,n)*tmpmod + tmp ;

				if(tmp <= b && j < tmp && found.find(tmp) == found.end()){
					found.insert(tmp);
						//cout << tmp << " " << j <<endl;	
					answer++;}
		k *=10;
			}
			found.clear();

		}

      cout << "Case #" << i+1 << ": " << answer  << endl;

	}


	return 0;
}

