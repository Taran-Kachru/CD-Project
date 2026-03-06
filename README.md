Multilingual Programming Language Compiler
Overview
This project implements a prototype Multilingual Programming Language Compiler that allows programmers to write code using regional-language keywords. The compiler translates these multilingual constructs into a standardized intermediate representation (IR) while maintaining the structure of traditional compiler pipelines.

The project demonstrates key compiler design concepts such as:
Lexical Analysis
Tokenization
Syntax Validation
Intermediate Representation (IR) Generation
IR-Level Structural Analysis

The implementation is written in C++ and developed as part of a Compiler Design coursework project.

Motivation
Most programming languages rely on English-based keywords. This creates a barrier for beginners who are more comfortable with regional languages.

This project explores how multilingual keywords can be supported while preserving the internal correctness of the compiler.

Example Multilingual Program

Input file (input.ml):

sankhya x = 10
agar x > 0
dikhao x

Meaning:

int x = 10
if x > 0
print x
Generated Intermediate Representation (IR)
DECLARE x 10
IF x > 0
PRINT x
IR Analysis Output
Declarations: 1
IF Statements: 1
Print Statements: 1

Project Architecture
Source Code (.ml)
        │
        ▼
Lexical Analyzer
        │
        ▼
Token Stream
        │
        ▼
IR Generator
        │
        ▼
IR Storage
        │
        ▼
IR Analysis
Technologies Used

C++

VS Code

GNU g++ Compiler

GitHub

Weekly Progress
Week 1–2

Problem definition and lexical analyzer prototype.

Week 3–4

System architecture design and preliminary implementation.

Week 5

Language and grammar design using simplified BNF.

Week 6

Syntax validation framework.

Week 7

Intermediate Representation (IR) generation.

Week 8

IR storage and structural analysis.

Future Work
Future improvements may include:
Full parser implementation
Control Flow Graph generation
IR optimization
Backend code generation

How to Run
Compile:
g++ main.cpp -o compiler
Run:

./compiler
Author

Compiler Design Project
B.Tech Computer Science
24CSB0B78 Taran Kachru CSE-B
