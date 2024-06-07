#include "PrintOperatorUnit.h"

//---------------------------------------------------------------------------
string CplusplusPrintOperator::compile( unsigned int level ) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
//---------------------------------------------------------------------------
string JavaPrintOperator::compile( unsigned int level ) const
{
    return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
}
//---------------------------------------------------------------------------
string CSharpPrintOperator::compile( unsigned int level ) const
{
    return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
}
