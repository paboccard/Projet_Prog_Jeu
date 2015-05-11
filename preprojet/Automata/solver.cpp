#include "../Utils.h"
#include <cstdlib>
#include <time.h>
using namespace std;

int sumVector(board waffer){
    int sum=0;
    for(int i=0;i<waffer.size();i++){
	sum += waffer[i];
    }   
    cout << sum<< endl;
    return sum;
}

Point alea(board waffer){
    int x=0, y=0, whichCase, sum=sumVector(waffer);
    Point p;
    srand(time(NULL));
    whichCase=rand()%(sum-1)+2;
    cout << whichCase << endl;
    while(x<waffer.size() && whichCase-waffer[x]>0){
	whichCase-=waffer[x];
	x++;
    }
    y=whichCase-1;
    p.x=x;
    p.y=y;
    return p;
}
    
int main(){
    board waffer(3, 3);
    waffer[1]=1;
    waffer[2]=1;
    Point p=alea(waffer);
    cout << p.x << endl << p.y << endl;
    return 0;
}
