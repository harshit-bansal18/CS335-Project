
Block:    LCURLY RCURLY
|         LCURLY BlockStatements RCURLY
;

BlockStatements:    BlockStatement BlockStatements
|                   BlockStatement
;

BlockStatement:     LocalClassDeclaration
|                   LocalInterfaceDeclaration
|                   LocalVariableDeclarationStatement
|                   Statement
;

LocalClassDeclaration:    ClassDeclaration
;

LocalInterfaceDeclaration:  NormalInterfaceDeclaration
;

LocalVariableDeclarationStatement:    LocalVariableDeclaration
;

LocalVariableDeclaration:    VariableModifiers LocalVariableType VariableDeclaratorList
|                            LocalVariableType VariableDeclaratorList
;

VariableModifiers:       VariableModifier VariableModifiers
|                        VariableModifier
;

LocalVariableType:   UnannType
|                    VAR
;

Statement:          StatementWithoutTrailingSubstatement
|                   LabeledStatement
|                   IfThenStatement
|                   IfThenElseStatement
|                   WhileStatement
|                   ForStatement
;

StatementNoShortIf:     StatementWithoutTrailingSubstatement
|                       LabeledStatementNoShortIf
|                       IfThenElseStatementNoShortIf
|                       WhileStatementNoShortIf
|                       ForStatementNoShortIf
;

StatementWithoutTrailingSubstatement:   Block
|                                       EmptyStatement
|                                       ExpressionStatement
|                                       AssertStatement
|                                       SwitchStatement
|                                       DoStatement
|                                       BreakStatement
|                                       ContinueStatement
|                                       ReturnStatement
|                                       SynchronizedStatement
|                                       ThrowStatement
|                                       TryStatement
|                                       YieldStatement
;

EmptyStatement:    SEMICOLON
;

LabeledStatement:    Identifier COLON Statement
;

LabeledStatementNoShortIf:    Identifier COLON StatementNoShortIf
;

ExpressionStatement:    StatementExpression SEMICOLON

StatementExpression:    Assignment
|                       PreIncrementExpression
|                       PreDecrementExpression
|                       PostIncrementExpression
|                       PostDecrementExpression
|                       MethodInvocation
|                       ClassInstanceCreationExpression

IfThenStatement:    IF LPAREN Expression RPAREN Statement
;

IfThenElseStatement:    IF LPAREN Expression RPAREN StatementNoShortIf ELSE Statement
;

IfThenElseStatementNoShortIf:    IF LPAREN Expression RPAREN StatementNoShortIf ELSE StatementNoShortIf
;

AssertStatement:    ASSERT Expression SEMICOLON
|                   ASSERT Expression COLON Expression SEMICOLON
;

CaseConstant:    ConditionalExpression
;

WhileStatement:    while LPAREN Expression RPAREN Statement
;

WhileStatementNoShortIf:    while LPAREN Expression RPAREN StatementNoShortIf
;

ForStatement:       BasicForStatement
|                   EnhancedForStatement
;

ForStatementNoShortIf:    BasicForStatementNoShortIf
|                   EnhancedForStatementNoShortIf
;

BasicForStatement:    for LPAREN ForInitOpts SEMICOLON ExpressionOpts SEMICOLON ForUpdateOpts RPAREN Statement
;

BasicForStatementNoShortIf:    for LPAREN ForInitOpts SEMICOLON ExpressionOpts SEMICOLON ForUpdateOpts RPAREN StatementNoShortIf

ForInitOpts:    ForInit
|
;

ForInit:    StatementExpressionList
|           LocalVariableDeclaration

ForUpdateOpts:  ForUpdate
|
;

ForUpdate:    StatementExpressionList

StatementExpressionList:    StatementExpression
|                           StatementExpression CommaStatementExpressions
;

CommaStatementExpressions:   COMMA StatementExpression CommaStatementExpressions
|                            COMMA StatementExpression
;

EnhancedForStatement:    for LPAREN LocalVariableDeclaration COLON Expression RPAREN Statement
;

EnhancedForStatementNoShortIf:    for LPAREN LocalVariableDeclaration COLON Expression RPAREN StatementNoShortIf
;

BreakStatement:    BREAK IdentifierOpts SEMICOLON
;

ContinueStatement:    CONTINUE IdentifierOpts SEMICOLON
;

ReturnStatement:    RETURN ExpressionOpts SEMICOLON
;

ThrowStatement:    THROW Expression SEMICOLON
;

ExpressionOpts:    ExpressionName
|
;

IdentifierOpts:     Identifier
|
;

Pattern:            TypePattern
;

TypePattern:        LocalVariableDeclaration
;