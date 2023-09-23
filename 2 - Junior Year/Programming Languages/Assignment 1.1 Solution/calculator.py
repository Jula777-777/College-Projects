#Listing the names of all of the tokens for the lexer and parser to use
tokens = (
    'INTEGER', 'FLOAT', 'PLUS','MINUS','TIMES','DIVIDE',
    'LPAREN','RPAREN', 'SINE', 'COSINE', 'TANGENT', 'QUIT', 'TEST'
    )

#Defining all the tokens. Each token is specified using Python's re moduel, which is what the r stands for. Each defintion must start with t_
t_PLUS    = r'\+'
t_MINUS   = r'\-'
t_TIMES   = r'\*'
t_DIVIDE  = r'/'
t_LPAREN  = r'\('
t_RPAREN  = r'\)'
t_SINE    = r'sin'         
t_COSINE  = r'cos'
t_TANGENT = r'tan'
t_QUIT = r'q'
t_TEST = r'test'

#Defining the more complicated tokens.
def t_FLOAT(t):
    r'\d+\.\d+'                                                 #The \.\d+ means that there can be many digits after a decimal point, which represents a float.
    t.value = float(t.value)
    return t

def t_INTEGER(t):
    r'\d+'                                                      #d stands for digit, and the plus means that the integer can contain many digits.
    t.value = int(t.value)                                      
    return t

t_ignore = ' \t'                                                #This lines makes it so that tabs and spaces do not affect the output.

def t_error(t):
    print(f'Illegal character {t.value[0]!r}')                  #This line prints "Illegal character" when the value of t is not tokenized. The f string is used to more easily embed the t.value expression in the string.
    t.lexer.skip(1)                                             #The untokenized character will then be skipped.
    

#Build the lexer using the preceding token defintions
import ply.lex as lex                                           
lex.lex()

#Defining Precedence: Precedence is defined from lowest to highest
precedence = (
    ('left', 'PLUS', 'MINUS' ),
    ('left', 'TIMES', 'DIVIDE'),
    ('left', 'SINE', 'COSINE', 'TANGENT'),
    ('right', 'UMINUS'),
)

#Defining the grammar rules. The variable p is a sequence that contains each grammar symbol in the corresponding rule. You can access each symbol in the same way you access elements in an array.
#Each defintion must start with p_
def p_statment_expression(p):
    'statement : expression'                                    #The first symbol (statment) is p[0]. The second symbol expression is p[1]. Each subsequent symbol will follow work the same way.
    print(f'Result: {p[1]}')                                    #This rule makes it so that the result of a calculation is always printed to the terminal.   

def p_binop(p):                                                 #When combining grammar rules, you use the '|' character for each rule after the first.
    '''expression : expression expression PLUS                  
                  | expression expression MINUS
                  | expression expression TIMES'''
    if p[3] == '+'  : p[0] = p[1] + p[2]                        #Addition: Since I am using reverse Polish notation, the syntax for addition is two expressions followed by a PLUS.
    elif p[3] == '-': p[0] = p[1] - p[2]                        #Subtraction
    elif p[3] == '*': p[0] = p[1] * p[2]                        #Multiplication

def p_trinop(p):                                                #Addition and multiplication can work on more than two operands, so I provided a rule where they can work on three operands.
    '''expression : expression expression expression PLUS       
                  | expression expression expression TIMES'''
    if p[4] == '+'  : p[0] = p[1] + p[2] + p[3]
    elif p[4] == '*': p[0] = p[1] * p[2] * p[3]

def p_div(p):
    'expression : expression expression DIVIDE'
    if p[2] == 0:
        raise ZeroDivisionError('You cannot divide by zero.')   
    else:
        p[0] = p[1] / p[2]                                      #Division

import math

def p_trig(p):                                                  #Since trig functions only work on one expression, the syntax is one expression followed by the trig function.
    '''expression : expression SINE
                  | expression COSINE
                  | expression TANGENT'''
    if p[2] == 'sin'  : p[0] = math.sin(p[1])                   #Sine
    elif p[2] == 'cos': p[0] = math.cos(p[1])                   #Cosine
    elif p[2] == 'tan': p[0] = math.tan(p[1])                   #Tangent

def p_uminus(p):
    'expression : MINUS expression %prec UMINUS'                #%prec UMINUS is used to give this grammar rule the precedence of UMINUS.
    p[0] = -p[2]

def p_group(p):
    'expression : LPAREN expression RPAREN'                 
    p[0] = p[2]                                                 #This line makes the result of a set of parentheses be equal to what is inside the parentheses, so grouping should work correctly. 

def p_number(p):
    '''expression : INTEGER
                  | FLOAT'''
    p[0] = p[1]                                                 #This rules makes a single number just print to the terminal since no calculation is involved.

def p_error(p):
    if p != None:
        print(f'Syntax error at {p.value!r}')                   #This line prints "syntax error" when a token is being used in a syntactically incorrect way.

def p_quit(p):
    'expression : QUIT'                                         #This grammar rule allows the user to quit the program.
    quit 

def p_test(p):                                                  #This grammar rule allows the user to test the function of the calculator using test cases, which is implemented in the following while loop.
    'expression : TEST'                                         

#Build the parser using the preceding grammar rules     
import ply.yacc as yacc
yacc.yacc()

userInput = ''
print("Welcome to this reverse polish notation calculator. You can use '+', '-', '*', '/', 'sin', 'cos', and 'tan' functions, and you can use '(' and ')' for grouping.")

#This loop allows the user to input calculations until pressing 'q'.
while userInput != 'q':                                         
    userInput = input("Input your calculation, input 'test' to test the calculator, or press 'q' to quit > ")
    
    if (userInput == 'test'):                                   #The test command prints out the results of some test cases to show some of the features of the calculator.
        print('Here are five test cases to check if the calculator is working correctly:')
        inputArray = ['(3.141 (2 3 +) (1.571 sin) *)', '3 5 + (3.14159 cos) *', '-9 3 / 2 3 +', '100.5 17.6 - 10 +', '5']
        resultArray = [15.704999674256515, -7.999999999971834, 2.0, 92.9, 5]
        
        for i in range(5):
            print(inputArray[i])                                #Each test cases is printed to the terminal.
            print(f'The result should be {resultArray[i]}')     #The correct result will be printed from the resultArray.
            userInput = inputArray[i]                           
            if (i < 4):                                         #After the last test case, the if statment will be over and control will return to the while loop, so the input will be parsed after exiting the if statement.
                yacc.parse(userInput)   
                 
    yacc.parse(userInput)                                       #The parser parses the user's input and applies the grammar rules to it.
