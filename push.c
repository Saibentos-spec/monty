int is_number(char *s)
{
    if (!s || *s == '\0')
        return 0;
    if (*s == '-' || *s == '+')
        s++;
    for (; *s; s++)
        if (!isdigit(*s))
            return 0;
    return 1;
}
