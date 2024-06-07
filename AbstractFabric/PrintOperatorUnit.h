#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include <unit.h>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit( const string& text ){m_text = text;};
    virtual string compile( unsigned int level = 0 ) const = 0;
protected:
    string m_text;
};
class CplusplusPrintOperator : public PrintOperatorUnit
{
public:
    explicit CplusplusPrintOperator( const string& text ) : PrintOperatorUnit(text){};
    string compile( unsigned int level = 0 ) const override;
};
class JavaPrintOperator : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperator( const string& text ): PrintOperatorUnit(text){};
    string compile( unsigned int level = 0 ) const override;
};
class CSharpPrintOperator : public PrintOperatorUnit
{
public:
    explicit CSharpPrintOperator( const string& text ) : PrintOperatorUnit(text){};
    string compile( unsigned int level = 0 ) const override;
};

#endif // PRINTOPERATORUNIT_H
