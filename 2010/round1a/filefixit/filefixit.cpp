#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
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

 class Directory {


	vector<Directory*> children;
public:
string name;
	~Directory() {
		int i;		
		fo(i,0,children.size())
			delete children.at(i);
	}
	int createIfNotExist(deque<string> path) {
		int i;
		int indexFound = -1;
		if(path.size() > 0) {
			string currentDir = path.at(0);
			path.pop_front();	
	
			fo(i,0,children.size()){
				if((children.at(i))->name == currentDir)
					indexFound = i;
			}


		if (indexFound == -1) {//dir doesDu not exist
			Directory *dir = new Directory();
			dir->name = currentDir;
			children.pb(dir);
			return 1 + dir->createIfNotExist(path);
		}
		else{
			return (children.at(indexFound))->createIfNotExist(path);
		}



		}
		return 0;

	}

	};

deque<string> split(string str){
	deque<string> words;
	int previousIndex = str.size() - 1,i;
	for(int i = str.size() -1 ; i >= 0 ; i--){
		if(str[i] == '/') { //we reached the end of a path
			words.push_front(str.substr(i+1,previousIndex - i+1));
			previousIndex = i-2;		
		}
	}

	return words;
}

int main() {
   
	int i,j,k,t,e,n,ans = 0;
	string str;
	deque<string> words;
	Directory *root;
	cin >> t;
	fo(i,0,t){
		 root = new Directory();
	  cin >> e >> n;
	  getline(cin,str);
	 fo(j,0,e){ //existing directory
 	 	getline(cin,str);
	 	words = split(str);
		root->createIfNotExist(words);
		words.clear();
	}
		
	fo(j,0,n)
	{
		getline(cin,str);
		words = split(str);
		ans += root->createIfNotExist(words);
		words.clear();

	}
	  
     cout << "Case #"<< i+1 << ": " << ans << endl;
	delete root;
	ans = 0;
	}
    

	return 0;
}

