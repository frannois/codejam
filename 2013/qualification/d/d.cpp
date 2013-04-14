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
#include <list>
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

unsigned int n;
struct chest {
    
    int keyToOpen;
    vector<int> keys;
    bool open;
    int chestNumber;
    
    };
    
     vector<int> updateKeys(vector<int> keys, chest c) {

        vector<int> keys2;
bool skipped = false;
        for(int i = 0 ; i < c.keys.size() ; i++) {
            keys2.push_back(c.keys[i]);
        }
        

        
         for(int i = 0 ; i < keys.size() ; i++) {
            if(keys[i] == c.keyToOpen && !skipped) skipped = true;
            else 
            keys2.push_back(keys[i]);
        }
        

        return keys2;
        }
        
list<chest> updateChest(list<chest> c, chest t) {
        
        list<chest> c2;
        list<chest>::iterator it = c.begin();
        
        while(it != c.end()) {
            if ( (*it).chestNumber != t.chestNumber) {
                c2.push_back(*it);
            }
            it++;
        }
        return c2;
        }

bool findKey (vector<int> keys, int key) {
    int i;
    fo(i,0,keys.size()) if (keys[i] == key) return true;
    
    return false;
}
    vector<int> openChest(vector<int> keys, list<chest> chests, vector<int> chestOpen, int depth) {
        
       list<chest>::iterator itc = chests.begin();
       vector<int> chestTmp;
       chest tmp;
       int i;
       bool foundKey;
       
       if (chests.size() == 0 || chestOpen.size() == n) return chestOpen;
   
           while (itc != chests.end()) {
               foundKey = findKey(keys,(*itc).keyToOpen);
               if(foundKey) {   
                  // fo(i,0,depth)cout <<" ";
                   //cout << "found key " << (*itc).keyToOpen << " to open chest " << (*itc).chestNumber << " " <<chestOpen.size() <<endl;
                   chestTmp = chestOpen;
                   chestTmp.push_back((*itc).chestNumber);
                   depth++;
                   
                   chestTmp = openChest(updateKeys(keys,*itc),updateChest(chests,*itc),chestTmp,depth);
                   depth--;
                   if(chestTmp.size() > n ) return chestOpen;
                   else if(chestTmp.size() == n) 
                   {
                       if(chestOpen.size() == n) {
                       for ( i = 0 ; i < chestOpen.size() ; i++) {
                           if( chestTmp[i] < chestOpen[i] ){
                               chestOpen = chestTmp;
                               break;
                           }
                       }
                   } else  chestOpen = chestTmp;
                       }
                chestTmp.pop_back();
               }
               itc++;
               }
       return chestOpen;
  }

void solve() {

  vector<int> answer;
  unsigned int  i, j, k, ntmp;
  int keytmp;
  cin >> k >> n;
  vector<int> keys;
  list<chest> chests;
  vector<int>::iterator it;
  for ( i = 0 ; i < k ; i++)
  { cin >> j;
    keys.push_back(j);
  }
  chest tmp;

  for ( i = 0 ; i < n ; i++) {
    cin >> tmp.keyToOpen;
    cin >> ntmp;
    for ( j = 0 ; j < ntmp ; j++) {
        cin >> keytmp;
        tmp.keys.push_back(keytmp);
    }
    tmp.open = false;
    tmp.chestNumber = i+1;
    chests.push_back(tmp);
  }
  
  answer = openChest(keys,chests,answer,0);

    if (answer.size() == n) {
       it = answer.begin();
       while (it != answer.end()) {
            cout << *it << " ";
             it++;
        }
     }
     else
      cout << "IMPOSSIBLE";
  
return;

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

