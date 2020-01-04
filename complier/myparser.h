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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 12/26/19
* Time: 11:33:29
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 128 ".\\myparser.y"

	// place any extra class members here

#line 69 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 143 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE TreeNode*
#endif

#line 82 "myparser.h"
#define IF 257
#define MAIN 258
#define FOR 259
#define WHILE 260
#define INT 261
#define CHAR 262
#define VOID 263
#define FLOAT 264
#define DOUBLE 265
#define BOOL 266
#define ID 267
#define NUMBER 268
#define CHARACTER 269
#define ADD 270
#define SUB 271
#define MUL 272
#define DIV 273
#define DIVQ 274
#define AUTOADD 275
#define AUTOSUB 276
#define LESS 277
#define LESSEQUAL 278
#define MORE 279
#define MOREEQUAL 280
#define EQUAL 281
#define NOTEQUAL 282
#define ASSIGN 283
#define ANDL 284
#define ORL 285
#define NOTL 286
#define SEMI 287
#define COMMA 288
#define LP 289
#define RP 290
#define COMPLEXLL 291
#define COMPLEXLR 292
#define INPUT 293
#define OUTPUT 294
#define ELSE 295
#endif
