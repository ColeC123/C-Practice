#include "stdio.h"
#include "stdlib.h"

#define default_string \
    {                  \
        NULL, 0        \
    }

typedef struct string
{
    char *text;
    int length;
} string;

void set_string(string *str, char *text);

int main(void)
{
    string str = default_string;
    set_string(&str, "Hello World");
    printf("%s\n", str.text);
    printf("%d\n", str.length);
    free(str.text);
    return 0;
}

void set_string(string *str, char *text)
{
    if (str->text == NULL)
    {
        str->length = 0;
        while (*text != '\0')
        {
            str->length++;
            text++;
        }
        text -= str->length;
        str->text = (char *)malloc((str->length + 1) * sizeof(char));
        for (int i = 0; i < str->length; i++)
        {
            *(str->text) = *text;
            text++;
            str->text++;
        }
        text -= str->length;
        *(str->text) = '\0';
        str->text -= str->length;
    }
    else 
    {
        free(str->text);
        str->length = 0;
        while (*text != '\0')
        {
            str->length++;
            text++;
        }
        text -= str->length;
        str->text = (char *)malloc((str->length + 1) * sizeof(char));
        for (int i = 0; i < str->length; i++)
        {
            *(str->text) = *text;
            text++;
            str->text++;
        }
        text -= str->length;
        *(str->text) = '\0';
        str->text -= str->length;
    }
}
