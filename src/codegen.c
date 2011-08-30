#include    "parser.h"      /* for types AST_node and Expression */
#include    "backend.h"     /* for self check */
#include    <stdio.h>
                                        /* PRIVATE */
static void Code_gen_expression(Expression *expr) {
    switch (expr->type) {
    case 'D':
        printf("PUSH %d\n", expr->value);
        break;
    case 'P':
        Code_gen_expression(expr->left);
        Code_gen_expression(expr->right);
        switch (expr->oper) {
        case '+': printf("ADD\n"); break;
        case '*': printf("MULT\n"); break;
		case '-': printf("SUB\n"); break;
		case '/': printf("DIV\n"); break;
        }
        break;
    }
}
                                        /* PUBLIC */
void Process(AST_node *icode) {
    Code_gen_expression(icode); printf("PRINT\n");
}
