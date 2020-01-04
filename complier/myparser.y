%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2019��12��17��
****************************************************************************/

#include "mylexer.h"
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

enum NodeKind {StmtK,ExpK,DeclK};
enum StmtKind {IfK,WhileK,ForK,CompK, InputK, OutputK};
enum ExpKind {OpK,ConstK,IdK,TypeK,VarK,AssignK};
enum ExpType {Void,Integer,Char,Bool,Float,Double};
#define MAXCHILDREN 4
int line=0;//���ɽڵ�ʱ��ı��
int Num=0;//���ͼ��ʱ��Ľڵ����
int curr_temp = 0;//��ʱ������Ŀ
int label_num = 1;//��ǩ
struct TreeNode
{ 
	struct TreeNode * child[MAXCHILDREN];
    struct TreeNode * sibling;
    int lineno;
    int nodekind;
    int kind;
    union{ int op;
             int val;
           char *name; }attr;
    int value;
    int type; //���ʽ����
    int tempid;////���ڼ�¼�������ʱ�������
    int label_start=0,label_next=0,label_true=0,label_false=0;//������תʱ��ļ�¼��ǩ
};
 
 
   
TreeNode * newStmtNode(int kind)
{ 
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
   printf("Out of memory error at line %d\n",line);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind = kind;
    t->lineno = line++;
  }
  return t;  
}


TreeNode * newExpNode(int kind)
{
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    printf("Out of memory error at line %d\n",line);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind = kind;
    t->lineno = line++;
    t->type = Void;
  }
  return t;
}



TreeNode *root;
void ShowTree(struct TreeNode *p);//��ʾ�﷨��
void ShowNode(struct TreeNode *p);//��ʾ�ڵ�

void type_check(TreeNode *root);
void traverse(TreeNode *root);
void check_node(TreeNode *root);

void gen_temp(TreeNode *r);
void gen_asm(ofstream &out, TreeNode *r);
void gen_header(ofstream &out);
void gen_data(ofstream &out, TreeNode *r);
void gen_code(ofstream &out, TreeNode *r);

void gen_code_stmt(ofstream &out, TreeNode *r);
void gen_code_exp(ofstream &out, TreeNode *r);
void gen_ADD(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// +
void gen_SUB(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// -
void gen_MUL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// *
void gen_DIV(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// /
void gen_DIVQ(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// %
void gen_AUTOADD(ofstream &out, TreeNode *r);// ++
void gen_AUTOSUB(ofstream &out, TreeNode *r);// --
void gen_MOREEQUAL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// >=
void gen_LESSEQUAL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// <=
void gen_MORE(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// >
void gen_LESS(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// <
void gen_NOTEQUAL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// !=
void gen_ANDL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// &&
void gen_ORL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// ||
void gen_EQUAL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// ==
void gen_NOTL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);//
void gen_ASSIGN(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r);// =



%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

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

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE TreeNode*
#endif
}

// place any declarations here
%token IF MAIN FOR WHILE 
%token INT CHAR VOID FLOAT DOUBLE BOOL
%token ID NUMBER CHARACTER
%token ADD SUB MUL DIV DIVQ AUTOADD AUTOSUB
%token LESS LESSEQUAL MORE MOREEQUAL EQUAL NOTEQUAL ASSIGN ANDL ORL NOTL
%token SEMI COMMA LP RP COMPLEXLL COMPLEXLR 
%token INPUT OUTPUT

%left	COMMA 
%right	ASSIGN
%left	ANDL,ORL
%left   NOTL 
%left	EQUAL NOTEQUAL 
%left	LESS LESSEQUAL MORE MOREEQUAL 
%left	ADD SUB 
%left   MUL DIV DIVQ 
%left   AUTOADD AUTOSUB
%left	LP RP COMPLEXLL COMPLEXLR 
%right	ELSE
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

start		:MAIN LP RP stmt
			{ 
			    $$ = $4;
				ShowTree($4);
				
				
				ofstream out;
				out.open("output.txt", 'w');
				gen_asm(out, $$);
				system("pause");
			}
			;
stmt		:var_dec				
			{	
				$$ = $1;
			}
			|exp_stmt					
			{	
				$$ = $1;
			}
			|if_stmt					
			{	
				$$ = $1;
			}
			|for_stmt
			{
				$$ = $1;
			}
			|while_stmt 
			{
				$$ = $1;
			}        
			|COMPLEXLL  stmt_list COMPLEXLR
			{	
				$$ = newStmtNode(CompK);
				$$->child[0]=$2;
			}
            |input_stmt
            {
                $$ = $1;
            }
            |output_stmt
            {
                $$ = $1;
            }
			|SEMI
			{	
				;
			}
			;			
stmt_list	:stmt stmt_list		
			{
				$$->sibling=$2;
				$$= $1;		
			}
			|stmt						
			{
				$$ = $1 ;
			}
			;

type_spec	:INT	
			{
				$$ = newExpNode(TypeK);//int
                $$->type=Integer;
                   
			}	
			|CHAR	
			{
				$$ = newExpNode(TypeK);//char
                $$->type=Char;
			}
			|VOID	
			{
				$$ = newExpNode(TypeK);//void
                $$->type=Void;
			}
			|FLOAT
			{
				$$ = newExpNode(TypeK);
				$$->type=Float;
			}
			|DOUBLE
			{
				$$ = newExpNode(TypeK);
				$$->type=Double;
			}
			|BOOL
			{
				$$ = newExpNode(TypeK);
				$$->type=Bool;
			}
			;
id_list		:ID COMMA id_list//
			{
				$$ = $1;
				$$->sibling=$3;
			}
			|ID
			;			             
var_dec		:type_spec id_list SEMI//
			{	
				$$ = newExpNode (VarK);//
				$$->child[0]=$1;
				$$->child[1]=$2;
			}
			;

if_stmt     :IF LP exp RP stmt //if(exp) stmt
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
      
            |IF LP exp RP stmt ELSE stmt//if (exp) stmt else stmt
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                 }
            ;
for_stmt	:FOR LP exp SEMI exp SEMI exp RP stmt//for(exp;exp;exp)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $7;
                $$->child[3] = $9;
			}
			|FOR LP SEMI exp SEMI exp RP stmt//for(;exp;exp)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = NULL;
				$$->child[1] = $4;
                $$->child[2] = $6;
                $$->child[3] = $8;
			}
			|FOR LP exp SEMI SEMI exp RP stmt//for(exp;;exp)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
				$$->child[1] = NULL;
                $$->child[2] = $6;
                $$->child[3] = $8;
			}
			|FOR LP exp SEMI exp SEMI RP stmt//for(exp;exp;)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $8;
                $$->child[3] = NULL;
			}
			|FOR LP SEMI SEMI exp RP stmt//for(;;exp)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = NULL;
				$$->child[1] = NULL;
				$$->child[2] = $5;
                $$->child[3] = $7;
			}
			|FOR LP SEMI exp SEMI RP stmt//for(;exp;)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = NULL;
				$$->child[1] = $4;
				$$->child[2] = NULL;
                $$->child[3] = $7;
			}
			|FOR LP exp SEMI SEMI RP stmt//for(exp;;)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = $3;
				$$->child[1] = NULL;
				$$->child[2] = NULL;
                $$->child[3] = $7;
			}
			|FOR LP SEMI SEMI RP stmt//for(;;)
			{
				$$ = newStmtNode(ForK);
				$$->child[0] = NULL;
				$$->child[1] = NULL;
				$$->child[2] = NULL;
				$$->child[3] = $6;
			}
			;
while_stmt	:WHILE LP exp RP stmt//while(exp)
			{
				$$ = newStmtNode(WhileK);
				$$->child[0] = $3;
                $$->child[1] = $5;
			}
			;
exp_stmt	:exp SEMI		//exp;
			{
				$$ = $1;
			}
			;

logical_exp :exp ORL exp
            {
                $$ = newExpNode(OpK);
                $$ -> attr.op =ORL;
                $$ ->child[0] = $1;
                $$ -> child[1] = $3;
            }
		|exp ANDL exp
            {
                $$ = newExpNode(OpK);
                $$ -> attr.op = ANDL;
                $$ -> child[0] = $1;
                $$ -> child[1] = $3;
            }           

		|exp EQUAL exp//==
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=EQUAL;
			}
		|exp LESSEQUAL exp//<=
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=LESSEQUAL;
			}
		|exp MOREEQUAL exp//>=
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=MOREEQUAL;
			}
		|exp LESS exp//<
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=LESS;
			}
		|exp MORE exp	//>
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=MORE;
			}
		|exp NOTEQUAL exp	//!=
			{	
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op=NOTEQUAL;
			}
		|NOTL exp
			{
			   $$ = newExpNode(OpK);
			   $$ -> attr.op = NOTL;
			   $$ -> child[0] =$2;
			}
			;
			
exp  :		exp ADD exp //+ - * / ++ --
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = ADD;

                 }
            | exp SUB exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = SUB;

                 } 
            | exp MUL exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = MUL;
                 } 
            | exp DIV exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = DIV;
                 } 
            | exp DIVQ exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = DIVQ;
                 } 
            |term AUTOADD 
			{
				$$ = newExpNode(OpK); 
				$$->child[0] = $1;
                $$->attr.op = AUTOADD;

			}
			|term AUTOSUB 
			{
				$$ = newExpNode(OpK); 
				$$->child[0] = $1;
                $$->attr.op = AUTOSUB;

			}
			|LP exp RP				
			{
				$$ = $2;
			}
			|logical_exp
			{
			    $$ = $1;
			}
			| term { $$ = $1; }
			|exp ASSIGN exp//exp=exp
			{
				$$ = newExpNode(OpK);
				$$->child[0]=$1;
				$$->child[1]=$3;
				$$->attr.op = ASSIGN;
			}
            ;
term		:ID					
			{
				$$ = $1;
			}
			|NUMBER				
			{
				$$ = $1;
			}
			| CHARACTER 
			{
				$$ = $1;
			}
			;
input_stmt  :INPUT LP exp RP SEMI
            {
                $$ = newStmtNode(InputK);
                $$ -> child[0] = $3;
                //$$->attr.name = $3->attr.name;;
            }
            ;
output_stmt  :OUTPUT LP exp RP SEMI
            {
                $$ = newStmtNode(OutputK);
                $$ -> child[0] = $3;
                //$$->attr.name = $3->attr.name;
            }
            ;

%%

/////////////////////////////////////////////////////////////////////////////
// programs section
void ShowTree(struct TreeNode *p)
{
	struct TreeNode *temp ;
	temp =(struct TreeNode *) malloc (sizeof(struct TreeNode));
    for(int i=0;i<MAXCHILDREN;i++)
    {
	   if(p->child[i] != NULL)
	   {
		ShowTree(p->child[i]);
	   }
	}
	ShowNode(p);
	temp=p->sibling;
	if(temp!=NULL){
    	ShowTree(temp);
	}	
	return;		
}

void ShowNode(struct TreeNode *p)
{
    p->lineno=Num++;
	struct TreeNode *temp ;
	temp = (struct TreeNode *) malloc (sizeof(struct TreeNode));
	printf("%d:",p->lineno);
	switch(p->nodekind)
	{
		case StmtK:
		{
			char *names[7] = {"If_statement,",  "While_statement,", "For_statement," , "Compound_statement,","Input_statement,","Print_statement," };
			printf("%s\t\t\t",names[p->kind]);
			break;
		}
			
		case ExpK:
		{
			char *names[5] = {"Expr," , "Const Declaration,", "ID Declaration,","Type Specifier,", "Var Declaration," };
			char *types[6] = {"Void","Integer ","Char","Bool","FLOAT","DOUBLE"};
			printf("%s\t", names[ p->kind ]);
			
			switch( p->kind )
			{
				case OpK:
					{
					   switch(p->attr.op)
					   {
					       case ADD:
					       {
					           printf("\top:+\t\t");
					           break;
					       }
					       case SUB:
					       {
					           printf("\top:-\t\t");
					           break;
					       }
					       case MUL:
					       {
					           printf("\top:*\t\t");
					           break;
					       }
					       case DIV:
					       {
					           printf("\top:/\t\t");
					           break;
					       }
					       case DIVQ:
					       {
					           printf("\top:%\t\t");
					           break;
					       }
					       case AUTOADD:
					       {
					           printf("\t\top:++\t\t");
					           break;
					       }
					       case AUTOSUB:
					       {
					           printf("\t\top:--\t\t");
					           break;
					       }
					       case LESS:
					       {
					           printf("\t\top:<\t\t");
					           break;
					       }
					       case LESSEQUAL:
					       {
					           printf("\t\top:<=\t\t");
					           break;
					       }
					       case MORE:
					       {
					           printf("\t\top:>\t\t");
					           break;
					       }
					       case MOREEQUAL:
					       {
					           printf("\t\top:>=\t\t");
					           break;
					       }	
					       case EQUAL:
					       {
					           printf("\t\top:==\t\t");
					           break;
					       }
					       case NOTEQUAL:
					       {
					           printf("\t\top:!=\t\t");
					           break;
					       }
					       case ORL:
					       {
					           printf("\t\top:||\t\t");
					           break;
					       }
					       case ANDL:
					       {
					           printf("\t\top:&&\t\t");
					           break;
					       }
					       case ASSIGN:
					       {
					           printf("\top:=\t\t");
					       }
					   }
					   break;
					}
				case ConstK:
					{
						if(p->type==Integer)
						{
							printf("values: %d\t",p->attr.val);
							break;
						}
						if(p->type==Char)
						{
							printf("values: %c\t",p->attr.val);
							break;
						}
					}
				case IdK:
					{
						printf("symbol: %s\t",p->attr.name);
						break;
					}
				case TypeK:
					{
						printf("%s\t", types[ p->type ]);
						break;
					}
				case VarK:
				{
					printf("\t\t");
					break;
				}
			}
			break;
		}
		
	}
	printf("children: ");
	for(int i=0;i<MAXCHILDREN;i++){
	    if(p->child[i] != NULL)
	    {
		    printf("%d  ",p->child[i]->lineno);
		    temp = p->child[i]->sibling;
		
		    while(temp != NULL)
		    {
			    printf("%d  ",temp->lineno);
			    temp = temp->sibling;
		    }
		
	    }
	}
	printf("\n");
	return ;
}

void type_check(TreeNode *root)
{
	traverse(root);
}

void traverse(TreeNode *root)
{
	if(root != NULL)
	{
		for(int i = 0;i<MAXCHILDREN;i++)
		{
			if(root->child[i] != NULL)
				traverse(root->child[i]);
		}
		if(root->sibling != NULL)
			traverse(root->sibling);
		check_node(root);
	}
}

void check_node(TreeNode *root)
{
	root->lineno=Num++;
	struct TreeNode *temp ;
	temp = (struct TreeNode *) malloc (sizeof(struct TreeNode));
	printf("%d:",root->lineno);
	switch(root->nodekind)
	{
		case StmtK:
		{
			char *names[7] = {"If_statement,",  "While_statement,", "For_statement," , "Compound_statement,","Input_statement,","Print_statement," };
			printf("%s\t\t",names[root->kind]);
			switch(root->kind)
			{
			case IfK:
			{
				if(root->child[0]->type != Bool)
				{
					printf("if test is not Bool. \t\t");
				}
				break;
			}
			case WhileK:
			{
				if(root->child[0]->type != Bool)
				{
					printf("while test is not Bool. \t\t");
				}
				break;
			}
			case ForK:
			{
				if((root->child[0] != NULL && root->child[0]->type != Integer) || (root->child[1] != NULL && root->child[1]->type != Bool)
				   || (root->child[2] != NULL && root->child[2]->type != Integer))
				{
					printf("for test error. \t\t");
				}
				break;
			}
			}
			break;
		}
		case ExpK:
		{
			char *names[5] = {"Expr," , "Const Declaration,", "ID Declaration,","Type Specifier,", "Var Declaration," };
			char *types[3] = {"Void","Integer ","Char"};
			printf("%s\t", names[ root->kind ]);
			
			switch( root->kind )
			{
				case OpK:
					{
					   switch(root->attr.op)
					   {
					       case ADD:
					       {
					           printf("\top:+\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case SUB:
					       {
					           printf("\top:-\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case MUL:
					       {
					           printf("\top:*\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case DIV:
					       {
					           printf("\top:/\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case DIVQ:
					       {
					           printf("\top:%\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case AUTOADD:
					       {
					           printf("\t\top:++\t\t");
					           if((root->child[0]->type != Integer) && (root->child[0]->type != Char))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case AUTOSUB:
					       {
					           printf("\t\top:--\t\t");
					           if((root->child[0]->type != Integer) && (root->child[0]->type != Char))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case LESS:
					       {
					           printf("\t\top:<\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Bool;
					           break;
					       }
					       case LESSEQUAL:
					       {
					           printf("\t\top:<=\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Bool;
					           break;
					       }
					       case MORE:
					       {
					           printf("\t\top:>\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Bool;
					           break;
					       }
					       case MOREEQUAL:
					       {
					           printf("\t\top:>=\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Bool;
					           break;
					       }	
					       case EQUAL:
					       {
					           printf("\t\top:==\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Bool;
					           break;
					       }
					       case NOTEQUAL:
					       {
					           printf("\t\top:!=\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Bool;
					           break;
					       }
					       case ORL:
					       {
					           printf("\t\top:||\t\t");
					           if((root->child[0]->type != Bool) || (root->child[1]->type != Bool))
					           {
					               printf("or test is not Bool.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case ANDL:
					       {
					           printf("\t\top:&&\t\t");
					           if((root->child[0]->type != Bool) || (root->child[1]->type != Bool))
					           {
					               printf("or test is not Bool.\t");
					           }
					           root->type = Integer;
					           break;
					       }
					       case ASSIGN:
					       {
					           printf("\top:=\t\t");
					           if(!((root->child[0]->type == Integer) || (root->child[1]->type == Integer) 
					              || (root->child[0]->type == Char) || (root->child[1]->type == Char)))
					           {
					               printf("OP applied to non-interger.\t");
					           }
					           root->type = Bool;
					       }
					   }
					   break;
					}
				case ConstK:
					{
						printf("values: %d\t",root->attr.val);
						break;
					}
				case IdK:
					{
						printf("symbol: %s\t",root->attr.name);
						root->type = Integer;
						break;
					}
				case TypeK:
					{
						printf("%s\t", types[ root->type ]);
						break;
					}
				case VarK:
				{
					printf("\t\t");
					break;
				}
			}
			break;
		}
		
	}
	printf("children: ");
	for(int i=0;i<MAXCHILDREN;i++){
	    if(root->child[i] != NULL)
	    {
		    printf("%d  ",root->child[i]->lineno);
		    temp = root->child[i]->sibling;
		
		    while(temp != NULL)
		    {
			    printf("%d  ",temp->lineno);
			    temp = temp->sibling;
		    }
		
	    }
	}
	printf("\n");
}

//��ȡ��ʱ����
void gen_temp(TreeNode *r)
{
	TreeNode* t=r;
	//�������������
	for(int i=0;i<MAXCHILDREN;i++)
	{
		if(r->child[i]!=NULL)
		gen_temp(r->child[i]);
	}
	if(r->sibling != NULL)
		gen_temp(r->sibling);
		
	
	if(r->nodekind!=ExpK)
		return ;
	if(r->attr.op!=ADD && r->attr.op!=SUB && r->attr.op != MUL && r->attr.op!=DIV && r->attr.op!=DIVQ)
		return;
		
	//��ʱ��������
	if(r->child[0]->kind==OpK )
		curr_temp--;
	if(r->child[1]!=NULL && r->child[1]->kind==OpK )
		curr_temp--;
	//��ʱ��������	
	r->tempid=curr_temp++;
			
}

//��ʼ����asm���루�Ӹ��ڵ㿪ʼ��
void gen_asm(ofstream &out, TreeNode *r)
{
    gen_header(out);								//����asm����ͷ��
    out << endl << endl << "\t.data" << endl;		//��ʼ�������ݶ�
    out<<"\ttype0 db '%d', 0"<<endl;
    out<<"\ttype1 db '%d ', 0"<<endl;
    out<<"\tindata DWORD ?"<<endl;
    gen_temp(r);									//������ʱ����
    for(int i = 0;i<=curr_temp;i++)
        out<<"\tt"<<i<<"\tDWORD 0"<<endl;
    gen_data(out, r);								//�������ݶ�
    out << endl << endl << "\t.code" << endl;		//��ʼ���ɴ����
    out<<"_start:"<<endl;							//����ʼ��ǩ
    gen_code(out, r);								//�����﷨������asm����
    //out << "\tinvoke crt_scanf, addr type0, indata"<<endl;
    out << "\tinvoke ExitProcess, 0" << endl;
    out << "end _start" <<endl;						//���������ǩ
}
//����asm����ͷ������������汾��ģʽ�Ϳ⣩
void gen_header(ofstream &out)
{
  out << "\t.586" << endl;//
  out << "\t.model flat, stdcall" << endl;
  out << "\toption casemap :none" << endl;
  out << endl;//
  out << "\tinclude \\masm32\\include\\windows.inc" << endl;
  out << "\tinclude \\masm32\\include\\user32.inc" << endl;
  out << "\tinclude \\masm32\\include\\kernel32.inc" << endl;
  out << "\tinclude \\masm32\\include\\masm32.inc" << endl;
  out << endl;
  out << "\tincludelib \\masm32\\lib\\user32.lib" << endl;
  out << "\tincludelib \\masm32\\lib\\kernel32.lib" << endl;
  out << "\tincludelib \\masm32\\lib\\masm32.lib" << endl;
  out << endl;
  out << "\tinclude \\masm32\\macros\\macros.asm" << endl;
  out << "\tinclude \\masm32\\include\\msvcrt.inc" << endl;
  out << "\tincludelib \\masm32\\lib\\msvcrt.lib" << endl;
}

//����asm�������ݶΣ�������������ʵ����ֻ���ڿ��ܴ�����������λ�ò����±���
void gen_data(ofstream &out, TreeNode *r)
{
    struct TreeNode *t;
	t = (struct TreeNode *) malloc (sizeof(struct TreeNode));
    for(t = r;t != NULL;t = t->sibling)
    {
        switch(t->nodekind)
        {
            case StmtK:
            {
                switch(t->kind)
                {
                    case IfK:
                    {
                        
                        if(t->child[1]) gen_data(out, t->child[1]);
                        if(t->child[2]) gen_data(out, t->child[2]);
                        break;
                    }
                    case WhileK:
                    {
                        
                        if(t->child[1]) gen_data(out, t->child[1]);
                        break;
                    }
                    case ForK:
                    {
                        if(t->child[0]) gen_data(out, t->child[0]);
                        
                        if(t->child[3]) gen_data(out, t->child[3]);
                        break;
                    }
                    case CompK:
                    {
                        if(t->child[0]) gen_data(out, t->child[0]);
                        break;
                    }
                    case InputK:
                    {
                        
                        break;
                    }
                    case OutputK:
                    {
                        
                        break;
                    }
                }
                break;
            }
            case ExpK:
            {
                switch(t->kind)
                {
                    case OpK:
                    {
                        //if(t->child[0]) gen_data(out, t->child[0]);
                        //if(t->child[1]) gen_data(out, t->child[1]);
                        break;
                    }
                    case IdK:
                    {
                        out<<"\t_"<<t->attr.name<<"\tDWORD 0"<<endl;//ֻ���ڱ�����������µı����Ż��������Ϊֻ�����Vark���������IdK��
                        break;
                    }
                    case ConstK:
                    {
                        break;
                    }
                    case TypeK:
                    {
                        break;
                    }
                    case VarK:
                    {
                        gen_data(out, t->child[1]);//��������
                        break;
                    }
                }
                break;
            }
        }
    }
}



//���ɴ���Σ������﷨���ڵ��Ϊ���ࣺ���ͱ��ʽ
void gen_code(ofstream &out, TreeNode *r)
{
    struct TreeNode *t;
	t = (struct TreeNode *) malloc (sizeof(struct TreeNode));
    t = r;
    while(t != NULL)
    {
        switch(t->nodekind)
        {
            case StmtK:
            {
                gen_code_stmt(out, t);//����������ͽڵ����
                break;
            }
            case ExpK:
            {
                gen_code_exp(out, t);//���ɱ��ʽ���ͽڵ����
                break;
            }
        }
        t = t->sibling;//�����ֵܽڵ����
    }
}
//���ɱ�ǩʱ���ж�Ϊ��ı�ǩ��Զ�������ж�������
void gen_code_stmt(ofstream &out, TreeNode *r)
{
    struct TreeNode *t;
	t = (struct TreeNode *) malloc (sizeof(struct TreeNode));
    t = r;
    switch(r->kind)
    {
        case IfK:
        {
            //label_startΪ��俪ʼ�ı�ǩ��label_nextΪ��һ�����ı�ǩ��label_trueΪ�ж�Ϊ��ʱ��ı�ǩ��label_falseΪ�ж�Ϊ��ʱ��ı�ǩ
            if(r->label_next==0)										//��if��������һ�����ı�ǩ
				r->label_next=label_num++;
           
            if(t->child[0]->kind == ConstK)								//���if�ж�������һ������
            {
                if(t->child[0]->attr.val == 0)							//����ó���Ϊ0��ֱ����ת
                {
                    out<<"\tJMP label"<<r->child[0]->label_false<<endl;	//ֱ����ת
                }
            }
            else
            {
                gen_code(out, t->child[0]);								//�����߼����ʽ���ֵĴ���
            }
            if(t->child[1])gen_code(out, t->child[1]);					//�ݹ���������Ϊ��ʱ��Ĵ���
            if(r->child[2])
				out<<"\tJMP label"<<r->label_next<<endl;				//�����else���ֵĴ�����Ҫ���ɣ����ڴ������ת
            out<<"label"<<r->child[0]->label_false<<":"<<endl;			//�������Ϊ��ʱ��ı�ǩ
            if(t->child[2])
            {
                gen_code(out, t->child[2]);								//��������Ϊ��ʱ��Ĵ���
                
            }
            out<<"label"<<r->label_next<<":"<<endl;						//��if�������������һ�����ı�ǩ
            break;
        }
        case WhileK:
        {
			if(r->label_start==0)										//��while�����俪ʼ��ǩ������ѭ����ת
				r->label_start=label_num++;
			
            out<<"label:"<<r->label_start<<":"<<endl;					//�ڷ���while���ǰ����symbol1��ǩ
            if(t->child[0]->kind == ConstK)								//��ѭ������Ϊ����
            {
                if(t->child[0]->attr.val == 0)							//������Ϊ0
                {
                    out<<"\tJMP label"<<r->child[0]->label_false<<endl;	//ֱ����ת
                }
            }
            else														//ѭ���������ǳ���
            {
                gen_code(out, t->child[0]);								//����ѭ���������ֵĴ���
                r->label_next=r->child[0]->label_false;					//while������һ������ǩ����ѭ������Ϊ�ٵı�ǩ
            }
            
            if(t->child[1])gen_code(out, t->child[1]);					//��������Ϊ��ʱ��Ĵ���
            out<<"\tJMP label"<<r->label_start<<endl;					//��ת��while�������λ��
            out<<"label"<<r->label_next<<":"<<endl;						//���ѭ������Ϊ��ʱ��ı�ǩ,����һ�����ı�ǩ
            break;
        }
        case ForK:
        {
			if(r->label_start==0)										//Ϊfor�����俪ʼ��ǩ
				r->label_start=label_num++;
            
            gen_code(out, t->child[0]);									//�����ʼ������
            out<<"label"<<r->label_start<<":"<<endl;					//��ʼ����ɺ����for���Ŀ�ʼ��ǩ
            if(t->child[1]->kind == ConstK)								//��ѭ������Ϊ����
            {
                if(t->child[1]->attr.val == 0)							//������Ϊ0
                {
                    out<<"\tJMP label"<<r->child[1]->label_false<<endl;	//ֱ����ת
                }
            }
            else														//ѭ���������ǳ���
            {
                gen_code(out, t->child[1]);								//����ѭ���������ֵĴ���
                r->label_next=r->child[1]->label_false;					//for������һ������ǩ����ѭ������Ϊ�ٵı�ǩ
            }
            if(t->child[3])gen_code(out, t->child[3]);					//��������Ϊ��ʱ��Ĵ���
            gen_code(out, t->child[2]);									//����ѭ���������
            out<<"\tJMP label"<<r->label_start<<endl;					//�����ת��for����ǩ
																		
            out<<"label"<<r->label_next<<":"<<endl;						//���ѭ������Ϊ��ʱ��ı�ǩ���������һ�����ı�ǩ
            break;
        }
        case CompK:
        {
            if(t->child[0])gen_code(out, t->child[0]);
            break;
        }
        case InputK:
        {
			
            out<<"\tMOV eax, sval(input(\"Enter a number : \"))"<<endl;
            out<<"\tmov _"<<t->child[0]->attr.name<<", "<<"eax"<<endl;
            break;
        }
        case OutputK:
        {	
			if (r->child[0]->kind == ConstK)
				out<<"\tinvoke crt_printf, addr type1, "<<r->child[0]->attr.val<<endl;
			else if(r->child[0]->kind == IdK)
				out<<"\tinvoke crt_printf, addr type1, _"<<r->child[0]->attr.name<<endl;
			else if(r->child[0]->kind == OpK)
			{
				gen_code(out,r->child[0]);
				out<<"\tinvoke crt_printf, addr type1, t"<<r->child[0]->tempid<<endl;
			}
            
            break;
        }
    }
}
//���ɱ��ʽ���ʹ��룬�������ɴ��룬���ɵ�ǰ����ʱ���뱣֤��Ҫʹ�õ���Դ��������
void gen_code_exp(ofstream &out, TreeNode *r)
{
    struct TreeNode *t;
	t = (struct TreeNode *) malloc (sizeof(struct TreeNode));
    t = r;
    switch(t->kind)
    {
        case OpK:
        {
            
            switch(t->attr.op)
            {
                case ADD:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ���� 
                    gen_ADD(out, t->child[0], t->child[1],r); 
                    
                
                    break;
                case SUB:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����  
                    gen_SUB(out, t->child[0], t->child[1],r); 
                    
                    break;
                case MUL: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ���� 
                    gen_MUL(out, t->child[0], t->child[1],r); 
                    
                    break;
                case DIV: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ���� 
                    gen_DIV(out, t->child[0], t->child[1],r); 
                    
                    break;
                case DIVQ: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ���� 
                    gen_DIVQ(out, t->child[0], t->child[1],r); 
                   
                    break;
                case MOREEQUAL:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����  
                    gen_MOREEQUAL(out, t->child[0], t->child[1],t); 
                    
                    break;
                case LESSEQUAL:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����  
                    gen_LESSEQUAL(out, t->child[0], t->child[1],t); 
                    
                    break;
                case MORE: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
                    gen_MORE(out, t->child[0], t->child[1],t); 
                    
                    break;
                case LESS: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
                    gen_LESS(out, t->child[0], t->child[1],t); 
                    
                    break;
                case EQUAL: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����  
                    gen_EQUAL(out, t->child[0], t->child[1],t); 
                    
                    break;
                case NOTEQUAL:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					gen_NOTEQUAL(out, t->child[0], t->child[1],t); 
                    
                    break;
                    
                case ANDL:
															
					if(t->child[0]->label_false==0)								//����ڵ��false��ǩδ���䣬����һ���±�ǩ
						t->child[0]->label_false=label_num++;
					t->child[1]->label_false=t->child[0]->label_false;			//��ڵ��false��ǩ�ͱ��ʽ2��false��ǩ����ʽ1��false��ǩ��ͬ
					t->label_false=t->child[0]->label_false;
					if(t->label_true==0)										//����ڵ��true��ǩδ���䣬����һ���±�ǩ
						t->label_true=label_num++;
					//t->child[1]->label_true=t->label_true;				
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
                  
                    break;
                case ORL:
					if(t->label_true==0)										//����ڵ��true��ǩδ���䣬����һ���±�ǩ
						t->label_true=label_num++; 
					if(t->label_false==0)										//����ڵ��false��ǩδ���䣬����һ���±�ǩ
						t->label_false=label_num++;

					t->child[1]->label_true=t->label_true;						//���ʽ2��true��ǩ�ͻ�ڵ��true��ǩ��ͬ
					t->child[1]->label_false=t->label_false;					//���ʽ2��false��ǩ�ͻ�ڵ��false��ǩ��ͬ
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					out<<"\tJMP label"<<t->label_true<<endl;					//Ϊ�棬��ת����ڵ�true��ǩ
					out<<"label"<<t->child[0]->label_false<<":"<<endl;			//������ʽ1Ϊ�ٵı�ǩ
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
                    break;
                case NOTL: 
                    if(t->label_true==0)										//���ǽڵ��true��ǩδ���䣬����һ���±�ǩ
						t->label_true=label_num++;
					if(t->label_false==0)										//���ǽڵ��true��ǩδ���䣬����һ���±�ǩ
						t->label_false=label_num++;
					t->child[0]->label_false=t->label_true;						//���ʽ��false��ǩ�ͷǽڵ��true��ǩ��ͬ
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ����
					out<<"\tJMP label"<<t->label_false<<endl;					//Ϊ�棬��ת���ǽڵ�Ϊ�ٵı�ǩ
					out<<"label"<<t->label_true<<":"<<endl;						//����ǽڵ�Ϊ��ʱ��ı�ǩ
                    break;
                case ASSIGN:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ���룬ֱ����������������
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ���룬ֱ���������������� 
                    gen_ASSIGN(out, t->child[0], t->child[1],r); 
                    
                    break;
                case AUTOADD:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ���룬ֱ����������������
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ���룬ֱ���������������� 
                    gen_AUTOADD(out, t->child[0]); 
                    
                    break;
                case AUTOSUB:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ���룬ֱ����������������
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);//�����ӽڵ�Ϊ���ʽ����������ɱ��ʽ���룬ֱ���������������� 
                    gen_AUTOSUB(out, t->child[0]); 
                    
                    break;
            }
            break;
        }
        case ConstK:
        {
            out<<"\tMOV eax, "<<t->attr.val<<endl;//����ֱ��ʹ��
            break;
        }
        case IdK:
        {
            out<<"\tMOV eax, _"<<t->attr.name<<endl;//����ֱ��ʹ��
            break;
        }
        case TypeK:
        {
            break;
        }
        case VarK:
        {
            break;
        }
    }
}
void gen_ADD(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
    if (r1->kind == ConstK)//���������1Ϊ����
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)//���������1Ϊ����
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)//���������1Ϊ���ʽ���������ʱ����
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)//���������2Ϊ����
        out<<"\tADD eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)//���������2Ϊ����
        out<<"\tADD eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)//���������2Ϊ���ʽ���������ʱ����
        out<<"\tADD eax, t"<<r2->tempid<<endl;
    out<<"\tMOV t"<<r->tempid<<", eax"<<endl;//��������������ʱ������
    
}

void gen_SUB(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tSUB eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tSUB eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tSUB eax, t"<<r2->tempid<<endl;
    out<<"\tMOV t"<<r->tempid<<", eax"<<endl;
    
}

void gen_MUL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tIMUL eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tIMUL eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tIMUL eax, t"<<r2->tempid<<endl;
    out<<"\tMOV t"<<r->tempid<<", eax"<<endl;
    
}

void gen_DIV(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tMOV ecx, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tMOV ecx, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tMOV ecx, t"<<r2->tempid<<endl;
    out<<"\tDIV ecx"<<endl;
    out<<"\tMOV t"<<r->tempid<<", eax"<<endl;
    
}

void gen_DIVQ(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
    out<<"\tMOV edx, 0"<<endl;
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tMOV ecx, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tMOV ecx, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tMOV ecx, t"<<r2->tempid<<endl;
    out<<"\tDIVQ ecx"<<endl;
    out<<"\tMOV t"<<r->tempid<<", edx"<<endl;
    
}

void gen_AUTOADD(ofstream &out, TreeNode *r)
{
    if (r->kind == ConstK)
        out<<"\tMOV eax, "<<r->attr.val<<endl;
    else if(r->kind == IdK)
        out<<"\tMOV eax, _"<<r->attr.name<<endl;
    out<<"\tMOV t"<<curr_temp<<", eax"<<endl;
    out<<"\tMOV eax, t"<<curr_temp<<endl;
    out<<"\tINC eax"<<endl;
    out<<"\tMOV _"<<r->attr.name<<", eax"<<endl;
}

void gen_AUTOSUB(ofstream &out, TreeNode *r)
{
    if (r->kind == ConstK)
        out<<"\tMOV eax, "<<r->attr.val<<endl;
    else if(r->kind == IdK)
        out<<"\tMOV eax, _"<<r->attr.name<<endl;
    out<<"\tMOV t"<<curr_temp<<", eax"<<endl;
    out<<"\tMOV eax, t"<<curr_temp<<endl;
    out<<"\tDEC eax"<<endl;
    out<<"\tMOV _"<<r->attr.name<<", eax"<<endl;
}
void gen_MOREEQUAL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
    if(r->label_true==0)
		r->label_true=label_num++;
	if(r->label_false==0)
		r->label_false=label_num++;
    out<<"\tJGE label"<<r->label_true<<endl;
    out<<"\tJMP label"<<r->label_false<<endl;
    out<<"label"<<r->label_true<<":"<<endl;
}

void gen_LESSEQUAL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
    if(r->label_true==0)
		r->label_true=label_num++;
	if(r->label_false==0)
		r->label_false=label_num++;
    out<<"\tJLE label"<<r->label_true<<endl;
    out<<"\tJMP label"<<r->label_false<<endl;
    out<<"label"<<r->label_true<<":"<<endl;
}

void gen_MORE(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
    if(r->label_true==0)
		r->label_true=label_num++;
	if(r->label_false==0)
		r->label_false=label_num++;
    out<<"\tJG label"<<r->label_true<<endl;
    out<<"\tJMP label"<<r->label_false<<endl;
    out<<"label"<<r->label_true<<":"<<endl;
}

void gen_LESS(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
	if(r->label_true==0)
		r->label_true=label_num++;
	if(r->label_false==0)
		r->label_false=label_num++;
    out<<"\tJL label"<<r->label_true<<endl;
    out<<"\tJMP label"<<r->label_false<<endl;
    out<<"label"<<r->label_true<<":"<<endl;
    
}
void gen_NOTEQUAL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
    if(r->label_true==0)
		r->label_true=label_num++;
	if(r->label_false==0)
		r->label_false=label_num++;
    out<<"\tJNE label"<<r->label_true<<endl;
    out<<"\tJMP label"<<r->label_false<<endl;
    out<<"label"<<r->label_true<<":"<<endl;
}

void gen_EQUAL(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
    if (r1->kind == ConstK)
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)
        out<<"\tCMP eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tCMP eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
        out<<"\tCMP eax, t"<<r2->tempid<<endl;
    if(r->label_true==0)
		r->label_true=label_num++;
	if(r->label_false==0)
		r->label_false=label_num++;
    out<<"\tJE label"<<r->label_true<<endl;
    out<<"\tJMP label"<<r->label_false<<endl;
    out<<"label"<<r->label_true<<":"<<endl;
}


void gen_ASSIGN(ofstream &out, TreeNode *r1, TreeNode *r2,TreeNode *r)
{
	if (r2->kind == ConstK)
        out<<"\tMOV eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)
        out<<"\tMOV eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)
		out<<"\tMOV eax, t"<<r2->tempid<<endl;//����ʱ�����е�ֵ����Ĵ�����
    out<<"\tMOV _"<<r1->attr.name<<", eax"<<endl;
    out<<"\tMOV t"<<r->tempid<<", eax"<<endl;//��������ֵ����ֵ����һ����ʱ�����У�Ϊ��ʵ�����ȣ�
}


	
int main(void)
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			lexer.yyin=new ifstream("test.txt");
			n=parser.yyparse();
		}
	}
	return n;
}

