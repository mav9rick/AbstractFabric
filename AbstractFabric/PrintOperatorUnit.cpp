#include "PrintOperatorUnit.h"

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
