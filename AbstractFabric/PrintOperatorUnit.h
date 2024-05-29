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
    explicit PrintOperatorUnit( const string& text );
    void add(const std::shared_ptr<Unit>& /* unit */, Flags /* flags */) override;
    string compile( unsigned int level = 0 ) const override;
private:
    string m_text;
};

#endif // PRINTOPERATORUNIT_H
