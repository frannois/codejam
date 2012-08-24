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

typedef long long ll;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<char> sc;
typedef pair<int, int> pii;
typedef map<string, int> msi;

struct Car {
    double pos,oldPos,speed;
    char lane;

};

void changeLane(Car &car) {

    if(car.lane == 'R')
        car.lane = 'L';
    else
        car.lane = 'R';

        //cout << "change lane" << endl;

}

bool isChange(Car car1,Car car2) {
    if (car1.pos <= car2.pos+5 && car1.pos >= car2.pos) return false;

    return true;

}



double solve() {

    int nbCars,i,j,k;
    bool stable = false,canChange;
    cin >> nbCars;
    vector<Car> cars;
    Car carTmp;
    double time = 0;
    double timer = 0.1;

    for(i = 0 ; i < nbCars ; i++) {
        cin >> carTmp.lane >> carTmp.speed >> carTmp.pos;
        cars.push_back(carTmp);
    }

    while(!stable) {
        stable = true;
        for(i = 0; i < cars.size() ; i++)
        {
        cars[i].oldPos = cars[i].pos;
        cars[i].pos += cars[i].speed*timer;
        //cout << "car " << i << " new position " << cars[i].pos << endl;
        }

        for(i = 0; i < cars.size() ; i++)
        {
            for(j = i+1; j < cars.size() ; j++) {

                if(cars[i].lane == cars[j].lane && fabs(cars[i].oldPos - cars[j].oldPos) > fabs(cars[i].pos - cars[j].pos))
                {
                    if (cars[i].lane == cars[j].lane && (cars[i].pos <= cars[j].pos+5 && cars[i].pos >= cars[j].pos)) return time;
                    cout << "problem!!! with car " << i << "and car " << j << endl;
                    cout << "car distance"  << fabs(cars[i].oldPos - cars[j].oldPos) << " " <<fabs(cars[i].pos - cars[j].pos) << endl;
                    stable = false;
                    if(cars[i].speed <= cars[j].speed)
                    {
                        // change lane for car i if possible
                        canChange = true;
                        for(k=0;k<cars.size();k++){
                            if(i != k){
                             bool c = isChange(cars[k],cars[i]);
                             if(!c) cout << "cars" << i << " " << k;
                             canChange &= isChange(cars[k],cars[i]);
                            }
                        }
                        if(!canChange){
                            canChange = true;
                            for(k=0;k<cars.size();k++){
                                if(i != k) {
                                bool c = isChange(cars[k],cars[i]);
                                if(!c) cout << "cars" << i << " " << k;
                                canChange &= isChange(cars[k],cars[j]);
                                }

                            }
                            if(!canChange){
                                return time;
                            }
                            else {
                                changeLane(cars[j]);
                                cout << " cars " << j << " changing lane" <<endl;
                        }
                        }
                        else {
                                changeLane(cars[i]);
                                cout << " cars " << i << " changing lane" <<endl;
                        }
                    }


                }

            }
        }
        time += timer;
    }

return -1;

}


int main() {

	int i,t;
	cin >> t;
	fo(i,0,3){
		double answer = solve();
		if(answer == -1){
            cout << "Case #" << i+1 << ": Possible" << endl;
		}
		else cout << "Case #" << i+1 << ": " <<  answer << endl;

	}


	return 0;
}

