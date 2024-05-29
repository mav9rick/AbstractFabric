#include "unit.h"
#include "MethodUnit.h"
#include "ClassUnit.h"
#include <iostream>
#include <QApplication>
using namespace std;
string generateProgram()
{
    ClassUnit myClass( "MyClass" );
    myClass.add(make_shared< MethodUnit >( "testFunc1", "void", 0 ),ClassUnit::PUBLIC);
    myClass.add(make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),ClassUnit::PRIVATE);
    myClass.add(make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),ClassUnit::PUBLIC);
    auto method = make_shared< MethodUnit >( "testFunc4", "void",MethodUnit::STATIC );
    method->add( make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
}
int main()
{
    cout << generateProgram() << endl;
    return 0;
}
