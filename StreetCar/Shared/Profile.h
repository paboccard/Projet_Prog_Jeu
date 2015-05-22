#ifndef PROFILE_H
#define PROFILE_H

#include <string>

class Profile {
public:
	Profile(std::string n, int a);
	
    std::string name;
    int avatar;
};


#endif
