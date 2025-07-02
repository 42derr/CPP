# include <stdlib.h>
# include <stdio.h>

typedef struct s_node {
    char op;
    int value;
    struct s_node *left;
    struct s_node *right;
} t_node;

void skipSpaces(char **str)
{
    while (*str && **str == ' ')
    {
        (*str)++;
    }
}

t_node* evaluatePlus (char **str);
t_node* evaluateMutiply (char **str);
t_node* evaluateNumber (char **str);

void broken(void)
{
    printf("BROKEN\n");
    exit(0);
}

t_node* evaluatePlus (char **str) {
    skipSpaces(str);
    t_node* left = evaluateMutiply(str);
    skipSpaces(str);
    while (*str && **str == '+')
    {
        (*str)++;
        skipSpaces(str);
        t_node* right = evaluateMutiply(str);
        skipSpaces(str);
        t_node* node = malloc(sizeof(t_node));
        if (!node)
            broken();
        node->op = '+';
        node->value = 0;
        node->left = left;
        node->right = right;

        left = node;
    }
    return left;
}

t_node* evaluateMutiply (char **str) {
    skipSpaces(str);
    t_node* left = evaluateNumber(str);
    skipSpaces(str);
    while (*str && **str == '*')
    {
        (*str)++;
        skipSpaces(str);
        t_node* right = evaluateNumber(str);
        skipSpaces(str);
        t_node* node = malloc(sizeof(t_node));
        if (!node)
            broken();
        node->op = '*';
        node->value = 0;
        node->left = left;
        node->right = right;

        left = node;
    }
    return left;
}

t_node* evaluateNumber (char **str) {
    t_node *node;

    if (*str && **str == '(') {
        (*str)++;
        skipSpaces(str);
        if (**str == ')')
            broken();
        node = evaluatePlus(str);
        skipSpaces(str);
        if (*str && **str == ')')
        {
            (*str)++;
            return node;
        }
        else
            broken();
    }
    else if (*str && **str >= '0' && **str <= '9')
    {
        if (*(*str + 1) >= '0' && *(*str + 1) <= '9')
            broken();
        node = malloc(sizeof(t_node));
        if (!node)
            broken();
        node->op = 0;
        node->value = **str - '0';
        node->left = NULL;
        node->right = NULL;
        (*str)++;
        return node;
    }
    return NULL;
}

int evaluate (t_node *node) {
    if (node->op == 0) {
        return node->value;
    }
    else if (node->op == '+') {
        return evaluate(node->left) + evaluate(node->right);
    }
    else if (node->op == '*') {
        return evaluate(node->left) * evaluate(node->right);
    }
    return 0;
}

int main(void)
{
    char *str = "      1       +          1      +      ( 1  *5     )      ";

    t_node *test = evaluatePlus(&str);
    int res = evaluate(test);

    printf("%d\n", res);
    return (0);
}