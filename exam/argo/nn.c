t_json_node *parse_value(char **str) {
    skip_spaces(str);

    t_json_node *new = NULL;

    if (**str == '"') {
        new = malloc(sizeof(t_json_node));
        if (!new) return NULL;

        new->type = JSON_STRING;
        new->str_val = parse_string(str);
        new->int_val = 0;
        new->child_count = 0;
    }
    else if (**str == '{') {
        new = parse_object(str);  // already returns a fully formed node
    }
    else if (**str >= '0' && **str <= '9') {
        new = malloc(sizeof(t_json_node));
        if (!new) return NULL;

        new->type = JSON_INT;
        new->int_val = 0;
        new->str_val = NULL;
        new->child_count = 0;

        // manually parse integer
        while (**str >= '0' && **str <= '9') {
            new->int_val = new->int_val * 10 + (**str - '0');
            (*str)++;
        }
    }

    skip_spaces(str);
    return new;
}
