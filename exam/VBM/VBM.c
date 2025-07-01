# include <stdlib.h>
# include <stdio.h>

typedef struct s_node {
    char op;
    int value;
    struct s_node *left;
    struct s_node *right;
} t_node;

t_node* evaluatePlus(char **str);
t_node* evaluateMutiply(char **str);
t_node* evaluateNumber(char **str);

void skipSpaces(char **str) {
    while (**str == ' ')
        (*str)++;
}

t_node* evaluatePlus(char **str){
    skipSpaces(str);
    t_node *left = evaluateMutiply(str);
    skipSpaces(str);
    while (**str == '+')
    {
        skipSpaces(str);
        (*str)++;
        t_node *right = evaluateMutiply(str);
        skipSpaces(str);
        t_node *node = malloc(sizeof(t_node));
        node->op = '+';
        node->value = 0;
        node->left = left;
        node->right = right;

        left = node;
    }
    return left;
}

t_node* evaluateMutiply(char **str){
    skipSpaces(str);
    t_node *left = evaluateNumber(str);
    skipSpaces(str);
    while (**str == '*')
    {
        (*str)++;
        skipSpaces(str);
        t_node *right = evaluateNumber(str);
        skipSpaces(str);
        t_node *node = malloc(sizeof(t_node));
        node->op = '*';
        node->value = 0;
        node->left = left;
        node->right = right;

        left = node;
    }
    return left;
}

t_node* evaluateNumber(char **str){
    skipSpaces(str);
    if (**str == '(')
    {
        (*str)++;
        t_node *node = evaluatePlus(str);
        skipSpaces(str);
        if (**str == ')') {
            (*str)++;
        }
        return node;
    }

    if (**str <= '9' && **str >= '0')
    {
        int value = 0;
        while (**str <= '9' && **str >= '0') {
            value = value * 10 + (**str - '0');
            (*str)++;
        }
        t_node *node = malloc(sizeof(t_node));
        node->op = 0;
        node->left = NULL;
        node->right = NULL;
        node->value = value;
        return node;
    }
    return NULL;
}

int evaluate(t_node *node)
{
    if (node->op == 0)
        return node->value;
    else if (node->op == '+')
        return evaluate(node->left) + evaluate(node->right);
    else if (node->op == '*')
        return evaluate(node->left) * evaluate(node->right);
    else
        return -1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (1);
    
    t_node *node = evaluatePlus(&argv[1]);

    int num = evaluate(node);

    printf("%d\n", num);
    return (0);
}
