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


map<char,char> preload(){

	map<char,char> preload;
		string str,str2;
		str = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		str2 = "our language is impossible to understand";

		for(int i = 0 ; i < str.size() ; i++)
			if(str[i] != ' ')
			preload[str[i]] = str2[i];

	str = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		str2 = "there are twenty six factorial possibilities";

		for(int i = 0 ; i < str.size() ; i++)
			if(str[i] != ' ')
				preload[str[i]] = str2[i];
	str = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
		str2 = "so it is okay if you want to just give up";

		for(int i = 0 ; i < str.size() ; i++)
			if(str[i] != ' ')
				preload[str[i]] = str2[i];

		preload['z'] = 'q';
		preload['q'] = 'z';


return preload;
}



int main() {
		int i,j,t;
		string str,str2;

		map<char,char> dict = preload();
		map<char,char>::iterator it;

		
		
		cin >> t;
		getline(cin,str);
	fo(i,0,t){
		getline(cin,str);
      cout << "Case #" << i+1 << ": ";
		fo(j,0,str.size()){
			if(dict.find(str[j]) != dict.end())
				cout << dict[str[j]];
			else cout << str[j];
		}
		cout <<endl;
	}
	

	return 0;
}

