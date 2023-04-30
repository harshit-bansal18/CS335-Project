#include "ast.h"
#include <iostream>
using namespace std;

static int count = 0;

FILE *script;

struct exp *make_exp_identifier(char *id) {
    struct exp *e = new exp;
    e->kind = k_expression_kind_identifier;
    e->val.identifier = id;
    e->label = id;
    return e;
}

struct exp *make_exp_add(struct exp* el, struct exp *er) {
    struct exp *e = new exp;
    e->kind = k_expression_kind_addition;
    e->val.binary.left = el;
    e->val.binary.right = er;
    e->label = "+";
    return e; 
}

struct exp *make_exp_sub(struct exp* el, struct exp *er) {
    struct exp *e = new exp;
    e->kind = k_expression_kind_subtraction;
    e->val.binary.left = el;
    e->val.binary.right = er;
    e->label = "-";
    return e; 
}

struct exp *make_exp_int(char* i) {
    struct exp *e = new exp;
    e->kind = k_expression_kind_intliteral;
    e->label = i; 
    return e;
}

struct exp *make_exp_assign(struct exp* el, struct exp *er) {
    struct exp *e = new exp;
    e->kind = k_expressoin_kind_assign;
    e->val.binary.left = el;
    e->val.binary.right = er;
    e->label = "=";
    return e;
}

struct exp *make_exp_end(struct exp* el, struct exp *er) {
    struct exp *e = new exp;
    e->kind = k_expression_kind_end;
    e->val.binary.left = el;
    e->val.binary.right = er;
    e->label = ";";
    return e;
}

void parse_tree(struct exp *node, int priv_count) {
    if (is_null(node))
        return;
                

    fprintf(script,"%d [label=\"%s\"]\n", priv_count, node->label);
    switch (node->kind) {
        case k_expression_kind_identifier:
            // fprintf(script,"%d [label=\"%s\"]\n", count, node->val.binary.left->label);
            break;
        
        case k_expression_kind_intliteral:
            // fprintf(script,"%d [label=\"%s\"]\n", count, node->val.binary.left->label);
            break;
        
        default:
            int c1 = ++count;
            int c2 = ++count;
            fprintf(script,"%d -> %d\n", priv_count, c1);
            if (!is_null(node->val.binary.right))
                fprintf(script,"%d -> %d\n", priv_count, c2);
            parse_tree(node->val.binary.left, c1);
            parse_tree(node->val.binary.right, c2);
            break;
    }

}

void generate_script(struct exp *root) {
    script = fopen("ast.gv", "w");
    fprintf(script, "digraph g {\n");
    parse_tree(root, 0);
    fprintf(script, "}\n");
    fclose(script);
}   