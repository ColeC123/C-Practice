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

char get_char(string* str, int index);

int main(void)
{
    string str = default_string;
    set_string(&str, "Hello World");
    printf("%s\n", str.text);
    printf("%d\n", str.length);
    set_string(&str, "This is a program");
    printf("%s\n", str.text);
    printf("%d\n", str.length);
    printf("%c\n", get_char(&str, 17));
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

char get_char(string* str, int index) {
    char result;
    if (index < str->length) {
        for (int i = 0; i < index; i++) {
            str->text++;
        }
        result = *str->text;
        str->text -= index;
        return result;
    } else {
        printf("--> Index out of bounds error. Tried to access an element beyond the length of the string <--");
        exit(1);
    }
}
