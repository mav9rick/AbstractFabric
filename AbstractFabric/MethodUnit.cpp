#include "MethodUnit.h"

MethodUnit::MethodUnit( const string& name, const string& returnType, Flags flags ):m_name( name ), m_returnType( returnType ), m_flags( flags )
{

}
void MethodUnit::add( const shared_ptr< Unit >& unit, Flags flags )
{
    m_body.push_back( unit );
}

/*-----------------------------------------------------------------------------------------------------*/

string CplusplusMethod::compile( unsigned int level ) const
{
    string result = generateShift( level );
    if( m_flags & STATIC )
    {
        result += "static ";
    }
    else if( m_flags & VIRTUAL )
    {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( m_flags & CONST )
    {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

/*-----------------------------------------------------------------------------------------------------*/

string JavaMethod::compile( unsigned int level ) const
{
    string result = generateShift( level );
    if( m_flags & STATIC )
    {
        result += "static ";
    }
    if( m_flags & FINAL )
    {
        result += "final ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

/*-----------------------------------------------------------------------------------------------------*/

string CSharpMethod::compile( unsigned int level ) const
{
    string result = generateShift( level );

    if( m_flags & STATIC )
    {
        result += "static ";
    }
    else if( m_flags & VIRTUAL )
    {
        result += "virtual ";
    }
    else if( m_flags & OVERRIDE)
    {
        result += "override ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}
