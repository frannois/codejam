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

int n, m;

int main() {

	int i, j, k, l, d, n, z;
	ll answer;
	int index = 0;
	string tmp;
	cin >> l >> d >> n;

	sc words[l];
	long poss[l];
	getline(cin, tmp);

	fo(i,0,d) {
		getline(cin, tmp);

		fo(j,0,l) {
			words[j].insert(tmp[j]);
		}
	}

	fo(i,0,n) { // loop all cases
		cout << "Case #" << i + 1 << ":";
		getline(cin, tmp);
		fo(z,0,l) {
			poss[z] = 0;
		}

			index = 0;
			fo(j,0,l) {
				if (tmp[index] == '(') {
					index++;
					while (tmp[index] != ')') {

						if (words[j].find(tmp[index]) != words[j].end()) {
							poss[j] = poss[j] + 1;
							
						}
						
						index++;
					}

				}
				else if (words[j].find(tmp[index]) != words[j].end()) poss[j] =  1;
				index++;
				cout << poss[j] <<endl;
			}
			answer = 1;
			fo(z,0,l) {
				answer *= poss[z];
			}
			cout << " " << answer << endl;
		

	}

	return 0;
}

