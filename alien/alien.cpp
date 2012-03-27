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

int l,d,n;

int solve(vs words) {
    int i,index = 0;
    string str;
    set<char> letters;
    //get scientists line
    getline(cin,str);
    fo(i,0,l) {
        if(words.size() == 0)
            return 0;
            
       if(str[index] == '('){
           index++;
           while(str[index] != ')'){
            letters.insert(str[index]);
            index++;
           }
       }
       else letters.insert(str[index]);
       
            for(vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
                if( letters.find((*it)[i]) == letters.end())
                    words.erase(it,it);
            }
            
        letters.clear();
        index++;
    
    }

}


int main() {
    string str;
    int i;
	cin >> l >> d >> n >> str;
    vs words;
    fo(i,0,d) {
        getline(cin,str);
        words.pb(str);
        }
    
    fo(i,0,n){
      cout << "Case #" << i+1 << ": " <<  solve(words);
    }

	return 0;
}

