#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <fstream>

class Profile {
public:
Profile();
Profile(std::string n, int a);
	
    std::string name;
    int avatar;

friend std::ostream& operator << (std::ostream &f, Profile &p);
friend std::istream& operator >> (std::istream &f, Profile &p);
};


#endif
