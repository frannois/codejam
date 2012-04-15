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




string solve (const string& mainString){

	if (mainString.size() <= 1) return "";
	string answer = "";
	string tmpAnswer;
	for(int i = 0 ; i < mainString.size() ; i++) {
		
		for(int j = 0 ; j < mainString.size() && i+j < mainString.size() - j; j++){
			tmpAnswer = mainString.substr(i,j+1);
			//cout << tmpAnswer << endl;
			for(int k = i+1 ; k < mainString.size() - tmpAnswer.size() ; k++){
				if(tmpAnswer == mainString.substr(k,tmpAnswer.size()) && tmpAnswer.size() > answer.size()){
					//cout << "answer " << tmpAnswer << endl;
					answer = tmpAnswer;
				}

			}

		}
	

	}

	
	
	return answer;
}

int main() {




      cout << solve("abababababababababa") << endl;
	


	return 0;
}

