#include "PrintOperatorUnit.h"

string PrintOperatorUnit::compile( unsigned int level ) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
//---------------------------------------------------------------------------
string CplusplusPrintOperator::compile( unsigned int level ) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
//---------------------------------------------------------------------------
string JavaPrintOperator::compile( unsigned int level ) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
//---------------------------------------------------------------------------
string CSharpPrintOperator::compile( unsigned int level ) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
