#include "Profile.h"

using namespace std;

Profile::Profile(){
	avatar = 0;
	name = "";
}

Profile::Profile(const Profile& p){
    this->avatar = p.avatar;
    this->name = p.name;
}

Profile::Profile(std::string n, int a, int c){
    avatar = a;
    name = n;
	color = c;
}

Profile Profile::operator = (Profile p){
    avatar = p.avatar;
    name = p.name;
	color = p.color;
    return *this;
}

ostream& operator << (ostream &f, Profile &p){
    f << p.name << " ";
	f << p.avatar << " ";
	f << p.color;
    return f;
}
istream& operator >> (istream &f, Profile &p){
    f >> p.name;
    f >> p.avatar;
	f >> p.color;
    return f;
}
