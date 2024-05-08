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
public:
    virtual ~Unit() = default;
    virtual void add( const shared_ptr< Unit >& , Flags );
    virtual string compile( unsigned int level = 0 ) const = 0;
protected:
    virtual string generateShift( unsigned int level ) const;
};
class ClassUnit : public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const vector< string > ACCESS_MODIFIERS;
public:
    explicit ClassUnit( const string& name );
    void add( const shared_ptr< Unit >& unit, Flags flags );
    string compile( unsigned int level = 0 ) const;
private:
    string m_name;
    using Fields = vector< shared_ptr< Unit > >;
    vector< Fields > m_fields;
};
class MethodUnit : public Unit
{
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit( const string& name, const string& returnType, Flags flags );
    void add( const shared_ptr< Unit >& unit, Flags /* flags */ = 0 );
    string compile( unsigned int level = 0 ) const;
private:
    string m_name;
    string m_returnType;
    Flags m_flags;
    vector< shared_ptr< Unit > > m_body;
};
class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit( const string& text );
    void add(const std::shared_ptr<Unit>& /* unit */, Flags /* flags */) override;
    string compile( unsigned int level = 0 ) const;
private:
    string m_text;
};
string generateProgram();
#endif // UNIT_H
