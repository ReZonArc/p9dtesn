#include "cogcity.h"
#include "y.tab.h"

/*
 * Cognitive Cities Lexer
 * Tokenizes cognitive grammar input for the YACC parser
 */

static char *input_text;
static int input_pos;
static int input_len;

/* Keyword table for cognitive grammar */
struct {
    char *word;
    int token;
} keywords[] = {
    {"query", QUERY},
    {"modify", MODIFY},
    {"create", CREATE},
    {"destroy", DESTROY},
    {"namespace", NAMESPACE},
    {"channel", CHANNEL},
    {"tensor", TENSOR},
    {"inference", INFERENCE},
    {"transform", TRANSFORM},
    {"partition", PARTITION},
    {"fibration", FIBRATION},
    {"hypergraph", HYPERGRAPH},
    {"chat", CHAT},
    {"with", WITH},
    {"in", IN},
    {"on", ON},
    {"for", FOR},
    {"optimize", OPTIMIZE},
    {"resources", RESOURCES},
    {"activate", ACTIVATE},
    {"deactivate", DEACTIVATE},
    {"multiplex", MULTIPLEX},
    {"demultiplex", DEMULTIPLEX},
    {"broadcast", BROADCAST},
    {"reasoning", REASONING},
    {"confidence", CONFIDENCE},
    {"threshold", THRESHOLD},
    {"zero-security", ZERO_SECURITY},
    {"execution", EXECUTION},
    {"environment", ENVIRONMENT},
    {nil, 0}
};

void set_lexer_input(char *text) {
    input_text = text;
    input_pos = 0;
    input_len = strlen(text);
}

static int next_char(void) {
    if (input_pos >= input_len) {
        return 0;
    }
    return input_text[input_pos++];
}

static void unget_char(void) {
    if (input_pos > 0) {
        input_pos--;
    }
}

static void skip_whitespace(void) {
    int c;
    while ((c = next_char()) != 0) {
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r') {
            unget_char();
            break;
        }
    }
}

static int is_alpha(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || c == '-';
}

static int is_alnum(int c) {
    return is_alpha(c) || (c >= '0' && c <= '9');
}

static int is_digit(int c) {
    return c >= '0' && c <= '9';
}

static int read_identifier(char *buf, int maxlen) {
    int c;
    int len = 0;
    
    while ((c = next_char()) != 0 && is_alnum(c) && len < maxlen - 1) {
        buf[len++] = c;
    }
    
    if (c != 0) {
        unget_char();
    }
    
    buf[len] = '\0';
    return len;
}

static int read_string(char *buf, int maxlen) {
    int c;
    int len = 0;
    
    // Skip opening quote
    next_char();
    
    while ((c = next_char()) != 0 && c != '"' && len < maxlen - 1) {
        if (c == '\\') {
            c = next_char();
            switch (c) {
            case 'n': c = '\n'; break;
            case 't': c = '\t'; break;
            case 'r': c = '\r'; break;
            case '\\': c = '\\'; break;
            case '"': c = '"'; break;
            default: break;
            }
        }
        buf[len++] = c;
    }
    
    buf[len] = '\0';
    return len;
}

static int read_number(char *buf, int maxlen) {
    int c;
    int len = 0;
    int has_dot = 0;
    
    while ((c = next_char()) != 0 && len < maxlen - 1) {
        if (is_digit(c)) {
            buf[len++] = c;
        } else if (c == '.' && !has_dot) {
            has_dot = 1;
            buf[len++] = c;
        } else {
            unget_char();
            break;
        }
    }
    
    buf[len] = '\0';
    return has_dot;  // Return 1 if float, 0 if integer
}

static int lookup_keyword(char *word) {
    int i;
    
    for (i = 0; keywords[i].word != nil; i++) {
        if (strcmp(word, keywords[i].word) == 0) {
            return keywords[i].token;
        }
    }
    
    return IDENTIFIER;
}

int yylex(void) {
    static char token_buf[256];
    int c;
    
    skip_whitespace();
    
    c = next_char();
    if (c == 0) {
        return 0;  // End of input
    }
    
    // Handle strings
    if (c == '"') {
        unget_char();
        read_string(token_buf, sizeof(token_buf));
        yylval.str = strdup(token_buf);
        return STRING;
    }
    
    // Handle numbers
    if (is_digit(c)) {
        unget_char();
        int is_float = read_number(token_buf, sizeof(token_buf));
        if (is_float) {
            yylval.dval = strtod(token_buf, nil);
            return FLOAT;
        } else {
            yylval.num = atoi(token_buf);
            return NUMBER;
        }
    }
    
    // Handle identifiers and keywords
    if (is_alpha(c)) {
        unget_char();
        read_identifier(token_buf, sizeof(token_buf));
        
        int token = lookup_keyword(token_buf);
        if (token == IDENTIFIER) {
            yylval.str = strdup(token_buf);
        }
        return token;
    }
    
    // Handle single character tokens
    switch (c) {
    case '.':
    case '(':
    case ')':
    case '{':
    case '}':
    case '[':
    case ']':
    case ';':
    case ',':
        return c;
    }
    
    // Unknown character - skip it
    return yylex();
}

/* Wrapper function for easy testing */
void tokenize_cognitive_input(char *input) {
    int token;
    
    set_lexer_input(input);
    
    print("Tokenizing cognitive input: %s\n", input);
    
    while ((token = yylex()) != 0) {
        switch (token) {
        case IDENTIFIER:
            print("IDENTIFIER: %s\n", yylval.str);
            free(yylval.str);
            break;
        case STRING:
            print("STRING: %s\n", yylval.str);
            free(yylval.str);
            break;
        case NUMBER:
            print("NUMBER: %d\n", yylval.num);
            break;
        case FLOAT:
            print("FLOAT: %g\n", yylval.dval);
            break;
        default:
            print("TOKEN: %d\n", token);
            break;
        }
    }
}