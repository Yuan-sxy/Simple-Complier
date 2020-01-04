#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 77 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 12/26/19
# Time: 11:33:29
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : start $end

    1  start : MAIN LP RP stmt

    2  stmt : var_dec
    3       | exp_stmt
    4       | if_stmt
    5       | for_stmt
    6       | while_stmt
    7       | COMPLEXLL stmt_list COMPLEXLR
    8       | input_stmt
    9       | output_stmt
   10       | SEMI

   11  stmt_list : stmt stmt_list
   12            | stmt

   13  type_spec : INT
   14            | CHAR
   15            | VOID
   16            | FLOAT
   17            | DOUBLE
   18            | BOOL

   19  id_list : ID COMMA id_list
   20          | ID

   21  var_dec : type_spec id_list SEMI

   22  if_stmt : IF LP exp RP stmt
   23          | IF LP exp RP stmt ELSE stmt

   24  for_stmt : FOR LP exp SEMI exp SEMI exp RP stmt
   25           | FOR LP SEMI exp SEMI exp RP stmt
   26           | FOR LP exp SEMI SEMI exp RP stmt
   27           | FOR LP exp SEMI exp SEMI RP stmt
   28           | FOR LP SEMI SEMI exp RP stmt
   29           | FOR LP SEMI exp SEMI RP stmt
   30           | FOR LP exp SEMI SEMI RP stmt
   31           | FOR LP SEMI SEMI RP stmt

   32  while_stmt : WHILE LP exp RP stmt

   33  exp_stmt : exp SEMI

   34  logical_exp : exp ORL exp
   35              | exp ANDL exp
   36              | exp EQUAL exp
   37              | exp LESSEQUAL exp
   38              | exp MOREEQUAL exp
   39              | exp LESS exp
   40              | exp MORE exp
   41              | exp NOTEQUAL exp
   42              | NOTL exp

   43  exp : exp ADD exp
   44      | exp SUB exp
   45      | exp MUL exp
   46      | exp DIV exp
   47      | exp DIVQ exp
   48      | term AUTOADD
   49      | term AUTOSUB
   50      | LP exp RP
   51      | logical_exp
   52      | term
   53      | exp ASSIGN exp

   54  term : ID
   55       | NUMBER
   56       | CHARACTER

   57  input_stmt : INPUT LP exp RP SEMI

   58  output_stmt : OUTPUT LP exp RP SEMI


##############################################################################
# States
##############################################################################

state 0
	$accept : . start $end

	MAIN  shift 1

	start  goto 2


state 1
	start : MAIN . LP RP stmt

	LP  shift 3


state 2
	$accept : start . $end  (0)

	$end  accept


state 3
	start : MAIN LP . RP stmt

	RP  shift 4


state 4
	start : MAIN LP RP . stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 25
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 5
	if_stmt : IF . LP exp RP stmt
	if_stmt : IF . LP exp RP stmt ELSE stmt

	LP  shift 35


state 6
	for_stmt : FOR . LP SEMI exp SEMI exp RP stmt
	for_stmt : FOR . LP SEMI SEMI exp RP stmt
	for_stmt : FOR . LP exp SEMI exp SEMI exp RP stmt
	for_stmt : FOR . LP SEMI exp SEMI RP stmt
	for_stmt : FOR . LP exp SEMI SEMI RP stmt
	for_stmt : FOR . LP SEMI SEMI RP stmt
	for_stmt : FOR . LP exp SEMI exp SEMI RP stmt
	for_stmt : FOR . LP exp SEMI SEMI exp RP stmt

	LP  shift 36


state 7
	while_stmt : WHILE . LP exp RP stmt

	LP  shift 37


state 8
	type_spec : INT .  (13)

	.  reduce 13


state 9
	type_spec : CHAR .  (14)

	.  reduce 14


state 10
	type_spec : VOID .  (15)

	.  reduce 15


state 11
	type_spec : FLOAT .  (16)

	.  reduce 16


state 12
	type_spec : DOUBLE .  (17)

	.  reduce 17


state 13
	type_spec : BOOL .  (18)

	.  reduce 18


state 14
	term : ID .  (54)

	.  reduce 54


state 15
	term : NUMBER .  (55)

	.  reduce 55


state 16
	term : CHARACTER .  (56)

	.  reduce 56


state 17
	logical_exp : NOTL . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 38


state 18
	stmt : SEMI .  (10)

	.  reduce 10


state 19
	exp : LP . exp RP

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 39


state 20
	stmt : COMPLEXLL . stmt_list COMPLEXLR

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 40
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	stmt_list  goto 41
	if_stmt  goto 34


state 21
	input_stmt : INPUT . LP exp RP SEMI

	LP  shift 42


state 22
	output_stmt : OUTPUT . LP exp RP SEMI

	LP  shift 43


state 23
	exp : term .  (52)
	exp : term . AUTOSUB
	exp : term . AUTOADD

	AUTOADD  shift 44
	AUTOSUB  shift 45
	.  reduce 52


state 24
	exp : logical_exp .  (51)

	.  reduce 51


state 25
	start : MAIN LP RP stmt .  (1)

	.  reduce 1


state 26
	stmt : while_stmt .  (6)

	.  reduce 6


state 27
	stmt : var_dec .  (2)

	.  reduce 2


state 28
	stmt : exp_stmt .  (3)

	.  reduce 3


state 29
	stmt : for_stmt .  (5)

	.  reduce 5


state 30
	stmt : input_stmt .  (8)

	.  reduce 8


state 31
	var_dec : type_spec . id_list SEMI

	ID  shift 46

	id_list  goto 47


state 32
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp
	exp_stmt : exp . SEMI

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	SEMI  shift 62


state 33
	stmt : output_stmt .  (9)

	.  reduce 9


state 34
	stmt : if_stmt .  (4)

	.  reduce 4


state 35
	if_stmt : IF LP . exp RP stmt
	if_stmt : IF LP . exp RP stmt ELSE stmt

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 63


state 36
	for_stmt : FOR LP . SEMI exp SEMI exp RP stmt
	for_stmt : FOR LP . SEMI SEMI exp RP stmt
	for_stmt : FOR LP . exp SEMI exp SEMI exp RP stmt
	for_stmt : FOR LP . SEMI exp SEMI RP stmt
	for_stmt : FOR LP . exp SEMI SEMI RP stmt
	for_stmt : FOR LP . SEMI SEMI RP stmt
	for_stmt : FOR LP . exp SEMI exp SEMI RP stmt
	for_stmt : FOR LP . exp SEMI SEMI exp RP stmt

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 64
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 65


state 37
	while_stmt : WHILE LP . exp RP stmt

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 66


state 38
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	logical_exp : NOTL exp .  (42)
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	.  reduce 42


state 39
	exp : LP exp . RP
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	RP  shift 67


state 40
	stmt_list : stmt . stmt_list
	stmt_list : stmt .  (12)

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22
	.  reduce 12

	term  goto 23
	logical_exp  goto 24
	stmt  goto 40
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	stmt_list  goto 68
	if_stmt  goto 34


state 41
	stmt : COMPLEXLL stmt_list . COMPLEXLR

	COMPLEXLR  shift 69


state 42
	input_stmt : INPUT LP . exp RP SEMI

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 70


state 43
	output_stmt : OUTPUT LP . exp RP SEMI

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 71


state 44
	exp : term AUTOADD .  (48)

	.  reduce 48


state 45
	exp : term AUTOSUB .  (49)

	.  reduce 49


state 46
	id_list : ID .  (20)
	id_list : ID . COMMA id_list

	COMMA  shift 72
	.  reduce 20


state 47
	var_dec : type_spec id_list . SEMI

	SEMI  shift 73


state 48
	exp : exp ADD . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 74


state 49
	exp : exp SUB . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 75


state 50
	exp : exp MUL . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 76


state 51
	exp : exp DIV . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 77


state 52
	exp : exp DIVQ . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 78


state 53
	logical_exp : exp LESS . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 79


state 54
	logical_exp : exp LESSEQUAL . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 80


state 55
	logical_exp : exp MORE . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 81


state 56
	logical_exp : exp MOREEQUAL . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 82


state 57
	logical_exp : exp EQUAL . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 83


state 58
	logical_exp : exp NOTEQUAL . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 84


state 59
	exp : exp ASSIGN . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 85


state 60
	logical_exp : exp ANDL . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 86


state 61
	logical_exp : exp ORL . exp

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 87


state 62
	exp_stmt : exp SEMI .  (33)

	.  reduce 33


state 63
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp
	if_stmt : IF LP exp . RP stmt
	if_stmt : IF LP exp . RP stmt ELSE stmt

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	RP  shift 88


state 64
	for_stmt : FOR LP SEMI . exp SEMI exp RP stmt
	for_stmt : FOR LP SEMI . SEMI exp RP stmt
	for_stmt : FOR LP SEMI . exp SEMI RP stmt
	for_stmt : FOR LP SEMI . SEMI RP stmt

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 89
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 90


state 65
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp
	for_stmt : FOR LP exp . SEMI exp SEMI exp RP stmt
	for_stmt : FOR LP exp . SEMI SEMI RP stmt
	for_stmt : FOR LP exp . SEMI exp SEMI RP stmt
	for_stmt : FOR LP exp . SEMI SEMI exp RP stmt

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	SEMI  shift 91


state 66
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp
	while_stmt : WHILE LP exp . RP stmt

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	RP  shift 92


state 67
	exp : LP exp RP .  (50)

	.  reduce 50


state 68
	stmt_list : stmt stmt_list .  (11)

	.  reduce 11


state 69
	stmt : COMPLEXLL stmt_list COMPLEXLR .  (7)

	.  reduce 7


state 70
	input_stmt : INPUT LP exp . RP SEMI
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	RP  shift 93


state 71
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	output_stmt : OUTPUT LP exp . RP SEMI
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	RP  shift 94


state 72
	id_list : ID COMMA . id_list

	ID  shift 46

	id_list  goto 95


state 73
	var_dec : type_spec id_list SEMI .  (21)

	.  reduce 21


state 74
	logical_exp : exp . MOREEQUAL exp
	exp : exp ADD exp .  (43)
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	.  reduce 43


state 75
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp SUB exp .  (44)
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	.  reduce 44


state 76
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp MUL exp .  (45)
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	.  reduce 45


state 77
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp DIV exp .  (46)
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	.  reduce 46


state 78
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp DIVQ exp .  (47)
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	.  reduce 47


state 79
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp LESS exp .  (39)
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	.  reduce 39


state 80
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp LESSEQUAL exp .  (37)
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	.  reduce 37


state 81
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp MORE exp .  (40)
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	.  reduce 40


state 82
	logical_exp : exp MOREEQUAL exp .  (38)
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	.  reduce 38


state 83
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp EQUAL exp .  (36)
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	.  reduce 36


state 84
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp NOTEQUAL exp .  (41)
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	.  reduce 41


state 85
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp ASSIGN exp .  (53)
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	.  reduce 53


state 86
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp ANDL exp .  (35)
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	.  reduce 35


state 87
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp ORL exp .  (34)
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	.  reduce 34


state 88
	if_stmt : IF LP exp RP . stmt
	if_stmt : IF LP exp RP . stmt ELSE stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 96
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 89
	for_stmt : FOR LP SEMI SEMI . exp RP stmt
	for_stmt : FOR LP SEMI SEMI . RP stmt

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19
	RP  shift 97

	term  goto 23
	logical_exp  goto 24
	exp  goto 98


state 90
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp
	for_stmt : FOR LP SEMI exp . SEMI exp RP stmt
	for_stmt : FOR LP SEMI exp . SEMI RP stmt

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	SEMI  shift 99


state 91
	for_stmt : FOR LP exp SEMI . exp SEMI exp RP stmt
	for_stmt : FOR LP exp SEMI . SEMI RP stmt
	for_stmt : FOR LP exp SEMI . exp SEMI RP stmt
	for_stmt : FOR LP exp SEMI . SEMI exp RP stmt

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 100
	LP  shift 19

	term  goto 23
	logical_exp  goto 24
	exp  goto 101


state 92
	while_stmt : WHILE LP exp RP . stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 102
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 93
	input_stmt : INPUT LP exp RP . SEMI

	SEMI  shift 103


state 94
	output_stmt : OUTPUT LP exp RP . SEMI

	SEMI  shift 104


state 95
	id_list : ID COMMA id_list .  (19)

	.  reduce 19


state 96
	if_stmt : IF LP exp RP stmt .  (22)
	if_stmt : IF LP exp RP stmt . ELSE stmt

	ELSE  shift 105
	.  reduce 22


state 97
	for_stmt : FOR LP SEMI SEMI RP . stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 106
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 98
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp
	for_stmt : FOR LP SEMI SEMI exp . RP stmt

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	RP  shift 107


state 99
	for_stmt : FOR LP SEMI exp SEMI . exp RP stmt
	for_stmt : FOR LP SEMI exp SEMI . RP stmt

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19
	RP  shift 108

	term  goto 23
	logical_exp  goto 24
	exp  goto 109


state 100
	for_stmt : FOR LP exp SEMI SEMI . RP stmt
	for_stmt : FOR LP exp SEMI SEMI . exp RP stmt

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19
	RP  shift 110

	term  goto 23
	logical_exp  goto 24
	exp  goto 111


state 101
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp
	for_stmt : FOR LP exp SEMI exp . SEMI exp RP stmt
	for_stmt : FOR LP exp SEMI exp . SEMI RP stmt

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	SEMI  shift 112


state 102
	while_stmt : WHILE LP exp RP stmt .  (32)

	.  reduce 32


state 103
	input_stmt : INPUT LP exp RP SEMI .  (57)

	.  reduce 57


state 104
	output_stmt : OUTPUT LP exp RP SEMI .  (58)

	.  reduce 58


state 105
	if_stmt : IF LP exp RP stmt ELSE . stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 113
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 106
	for_stmt : FOR LP SEMI SEMI RP stmt .  (31)

	.  reduce 31


state 107
	for_stmt : FOR LP SEMI SEMI exp RP . stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 114
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 108
	for_stmt : FOR LP SEMI exp SEMI RP . stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 115
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 109
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp
	for_stmt : FOR LP SEMI exp SEMI exp . RP stmt

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	RP  shift 116


state 110
	for_stmt : FOR LP exp SEMI SEMI RP . stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 117
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 111
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp
	for_stmt : FOR LP exp SEMI SEMI exp . RP stmt

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	RP  shift 118


state 112
	for_stmt : FOR LP exp SEMI exp SEMI . exp RP stmt
	for_stmt : FOR LP exp SEMI exp SEMI . RP stmt

	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	LP  shift 19
	RP  shift 119

	term  goto 23
	logical_exp  goto 24
	exp  goto 120


state 113
	if_stmt : IF LP exp RP stmt ELSE stmt .  (23)

	.  reduce 23


state 114
	for_stmt : FOR LP SEMI SEMI exp RP stmt .  (28)

	.  reduce 28


state 115
	for_stmt : FOR LP SEMI exp SEMI RP stmt .  (29)

	.  reduce 29


state 116
	for_stmt : FOR LP SEMI exp SEMI exp RP . stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 121
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 117
	for_stmt : FOR LP exp SEMI SEMI RP stmt .  (30)

	.  reduce 30


state 118
	for_stmt : FOR LP exp SEMI SEMI exp RP . stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 122
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 119
	for_stmt : FOR LP exp SEMI exp SEMI RP . stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 123
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 120
	logical_exp : exp . MOREEQUAL exp
	exp : exp . ADD exp
	logical_exp : exp . MORE exp
	exp : exp . SUB exp
	exp : exp . DIV exp
	exp : exp . DIVQ exp
	logical_exp : exp . NOTEQUAL exp
	logical_exp : exp . LESSEQUAL exp
	logical_exp : exp . LESS exp
	exp : exp . ASSIGN exp
	logical_exp : exp . ANDL exp
	logical_exp : exp . ORL exp
	exp : exp . MUL exp
	logical_exp : exp . EQUAL exp
	for_stmt : FOR LP exp SEMI exp SEMI exp . RP stmt

	ADD  shift 48
	SUB  shift 49
	MUL  shift 50
	DIV  shift 51
	DIVQ  shift 52
	LESS  shift 53
	LESSEQUAL  shift 54
	MORE  shift 55
	MOREEQUAL  shift 56
	EQUAL  shift 57
	NOTEQUAL  shift 58
	ASSIGN  shift 59
	ANDL  shift 60
	ORL  shift 61
	RP  shift 124


state 121
	for_stmt : FOR LP SEMI exp SEMI exp RP stmt .  (25)

	.  reduce 25


state 122
	for_stmt : FOR LP exp SEMI SEMI exp RP stmt .  (26)

	.  reduce 26


state 123
	for_stmt : FOR LP exp SEMI exp SEMI RP stmt .  (27)

	.  reduce 27


state 124
	for_stmt : FOR LP exp SEMI exp SEMI exp RP . stmt

	IF  shift 5
	FOR  shift 6
	WHILE  shift 7
	INT  shift 8
	CHAR  shift 9
	VOID  shift 10
	FLOAT  shift 11
	DOUBLE  shift 12
	BOOL  shift 13
	ID  shift 14
	NUMBER  shift 15
	CHARACTER  shift 16
	NOTL  shift 17
	SEMI  shift 18
	LP  shift 19
	COMPLEXLL  shift 20
	INPUT  shift 21
	OUTPUT  shift 22

	term  goto 23
	logical_exp  goto 24
	stmt  goto 125
	while_stmt  goto 26
	var_dec  goto 27
	exp_stmt  goto 28
	for_stmt  goto 29
	input_stmt  goto 30
	type_spec  goto 31
	exp  goto 32
	output_stmt  goto 33
	if_stmt  goto 34


state 125
	for_stmt : FOR LP exp SEMI exp SEMI exp RP stmt .  (24)

	.  reduce 24


##############################################################################
# Summary
##############################################################################

41 token(s), 16 nonterminal(s)
59 grammar rule(s), 126 state(s)


##############################################################################
# End of File
##############################################################################
