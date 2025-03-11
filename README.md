# Automata Programs:

This document explains how to compile and run the following programs:

1. **Lexical Analyzer in C**
2. **Lexical Analyzer using Lex Tool**
3. **YACC Specifications for Syntactic Categories**
4. **Find ε-Closure of all states in an NFA**
5. **Convert NFA with ε-transition to NFA without ε-transition**
6. **Convert NFA to DFA**
7. **Minimize a DFA**

## Prerequisites
- GCC compiler installed
- Basic knowledge of terminal commands

---

## 1. Running the Lexical Analyzer Program in C

### **Steps to Compile and Run:**
```sh
gcc lexical_analyzer.c -o lexical_analyzer
./lexical_analyzer
```

### **Input Format:**
- Enter a C program as input.
- Press `Ctrl+D` (Linux/Mac) or `Ctrl+Z` (Windows) to end input.

### **Example Input:**
```c
int main() {
    int a = 10;
    float b = 5.5;
    if (a > b) {
        printf("Hello World\n");
    }
    return 0;
}
```

### **Expected Output:**
```
int is a keyword
main is an identifier
( is a special symbol
) is a special symbol
{ is a special symbol
int is a keyword
a is an identifier
10 is a number
; is a special symbol
float is a keyword
b is an identifier
5.5 is a number
; is a special symbol
if is a keyword
( is a special symbol
a is an identifier
> is a special symbol
b is an identifier
) is a special symbol
{ is a special symbol
printf is an identifier
( is a special symbol
"Hello World\n" is a string
) is a special symbol
; is a special symbol
} is a special symbol
return is a keyword
0 is a number
; is a special symbol
} is a special symbol
Total number of lines: 9
```

---

## 2. Running the Lexical Analyzer using Lex Tool

### **Lex Program (lexical_analyzer.l):**
```lex
%{
#include <stdio.h>
%}

DIGIT [0-9]+
ID [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE [ \t\n]+

%%
{DIGIT}     { printf("%s is a number\n", yytext); }
{ID}        { printf("%s is an identifier\n", yytext); }
[+\-*/=;]   { printf("%s is an operator or special symbol\n", yytext); }
{WHITESPACE} { /* Ignore whitespace */ }
.           { printf("%s is an unknown character\n", yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
```

### **Steps to Compile and Run:**
```sh
lex lexical_analyzer.l
gcc lex.yy.c -o lexical_analyzer -ll
./lexical_analyzer
```

---

## 3. Running the YACC Specification Programs

### **Steps to Compile and Run:**
```sh
yacc -d arith.y
lex arith.l
gcc y.tab.c lex.yy.c -o arith -ll
./arith
```

### **Example Implementations:**
- Recognizing valid arithmetic expressions (`arith.y`, `arith.l`)
- Recognizing valid variable names (`var.y`, `var.l`)
- Calculator implementation using Lex and YACC (`calc.y`, `calc.l`)
- Abstract syntax tree generation (`ast.y`, `ast.l`)

---

## 4. Running the ε-Closure Program

### **Steps to Compile and Run:**
```sh
gcc epsilon_closure.c -o epsilon_closure
./epsilon_closure
```

![Epsilion DFA IMAGE](https://github.com/TheVivekYadav/CompilerDesignLab/blob/f0b8654c17abaecb19a80c74f65f4ddab8bc683e/4/4.jpeg)

### **Example Input:**
```
11
8
0 1
1 2
1 3
6 1
0 7
4 6
5 6
6 7
```

### **Example Output:**
```
ε-Closure(q0): { q0 q1 q2 }
ε-Closure(q1): { q1 q2 }
ε-Closure(q2): { q2 }
```

---

## 5. Running the NFA-ε to NFA Program

### **Steps to Compile and Run:**
```sh
gcc nfa_epsilon_to_nfa.c -o nfa_epsilon_to_nfa
./nfa_epsilon_to_nfa
```

### **Example Output:**
```
NFA after removing ε-transitions:
δ(q0, a) -> { q1 }
δ(q0, b) -> { q2 }
δ(q1, a) -> { }
δ(q1, b) -> { q2 }
```

---

## 6. Running the NFA to DFA Conversion Program

### **Steps to Compile and Run:**
```sh
gcc nfa_to_dfa.c -o nfa_to_dfa
./nfa_to_dfa
```

### **Example Output:**
```
DFA Transition Table:
δ(q0, a) -> q1
δ(q0, b) -> q2
δ(q1, a) -> {}
δ(q1, b) -> q2
```

---

## 7. Running the DFA Minimization Program

### **Steps to Compile and Run:**
```sh
gcc minimize_dfa.c -o minimize_dfa
./minimize_dfa
```

### **Example Output:**
```
Minimized DFA Table:
q0 -> { q1, q2 }
q1 -> { q2, q3 }
```

This guide provides the steps to run each automata conversion program. Modify the input values as needed to test different cases!


