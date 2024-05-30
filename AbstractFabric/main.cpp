#include "unit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"
#include "ClassUnit.h"
#include "Fabric.h"
#include <iostream>
#include <QApplication>
using namespace std;
string generateProgram(Fabric& factory)
{
    shared_ptr<ClassUnit> myClass = factory.createClass("MyClass" , ClassUnit::PUBLIC);
    myClass->add(factory.createMethod( "testFunc1", "void", 0 ),ClassUnit::PUBLIC);
    myClass->add(factory.createMethod( "testFunc2", "void", MethodUnit::STATIC | MethodUnit::PRIVATE ),ClassUnit::PRIVATE);
    myClass->add(factory.createMethod( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),ClassUnit::PUBLIC);
    auto method = factory.createMethod( "testFunc4", "void",MethodUnit::STATIC );
    method->add( factory.createPrintOperatorUnit( R"(Hello, world!\n)" ) );
    myClass->add( method, ClassUnit::PROTECTED );
    return myClass->compile();
}
int main()
{
    Fabric* factory = nullptr;
    factory = new JavaFabric;
    cout << generateProgram(*factory) << endl;
    return 0;
}
