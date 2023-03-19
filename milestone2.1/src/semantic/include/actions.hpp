#ifndef ACTIONS_H
    #define ACTIONS_H
#endif

#ifndef SYMBOL_TABLE_H
    #include "symbol_table.hpp"
#endif

stackentry* ClassOrInterfaceType(stackentry* e1);
stackentry* ArrayType(stackentry* e1, stackentry* e2, int rule_no);
void VariableDeclarator(stackentry* e1, stackentry* e2, int rule_no);
void MethodDeclaration();
void ConstructorDeclaration();
void IfCondition(stackentry* e1);
void AssertCondition(stackentry* e1);
void WhileCondition(stackentry* e1);
void ForCondition(stackentry* e1);
void EnhancedForCondition(stackentry* e1);