#include "unit.h"

string Unit::generateShift( unsigned int level ) const
{
    static const auto DEFAULT_SHIFT = " ";
    string result;
    for( unsigned int i = 0; i < level; ++i )
    {
        result += DEFAULT_SHIFT;
    }
    return result;
}
void Unit::add( const shared_ptr< Unit >& , Flags )
{
    throw runtime_error( "Not supported" );
}
const vector< string > ClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };
ClassUnit::ClassUnit( const string& name ): m_name( name )
{
    m_fields.resize( ACCESS_MODIFIERS.size() );
}
void ClassUnit::add( const shared_ptr< Unit >& unit, Flags flags )
{

    int accessModifier = PRIVATE;

    if( flags < ACCESS_MODIFIERS.size() )
    {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}
string ClassUnit::compile( unsigned int level ) const
{
    string result = generateShift( level ) + "class " + m_name + " {\n";

    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        if( m_fields[ i ].empty() )
        {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] ) {

            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
MethodUnit::MethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :
    m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

void MethodUnit::add( const std::shared_ptr< Unit >& unit, Flags /* flags */ )
{
    m_body.push_back( unit );
}
string MethodUnit::compile( unsigned int level ) const
{
    string result = generateShift( level );
    if( m_flags & STATIC )
    {
        result += "static ";
    } else if( m_flags & VIRTUAL )
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
PrintOperatorUnit::PrintOperatorUnit( const std::string& text ) : m_text( text ) { }

void PrintOperatorUnit::add(const std::shared_ptr<Unit>& /* unit */, Flags /* flags */) { }

std::string PrintOperatorUnit::compile( unsigned int level ) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
string generateProgram()
{
    ClassUnit myClass( "MyClass" );
    myClass.add(std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),ClassUnit::PUBLIC);
    myClass.add(std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),ClassUnit::PRIVATE);
    myClass.add(std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),ClassUnit::PUBLIC);
    auto method = std::make_shared< MethodUnit >( "testFunc4", "void",MethodUnit::STATIC );
    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
}
