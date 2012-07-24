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

char space[30][30];

int bounce(int x, int y,int myX,int myY,float  dUpToNow,int d)
{

	int cursorY = myY+y;
	int cursorX = myX+x;
	int i = 0;
	while(space[cursorX][cursorY] != '#' && space[cursorX][cursorY] != 'X')
		{cursorY += x;cursorX += y;i+=fabs(y)+fabs(x);}


	if( sqrt(i)+ dUpToNow <= d)
		{

		if (space[cursorX][cursorY] == 'X') {cout<< "X" << endl;return 1;}
		if (space[cursorX][cursorY] == '#' && space[cursorX-x][cursorY] == '#' && space[cursorX][cursorY-y] == '#'){
			cout << "corner" <<endl;
			return bounce(-x,-y,cursorX,cursorY,sqrt(i)+dUpToNow,d);}
			if (space[cursorX][cursorY] == '#')
				{		cout << " bigger" <<endl;return bounce(y,x,cursorX,cursorY,sqrt(i )+dUpToNow,d);}
			
		}

	return 0;
	}

int solve() {

ll i,j,h,w,d;
int myX,myY;
int answer = 0;
int cursorX,cursorY;
cin >> h >> w >> d;


	fo(i,0,h)
		fo(j,0,w){
		
			cin >> space[i][j];
			if(space[i][j] == 'X')
				{ myX = i; myY = j;}
			}

	//up
	cursorX = myX;
	i = 0;
	while(space[cursorX][myY] != '#')
		{cursorX--;i++;}
	
	if( ((i - 1)+0.5)*2 <= d)
		{
		cout << "up" << i <<endl;
		answer++;
		}
	//down
	cursorX = myX;
	i = 0;
	while(space[cursorX][myY] != '#')
		{cursorX++;i++;}

	if( ((i - 1)+0.5)*2 <= d)
		{
		cout << "down" << i <<endl;
		answer++;
		}

	//right
	cursorY = myY;
	i = 0;
	while(space[myX][cursorY] != '#')
		{cursorY++;i++;}

	if( ((i - 1)+0.5)*2 <= d)
		{
		cout << "right" << i <<endl;
		answer++;
		}

		//left
	cursorY = myY;
	i = 0;
	while(space[myX][cursorY] != '#')
		{cursorY--;i++;}

	if( ((i - 1)+0.5)*2 <= d)
		{
		cout << "left" << i <<endl;
		answer++;
		}

	answer += bounce(1,1,myX,myY,0.0,d);
	answer += bounce(1,-1,myX,myY,0.0,d);
answer += bounce(-1,1,myX,myY,0.0,d);
answer += 	bounce(-1,-1,myX,myY,0.0,d);

return answer;
}



int main() {
		int i,j,t;
	
		
		cin >> t;
		
	fo(i,0,t){
		
      cout << "Case #" << i+1 << ": " << solve() << endl;
		
	}
	

	return 0;
}

