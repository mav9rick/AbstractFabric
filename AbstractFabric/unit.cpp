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
PrintOperatorUnit::PrintOperatorUnit( const string& text ) : m_text( text )
{

}
void PrintOperatorUnit::add(const shared_ptr<Unit>& /* unit */, Flags /* flags */)
{

}
string PrintOperatorUnit::compile( unsigned int level ) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}

