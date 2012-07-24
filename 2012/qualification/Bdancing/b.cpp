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


	int solve(int p,int score) {

		int a,b,c;

		bool specialFound = false;
		for(a = p ; a <=10 ; a++)
			for ( b = a-2 > 0 ? a-2 : 0; b <= a+2 ; b++)
				for (c = a-2 > 0 ? a-2: 0 ; c <= a+2 ; c++)
				{
					if(a+b+c == score){
						//cout <<"score "<< a << " " << b << " " << c << endl;
						if(fabs(a-b) == 2 || fabs(a-c) ==2 || fabs(b-c) ==2)
						{
							//cout <<"special "<< a << " " << b << " " << c << endl;
							specialFound = true;
						}
						else {// cout << a << " " << b << " " << c << endl;
							return 1;}
					}

				}


			if(specialFound) return 2;
			else return 0;
	}


int main() {
		int i,j,t,n,totalspecial,p;
		int nbSpecial,tmp,answer,score;
		cin >> t;
	fo(i,0,t){
		nbSpecial = 0;
		answer = 0;
		cin >> n >> totalspecial >> p;

		fo(j,0,n){
			cin >> score;
				//	cout << "score to have " << score <<endl;
			//cout << "j :"  << j <<endl;
			tmp = 	solve(p,score);

			if(tmp <=1) answer += tmp;
			else 
			{
				nbSpecial++;
				if(nbSpecial <= totalspecial)
				answer +=1;
			}
		}

      cout << "Case #" << i+1 << ": " << answer  << endl;

	}


	return 0;
}

