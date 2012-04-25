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
#include <stack>
#include <deque>
#include <queue>
#include <math.h>
#include <time.h>


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

class Node {

	private :
			Node *mLeft;
			Node *mRight;
			int mValue;

	public:
  ~Node(){ cout << "delete Left";delete mLeft;cout << "delete right";delete mRight; }
	Node(int value);
	Node* getRight(){return mRight;}
	Node* getLeft(){return mLeft;}
	void insert(int value);
	bool remove(int value);
	Node* find(int value);
	int getValue(){ return mValue;}
};


Node::Node(int value) {

	mValue = value;
	mRight= NULL;
	mLeft = NULL;

}

void Node::insert(int value){

	if(value > mValue){
		if(mRight == NULL)
		  mRight = new Node(value);
		else
			mRight->insert(value);
	}
	else{
		if(mLeft == NULL)
		  mLeft = new Node(value);
		else
			mLeft->insert(value);
	}

}

void preorderTraverse(Node *node) {

  if(node == NULL)
    return;
  cout << node->getValue() << " ";
  preorderTraverse(node->getLeft());
  preorderTraverse(node->getRight());

}


void inorderTraverse(Node *node){

if(node == NULL)
    return;
  inorderTraverse(node->getLeft());
  cout << node->getValue() << " ";
  inorderTraverse(node->getRight());


}

void preorderTraverseNoIteration(Node *node){


    stack<Node*> nodeStack;
    nodeStack.push(node);

    while(nodeStack.empty() == false) {
        node = nodeStack.top();
        nodeStack.pop();
        cout << node->getValue() << " ";
        if(node->getRight() != NULL){
            nodeStack.push(node->getRight());

        }
        if(node->getLeft() != NULL){
            nodeStack.push(node->getLeft());

        }


    }


}

void breadthSearch(Node* node){

    queue<Node> nodeQueue;
    nodeQueue.push(node);

    while(!nodeQueue.empty()){





    }



}


int main() {
  Node *root = new Node(24);
  root->insert(12);
  root->insert(17);
  root->insert(-4);
   root->insert(53);
   root->insert(93);
   root->insert(123);
   root->insert(9494);
   root->insert(-23);


  preorderTraverseNoIteration(root);
  delete root;

	return 0;
}

