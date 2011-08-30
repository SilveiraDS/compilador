#include    "parser.h"      /* for types AST_node and Expression */
#include    "backend.h"     /* for self check */
#include    "error.h" 
                                        /* PRIVATE */
static int Interpret_expression(Expression *expr) {
    switch (expr->type) {
    case 'D':
        return expr->value;
        break;
    case 'P': {
        int e_left = Interpret_expression(expr->left);
        int e_right = Interpret_expression(expr->right);
        switch (expr->oper) {
        case '+': return e_left + e_right;
        case '*': return e_left * e_right;
		case '-': if(e_left >= e_right) return e_left - e_right;
			  else Error("Resultado fora dos naturais");
		case '/': if (e_right != 0) return e_left/e_right;
			  else Error("Divisao por zero"); 
        }}
        break;
    }
}
                                        /* PUBLIC */
void Process(AST_node *icode) {
    printf("%d\n", Interpret_expression(icode));
}
