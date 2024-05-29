#ifndef UNIT_H
#define UNIT_H
#include <memory>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Unit
{
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;
    virtual void add( const shared_ptr< Unit >& , Flags );
    virtual string compile( unsigned int level = 0 ) const = 0;
protected:
    virtual string generateShift( unsigned int level ) const;
};
class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit( const string& text );
    void add(const std::shared_ptr<Unit>& /* unit */, Flags /* flags */) override;
    string compile( unsigned int level = 0 ) const override;
private:
    string m_text;
};
string generateProgram();
#endif // UNIT_H
