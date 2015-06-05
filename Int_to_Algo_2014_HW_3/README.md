# Istanbul University
## Introduction to Algorithms
## Homework 3

In this homework you will create a program that fill the numbers in an array that suits the pattern given in
Homework Assignment 2. Your program must take the matrix dimensions and terms in the matrix as
arguments from command line. For example your program name is “myProg.exe” and we want to create
2x3 dimensioned matrix with (Maximum dimension limit is 20x20)

![alt text]

 I will run your program as (terms are not in desired order)

myProg.exe 2 3 1 2 4 6 5 3

The program will check a special matrix pattern and prints out “ACCEPTABLE” or “NOT MATCH”
according to the values we put from the console.

The Special Pattern: In a row major representation the cells of the matrix must obey this rule. Some terms
of the matrix must be sum or product of the neighbor cells. In row major representation the sum and
product operations are placed as given in the examples. Sum and Product cells follows each other with one
free cells. For Odd rows the sequence starts with free cells and in Even Rows the sequence starts with
Sum or Product cell.

In this homework first you must reorder the given values to check all the combinations. If one
combination is ACCEPTABLE than your program must print the matching matrix allocation else the
program prints “NOT MATCH”.
