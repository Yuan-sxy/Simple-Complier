/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 77 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 12/26/19
* Time: 10:00:01
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2019年12月17日
****************************************************************************/

#include "myparser.h"
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <cstring>
#include <malloc.h>
#include <stdlib.h>
#include <unordered_map>

enum NodeKind {StmtK,ExpK,DeclK};
enum StmtKind {IfK,WhileK,ForK,CompK, InputK, OutputK};
enum ExpKind {OpK,ConstK,IdK,TypeK,VarK,AssignK};
enum ExpType {Void,Integer,Char,Bool,Float,Double};

#define MAXCHILDREN 4
unordered_map<string, int> idtable;//哈希符号表
int idnumber=0;//ID序号
struct TreeNode
   { 
	struct TreeNode * child[MAXCHILDREN];
     struct TreeNode * sibling;
     int lineno;
     int nodekind;
     int kind;
     union{ int op;
             int val;
           char *name; }attr;//用于记录结点的值
     int value;
     int type;//记录表达式类型
	 int tempid;//用于记录分配的临时变量序号
     int label_start,label_next,label_true,label_false;//用于跳转时候的记录标签
	 
   } ;
   
extern YYSTYPE yylval;
extern int line;

#line 84 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 59 ".\\mylexer.l"

	// place any extra initialisation code here

#line 108 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 64 ".\\mylexer.l"

	// place any extra cleanup code here

#line 120 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 122 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 191 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 128 ".\\mylexer.l"
return IF;
#line 198 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 129 ".\\mylexer.l"
return ELSE;
#line 205 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 130 ".\\mylexer.l"
return FOR;
#line 212 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 131 ".\\mylexer.l"
return WHILE;
#line 219 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 132 ".\\mylexer.l"
return VOID;
#line 226 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 133 ".\\mylexer.l"
return INT;
#line 233 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 134 ".\\mylexer.l"
return CHAR;
#line 240 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 135 ".\\mylexer.l"
return INPUT;
#line 247 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 136 ".\\mylexer.l"
return OUTPUT;
#line 254 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 137 ".\\mylexer.l"
return MAIN;
#line 261 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 138 ".\\mylexer.l"
;
#line 268 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 139 ".\\mylexer.l"
return ADD;
#line 275 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 140 ".\\mylexer.l"
return SUB;
#line 282 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 141 ".\\mylexer.l"
return MUL;
#line 289 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 142 ".\\mylexer.l"
return DIV;
#line 296 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 143 ".\\mylexer.l"
return DIVQ;
#line 303 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 144 ".\\mylexer.l"
return AUTOADD;
#line 310 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 145 ".\\mylexer.l"
return AUTOSUB;
#line 317 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 146 ".\\mylexer.l"
return MOREEQUAL;
#line 324 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 147 ".\\mylexer.l"
return LESSEQUAL;
#line 331 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 148 ".\\mylexer.l"
return MORE;
#line 338 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 149 ".\\mylexer.l"
return	LESS;
#line 345 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 150 ".\\mylexer.l"
return NOTEQUAL;
#line 352 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 151 ".\\mylexer.l"
return ANDL;
#line 359 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 152 ".\\mylexer.l"
return ORL;
#line 366 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 153 ".\\mylexer.l"
return NOTL;
#line 373 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 154 ".\\mylexer.l"
return EQUAL;
#line 380 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 155 ".\\mylexer.l"
return ASSIGN;
#line 387 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 156 ".\\mylexer.l"
return COMMA;
#line 394 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 157 ".\\mylexer.l"
return SEMI;
#line 401 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 158 ".\\mylexer.l"
return LP;
#line 408 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 159 ".\\mylexer.l"
return RP;
#line 415 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 160 ".\\mylexer.l"
return COMPLEXLL;
#line 422 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 161 ".\\mylexer.l"
return COMPLEXLR;
#line 429 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 162 ".\\mylexer.l"
;
#line 436 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 163 ".\\mylexer.l"

					TreeNode * t = (TreeNode*) malloc(sizeof(TreeNode));
                    for (int i=0;i<MAXCHILDREN;i++) 
						t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = ConstK;
                    t->lineno = line++;
                    t->type = Char;
			        t->attr.val=yytext[1];//获取字符常量
			        yylval =t;	
					return CHARACTER;
			
#line 455 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 176 ".\\mylexer.l"
	
					TreeNode * t = (TreeNode*) malloc(sizeof(TreeNode));
                    for (int i=0;i<MAXCHILDREN;i++)
						t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = IdK;
                    t->lineno = line++;
                    t->type = Void;
                    if(idtable.find(yytext)==idtable.end())//将变量放入符号表中
						{
							idtable[yytext]=idnumber;
							idnumber++;
						}
                    t->attr.name=new char[10];
					strcpy(t->attr.name,yytext);//获取变量名
					yylval = t;
					return ID;
			
#line 480 "mylexer.cpp"
		}
		break;
#line 195 ".\\mylexer.l"
				
#line 485 "mylexer.cpp"
	case 38:
		{
#line 196 ".\\mylexer.l"
	
					TreeNode * t = (TreeNode*) malloc(sizeof(TreeNode));
                    for (int i=0;i<MAXCHILDREN;i++) 
						t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = ConstK;
                    t->lineno = line++;
                    t->type = Integer;
			        t->attr.val=atoi(yytext);//获取整数值	
			        yylval =t;	
					return NUMBER;
			
#line 502 "mylexer.cpp"
		}
		break;
#line 209 ".\\mylexer.l"
			
#line 507 "mylexer.cpp"
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 193;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 3, 1 },
		{ 3, 1 },
		{ 45, 24 },
		{ 3, 1 },
		{ 63, 63 },
		{ 33, 6 },
		{ 37, 14 },
		{ 39, 17 },
		{ 57, 46 },
		{ 0, 63 },
		{ 46, 24 },
		{ 38, 14 },
		{ 58, 46 },
		{ 3, 3 },
		{ 3, 3 },
		{ 3, 3 },
		{ 40, 18 },
		{ 3, 3 },
		{ 41, 19 },
		{ 42, 21 },
		{ 43, 22 },
		{ 44, 23 },
		{ 3, 1 },
		{ 4, 1 },
		{ 0, 7 },
		{ 47, 25 },
		{ 48, 26 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 3, 3 },
		{ 14, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 49, 27 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 50, 28 },
		{ 51, 30 },
		{ 52, 34 },
		{ 53, 37 },
		{ 0, 38 },
		{ 54, 42 },
		{ 55, 43 },
		{ 56, 44 },
		{ 35, 11 },
		{ 59, 47 },
		{ 60, 48 },
		{ 61, 49 },
		{ 62, 50 },
		{ 64, 53 },
		{ 65, 54 },
		{ 66, 55 },
		{ 67, 57 },
		{ 68, 59 },
		{ 69, 60 },
		{ 70, 61 },
		{ 71, 62 },
		{ 36, 13 },
		{ 72, 67 },
		{ 73, 69 },
		{ 74, 71 },
		{ 75, 73 },
		{ 21, 1 },
		{ 32, 4 },
		{ 22, 1 },
		{ 23, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 24, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 25, 1 },
		{ 0, 0 },
		{ 26, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 27, 1 },
		{ 28, 1 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 20, 75 },
		{ 0, 0 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 },
		{ 20, 75 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 75, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 6, 35 },
		{ 0, 31, 26 },
		{ 0, 0, 16 },
		{ 0, -31, 0 },
		{ -34, 16, 0 },
		{ 0, 0, 31 },
		{ 0, 0, 32 },
		{ 0, 0, 14 },
		{ 0, 30, 12 },
		{ 0, 0, 29 },
		{ 0, 41, 13 },
		{ 0, -34, 15 },
		{ 0, 7, 38 },
		{ 0, 0, 30 },
		{ 0, -52, 22 },
		{ 0, -43, 28 },
		{ 0, -41, 21 },
		{ 75, 0, 37 },
		{ 75, -83, 37 },
		{ 75, -86, 37 },
		{ 75, -88, 37 },
		{ 75, -98, 37 },
		{ 75, -70, 37 },
		{ 75, -89, 37 },
		{ 75, -61, 37 },
		{ 75, -39, 37 },
		{ 0, 0, 33 },
		{ 0, -58, 0 },
		{ 0, 0, 34 },
		{ 0, 0, 23 },
		{ 0, 0, 24 },
		{ 0, 28, 0 },
		{ 0, 0, 17 },
		{ 0, 0, 18 },
		{ -37, 26, 0 },
		{ -38, 59, 11 },
		{ 0, 0, 20 },
		{ 0, 0, 27 },
		{ 0, 0, 19 },
		{ 75, -27, 37 },
		{ 75, -44, 37 },
		{ 75, -42, 37 },
		{ 75, 0, 1 },
		{ 75, -102, 37 },
		{ 75, -31, 37 },
		{ 75, -41, 37 },
		{ 75, -29, 37 },
		{ 75, -28, 37 },
		{ 0, 0, 25 },
		{ 0, 0, 36 },
		{ 63, 31, 0 },
		{ 75, -35, 37 },
		{ 75, -21, 37 },
		{ 75, 0, 3 },
		{ 75, -36, 37 },
		{ 75, 0, 6 },
		{ 75, -28, 37 },
		{ 75, -29, 37 },
		{ 75, -16, 37 },
		{ 75, -23, 37 },
		{ -37, -36, 0 },
		{ 0, 0, 11 },
		{ 75, 0, 7 },
		{ 75, 0, 2 },
		{ 75, -29, 37 },
		{ 75, 0, 10 },
		{ 75, -29, 37 },
		{ 75, 0, 5 },
		{ 75, -12, 37 },
		{ 75, 0, 8 },
		{ 75, -26, 37 },
		{ 75, 0, 4 },
		{ 0, 70, 9 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 211 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section

