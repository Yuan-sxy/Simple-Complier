%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2019��12��17��
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
unordered_map<string, int> idtable;//��ϣ���ű�
int idnumber=0;//ID���
struct TreeNode
   { 
	struct TreeNode * child[MAXCHILDREN];
     struct TreeNode * sibling;
     int lineno;
     int nodekind;
     int kind;
     union{ int op;
             int val;
           char *name; }attr;//���ڼ�¼����ֵ
     int value;
     int type;//��¼����ʽ����
	 int tempid;//���ڼ�¼�������ʱ�������
     int label_start,label_next,label_true,label_false;//������תʱ��ļ�¼��ǩ
	 
   } ;
   
extern YYSTYPE yylval;
extern int line;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here
FOR "for"
IF "if"
WHILE "while"
BREAK "break"
INT "int"
CHAR "char"
DOUBLE "double"
FLOAT "float"
BOOL "bool"
VOID "void"
INPUT "input"
OUTPUT "output"
ELSE "else"
MAIN "main"
COMMENT ("/*"([^\*]|(\*)*[^\*/])*"*/")|"//"[^\n]*
COMPLEXLL \{
COMPLEXLR \}
EQUAL "=="
LEFTMOVE "<<"
RIGHTMOVE ">>"
LESSEQUAL "<="
LESS \<
MOREEQUAL ">="
MORE \>
NOTEQUAL "!="
ANDL "&&"
ORL "||"
NOTL \!
DIVQ \%
AUTOADD "++"
AUTOSUB "--"
ADD \+
SUB \-
MUL \*
DIV \/
AND \&
OR \|
XOT \^
CHARACTER '.'
NUMBER		[0-9]+
ASSIGN \=
LP \(
RP \)
letter		[_A-Za-z]
ID	{letter}({letter}|{NUMBER})*
SEMI \;
COMMA \,
WS			[ \t\n\r\v]*
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
{IF}			{return IF;}
{ELSE}			{return ELSE;}
{FOR}			{return FOR;}
{WHILE}			{return WHILE;}
{VOID}			{return VOID;}
{INT}			{return INT;}
{CHAR}			{return CHAR;}
{INPUT}         {return INPUT;}
{OUTPUT}        {return OUTPUT;}
{MAIN}			{return MAIN;}
{COMMENT}		{;}
{ADD}			{return ADD;}	
{SUB}			{return SUB;}
{MUL}			{return MUL;}
{DIV}			{return DIV;}
{DIVQ}			{return DIVQ;}
{AUTOADD}		{return AUTOADD;}
{AUTOSUB}		{return AUTOSUB;}
{MOREEQUAL}		{return MOREEQUAL;}
{LESSEQUAL}		{return LESSEQUAL;}
{MORE}			{return MORE;}
{LESS}			{return	LESS;}
{NOTEQUAL}		{return NOTEQUAL;}
{ANDL}          {return ANDL;}
{ORL}           {return ORL;}
{NOTL}          {return NOTL;}
{EQUAL}			{return EQUAL;}
{ASSIGN}		{return ASSIGN;}
{COMMA}			{return COMMA;}
{SEMI}			{return SEMI;}		
{LP}			{return LP;} 
{RP}			{return RP;} 
{COMPLEXLL}	    {return COMPLEXLL;} 
{COMPLEXLR}		{return COMPLEXLR;}
{WS}			{;}
{CHARACTER}	{
					TreeNode * t = (TreeNode*) malloc(sizeof(TreeNode));
                    for (int i=0;i<MAXCHILDREN;i++) 
						t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = ConstK;
                    t->lineno = line++;
                    t->type = Char;
			        t->attr.val=yytext[1];//��ȡ�ַ�����
			        yylval =t;	
					return CHARACTER;
			}
{ID}		{	
					TreeNode * t = (TreeNode*) malloc(sizeof(TreeNode));
                    for (int i=0;i<MAXCHILDREN;i++)
						t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = IdK;
                    t->lineno = line++;
                    t->type = Void;
                    if(idtable.find(yytext)==idtable.end())//������������ű���
						{
							idtable[yytext]=idnumber;
							idnumber++;
						}
                    t->attr.name=new char[10];
					strcpy(t->attr.name,yytext);//��ȡ������
					yylval = t;
					return ID;
			}
				
{NUMBER}	{	
					TreeNode * t = (TreeNode*) malloc(sizeof(TreeNode));
                    for (int i=0;i<MAXCHILDREN;i++) 
						t->child[i] = NULL;
                    t->sibling = NULL;
                    t->nodekind = ExpK;
                    t->kind = ConstK;
                    t->lineno = line++;
                    t->type = Integer;
			        t->attr.val=atoi(yytext);//��ȡ����ֵ	
			        yylval =t;	
					return NUMBER;
			}
			

%%

/////////////////////////////////////////////////////////////////////////////
// programs section