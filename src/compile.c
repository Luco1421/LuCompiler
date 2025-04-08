#include <stdio.h>
#include "../include/parser.h"

int main() {
    Scanner scanner;
    Trie trie;
    Parser parser;
    
    char* source = "begin; read b; read a; a = 5; b = a + 3; write b; end;";
    
    create_scanner(&scanner, source);
    create_trie(&trie);
    
    trie_insert(&trie, "begin", false, TOKEN_BEGIN);
    trie_insert(&trie, "end", false, TOKEN_END);
    trie_insert(&trie, "read", false, TOKEN_READ);
    trie_insert(&trie, "write", false, TOKEN_WRITE);
    
    init_parser(&parser, &scanner, &trie);
    
    ASTNode* ast = parse_program(&parser);
    printf("\n--- AST ---\n");
    print_ast(ast, 0);
    
    return 0;
}