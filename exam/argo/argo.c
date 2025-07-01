# include <stdio.h>
# include <stdlib.h>

typedef enum { JSON_STRING, JSON_INT, JSON_OBJECT } t_json_type;

typedef struct s_json_node {
    char *key;
    t_json_type type;

    // Instead of union, separate fields:
    char *str_val;
    int int_val;
    struct s_json_node *children[10];
    int child_count;
} t_json_node;


/*
{
  "name": "Bob",
  "stats": {
    "score": 1500,
    "level": 5
  },
  "premium": 0
}
*/

t_json_node *parse_object(char **str);

void skip_spaces(char **str) {
    while ((**str >= 9 && **str <= 13) || **str == ' ')
        (*str)++;
}

char* parse_string(char **str){
    skip_spaces(str);

    if (**str != '\"')
        return NULL;

    (*str)++;

    char *start = *str;
    int len = 0;

    while (**str && **str != '\"') {
        (*str)++;
        len++;
    }

    if (**str != '"')
        return NULL;

    char *new = malloc(len + 1);
    if (!new)
        return NULL;

    for (int i = 0; i < len; i++) {
        new[i] = start[i];
    }
    new[len] = '\0';

    (*str)++;
    skip_spaces(str);
    return new;
}

t_json_node *parse_value(char **str){
    skip_spaces(str);
    t_json_node *new = NULL;

    if (**str == '\"')
    {
        new = malloc(sizeof(t_json_node));
        new->type = JSON_STRING;
        new->str_val = parse_string(str);
        new->int_val = 0;
        new->child_count = 0;
    }
    else if (**str == '{')
    {
        new = parse_object(str);
    }
    else if (**str >= '0' && **str <= '9')
    {
        new = malloc(sizeof(t_json_node));
        new->type = JSON_INT;
        new->int_val = atoi(*str);

        while (**str >= '0' && **str <= '9')
            (*str)++;
        skip_spaces(str);
    }
    return new;
}


t_json_node *parse_object(char **str) {
    skip_spaces(str);
    if (**str != '{')
        return NULL;

    (*str)++;

    t_json_node *json= malloc(sizeof(t_json_node));

    json->type = JSON_OBJECT;
    json->child_count = 0;

    skip_spaces(str);
    if (**str == '}') {
        (*str)++;
        return json;
    }

    while (1) {
        char *key_str = parse_string(str);
        if (!key_str)
            return NULL;

        skip_spaces(str);
        if (**str != ':')
            return NULL;

        (*str)++;
        skip_spaces(str);

        t_json_node *new = parse_value(str);
        if (!new)
            return NULL;

        new->key = key_str;

        json->children[json->child_count] = new;
        json->child_count += 1;

        skip_spaces(str);
        if (**str == ',')
        {
            (*str)++;
            skip_spaces(str);
            continue;
        }
        else if (**str == '}')
        {
            (*str)++;
            break;
        }
        else
            return NULL;
    }
    return json;
}

// Helper for indentation
void print_indent(int level) {
    for (int i = 0; i < level; i++)
        printf("  ");
}

// Print function
void print_json(t_json_node *node, int indent) {
    if (!node)
        return;

    print_indent(indent);
    if (node->key)
        printf("key: %s, ", node->key);

    if (node->type == JSON_STRING) {
        printf("value: \"%s\" (string)\n", node->str_val);
    } else if (node->type == JSON_INT) {
        printf("value: %d (int)\n", node->int_val);
    } else if (node->type == JSON_OBJECT) {
        printf("value: {\n");
        for (int i = 0; i < node->child_count; i++) {
            print_json(node->children[i], indent + 1);
        }
        print_indent(indent);
        printf("}\n");
    }
}

// Main test
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s '{\"key\": \"value\"}'\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    t_json_node *root = parse_object(&input);

    if (!root) {
        printf("Parse error.\n");
        return 1;
    }

    print_json(root, 0);
    return 0;
}