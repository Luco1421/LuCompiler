
// ALgo asi, todavia hay que hacerlo bien, son las 12, no voy a trasnochar por esto

#include <stdio.h>
#include <../include/ast.h>

FILE* output_file = fopen("program.nasm", "w");

void generate_code(ASTNode* node) {
    if (node == NULL) return;
    switch (node->type) {
        case PROGRAM_NODE:
            //fprintf(output_file, ".macro read\n");
            //fprintf(output_file, ".macro write\n");
            fprintf(output_file, "section .text\n");
            fprintf(output_file, "global _start\n");
            fprintf(output_file, "_start:\n");
            generate_code(node->stmt.first);
            break;
        case STMT_NODE:
            generate_code(node->stmt.first);
            generate_code(node->stmt.rest);
            break;
        case ASSIGN_NODE:
            fprintf(output_file, "mov rax, %d\n", node->value);
            break;
        case READ_NODE:
            fprintf(output_file, "call read\n");
            break;
        case WRITE_NODE:
            fprintf(output_file, "call write\n");
            break;
        default:
            break;
    }
}