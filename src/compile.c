#include <stdio.h>
#include "../include/parser.h"

int main() {
    Scanner scanner;
    Trie trie;
    Parser parser;
    
    char* source = "begin \n"
                   "x = 5;\n"
                   "y = x + 3;\n"
                   "read x;\n"
                   "write y;\n"
                   "end\n";
    
    create_scanner(&scanner, source);
    create_trie(&trie);
    
    trie_insert(&trie, "begin", false, TOKEN_BEGIN);
    trie_insert(&trie, "end", false, TOKEN_END);
    
    init_parser(&parser, &scanner, &trie);
    
    ASTNode* ast = parse_program(&parser);
    printf("\n--- AST ---\n");
    print_ast(ast, 0);
    
    return 0;
}