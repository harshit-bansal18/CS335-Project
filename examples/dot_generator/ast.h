#include <stdlib.h>

#define is_null(p) p==NULL
typedef enum {
    k_expression_kind_identifier,
    k_expression_kind_intliteral,
    k_expression_kind_addition,
    k_expression_kind_subtraction,
    k_expressoin_kind_assign,
    k_expression_kind_end
} expression_kind;


struct exp {
    expression_kind kind;
    union {
        char *identifier;
        int intliteral;
        struct {struct exp *left; struct exp *right;} binary;
    }val;

    char *label;

};



struct exp *make_exp_identifier(char *id);
struct exp *make_exp_add(struct exp* el, struct exp *er);
struct exp *make_exp_sub(struct exp* el, struct exp *er);
struct exp *make_exp_int(char *);
struct exp *make_exp_assign(struct exp*, struct exp *);
struct exp *make_exp_end(struct exp* , struct exp*);
void generate_script(struct exp*);