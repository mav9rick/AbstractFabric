#ifndef UNIT_H
#define UNIT_H
#include <memory>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Unit
{
public:
    using Flags = unsigned int;
    virtual ~Unit() = default;
    virtual void add( const shared_ptr< Unit >& , Flags );
    virtual string compile( unsigned int level = 0 ) const = 0;
protected:
    virtual string generateShift( unsigned int level ) const;
};
#endif // UNIT_H
