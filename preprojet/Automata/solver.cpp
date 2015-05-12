#include "solver.h"

using namespace std;

int nbrLinesnotEmpty;

int sumVector(board waffer){
    int sum=0;
    for(int i=0;i<nbrLinesnotEmpty;i++){
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
    while(x<nbrLinesnotEmpty && whichCase-waffer[x]>0){
	whichCase-=waffer[x];
	x++;
    }
    y=whichCase-1;
    p.x=x;
    p.y=y;
    return p;
}


Point winnerLoser(board waffer){
    int x=0, y=0, whichCase, sum=sumVector(waffer);
    Point p;
    if(sum==3 && waffer[0]==2)
	p=alea(waffer);
    else { 
	if (sum==waffer[0]){
	    p.x=0;
	    p.y=1;
	}
    
	else {
	    if(nbrLinesnotEmpty==sum){	
		p.x=1;
		p.y=0;
	    }
	    else {
		srand(time(NULL));
		do
		    whichCase=rand()%(sum-2)+3;
		while(whichCase==waffer[0]+1);
		cout << whichCase << endl;
		while(x<nbrLinesnotEmpty && whichCase-waffer[x]>0){
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
    for(nbrLinesnotEmpty=0;nbrLinesnotEmpty<waffer.size() && waffer[nbrLinesnotEmpty]!=0;nbrLinesnotEmpty++);
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
