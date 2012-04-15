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




long double solve(){

    int i,x,r,s,n,b,e,w;
    long double t = 0.0,time=0.0,remainingDist,tmp ;
    cin >> x >> s >> r >> t >> n;
    map<int,int> walkways;


    fo(i,0,n){
        cin >> b >> e >> w;
        if(walkways.find(w) == walkways.end())
        {
         walkways[w] = e - b;
        }
        else    walkways[w] += e - b;

        x-= e-b;
    }

     if(walkways.find(0) == walkways.end())
        {
         walkways[0] = x;
        }
        else    walkways[0] += x;


    map<int,int>::iterator it ;

    for(it= walkways.begin(); it != walkways.end() ; it++)
    {
        //cout << (*it).first << " " << (*it).second << endl;
        if(t > 0 ) {
        //we have running time left;
        remainingDist = (it->first + r) * t;
        tmp = (long double) it->second / (it->first + r);
        if(remainingDist > it->second){
            time += tmp;
            t -= tmp;
            //cout << tmp << " ";
        }
        else {
            time += (long double)remainingDist/(r + it->first) + (long double)(it->second - remainingDist)/(s + it->first);
            t = 0;
          //  cout << (long double)remainingDist/(r + it->first) + (long double)(it->second - remainingDist)/(s + it->first) << " ";
        }
        }
        else {

            time += (long double)(it->second)/(s + it->first);
            //cout << (long double)(it->second)/(s + it->first) << " ";
        }

    }

    return time;


}

int main() {

	int t,i;
	cin >> t;
	fo(i,0,t){

      cout << "Case #" << i+1 << ": " << setiosflags(ios::fixed) << setprecision(6)  <<  (long double)solve() << endl;
	}


	return 0;
}

