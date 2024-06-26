#include "ClassUnit.h"

const vector< string > ClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };
ClassUnit::ClassUnit( const string& name, Flags flags ): m_flags(flags), m_name( name )
{
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

/*-------------------------------------------------------------------------------------------------*/

const vector< string > СplusplusClass::ACCESS_MODIFIERS = { "public", "protected", "private" };
СplusplusClass::СplusplusClass( const string& name, Flags flags ):  ClassUnit(name,flags)
{
    if (flags > PRIVATE)
        flags = PUBLIC;
    m_fields.resize( ACCESS_MODIFIERS.size() );
}
void СplusplusClass::add( const shared_ptr< Unit >& unit, Flags flags )
{
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() )
    {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}
string СplusplusClass::compile( unsigned int level ) const
{
    string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        if( m_fields[ i ].empty() )
        {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] )
        {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}

/*-----------------------------------------------------------------------------------------------------*/

const vector< string > JavaClass::ACCESS_MODIFIERS = { "public", "protected", "private" , "default" };
JavaClass::JavaClass( const string& name,Flags flags): ClassUnit(name,flags)
{
    if (flags > DEFAULT)
        flags = PUBLIC;
    m_fields.resize( ACCESS_MODIFIERS.size() );
}
void JavaClass::add( const shared_ptr< Unit >& unit, Flags flags )
{
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() )
    {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}
string JavaClass::compile( unsigned int level ) const
{
    string result = generateShift(level);
    if (m_flags == PUBLIC)
    {
        result += "public ";
    }
    if (m_flags == PROTECTED)
    {
        result += "protected ";
    }
    if (m_flags == PRIVATE)
    {
        result += "private ";
    }
    if (m_flags == DEFAULT)
    {
        result += "default ";
    }
    result += "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        if( m_fields[ i ].empty() )
        {
            continue;
        }
        for( const auto& f : m_fields[ i ] )
        {
            result += generateShift(level + 1);
            result += ACCESS_MODIFIERS[ i ];
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}

/*-----------------------------------------------------------------------------------------------------*/

const vector< string > CSharpClass::ACCESS_MODIFIERS = { "public", "protected", "private" , "internal"
                                                        , "protected_internal" , "private_protected", "file" };
CSharpClass::CSharpClass( const string& name ,Flags flags): ClassUnit(name,flags)
{
    m_fields.resize( ACCESS_MODIFIERS.size() );
}
void CSharpClass::add( const shared_ptr< Unit >& unit, Flags flags )
{
    int accessModifier = PRIVATE;
    if (flags >= DEFAULT)
        flags --;
    if( flags < ACCESS_MODIFIERS.size() )
    {
        accessModifier = flags;
    }

    m_fields[ accessModifier ].push_back( unit );
}
string CSharpClass::compile( unsigned int level ) const
{
    string result = generateShift(level);
    if (m_flags == PUBLIC)
    {
        result += "public ";
    }
    else if (m_flags == PROTECTED)
    {
        result += "protected ";
    }
    else if (m_flags == PRIVATE)
    {
        result += "private ";
    }
    else if (m_flags == INTERNAL)
    {
        result += "internal ";
    }
    else if (m_flags == PROTECTED_INTERNAL)
    {
        result += "protected_internal ";
    }
    else if (m_flags == PRIVATE_PROTECTED)
    {
        result += "private_protected ";
    }
    else if (m_flags == FILE)
    {
        result += "file ";
    }
    result += "class " + m_name + " {\n";

    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        if( m_fields[ i ].empty() )
        {
            continue;
        }
        for( const auto& f : m_fields[ i ] )
        {
            result += generateShift(level + 1);
            result += ACCESS_MODIFIERS[ i ];
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
