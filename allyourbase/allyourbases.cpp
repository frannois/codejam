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


int solve(int n, int k) {
   
	char board[n][n];
	int i,j,y,z;
	bool redWin = false, blueWin = false;
//cout << n << " " << k << endl;
	for ( j = n-1 ; j >=0 ; j--){
		fo(i,0,n){
			cin >> board[j][i];
			//cout << board[j][i];
		}
			//cout <<endl;
	}


	//cout <<endl;cout <<endl;

	for (j = n-1 ; j >= 0 ; j--)
		fo(i,0,n) {
			if(board[i][j] == '.') {
				z = j - 1;
				while( z >= 0)
				{
					if(board[i][z] != '.') {
						board[i][j] = board[i][z];
						board[i][z] = '.';
						break;
					}
					z--;
				}
			}

		}

	/*fo(j,0,n){
		fo(i,0,n){
			cout << board[i][j];
		}
		cout <<endl;
	}	*/
	for (j = n-1 ; j >= 0 ; j--)
		fo(i,0,n) {
			if(board[i][j] != '.') {

			
			//check for hor line
			z = i+1;
			while (z < n && z < i+k)
			{
				if(board[z][j] != board[i][j])
					break;
				z++;
			}
			if(z == i+k)
				if(board[i][j] == 'R')
					redWin = true;
				else blueWin = true;

			

			//check for vert line
			z = j+1;
			while (z < n && z < j+k)
			{
				if(board[i][z] != board[i][j])
					break;
				z++;
			}
			if(z == j+k)
				if(board[i][j] == 'R')
					redWin = true;
				else blueWin = true;

			
			//check for diag pos line
			z = j+1;
			y = i+1;
			while (z < n && y < n && y < i+k &&  z < j+k)
			{
				if(board[y][z] != board[i][j])
					break;
				z++;
				y++;
			}
			if(z == j+k)
				if(board[i][j] == 'R')
					redWin = true;
				else blueWin = true;

			
			//check for diag neg line
			z = j+1;
			y = i-1;
			while (z < n  && y >= 0  && z < j+k && y > i-k )
			{
				if(board[y][z] != board[i][j])
					break;
				z++;
				y--;
			}

			if(z == j+k)
				if(board[i][j] == 'R')
					redWin = true;
				else blueWin = true;

			
		
		}	
	}
	
	if(blueWin && redWin)
		return 3;
	if(blueWin)
		return 2;
	if(redWin)
		return 1;

	return 0;
	
	
}


int main() {

    int i,t,n,k,answer;
	cin >> t;
	
    fo(i,0,t) {
		cin >> n >> k;
		answer = solve(n,k);
		switch(answer){
		case 0:
			cout << "Case #" << i+1 << ": Neither"  << endl;
			break;
		case 1: 
			cout << "Case #" << i+1 << ": Red"   << endl;
			break;
		case 2 :
			cout << "Case #" << i+1 << ": Blue"   << endl;
			break;
		case 3 :
			cout << "Case #" << i+1 << ": Both"   << endl;
			break;
		}
       
    }

	return 0;
}

