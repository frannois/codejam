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

long solve(string str) {

	int i,base;
	unsigned long answer = 0;
	map<char,int> values;
	fo(i,0,str.size()){
		if(values.find(str[i]) == values.end())
		{
			if ( i == 0)
				values[str[i]] = 1;
			else if ( values.size() == 1)
				values[str[i]] = 0;
			else
				values[str[i]] = values.size()-1;
		}
	}

	base = values.size();
	if(base ==1)base++;
	//cout << base << " ";
	map<char,int>::iterator it;

	fo(i,0,str.size()){
		answer *= base;
		answer += (int)values.find(str[i])->second;
	}
		return answer;


}

int main() {

    int i,t;
	string str;
	cin >> t;
	
    fo(i,0,t) {
		
		cin >> str;
		cout << "Case #" << i+1 << ": " << solve(str) << endl;

    }

	return 0;
}

