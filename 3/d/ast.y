%{
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char op;
    int value;
    struct node *left, *right;
} Node;

Node* createNode(int value, char op, Node* left, Node* right) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->op = op;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void printTree(Node* root, int depth) {
    if (root == NULL) return;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++) printf("\t");
    if (root->op)
        printf("%c\n", root->op);
    else
        printf("%d\n", root->value);
    printTree(root->left, depth + 1);
}

%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

expr: expr '+' expr  { $$ = createNode(0, '+', $1, $3); }
    | expr '-' expr  { $$ = createNode(0, '-', $1, $3); }
    | expr '*' expr  { $$ = createNode(0, '*', $1, $3); }
    | expr '/' expr  { $$ = createNode(0, '/', $1, $3); }
    | '-' expr %prec UMINUS { $$ = createNode(0, '-', NULL, $2); }
    | '(' expr ')'  { $$ = $2; }
    | NUMBER       { $$ = createNode($1, 0, NULL, NULL); }
    ;

%%

int main() {
    printf("Enter an arithmetic expression:\n");
    Node* root;
    yyparse(&root);
    printf("Abstract Syntax Tree:\n");
    printTree(root, 0);
    return 0;
}

void yyerror(char *s) {
    printf("Error: %s\n", s);
}

