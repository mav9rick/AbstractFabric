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
        STATIC = 1,
        CONST = 2,
        VIRTUAL = 3
    };
public:
    MethodUnit( const string& name, const string& returnType, Flags flags );
    void add( const shared_ptr< Unit >& unit, Flags flags = 0 );
    string compile( unsigned int level = 0 ) const;
private:
    string m_name;
    string m_returnType;
    Flags m_flags;
    vector< shared_ptr< Unit > > m_body;
};
class JavaMethod : public Unit
{
public:
    enum Modifier
    {
        STATIC = 1,
        FINAL = 2
    };
    enum AccessModifier
    {
        PUBLIC = 1,
        PROTECTED = 2,
        PRIVATE = 3,
        DEFAULT = 4
    };
public:
    JavaMethod( const string& name, const string& returnType, Flags flags );
    void add( const shared_ptr< Unit >& unit, Flags flags = 0 );
    string compile( unsigned int level = 0 ) const;
private:
    string m_name;
    string m_returnType;
    Flags m_flags;
    vector< shared_ptr< Unit > > m_body;
};
class CSharpMethod : public Unit
{
public:
    enum Modifier
    {
        STATIC = 1,
        OVERRIDE = 2,
        VIRTUAL = 3
    };
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED,
        FILE
    };
public:
    CSharpMethod ( const string& name, const string& returnType, Flags flags );
    void add( const shared_ptr< Unit >& unit, Flags flags = 0 );
    string compile( unsigned int level = 0 ) const;
private:
    string m_name;
    string m_returnType;
    Flags m_flags;
    vector< shared_ptr< Unit > > m_body;
};
#endif // METHODUNIT_H
