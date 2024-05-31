#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include <unit.h>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class ClassUnit : public Unit
{
public:
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
    static const vector< string > ACCESS_MODIFIERS;
public:
    explicit ClassUnit( const string& name , Flags flags = PRIVATE);
    virtual void add( const shared_ptr< Unit >& unit, Flags flags ) = 0;
    virtual string compile( unsigned int level = 0 ) const = 0;
    Flags m_flags;
    string m_name;
    using Fields = vector< shared_ptr< Unit > >;
    vector< Fields > m_fields;
};
class СplusplusClass : public ClassUnit
{
public:
    static const vector< string > ACCESS_MODIFIERS;
public:
    explicit СplusplusClass( const string& name , Flags flags = PRIVATE);
    void add( const shared_ptr< Unit >& unit, Flags flags );
    string compile( unsigned int level = 0 ) const;
};
class JavaClass : public ClassUnit
{
public:
    static const vector< string > ACCESS_MODIFIERS;
public:
    explicit JavaClass( const string& name , Flags flags = PRIVATE);
    void add( const shared_ptr< Unit >& unit, Flags flags );
    string compile( unsigned int level = 0 ) const;
};
class CSharpClass : public ClassUnit
{
public:
    static const vector< string > ACCESS_MODIFIERS;
public:
    explicit CSharpClass( const string& name ,Flags flags = PRIVATE);
    void add( const shared_ptr< Unit >& unit, Flags flags);
    string compile( unsigned int level = 0 ) const;
};

#endif // CLASSUNIT_H
