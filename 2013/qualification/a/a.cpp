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


void solve() {

  bool gameOver = true;
  bool win;
  char board[16];
  char tmp;
  int i,j;
  
  for( i = 0 ; i < 16 ; i++) {
    cin >> board[i];
    if(board[i] == '.') gameOver = false;
   }

   //check hor lines
   for (i = 0 ; i < 4 ; i++) {
       if (board[i*4] == '.') continue;
       if(board[i*4] != 'T') tmp = board[i*4];
       else tmp = board[i*4+1];
       win = true;
       for (j = 0 ; j < 4 ; j++) {
           if(board[i*4+j] == '.' || (board[i*4+j] != tmp && board[i*4+j] != 'T')) {
             win = false;
             break;
           }
       }
       if(win) {
         cout << tmp << " won";
         return;
       }
   }

   //check vert lines
      for (i = 0 ; i < 4 ; i++) {
       if (board[i] == '.') continue;
       if(board[i] != 'T') tmp = board[i];
       else tmp = board[i+4];
       win = true;
       for (j = 0 ; j < 4 ; j++) {
           if(board[i+j*4] == '.' || (board[i+j*4] != tmp && board[i+j*4] != 'T')) {
             win = false;
             break;
           }
       }
      if(win) {
         cout << tmp << " won";
         return;
       }
   }
   //check 2 diagonals
   if (board[0] != '.') {
   win = true;
   if(board[0] != 'T') tmp = board[0];
       else tmp = board[5];
   for (i = 0 ; i < 16 ; i+=5) {
           if(board[i] == '.' || (board[i] != tmp && board[i] != 'T')) {
             win = false;
             break;
           }
       }
      if(win) {
         cout << tmp << " won";
         return;
       }
}
   //check 2 diagonals
      if (board[3] != '.') {
   win = true;
   if(board[3] != 'T') tmp = board[3];
       else tmp = board[6];
   for (i = 3 ; i < 15 ; i+=3) {
           if(board[i] == '.' || (board[i] != tmp && board[i] != 'T')) {
             win = false;
             break;
           }
       }
      if(win) {
         cout << tmp << " won";
         return;
       }
}
  if (gameOver) {
      cout << "Draw";
      return;
  } else {
      cout << "Game has not completed";
  }
  

}

int main() {
    int i,t;
	cin >> t;

	fo(i,0,t){
        cout << "Case #" << i+1 << ": " ;
        solve();
		cout <<endl;
	}
	
	return 0;
}

