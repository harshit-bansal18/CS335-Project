SwitchStatement:    SWITCH LPAREN Expression SPAREN SwitchBlock
;

SwitchBlock:        LCURLY SwitchRules RCURLY
|                   LCURLY SwitchBlockStatementGroupOpts {SwitchLabel :} RCURLY

SwitchRules:    SwitchRule SwitchRules
|               SwitchRule
;

SwitchRule:    SwitchLabel -> Expression ;
|                   SwitchLabel -> Block
|                   SwitchLabel -> ThrowStatement

SwitchBlockStatementGroupOpts:  SwitchBlockStatementGroup
|
;

SwitchBlockStatementGroup:    SwitchLabel COLON {SwitchLabel :} BlockStatements

SwitchLabel:        CASE CaseConstant {, CaseConstant}
|                   default

DoStatement:    do Statement while ( Expression ) ;

YieldStatement:    yield Expression ;

SynchronizedStatement:    synchronized ( Expression ) Block

TryStatement:    try Block Catches
|                   try Block [Catches] Finally
|                   TryWithResourcesStatement

Catches:    CatchClause {CatchClause}

CatchClause:    catch ( CatchFormalParameter ) Block

CatchFormalParameter:    {VariableModifier} CatchType VariableDeclaratorId

CatchType:    UnannClassType {| ClassType}

Finally:    finally Block

TryWithResourcesStatement:    try ResourceSpecification Block [Catches] [Finally]

ResourceSpecification:    ( ResourceList [;] )

ResourceList:    Resource {; Resource}

Resource:    LocalVariableDeclaration
|                   VariableAccess
