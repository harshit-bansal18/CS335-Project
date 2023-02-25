"+="                                  {return PLUS_EQ;}
"-="                                  {return MINUS_EQ}
"*="                                  {return MUL_EQ;}
"/="                                  {return DIV_EQ;}
"&="                                  {return AMBERSENT_EQ;}

LITERAL             {BOOLEAN_LITERAL}|{CHAR_LITERAL}|{NULL_LITERAL}|{INTEGER_LITERAL}|{FP_LITERAL}|{TEXT_BLOCK}|{STRING}
DELIMITER           ","|";"|"("|")"|"["|"]"|"..."|"{"|"}"|"."|"@"|"::"

OPERATOR            "+"|"-"|"*"|"/"|"="|"<"|"<="|">="|">"|"^"|"!"|"~"|"?"|":"|"->"|"=="|"!="|"&&"|"||"|"++"|"--"|"&"|"|"|"^"|"%"|"<<"|">>"|">>>"|"+="|"-="|"*="|"/="|"&="|"|="|"^="|"%="|"<<="|">>="|">>>="
LETTER              [a-zA-Z]

KEYWORDS            "abstract"|"continue"|"for"|"new"|"switch"|"assert"|"default"|"goto"|"package"|"synchronized"|"boolean"|"do"|"if"|"private"|"this"|"break"|"double"|"implements"|"protected"|"throw"|"byte"|"else"|"import"|"public"|"throws"|"case"|"enum"|"instanceof"|"return"|"transient"|"catch"|"extends"|"int"|"short"|"try"|"char"|"final"|"interface"|"static"|"void"|"class"|"finally"|"long"|"strictfp"|"volatile"|"const"|"float"|"native"|"super"|"while"|"_"

CONTEXTUAL_KEYWORDS "exports"|"opens"|"requires"|"uses"|"module"|"permits"|"sealed"|"var"|"non-sealed"|"provides"|"to"|"with"|"open"|"record"|"transitive"|"yield"

