#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <fstream>

class Profile {
 public:
    Profile();
    Profile(const Profile& p);
    Profile(std::string n, int a, int t);
    
    std::string name;
    int avatar;
    int type;

    Profile operator = (Profile p);
    friend std::ostream& operator << (std::ostream &f, Profile &p);
    friend std::istream& operator >> (std::istream &f, Profile &p);
};


#endif
