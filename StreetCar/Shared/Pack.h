#ifndef PACK_H
#define PACK_H

class Pack{
 public:
    virtual void writePack(int fd) = 0;
};

#endif
