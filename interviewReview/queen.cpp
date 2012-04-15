#define _CRT_SECURE_NO_DEPRECATE
#include <pthread.h>
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
#define MAX 8
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


set<pair<int,int> > invalidate(set<pair<int,int> > board , set<pair<int,int> > queens,pair<int,int> position){

    cout << "\tinvalidate" << "position " << position.first << " " << position.second << endl;
        set<pair<int,int> > newBoard = board;

        //up down
        for (int j = 0 ; j < MAX; j++ )
            {
                if( queens.find(pair<int,int>(position.first,j)) == queens.end() )
                    newBoard.erase(pair<int,int>(position.first,j));
                else return board;
            }
        //left right
        for (int i = 0 ; i < MAX; i++ )
            {
                if( queens.find(pair<int,int>(i,position.second)) == queens.end() )
                    newBoard.erase(pair<int,int>(i,position.second));
                else return board;
            }
         //pleft right up down
            cout << "\t\t positive diag" << endl;
            int i =  position.first - position.second > 0 ? position.first - position.second : 0;
            int j = position.second - position.first > 0 ?position.second - position.first : 0 ;
            while(i < MAX && j < MAX)
            {
                if( queens.find(pair<int,int>(i,j)) == queens.end() )
                    newBoard.erase(pair<int,int>(i,j));
                else return board;
                i++;
                j++;
            }
cout << "\t\t negative diag" << endl;
             //left right
            j =  position.second + position.first < MAX ? position.second + position.first : (MAX-1);
            i = position.second + position.first < MAX ? 0 : (position.second + position.first) - MAX+1;
            cout << "\t\t negative diag " << " i " << i << " j " << j <<  endl;
            while(i < MAX && j < MAX)
            {
                if( queens.find(pair<int,int>(i,j)) == queens.end() )
                    newBoard.erase(pair<int,int>(i,j));
                else return board;
                i++;
                j--;
            }
            cout << "\t done invalidate" <<endl;

        return newBoard;
}


 set<set<pair<int,int> > > solve (set<pair<int,int> > board , set<pair<int,int> > queens,int x,int y){

    int i = x;
    int j = y;
    set<set<pair<int,int> > > answers;
    set<set<pair<int,int> > > tmpAnswers;
    set<pair<int,int> > tmpBoard;
    set<pair<int,int> > tmpQueens;

   // cout << "solve" << endl;

            while(board.size() > 0 && i < MAX && j < MAX){
            if( board.find(pair<int,int>(i,j)) != board.end()){ //if the place stil exists

                tmpBoard = invalidate(board,queens,pair<int,int>(i,j));

                if(tmpBoard != board){
                    tmpQueens = queens;
                tmpQueens.insert(pair<int,int>(i,j));

                if(tmpQueens.size() == MAX)
                    answers.insert(tmpQueens);
                else {
                 tmpAnswers = solve( tmpBoard, tmpQueens,i,j);
                 for(set<set<pair<int,int> > >::iterator it = tmpAnswers.begin(); it != tmpAnswers.end() ; it++)
                 {
                     answers.insert((*it));
                 }

                }

                }

            }
            if(j+1 == MAX && i+1 ==MAX)
                return answers;
            else if(i+1 == MAX){
                i = 0;
                j++;
            }
            else i++;

        }
//should never get here
cout << "ERROR";
    return answers;
}

int main() {

    set<pair<int,int> > board;
    set<pair<int,int> > queens;
    set<set<pair<int,int> > > answers;
    for (int i = 0 ; i < MAX; i++ )
        for (int j = 0 ; j < MAX; j++ )
            board.insert(pair<int,int>(i,j));


            answers = solve(board,queens,0,0);


        cout << answers.size() <<endl;
}

