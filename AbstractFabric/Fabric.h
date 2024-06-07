#ifndef FABRIC_H
#define FABRIC_H
#include "unit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"
#include "ClassUnit.h"
#include <iostream>
using namespace std;

class Fabric
{
public:
    virtual shared_ptr<ClassUnit> createClass(const string& name,unsigned int flags) = 0;
    virtual shared_ptr<MethodUnit> createMethod(const string& name, const string& returnType, unsigned int flags) = 0;
    virtual shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const string& text) = 0;
};
class JavaFabric : public Fabric
{
public:
    shared_ptr<ClassUnit> createClass(const string& name,unsigned int flags) override
    {
        return make_shared<JavaClass>(name,flags);
    }
    shared_ptr<MethodUnit> createMethod(const string& name, const string& returnType, unsigned int flags) override
    {
        return make_shared<JavaMethod> (name, returnType, flags);
    }
    shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const string& text) override
    {
        return make_shared<JavaPrintOperator>(text);
    }
};
class CsharpFabric : public Fabric
{
public:
    shared_ptr<ClassUnit> createClass(const string& name,unsigned int flags) override
    {
        return make_shared<CSharpClass>(name,flags);
    }
    shared_ptr<MethodUnit> createMethod(const string& name, const string& returnType, unsigned int flags) override
    {
        return make_shared<CSharpMethod>(name, returnType, flags);
    }
    shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const string& text) override
    {
        return make_shared<CSharpPrintOperator>(text);
    }
};
class CplusplusFabric : public Fabric
{
public:
    shared_ptr<ClassUnit> createClass(const string& name,unsigned int flags) override
    {
        return make_shared<СplusplusClass>(name,flags);
    }
    shared_ptr<MethodUnit> createMethod(const string& name, const string& returnType, unsigned int flags) override
    {
        return make_shared<CplusplusMethod>(name, returnType, flags);
    }
    shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const string& text) override
    {
        return make_shared<CplusplusPrintOperator>(text);
    }
};

#endif // FABRIC_H
