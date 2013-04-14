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
#include <stdint.h>


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

uint64_t first, second;
bool isPalindrome(uint64_t a) {
    
    if (a < 10 ) return true;

    stringstream ss;
    ss << a;
    string str = ss.str();
    //cout << "is Palindrome " << str << endl;
    int s = str.size();
    for (int i = 0 ; i <= s/2; i++) {
        if (str[i] != str[s-1-i] )
        { 
            //cout << " it isn't" << str[i] << " " << str[s-1-i] << endl;
            return false;
        }
    }
    return true;
}


int solve() {

  int answer = 0;
  uint64_t i,j,s,e;
  cin >> s >> e;
  for ( i = s ; i <= e ; i++) {
      //cout << "h" << endl;
      if (!isPalindrome(i)) continue;
      if  ( i - 100000000 > 0) {
      j = sqrt(i);
      if(j*j == i && isPalindrome(j))
    	  answer++;
      }else
      answer++;
      
    }
  return answer;

}

int main() {
    int i,t;
	cin >> t;

	fo(i,0,t){
        cout << "Case #" << i+1 << ": " << solve();
		cout <<endl;
	}
	
	return 0;
}

