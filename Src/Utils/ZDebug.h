#ifndef ZDebug_h
#define ZDebug_h

#include <iostream>
#include <cassert>

#ifdef DEBUG
    #define ASSERT(exp, msg) assert(((void)msg, exp))
#endif


#endif /* ZDebug_h */
