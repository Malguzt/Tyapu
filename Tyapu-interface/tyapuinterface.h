#ifndef TYAPUINTERFACE_H
#define TYAPUINTERFACE_H

#include "tyapu-interface_global.h"

class TYAPUINTERFACESHARED_EXPORT Tyapuinterface
{

public:
    Tyapuinterface();
    virtual void addSong(QString &path) = 0;
};

#endif // TYAPUINTERFACE_H
