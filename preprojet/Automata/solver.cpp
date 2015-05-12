#include "solver.h"
#include <ctime>       
#include <cstdlib>     
#include <algorithm>
using namespace std;

int nbrLinesnotEmpty;

int sumVector(board waffer){
    int sum=0;
    for(int i=0;i<nbrLinesnotEmpty;i++){
	sum += waffer[i];
    }   
   // cout << sum<< endl;
    return sum;
}

Point alea(board waffer){
    int x=0, y=0, whichCase, sum=sumVector(waffer);
    Point p;
    srand(time(NULL));
    whichCase=rand()%(sum-1)+2;
    //cout << whichCase << endl;
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
        //cout << whichCase << endl;
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

board eatWaffer(board waffer,int x, int y){
    board waffertmp=waffer;
    for(int k=x;k<waffertmp.size();k++)
	if (waffertmp[k]>y)
	    waffertmp[k]=y;
    return waffertmp;
}

int Recursivminimax(board waffer,int currentIsPlayer1){
    /* this boolean have a different signification according to currentIsPlayer1 :    
       - currentIsPlayer1=false : loop until false 
       - currentIsPlayer1=true  : loop until true 
     */
    int loop=1;
    int res;
    if( (sumVector(waffer)==3 && waffer[0]==2) || sumVector(waffer)==1 )
	return !currentIsPlayer1;
    else{
	for(int x=0;x<nbrLinesnotEmpty && loop;x++)
	    for(int y=0;y<waffer[x] &&  loop;y++){
		if(x || y){
		    res=Recursivminimax(eatWaffer(waffer,x,y),!currentIsPlayer1);
		    if( (currentIsPlayer1 && res) || (!currentIsPlayer1 && !res) ) 
			    loop=0;
		}
	    }
    }
    return currentIsPlayer1^loop;
}



Point minimax(board waffer){
    Point p;
    vector<Point> tab;
    int isWinning=0;
    
    for(int x=0;x<nbrLinesnotEmpty;x++)
	for(int y=0;y<waffer[x];y++){
	    if(x || y){
		p.x=x;
		p.y=y;
		tab.push_back(p);
	    }
	}
    srand ( unsigned ( std::time(0) ) );
    random_shuffle ( tab.begin(), tab.end() );
    for(int currentPoint=0;currentPoint<tab.size() && !isWinning;currentPoint++){
	isWinning=Recursivminimax(eatWaffer(waffer,tab[currentPoint].x,tab[currentPoint].y),0);
	p.x=tab[currentPoint].x;
	p.y=tab[currentPoint].y;
    }
    if (!isWinning)
     //  cout << "tout est foutu"<< endl;
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
