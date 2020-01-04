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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 12/26/19
* Time: 11:33:29
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2019年12月17日
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
int line=0;//生成节点时候的编号
int Num=0;//类型检查时候的节点序号
int curr_temp = 0;//临时变量数目
int label_num = 1;//标签
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
    int type; //表达式类型
    int tempid;////用于记录分配的临时变量序号
    int label_start=0,label_next=0,label_true=0,label_false=0;//用于跳转时候的记录标签
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
void ShowTree(struct TreeNode *p);//显示语法树
void ShowNode(struct TreeNode *p);//显示节点

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




#line 158 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 133 ".\\myparser.y"

	// place any extra initialisation code here

#line 182 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 138 ".\\myparser.y"

	// place any extra cleanup code here

#line 196 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 177 ".\\myparser.y"
 
			    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(4 - 4);
				ShowTree(yyattribute(4 - 4));
				
				
				ofstream out;
				out.open("output.txt", 'w');
				gen_asm(out, (*(YYSTYPE YYFAR*)yyvalptr));
				system("pause");
			
#line 315 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 189 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 330 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 193 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 345 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 197 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 360 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 201 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 375 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 205 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 390 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 209 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(CompK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(2 - 3);
			
#line 406 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 214 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
#line 421 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 218 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
#line 436 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 222 ".\\myparser.y"
	
				;
			
#line 451 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 227 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr)->sibling=yyattribute(2 - 2);
				(*(YYSTYPE YYFAR*)yyvalptr)= yyattribute(1 - 2);		
			
#line 467 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 232 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1) ;
			
#line 482 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 238 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);//int
                (*(YYSTYPE YYFAR*)yyvalptr)->type=Integer;
                   
			
#line 499 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 244 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);//char
                (*(YYSTYPE YYFAR*)yyvalptr)->type=Char;
			
#line 515 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 249 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);//void
                (*(YYSTYPE YYFAR*)yyvalptr)->type=Void;
			
#line 531 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 254 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);
				(*(YYSTYPE YYFAR*)yyvalptr)->type=Float;
			
#line 547 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 259 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);
				(*(YYSTYPE YYFAR*)yyvalptr)->type=Double;
			
#line 563 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 264 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(TypeK);
				(*(YYSTYPE YYFAR*)yyvalptr)->type=Bool;
			
#line 579 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 270 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->sibling=yyattribute(3 - 3);
			
#line 595 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 277 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode (VarK);//
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(2 - 3);
			
#line 612 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 285 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
                 
#line 628 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 291 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 7);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 7);
                 
#line 645 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 298 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(9 - 9);
			
#line 664 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 306 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(6 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8);
			
#line 683 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 314 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(6 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8);
			
#line 702 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 322 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(8 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = NULL;
			
#line 721 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 330 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(5 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
			
#line 740 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 338 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 7);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = NULL;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
			
#line 759 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 346 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = NULL;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
			
#line 778 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 354 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = NULL;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(6 - 6);
			
#line 797 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 363 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(WhileK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
			
#line 814 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 370 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
			
#line 829 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 376 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                (*(YYSTYPE YYFAR*)yyvalptr) -> attr.op =ORL;
                (*(YYSTYPE YYFAR*)yyvalptr) ->child[0] = yyattribute(1 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[1] = yyattribute(3 - 3);
            
#line 847 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 383 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                (*(YYSTYPE YYFAR*)yyvalptr) -> attr.op = ANDL;
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] = yyattribute(1 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[1] = yyattribute(3 - 3);
            
#line 865 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 391 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=EQUAL;
			
#line 883 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 398 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=LESSEQUAL;
			
#line 901 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 405 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=MOREEQUAL;
			
#line 919 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 412 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=LESS;
			
#line 937 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 419 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=MORE;
			
#line 955 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 426 ".\\myparser.y"
	
				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op=NOTEQUAL;
			
#line 973 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 433 ".\\myparser.y"

			   (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
			   (*(YYSTYPE YYFAR*)yyvalptr) -> attr.op = NOTL;
			   (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] =yyattribute(2 - 2);
			
#line 990 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 441 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = ADD;

                 
#line 1008 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 448 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = SUB;

                 
#line 1026 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 455 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = MUL;
                 
#line 1043 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 461 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = DIV;
                 
#line 1060 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 467 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = DIVQ;
                 
#line 1077 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 473 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK); 
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
                (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = AUTOADD;

			
#line 1095 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 480 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK); 
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
                (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = AUTOSUB;

			
#line 1113 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 487 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
			
#line 1128 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 491 ".\\myparser.y"

			    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 1143 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 494 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 1156 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 496 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op = ASSIGN;
			
#line 1174 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 504 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 1189 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 508 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 1204 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 512 ".\\myparser.y"

				(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
#line 1219 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 517 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(InputK);
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] = yyattribute(3 - 5);
                //$$->attr.name = $3->attr.name;;
            
#line 1236 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 524 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(OutputK);
                (*(YYSTYPE YYFAR*)yyvalptr) -> child[0] = yyattribute(3 - 5);
                //$$->attr.name = $3->attr.name;
            
#line 1253 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "IF", 257 },
		{ "MAIN", 258 },
		{ "FOR", 259 },
		{ "WHILE", 260 },
		{ "INT", 261 },
		{ "CHAR", 262 },
		{ "VOID", 263 },
		{ "FLOAT", 264 },
		{ "DOUBLE", 265 },
		{ "BOOL", 266 },
		{ "ID", 267 },
		{ "NUMBER", 268 },
		{ "CHARACTER", 269 },
		{ "ADD", 270 },
		{ "SUB", 271 },
		{ "MUL", 272 },
		{ "DIV", 273 },
		{ "DIVQ", 274 },
		{ "AUTOADD", 275 },
		{ "AUTOSUB", 276 },
		{ "LESS", 277 },
		{ "LESSEQUAL", 278 },
		{ "MORE", 279 },
		{ "MOREEQUAL", 280 },
		{ "EQUAL", 281 },
		{ "NOTEQUAL", 282 },
		{ "ASSIGN", 283 },
		{ "ANDL", 284 },
		{ "ORL", 285 },
		{ "NOTL", 286 },
		{ "SEMI", 287 },
		{ "COMMA", 288 },
		{ "LP", 289 },
		{ "RP", 290 },
		{ "COMPLEXLL", 291 },
		{ "COMPLEXLR", 292 },
		{ "INPUT", 293 },
		{ "OUTPUT", 294 },
		{ "ELSE", 295 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: start",
		"start: MAIN LP RP stmt",
		"stmt: var_dec",
		"stmt: exp_stmt",
		"stmt: if_stmt",
		"stmt: for_stmt",
		"stmt: while_stmt",
		"stmt: COMPLEXLL stmt_list COMPLEXLR",
		"stmt: input_stmt",
		"stmt: output_stmt",
		"stmt: SEMI",
		"stmt_list: stmt stmt_list",
		"stmt_list: stmt",
		"type_spec: INT",
		"type_spec: CHAR",
		"type_spec: VOID",
		"type_spec: FLOAT",
		"type_spec: DOUBLE",
		"type_spec: BOOL",
		"id_list: ID COMMA id_list",
		"id_list: ID",
		"var_dec: type_spec id_list SEMI",
		"if_stmt: IF LP exp RP stmt",
		"if_stmt: IF LP exp RP stmt ELSE stmt",
		"for_stmt: FOR LP exp SEMI exp SEMI exp RP stmt",
		"for_stmt: FOR LP SEMI exp SEMI exp RP stmt",
		"for_stmt: FOR LP exp SEMI SEMI exp RP stmt",
		"for_stmt: FOR LP exp SEMI exp SEMI RP stmt",
		"for_stmt: FOR LP SEMI SEMI exp RP stmt",
		"for_stmt: FOR LP SEMI exp SEMI RP stmt",
		"for_stmt: FOR LP exp SEMI SEMI RP stmt",
		"for_stmt: FOR LP SEMI SEMI RP stmt",
		"while_stmt: WHILE LP exp RP stmt",
		"exp_stmt: exp SEMI",
		"logical_exp: exp ORL exp",
		"logical_exp: exp ANDL exp",
		"logical_exp: exp EQUAL exp",
		"logical_exp: exp LESSEQUAL exp",
		"logical_exp: exp MOREEQUAL exp",
		"logical_exp: exp LESS exp",
		"logical_exp: exp MORE exp",
		"logical_exp: exp NOTEQUAL exp",
		"logical_exp: NOTL exp",
		"exp: exp ADD exp",
		"exp: exp SUB exp",
		"exp: exp MUL exp",
		"exp: exp DIV exp",
		"exp: exp DIVQ exp",
		"exp: term AUTOADD",
		"exp: term AUTOSUB",
		"exp: LP exp RP",
		"exp: logical_exp",
		"exp: term",
		"exp: exp ASSIGN exp",
		"term: ID",
		"term: NUMBER",
		"term: CHARACTER",
		"input_stmt: INPUT LP exp RP SEMI",
		"output_stmt: OUTPUT LP exp RP SEMI"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 4, 0 },
		{ 2, 1, 1 },
		{ 2, 1, 2 },
		{ 2, 1, 3 },
		{ 2, 1, 4 },
		{ 2, 1, 5 },
		{ 2, 3, 6 },
		{ 2, 1, 7 },
		{ 2, 1, 8 },
		{ 2, 1, 9 },
		{ 3, 2, 10 },
		{ 3, 1, 11 },
		{ 4, 1, 12 },
		{ 4, 1, 13 },
		{ 4, 1, 14 },
		{ 4, 1, 15 },
		{ 4, 1, 16 },
		{ 4, 1, 17 },
		{ 5, 3, 18 },
		{ 5, 1, -1 },
		{ 6, 3, 19 },
		{ 7, 5, 20 },
		{ 7, 7, 21 },
		{ 8, 9, 22 },
		{ 8, 8, 23 },
		{ 8, 8, 24 },
		{ 8, 8, 25 },
		{ 8, 7, 26 },
		{ 8, 7, 27 },
		{ 8, 7, 28 },
		{ 8, 6, 29 },
		{ 9, 5, 30 },
		{ 10, 2, 31 },
		{ 11, 3, 32 },
		{ 11, 3, 33 },
		{ 11, 3, 34 },
		{ 11, 3, 35 },
		{ 11, 3, 36 },
		{ 11, 3, 37 },
		{ 11, 3, 38 },
		{ 11, 3, 39 },
		{ 11, 2, 40 },
		{ 12, 3, 41 },
		{ 12, 3, 42 },
		{ 12, 3, 43 },
		{ 12, 3, 44 },
		{ 12, 3, 45 },
		{ 12, 2, 46 },
		{ 12, 2, 47 },
		{ 12, 3, 48 },
		{ 12, 1, 49 },
		{ 12, 1, 50 },
		{ 12, 3, 51 },
		{ 13, 1, 52 },
		{ 13, 1, 53 },
		{ 13, 1, 54 },
		{ 14, 5, 55 },
		{ 15, 5, 56 }
	};
	yyreduction = reduction;

	yytokenaction_size = 181;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 40, YYAT_SHIFT, 5 },
		{ 111, YYAT_SHIFT, 118 },
		{ 40, YYAT_SHIFT, 6 },
		{ 40, YYAT_SHIFT, 7 },
		{ 40, YYAT_SHIFT, 8 },
		{ 40, YYAT_SHIFT, 9 },
		{ 40, YYAT_SHIFT, 10 },
		{ 40, YYAT_SHIFT, 11 },
		{ 40, YYAT_SHIFT, 12 },
		{ 40, YYAT_SHIFT, 13 },
		{ 40, YYAT_SHIFT, 14 },
		{ 40, YYAT_SHIFT, 15 },
		{ 40, YYAT_SHIFT, 16 },
		{ 120, YYAT_SHIFT, 48 },
		{ 120, YYAT_SHIFT, 49 },
		{ 120, YYAT_SHIFT, 50 },
		{ 120, YYAT_SHIFT, 51 },
		{ 120, YYAT_SHIFT, 52 },
		{ 23, YYAT_SHIFT, 44 },
		{ 23, YYAT_SHIFT, 45 },
		{ 120, YYAT_SHIFT, 53 },
		{ 120, YYAT_SHIFT, 54 },
		{ 120, YYAT_SHIFT, 55 },
		{ 120, YYAT_SHIFT, 56 },
		{ 120, YYAT_SHIFT, 57 },
		{ 120, YYAT_SHIFT, 58 },
		{ 120, YYAT_SHIFT, 59 },
		{ 120, YYAT_SHIFT, 60 },
		{ 120, YYAT_SHIFT, 61 },
		{ 40, YYAT_SHIFT, 17 },
		{ 40, YYAT_SHIFT, 18 },
		{ 109, YYAT_SHIFT, 116 },
		{ 40, YYAT_SHIFT, 19 },
		{ 120, YYAT_SHIFT, 124 },
		{ 40, YYAT_SHIFT, 20 },
		{ 100, YYAT_SHIFT, 110 },
		{ 40, YYAT_SHIFT, 21 },
		{ 40, YYAT_SHIFT, 22 },
		{ 124, YYAT_SHIFT, 5 },
		{ 99, YYAT_SHIFT, 108 },
		{ 124, YYAT_SHIFT, 6 },
		{ 124, YYAT_SHIFT, 7 },
		{ 124, YYAT_SHIFT, 8 },
		{ 124, YYAT_SHIFT, 9 },
		{ 124, YYAT_SHIFT, 10 },
		{ 124, YYAT_SHIFT, 11 },
		{ 124, YYAT_SHIFT, 12 },
		{ 124, YYAT_SHIFT, 13 },
		{ 85, YYAT_SHIFT, 48 },
		{ 85, YYAT_SHIFT, 49 },
		{ 85, YYAT_SHIFT, 50 },
		{ 85, YYAT_SHIFT, 51 },
		{ 85, YYAT_SHIFT, 52 },
		{ 98, YYAT_SHIFT, 107 },
		{ 96, YYAT_SHIFT, 105 },
		{ 85, YYAT_SHIFT, 53 },
		{ 85, YYAT_SHIFT, 54 },
		{ 85, YYAT_SHIFT, 55 },
		{ 85, YYAT_SHIFT, 56 },
		{ 85, YYAT_SHIFT, 57 },
		{ 85, YYAT_SHIFT, 58 },
		{ 85, YYAT_SHIFT, 59 },
		{ 85, YYAT_SHIFT, 60 },
		{ 85, YYAT_SHIFT, 61 },
		{ 75, YYAT_SHIFT, 50 },
		{ 75, YYAT_SHIFT, 51 },
		{ 75, YYAT_SHIFT, 52 },
		{ 94, YYAT_SHIFT, 104 },
		{ 124, YYAT_SHIFT, 18 },
		{ 74, YYAT_SHIFT, 50 },
		{ 74, YYAT_SHIFT, 51 },
		{ 74, YYAT_SHIFT, 52 },
		{ 124, YYAT_SHIFT, 20 },
		{ 93, YYAT_SHIFT, 103 },
		{ 124, YYAT_SHIFT, 21 },
		{ 124, YYAT_SHIFT, 22 },
		{ 87, YYAT_SHIFT, 48 },
		{ 87, YYAT_SHIFT, 49 },
		{ 87, YYAT_SHIFT, 50 },
		{ 87, YYAT_SHIFT, 51 },
		{ 87, YYAT_SHIFT, 52 },
		{ 91, YYAT_SHIFT, 100 },
		{ 90, YYAT_SHIFT, 99 },
		{ 87, YYAT_SHIFT, 53 },
		{ 87, YYAT_SHIFT, 54 },
		{ 87, YYAT_SHIFT, 55 },
		{ 87, YYAT_SHIFT, 56 },
		{ 87, YYAT_SHIFT, 57 },
		{ 87, YYAT_SHIFT, 58 },
		{ 86, YYAT_SHIFT, 48 },
		{ 86, YYAT_SHIFT, 49 },
		{ 86, YYAT_SHIFT, 50 },
		{ 86, YYAT_SHIFT, 51 },
		{ 86, YYAT_SHIFT, 52 },
		{ 89, YYAT_SHIFT, 97 },
		{ 72, YYAT_SHIFT, 46 },
		{ 86, YYAT_SHIFT, 53 },
		{ 86, YYAT_SHIFT, 54 },
		{ 86, YYAT_SHIFT, 55 },
		{ 86, YYAT_SHIFT, 56 },
		{ 86, YYAT_SHIFT, 57 },
		{ 86, YYAT_SHIFT, 58 },
		{ 38, YYAT_SHIFT, 48 },
		{ 38, YYAT_SHIFT, 49 },
		{ 38, YYAT_SHIFT, 50 },
		{ 38, YYAT_SHIFT, 51 },
		{ 38, YYAT_SHIFT, 52 },
		{ 71, YYAT_SHIFT, 94 },
		{ 70, YYAT_SHIFT, 93 },
		{ 38, YYAT_SHIFT, 53 },
		{ 38, YYAT_SHIFT, 54 },
		{ 38, YYAT_SHIFT, 55 },
		{ 38, YYAT_SHIFT, 56 },
		{ 38, YYAT_SHIFT, 57 },
		{ 38, YYAT_SHIFT, 58 },
		{ 84, YYAT_SHIFT, 48 },
		{ 84, YYAT_SHIFT, 49 },
		{ 84, YYAT_SHIFT, 50 },
		{ 84, YYAT_SHIFT, 51 },
		{ 84, YYAT_SHIFT, 52 },
		{ 66, YYAT_SHIFT, 92 },
		{ 65, YYAT_SHIFT, 91 },
		{ 84, YYAT_SHIFT, 53 },
		{ 84, YYAT_SHIFT, 54 },
		{ 84, YYAT_SHIFT, 55 },
		{ 84, YYAT_SHIFT, 56 },
		{ 83, YYAT_SHIFT, 48 },
		{ 83, YYAT_SHIFT, 49 },
		{ 83, YYAT_SHIFT, 50 },
		{ 83, YYAT_SHIFT, 51 },
		{ 83, YYAT_SHIFT, 52 },
		{ 64, YYAT_SHIFT, 89 },
		{ 63, YYAT_SHIFT, 88 },
		{ 83, YYAT_SHIFT, 53 },
		{ 83, YYAT_SHIFT, 54 },
		{ 83, YYAT_SHIFT, 55 },
		{ 83, YYAT_SHIFT, 56 },
		{ 112, YYAT_SHIFT, 14 },
		{ 112, YYAT_SHIFT, 15 },
		{ 112, YYAT_SHIFT, 16 },
		{ 82, YYAT_SHIFT, 48 },
		{ 82, YYAT_SHIFT, 49 },
		{ 82, YYAT_SHIFT, 50 },
		{ 82, YYAT_SHIFT, 51 },
		{ 82, YYAT_SHIFT, 52 },
		{ 81, YYAT_SHIFT, 48 },
		{ 81, YYAT_SHIFT, 49 },
		{ 81, YYAT_SHIFT, 50 },
		{ 81, YYAT_SHIFT, 51 },
		{ 81, YYAT_SHIFT, 52 },
		{ 80, YYAT_SHIFT, 48 },
		{ 80, YYAT_SHIFT, 49 },
		{ 80, YYAT_SHIFT, 50 },
		{ 80, YYAT_SHIFT, 51 },
		{ 80, YYAT_SHIFT, 52 },
		{ 101, YYAT_SHIFT, 112 },
		{ 112, YYAT_SHIFT, 17 },
		{ 61, YYAT_ERROR, 0 },
		{ 101, YYAT_ERROR, 0 },
		{ 112, YYAT_SHIFT, 19 },
		{ 112, YYAT_SHIFT, 119 },
		{ 79, YYAT_SHIFT, 48 },
		{ 79, YYAT_SHIFT, 49 },
		{ 79, YYAT_SHIFT, 50 },
		{ 79, YYAT_SHIFT, 51 },
		{ 79, YYAT_SHIFT, 52 },
		{ 47, YYAT_SHIFT, 73 },
		{ 46, YYAT_SHIFT, 72 },
		{ 41, YYAT_SHIFT, 69 },
		{ 39, YYAT_SHIFT, 67 },
		{ 36, YYAT_SHIFT, 64 },
		{ 32, YYAT_SHIFT, 62 },
		{ 22, YYAT_SHIFT, 43 },
		{ 21, YYAT_SHIFT, 42 },
		{ 7, YYAT_SHIFT, 37 },
		{ 6, YYAT_SHIFT, 36 },
		{ 5, YYAT_SHIFT, 35 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -78, 1, YYAT_ERROR, 0 },
		{ -110, 1, YYAT_ERROR, 0 },
		{ 178, 1, YYAT_ERROR, 0 },
		{ -113, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -113, 1, YYAT_ERROR, 0 },
		{ -114, 1, YYAT_ERROR, 0 },
		{ -115, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -116, 1, YYAT_ERROR, 0 },
		{ -117, 1, YYAT_ERROR, 0 },
		{ -257, 1, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_DEFAULT, 72 },
		{ -116, 1, YYAT_DEFAULT, 101 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ -117, 1, YYAT_DEFAULT, 91 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ -168, 1, YYAT_REDUCE, 42 },
		{ -121, 1, YYAT_DEFAULT, 120 },
		{ -257, 1, YYAT_REDUCE, 12 },
		{ -124, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ -121, 1, YYAT_REDUCE, 20 },
		{ -121, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ -133, 1, YYAT_DEFAULT, 112 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ -158, 1, YYAT_DEFAULT, 120 },
		{ -156, 1, YYAT_DEFAULT, 91 },
		{ -166, 1, YYAT_DEFAULT, 101 },
		{ -170, 1, YYAT_DEFAULT, 120 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ -182, 1, YYAT_DEFAULT, 120 },
		{ -183, 1, YYAT_DEFAULT, 120 },
		{ -172, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ -203, 1, YYAT_REDUCE, 43 },
		{ -208, 1, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ -109, 1, YYAT_REDUCE, 39 },
		{ -120, 1, YYAT_REDUCE, 37 },
		{ -125, 1, YYAT_REDUCE, 40 },
		{ -130, 1, YYAT_REDUCE, 38 },
		{ -144, 1, YYAT_REDUCE, 36 },
		{ -155, 1, YYAT_REDUCE, 41 },
		{ -222, 1, YYAT_REDUCE, 53 },
		{ -181, 1, YYAT_REDUCE, 35 },
		{ -194, 1, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -196, 1, YYAT_DEFAULT, 112 },
		{ -205, 1, YYAT_DEFAULT, 101 },
		{ -206, 1, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -214, 1, YYAT_ERROR, 0 },
		{ -220, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ -241, 1, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -237, 1, YYAT_DEFAULT, 120 },
		{ -251, 1, YYAT_DEFAULT, 112 },
		{ -255, 1, YYAT_DEFAULT, 112 },
		{ -132, 1, YYAT_DEFAULT, 120 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -259, 1, YYAT_DEFAULT, 120 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -289, 1, YYAT_DEFAULT, 120 },
		{ -130, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ 0, 0, YYAT_DEFAULT, 124 },
		{ -257, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ -219, 1, YYAT_DEFAULT, 91 },
		{ 0, 0, YYAT_REDUCE, 24 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 56;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 124, 125 },
		{ 119, 123 },
		{ 124, 31 },
		{ 118, 122 },
		{ 124, 27 },
		{ 124, 34 },
		{ 124, 29 },
		{ 124, 26 },
		{ 124, 28 },
		{ 116, 121 },
		{ 124, 32 },
		{ 110, 117 },
		{ 124, 30 },
		{ 124, 33 },
		{ 112, 24 },
		{ 112, 120 },
		{ 112, 23 },
		{ 40, 40 },
		{ 40, 68 },
		{ 108, 115 },
		{ 107, 114 },
		{ 105, 113 },
		{ 100, 111 },
		{ 99, 109 },
		{ 97, 106 },
		{ 92, 102 },
		{ 91, 101 },
		{ 89, 98 },
		{ 88, 96 },
		{ 72, 95 },
		{ 64, 90 },
		{ 61, 87 },
		{ 60, 86 },
		{ 59, 85 },
		{ 58, 84 },
		{ 57, 83 },
		{ 56, 82 },
		{ 55, 81 },
		{ 54, 80 },
		{ 53, 79 },
		{ 52, 78 },
		{ 51, 77 },
		{ 50, 76 },
		{ 49, 75 },
		{ 48, 74 },
		{ 43, 71 },
		{ 42, 70 },
		{ 37, 66 },
		{ 36, 65 },
		{ 35, 63 },
		{ 31, 47 },
		{ 20, 41 },
		{ 19, 39 },
		{ 17, 38 },
		{ 4, 25 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 54, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 52, 124 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 41, 112 },
		{ 0, -1 },
		{ 40, 112 },
		{ 48, 40 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 45, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 37, 112 },
		{ 36, 112 },
		{ 35, 112 },
		{ 0, -1 },
		{ 0, -1 },
		{ 15, 124 },
		{ 0, -1 },
		{ 34, 112 },
		{ 33, 112 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 32, 112 },
		{ 31, 112 },
		{ 30, 112 },
		{ 29, 112 },
		{ 28, 112 },
		{ 27, 112 },
		{ 26, 112 },
		{ 25, 112 },
		{ 24, 112 },
		{ 23, 112 },
		{ 22, 112 },
		{ 21, 112 },
		{ 20, 112 },
		{ 19, 112 },
		{ 0, -1 },
		{ 0, -1 },
		{ 18, 112 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 26, 124 },
		{ 15, 112 },
		{ 0, -1 },
		{ 14, 112 },
		{ 23, 124 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 22, 124 },
		{ 0, -1 },
		{ 11, 112 },
		{ 10, 112 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 19, 124 },
		{ 0, -1 },
		{ 18, 124 },
		{ 17, 124 },
		{ 0, -1 },
		{ 9, 124 },
		{ 0, -1 },
		{ 3, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 7, 124 },
		{ 0, -1 },
		{ 1, 124 },
		{ -1, 124 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 112 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 531 ".\\myparser.y"


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

//获取临时变量
void gen_temp(TreeNode *r)
{
	TreeNode* t=r;
	//后序遍历整棵树
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
		
	//临时变量重用
	if(r->child[0]->kind==OpK )
		curr_temp--;
	if(r->child[1]!=NULL && r->child[1]->kind==OpK )
		curr_temp--;
	//临时变量分配	
	r->tempid=curr_temp++;
			
}

//开始生成asm代码（从根节点开始）
void gen_asm(ofstream &out, TreeNode *r)
{
    gen_header(out);								//生成asm代码头部
    out << endl << endl << "\t.data" << endl;		//开始生成数据段
    out<<"\ttype0 db '%d', 0"<<endl;
    out<<"\ttype1 db '%d ', 0"<<endl;
    out<<"\tindata DWORD ?"<<endl;
    gen_temp(r);									//分配临时变量
    for(int i = 0;i<=curr_temp;i++)
        out<<"\tt"<<i<<"\tDWORD 0"<<endl;
    gen_data(out, r);								//生成数据段
    out << endl << endl << "\t.code" << endl;		//开始生成代码段
    out<<"_start:"<<endl;							//程序开始标签
    gen_code(out, r);								//根据语法树生成asm代码
    //out << "\tinvoke crt_scanf, addr type0, indata"<<endl;
    out << "\tinvoke ExitProcess, 0" << endl;
    out << "end _start" <<endl;						//程序结束标签
}
//生成asm代码头部（包括代码版本、模式和库）
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

//生成asm代码数据段，遍历整棵树，实际上只有在可能存在声明语句的位置才向下遍历
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
                        out<<"\t_"<<t->attr.name<<"\tDWORD 0"<<endl;//只有在变量声明语句下的变量才会输出，因为只会进入Vark后才能遇到IdK。
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
                        gen_data(out, t->child[1]);//变量声明
                        break;
                    }
                }
                break;
            }
        }
    }
}



//生成代码段，根据语法树节点分为两类：语句和表达式
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
                gen_code_stmt(out, t);//生成语句类型节点代码
                break;
            }
            case ExpK:
            {
                gen_code_exp(out, t);//生成表达式类型节点代码
                break;
            }
        }
        t = t->sibling;//生成兄弟节点代码
    }
}
//生成标签时，判断为真的标签永远跟随在判断条件后
void gen_code_stmt(ofstream &out, TreeNode *r)
{
    struct TreeNode *t;
	t = (struct TreeNode *) malloc (sizeof(struct TreeNode));
    t = r;
    switch(r->kind)
    {
        case IfK:
        {
            //label_start为语句开始的标签，label_next为下一条语句的标签，label_true为判断为真时候的标签，label_false为判断为假时候的标签
            if(r->label_next==0)										//给if语句分配下一条语句的标签
				r->label_next=label_num++;
           
            if(t->child[0]->kind == ConstK)								//如果if判断条件是一个常量
            {
                if(t->child[0]->attr.val == 0)							//如果该常量为0则直接跳转
                {
                    out<<"\tJMP label"<<r->child[0]->label_false<<endl;	//直接跳转
                }
            }
            else
            {
                gen_code(out, t->child[0]);								//生成逻辑表达式部分的代码
            }
            if(t->child[1])gen_code(out, t->child[1]);					//递归生成条件为真时候的代码
            if(r->child[2])
				out<<"\tJMP label"<<r->label_next<<endl;				//如果有else部分的代码需要生成，则在此输出跳转
            out<<"label"<<r->child[0]->label_false<<":"<<endl;			//输出条件为假时候的标签
            if(t->child[2])
            {
                gen_code(out, t->child[2]);								//翻译条件为假时候的代码
                
            }
            out<<"label"<<r->label_next<<":"<<endl;						//在if语句结束后输出下一条语句的标签
            break;
        }
        case WhileK:
        {
			if(r->label_start==0)										//给while语句分配开始标签，用于循环跳转
				r->label_start=label_num++;
			
            out<<"label:"<<r->label_start<<":"<<endl;					//在翻译while语句前加上symbol1标签
            if(t->child[0]->kind == ConstK)								//若循环条件为常量
            {
                if(t->child[0]->attr.val == 0)							//若常量为0
                {
                    out<<"\tJMP label"<<r->child[0]->label_false<<endl;	//直接跳转
                }
            }
            else														//循环条件不是常量
            {
                gen_code(out, t->child[0]);								//翻译循环条件部分的代码
                r->label_next=r->child[0]->label_false;					//while语句的下一条语句标签的是循环条件为假的标签
            }
            
            if(t->child[1])gen_code(out, t->child[1]);					//翻译条件为真时候的代码
            out<<"\tJMP label"<<r->label_start<<endl;					//跳转至while语句所在位置
            out<<"label"<<r->label_next<<":"<<endl;						//输出循环条件为假时候的标签,即下一条语句的标签
            break;
        }
        case ForK:
        {
			if(r->label_start==0)										//为for语句分配开始标签
				r->label_start=label_num++;
            
            gen_code(out, t->child[0]);									//翻译初始化条件
            out<<"label"<<r->label_start<<":"<<endl;					//初始化完成后，输出for语句的开始标签
            if(t->child[1]->kind == ConstK)								//若循环条件为常量
            {
                if(t->child[1]->attr.val == 0)							//若常量为0
                {
                    out<<"\tJMP label"<<r->child[1]->label_false<<endl;	//直接跳转
                }
            }
            else														//循环条件不是常量
            {
                gen_code(out, t->child[1]);								//翻译循环条件部分的代码
                r->label_next=r->child[1]->label_false;					//for语句的下一条语句标签的是循环条件为假的标签
            }
            if(t->child[3])gen_code(out, t->child[3]);					//翻译条件为真时候的代码
            gen_code(out, t->child[2]);									//翻译循环控制语句
            out<<"\tJMP label"<<r->label_start<<endl;					//输出跳转到for语句标签
																		
            out<<"label"<<r->label_next<<":"<<endl;						//输出循环条件为假时候的标签，即输出下一条语句的标签
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
//生成表达式类型代码，后序生成代码，生成当前代码时必须保证所要使用的资源可以利用
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
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码 
                    gen_ADD(out, t->child[0], t->child[1],r); 
                    
                
                    break;
                case SUB:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码  
                    gen_SUB(out, t->child[0], t->child[1],r); 
                    
                    break;
                case MUL: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码 
                    gen_MUL(out, t->child[0], t->child[1],r); 
                    
                    break;
                case DIV: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码 
                    gen_DIV(out, t->child[0], t->child[1],r); 
                    
                    break;
                case DIVQ: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码 
                    gen_DIVQ(out, t->child[0], t->child[1],r); 
                   
                    break;
                case MOREEQUAL:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码  
                    gen_MOREEQUAL(out, t->child[0], t->child[1],t); 
                    
                    break;
                case LESSEQUAL:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码  
                    gen_LESSEQUAL(out, t->child[0], t->child[1],t); 
                    
                    break;
                case MORE: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码
                    gen_MORE(out, t->child[0], t->child[1],t); 
                    
                    break;
                case LESS: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码
                    gen_LESS(out, t->child[0], t->child[1],t); 
                    
                    break;
                case EQUAL: 
                    if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码  
                    gen_EQUAL(out, t->child[0], t->child[1],t); 
                    
                    break;
                case NOTEQUAL:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码
					gen_NOTEQUAL(out, t->child[0], t->child[1],t); 
                    
                    break;
                    
                case ANDL:
															
					if(t->child[0]->label_false==0)								//若与节点的false标签未分配，分配一个新标签
						t->child[0]->label_false=label_num++;
					t->child[1]->label_false=t->child[0]->label_false;			//与节点的false标签和表达式2的false标签与表达式1的false标签相同
					t->label_false=t->child[0]->label_false;
					if(t->label_true==0)										//若与节点的true标签未分配，分配一个新标签
						t->label_true=label_num++;
					//t->child[1]->label_true=t->label_true;				
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码
                  
                    break;
                case ORL:
					if(t->label_true==0)										//若或节点的true标签未分配，分配一个新标签
						t->label_true=label_num++; 
					if(t->label_false==0)										//若或节点的false标签未分配，分配一个新标签
						t->label_false=label_num++;

					t->child[1]->label_true=t->label_true;						//表达式2的true标签和或节点的true标签相同
					t->child[1]->label_false=t->label_false;					//表达式2的false标签和或节点的false标签相同
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					out<<"\tJMP label"<<t->label_true<<endl;					//为真，跳转到或节点true标签
					out<<"label"<<t->child[0]->label_false<<":"<<endl;			//输出表达式1为假的标签
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码
                    break;
                case NOTL: 
                    if(t->label_true==0)										//若非节点的true标签未分配，分配一个新标签
						t->label_true=label_num++;
					if(t->label_false==0)										//若非节点的true标签未分配，分配一个新标签
						t->label_false=label_num++;
					t->child[0]->label_false=t->label_true;						//表达式的false标签和非节点的true标签相同
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码
					out<<"\tJMP label"<<t->label_false<<endl;					//为真，跳转到非节点为假的标签
					out<<"label"<<t->label_true<<":"<<endl;						//输出非节点为真时候的标签
                    break;
                case ASSIGN:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);		//若孩子节点为表达式，则继续生成表达式代码，直到遇到常量（后序）
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);		//若孩子节点为表达式，则继续生成表达式代码，直到遇到常量（后序） 
                    gen_ASSIGN(out, t->child[0], t->child[1],r); 
                    
                    break;
                case AUTOADD:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);//若孩子节点为表达式，则继续生成表达式代码，直到遇到常量（后序）
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);//若孩子节点为表达式，则继续生成表达式代码，直到遇到常量（后序） 
                    gen_AUTOADD(out, t->child[0]); 
                    
                    break;
                case AUTOSUB:
					if(t->child[0]->kind == OpK)gen_code(out, t->child[0]);//若孩子节点为表达式，则继续生成表达式代码，直到遇到常量（后序）
					if(t->child[1]->kind == OpK)gen_code(out, t->child[1]);//若孩子节点为表达式，则继续生成表达式代码，直到遇到常量（后序） 
                    gen_AUTOSUB(out, t->child[0]); 
                    
                    break;
            }
            break;
        }
        case ConstK:
        {
            out<<"\tMOV eax, "<<t->attr.val<<endl;//常量直接使用
            break;
        }
        case IdK:
        {
            out<<"\tMOV eax, _"<<t->attr.name<<endl;//变量直接使用
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
    if (r1->kind == ConstK)//如果操作数1为常量
        out<<"\tMOV eax, "<<r1->attr.val<<endl;
    else if(r1->kind == IdK)//如果操作数1为变量
        out<<"\tMOV eax, _"<<r1->attr.name<<endl;
    else if(r1->kind == OpK)//如果操作数1为表达式，则调用临时变量
        out<<"\tMOV eax, t"<<r1->tempid<<endl;
    if (r2->kind == ConstK)//如果操作数2为常量
        out<<"\tADD eax, "<<r2->attr.val<<endl;
    else if(r2->kind == IdK)//如果操作数2为变量
        out<<"\tADD eax, _"<<r2->attr.name<<endl;
    else if(r2->kind == OpK)//如果操作数2为表达式，则调用临时变量
        out<<"\tADD eax, t"<<r2->tempid<<endl;
    out<<"\tMOV t"<<r->tempid<<", eax"<<endl;//将运算结果放入临时变量中
    
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
		out<<"\tMOV eax, t"<<r2->tempid<<endl;//将临时变量中的值放入寄存器中
    out<<"\tMOV _"<<r1->attr.name<<", eax"<<endl;
    out<<"\tMOV t"<<r->tempid<<", eax"<<endl;//将整个赋值语句的值放入一个临时变量中（为了实现连等）
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


