struct stackentry {
    string id;           //key
    int scope;      
    int modifier;           //public, private, static, final
    string argument_type;   //argument list of function
    type_t type;            // type for variable and return type for function
    string nature;          // class or function or variable etc.
    int offset;
    int lineno;
};