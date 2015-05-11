#include "solver.h"

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


Point winnerLoser(board waffer){
    int x=0, y=0, whichCase, sum;
    Point p;
    if(waffer.size()==2 && waffer[0]==2 && waffer[1]==1)
	p=alea(waffer);
    else { 
	if (waffer.size()==1){
	    p.x=0;
	    p.y=1;
	}
    
	else {
	    sum=sumVector(waffer);
	    if(sum==waffer.size()){
		p.x=1;
		p.y=0;
	    }
	    else {
		srand(time(NULL));
		do
		    whichCase=rand()%(sum-2)+3;
		while(whichCase==waffer[0]+1);
		cout << whichCase << endl;
		while(x<waffer.size() && whichCase-waffer[x]>0){
		    whichCase-=waffer[x];
		    x++;
		}
		y=whichCase-1;
		p.x=x;
		p.y=y;
	    }
	}
    }
    return p;
}

Point minimax(board waffer){
    Point p;
    p.x=0;
    p.y=0;
    return p; 
}

Point play(board waffer, difficulty diff){
    Point p;
    switch (diff){
    case Easy:
	p=alea(waffer);
	break;
    case Medium:
	p=winnerLoser(waffer);
	break;
    case Hard:
	p=minimax(waffer);
	break;
    }
    return p;
}
