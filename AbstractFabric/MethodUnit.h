#ifndef METHODUNIT_H
#define METHODUNIT_H
#include <unit.h>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class MethodUnit : public Unit
{
public:
    enum Modifier
    {
        STATIC = 1 << 0,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        OVERRIDE = 1 << 3,
        FINAL = 1 << 4
    };
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED,
        FILE
    };
public:
    MethodUnit( const string& name, const string& returnType, Flags flags );
    void add( const shared_ptr< Unit >& unit, Flags flags = 0 );
    virtual string compile( unsigned int level = 0 ) const = 0;
    string m_name;
    string m_returnType;
    Flags m_flags;
    vector< shared_ptr< Unit > > m_body;
};
class CplusplusMethod : public MethodUnit
{
public:
    CplusplusMethod( const string& name, const string& returnType, Flags flags ):MethodUnit(name,  returnType,  flags){};
    string compile( unsigned int level = 0 ) const;
};
class JavaMethod : public MethodUnit
{
public:
    JavaMethod( const string& name, const string& returnType, Flags flags ):MethodUnit(name,  returnType,  flags ){};
    string compile( unsigned int level = 0 ) const;
};
class CSharpMethod : public MethodUnit
{
public:
    CSharpMethod ( const string& name, const string& returnType, Flags flags ):MethodUnit(name,  returnType,  flags){};
    string compile( unsigned int level = 0 ) const;
};
#endif // METHODUNIT_H
