#include "Profile.h"

using namespace std;

Profile::Profile(){
	avatar = 0;
	name = "";
}

Profile::Profile(std::string n, int a){
    avatar = a;
    name = n;
}

ostream& operator << (ostream &f, Profile &p){
    f << p.name << " ";
    f << p.avatar;
    return f;
}
istream& operator >> (istream &f, Profile &p){
    f >> p.name;
    f >> p.avatar;
    return f;
}
