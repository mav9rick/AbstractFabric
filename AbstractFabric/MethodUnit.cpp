#include "MethodUnit.h"

MethodUnit::MethodUnit( const string& name, const string& returnType, Flags flags ):m_name( name ), m_returnType( returnType ), m_flags( flags )
{

}
void MethodUnit::add( const shared_ptr< Unit >& unit, Flags flags )
{
    m_body.push_back( unit );
}
string MethodUnit::compile( unsigned int level ) const
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

JavaMethod::JavaMethod( const string& name, const string& returnType, Flags flags ):m_name( name ), m_returnType( returnType ), m_flags( flags )
{

}
void JavaMethod::add( const shared_ptr< Unit >& unit, Flags flags )
{
    m_body.push_back( unit );
}
string JavaMethod::compile( unsigned int level ) const
{
    string result = generateShift( level );
    if (m_flags & PUBLIC)
    {
        result += "public ";
    }
    else if (m_flags & PROTECTED)
    {
        result += "protected ";
    }
    else if (m_flags & PRIVATE)
    {
        result += "private ";
    }
    else if (m_flags & DEFAULT)
    {
        result += "default ";
    }
    if( m_flags & STATIC )
    {
        result += "static ";
    }
    else if( m_flags & FINAL )
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

CSharpMethod::CSharpMethod( const string& name, const string& returnType, Flags flags ):m_name( name ), m_returnType( returnType ), m_flags( flags )
{

}
void CSharpMethod::add( const shared_ptr< Unit >& unit, Flags flags )
{
    m_body.push_back( unit );
}
string CSharpMethod::compile( unsigned int level ) const
{
    string result = generateShift( level );
    if (m_flags & PUBLIC)
    {
        result += "public ";
    }
    else if (m_flags & PROTECTED)
    {
        result += "protected ";
    }
    else if (m_flags & PRIVATE)
    {
        result += "private ";
    }
    else if (m_flags & PROTECTED_INTERNAL)
    {
        result += "protected internal ";
    }
    else if (m_flags & PRIVATE_PROTECTED)
    {
        result += "private protected ";
    }
    else if (m_flags & FILE)
    {
        result += "file ";
    }
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

    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}
