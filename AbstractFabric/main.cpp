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
    myClass->add(factory.createMethod( "testFunc1", "void", 0 ),ClassUnit::PROTECTED_INTERNAL);
    myClass->add(factory.createMethod( "testFunc2", "void", MethodUnit::STATIC | MethodUnit::CONST),ClassUnit::DEFAULT);
    myClass->add(factory.createMethod( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),ClassUnit::PUBLIC);
    auto method = factory.createMethod( "testFunc4", "void",MethodUnit::FINAL | MethodUnit::OVERRIDE);
    method->add( factory.createPrintOperatorUnit( R"(Hello, world!\n)" ) );
    myClass->add( method, ClassUnit::PROTECTED );
    return myClass->compile();
}
int main()
{
    Fabric* factory = nullptr;
    factory = new JavaFabric;
    cout << generateProgram(*factory) << endl;
    factory = new CsharpFabric;
    cout << generateProgram(*factory) << endl;
    factory = new CplusplusFabric;
    cout << generateProgram(*factory) << endl;
    delete factory;
    return 0;
}
