# AbstractFabric
## Постановка задачи 
Используя шаблон проектирования "Абстрактная фабрика", реализовать приложение генерирующее код 3-ёх для языков программирования (JAVA, C#, С++).
## Предложенное решение
- Fabric: абстракная фабрика, наследники: JavaCodeGenerator, CsharpCodeGenerator, CplusCodeGenerator.
- Unit: базовый класс сущьностей языка, наследники: ClassUnit, MethodUnit, PrintOperationUnit.
- ClassUnit: продут типа класса, наследники: JavaClass, CsharpClass, CplusplusClass.
- MethodUnit: продукт типа метод, наследники: JavaMethod, CsharpMethod, CplusplusMethod.
- PrintOperationUnit: продукт типа оператор печати, наследники: JavaPrintOperator, CsharpPrintOperator, CplusPrintOperator.
## UML-диаграмма
![Иллюстрация к проекту](https://github.com/mav9rick/Qt-lab-1.2/raw//main/AbstractFabricUML.png)