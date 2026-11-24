%{
/*
* grammar.y
*
* Pascal grammar in Yacc format, based originally on BNF given
* in "Standard Pascal -- User Reference Manual", by Doug Cooper.
* This in turn is the BNF given by the ANSI and ISO Pascal standards,
* and so, is PUBLIC DOMAIN. The grammar is for ISO Level 0 Pascal.
* The grammar has been massaged somewhat to make it LALR, and added
* the following extensions.
*
* constant expressions
* otherwise statement in a case
* productions to correctly match else's with if's
* beginnings of a separate compilation facility
*/

#include "service.h"

%}

%token KWAND KWARRAY ASSIGNMENT KWCASE CHARACTER_STRING
%token COLON COMMA KWCONST DIGSEQ KWDIV KWDO DOT DOTDOT
%token KWDOWNTO KWELSE KWEND EQUAL KWEXTERNAL KWFOR KWFORWARD
%token KWFUNCTION GE KWGOTO GT IDENTIFIER KWIF KWIN KWLABEL LBRAC
%token LE LPAREN LT MINUS KWMOD KWMODULE KWNIL KWNOT NOTEQUAL KWOF KWOR
%token KWOTHERWISE KWPACKED KWBEGIN KWFILE PLUS KWPROCEDURE
%token KWPROGRAM RBRAC REALNUMBER KWRECORD KWREPEAT RPAREN
%token SEMICOLON KWSET SLASH STAR STARSTAR KWTHEN
%token KWTO KWTYPE KWUNTIL UPARROW KWVAR KWWHILE KWWITH KWIMPORT

%token LEX_WHITE LEX_COMMENT LEX_LINE_COMMENT

%%
file    : program
        | module
		| error		
        ;


program : KWPROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON import_section block DOT
										{ /* g_service->addScope( $1, $8, ScopeModule, AccessPublic, StorageType,
																  $2, $1, $6); */}     
        ;



identifier_list : identifier_list COMMA IDENTIFIER
        | IDENTIFIER
        ;

import_section : import_section import_statement
			   |
			   ;
		
import_statement : KWIMPORT CHARACTER_STRING SEMICOLON 
								{ char fileName[1024]; 
								  const char * tokenstring;
								  //copy and remove the quotes	
								  tokenstring = g_service->tokenText(&$2) + 1;
								  int i = 0;
								  while (*tokenstring != '\0')
									fileName[i++] = *(tokenstring++);
									
	                              fileName[i-1] = '\0';
								  //find & load source
								  IScope* scope = NULL;

								  //searchFile does ParseSink::GetProject & BabelProject::SearchFile
								  g_service->searchFile(fileName,1024);
								  g_service->loadScope( fileName, &scope );
								  if (scope) { g_service->addExtern( $1, $2, scope ); scope->Release(); }										  									
								}
				;

block : label_declaration_part
        constant_definition_part
        type_definition_part
        variable_declaration_part
        procedure_and_function_declaration_part
        statement_part		
				
        ;

blockb : label_declaration_part
        constant_definition_part
        type_definition_part
        variable_declaration_part
        procedure_and_function_declaration_part
        ;

module : constant_definition_part
        type_definition_part
        variable_declaration_part
        procedure_and_function_declaration_part
        ;

label_declaration_part : KWLABEL label_list SEMICOLON
        |
        ;

label_list : label_list COMMA label
        | label
        ;

label : DIGSEQ
        ;

constant_definition_part : KWCONST constant_list
        |
        ;

constant_list : constant_list constant_definition
        | constant_definition
        ;

constant_definition : IDENTIFIER EQUAL cexpression SEMICOLON	
        ;

                                             
cexpression : csimple_expression
        | csimple_expression relop csimple_expression
        ;

csimple_expression : cterm
        | csimple_expression addop cterm
        ;

cterm : cfactor
        | cterm mulop cfactor
        ;

cfactor : sign cfactor
        | cexponentiation
        ;

cexponentiation : cprimary
        | cprimary STARSTAR cexponentiation
        ;

cprimary : IDENTIFIER
        | LPAREN cexpression RPAREN		{ g_service->matchPair($1,$3); }
        | unsigned_constant
        | KWNOT cprimary
        ;

constant : non_string
        | sign non_string
        | CHARACTER_STRING
        ;

sign : PLUS
        | MINUS
        ;

non_string : DIGSEQ
        | IDENTIFIER
        | REALNUMBER
        ;

type_definition_part : KWTYPE type_definition_list
        |
        ;

type_definition_list : type_definition_list type_definition
        | type_definition
        ;

type_definition : IDENTIFIER EQUAL type_denoter SEMICOLON
        ;

type_denoter : IDENTIFIER
        | new_type
        ;

new_type : new_ordinal_type
        | new_structured_type
        | new_pointer_type
        ;

new_ordinal_type : enumerated_type
        | subrange_type
        ;

enumerated_type : LPAREN identifier_list RPAREN		{ g_service->matchPair($1,$3); }
		   	    | LPAREN error RPAREN				{ g_service->syntaxError( "identifier list", &$2 ); }
				| LPAREN identifier_list error		{ g_service->expectError( "unmatched parenthesis", ")" ); }
				;

subrange_type : constant DOTDOT constant
        ;

new_structured_type : structured_type
        | KWPACKED structured_type
        ;

structured_type : array_type
        | record_type
        | set_type
        | file_type
        ;

array_type : KWARRAY LBRAC index_list RBRAC KWOF component_type
        ;

index_list : index_list COMMA index_type
        | index_type
        ;

index_type : ordinal_type ;

ordinal_type : new_ordinal_type
        | IDENTIFIER
        ;

component_type : type_denoter ;

record_type : KWRECORD record_section_list KWEND
        | KWRECORD record_section_list SEMICOLON variant_part KWEND
        | KWRECORD variant_part KWEND
        ;

record_section_list : record_section_list SEMICOLON record_section
        | record_section
        ;

record_section : identifier_list COLON type_denoter
        ;

variant_part : KWCASE variant_selector KWOF variant_list SEMICOLON
        | KWCASE variant_selector KWOF variant_list
        |
        ;

variant_selector : tag_field COLON tag_type
        | tag_type
        ;

variant_list : variant_list SEMICOLON variant
        | variant
        ;

variant : case_constant_list COLON LPAREN record_section_list RPAREN		{ g_service->matchPair($3,$5); }
        | case_constant_list COLON LPAREN record_section_list SEMICOLON		
                variant_part RPAREN											{ g_service->matchPair($3,$7); }
        | case_constant_list COLON LPAREN variant_part RPAREN				{ g_service->matchPair($3,$5); }
        ;

case_constant_list : case_constant_list COMMA case_constant
        | case_constant
        ;

case_constant : constant
        | constant DOTDOT constant
        ;

tag_field : IDENTIFIER ;

tag_type : IDENTIFIER ;

set_type : KWSET KWOF base_type
        ;

base_type : ordinal_type ;

file_type : KWFILE KWOF component_type
        ;

new_pointer_type : UPARROW domain_type
        ;

domain_type : IDENTIFIER ;

variable_declaration_part : KWVAR variable_declaration_list SEMICOLON
        |
        ;

variable_declaration_list :
          variable_declaration_list SEMICOLON variable_declaration
        | variable_declaration
        ;

variable_declaration : var_identifier_list COLON type_denoter   { g_service->addScope( $1, $2, ScopeVariable, AccessPublic, StorageLocal,
																$1, $1, $3, &$3 );  }
        ;

var_identifier_list : identifier_list COMMA IDENTIFIER		{	$$ = $3;
																g_service->addScope( $1, $3, ScopeVariable, AccessPublic, StorageLocal,
																$3, $1, $3);  }
        | IDENTIFIER										{ g_service->addScope( $1, $1, ScopeVariable, AccessPublic, StorageLocal,
																$1, $1, $1);  }
        ;


procedure_and_function_declaration_part :
          proc_or_func_declaration_list SEMICOLON
        |
        ;

proc_or_func_declaration_list :
          proc_or_func_declaration_list SEMICOLON proc_or_func_declaration
        | proc_or_func_declaration
        ;

proc_or_func_declaration : procedure_declaration
        | function_declaration
        ;

procedure_declaration : procedure_heading SEMICOLON directive
        | procedure_heading SEMICOLON procedure_block  { g_service->addScope( $1, $3, ScopeProcedure, AccessPublic, StorageType,
																  $1, $1, $2); }     
        ;

procedure_heading : procedure_identification
        | procedure_identification formal_parameter_list
        ;

directive : KWFORWARD
        | KWEXTERNAL
        ;

formal_parameter_list : LPAREN formal_parameter_section_list RPAREN		{ g_service->matchPair($1,$3); } 
					  | LPAREN error RPAREN								{ g_service->syntaxError( "parameters", &$2 ); }
					  | LPAREN formal_parameter_section_list error		{ g_service->expectError( "unmatched parenthesis", ")" ); }
					  ;

formal_parameter_section_list : 
          formal_parameter_section_list SEMICOLON formal_parameter_section
        | formal_parameter_section
        ;

formal_parameter_section : value_parameter_specification
        | variable_parameter_specification
        | procedural_parameter_specification
        | functional_parameter_specification
        ;

value_parameter_specification : identifier_list COLON IDENTIFIER	{	g_service->addScope( $1, $1, ScopeVariable, AccessPublic, StorageParameter,
																		$3, $1, $3, &$3 );  }  

        ;

variable_parameter_specification : KWVAR identifier_list COLON IDENTIFIER	{ g_service->addScope( $1, $4, ScopeVariable, AccessPublic, StorageParameter,
																		$4, $1, $4, &$4 );  }  
        ;

procedural_parameter_specification : procedure_heading ;

functional_parameter_specification : function_heading ;

procedure_identification : KWPROCEDURE IDENTIFIER    { $$ = $2 };

procedure_block : block ;

function_declaration : function_heading SEMICOLON directive
        | function_identification SEMICOLON function_block	{ g_service->addScope( $1, $3, ScopeProcedure, AccessPublic, StorageType,
																  $1, $1, $2); }     
        | function_heading SEMICOLON function_block	{ g_service->addScope( $1, $3, ScopeProcedure, AccessPublic, StorageType,
																  $1, $1, $2); }     
        ;

function_heading : KWFUNCTION IDENTIFIER COLON result_type		{ $$ = $2; }
        | KWFUNCTION IDENTIFIER formal_parameter_list COLON result_type		{ $$ = $2; }
        ;

result_type : IDENTIFIER ;

function_identification : KWFUNCTION IDENTIFIER		{ $$ = $2; }
				;	

function_block : block ;

statement_part : compound_statement ;

compound_statement : KWBEGIN statement_sequence KWEND	{ $$ = $3;
														  g_service->matchPair($1,$3);
														  g_service->addScopeText( $1, $3, ScopeBlock, AccessPublic, StorageOther);  }
				   | KWBEGIN statement_sequence error	{ $$ = @3;
														  g_service->expectError( "block", "END" ); 
														  g_service->addScopeText( $1, @3, ScopeBlock, AccessPublic, StorageOther); }
				   | KWBEGIN error KWEND				{ $$ = $3;
														  g_service->matchPair($1,$3); 
														  g_service->syntaxError( "block", &@2 );
														  g_service->addScopeText( $1, $3, ScopeBlock, AccessPublic, StorageOther ); }
				   ;

statement_sequence : statement_sequence SEMICOLON statement
        | statement
        ;

statement : open_statement
        | closed_statement
        ;

open_statement : label COLON non_labeled_open_statement
        | non_labeled_open_statement
        ;

closed_statement : label COLON non_labeled_closed_statement
        | non_labeled_closed_statement
        ;

non_labeled_closed_statement : assignment_statement
        | procedure_statement
        | goto_statement
        | compound_statement
        | case_statement
        | repeat_statement
        | closed_with_statement
        | closed_if_statement
        | closed_while_statement
        | closed_for_statement
        |
        ;

non_labeled_open_statement : open_with_statement
        | open_if_statement
        | open_while_statement
        | open_for_statement
        ;

repeat_statement : KWREPEAT statement_sequence KWUNTIL boolean_expression
        ;

open_while_statement : KWWHILE boolean_expression KWDO open_statement
        ;

closed_while_statement : KWWHILE boolean_expression KWDO closed_statement
        ;

open_for_statement : KWFOR control_variable ASSIGNMENT initial_value direction
                        final_value KWDO open_statement
        ;

closed_for_statement : KWFOR control_variable ASSIGNMENT initial_value direction
                        final_value KWDO closed_statement
        ;

open_with_statement : KWWITH record_variable_list KWDO open_statement
        ;

closed_with_statement : KWWITH record_variable_list KWDO closed_statement
        ;

open_if_statement : KWIF boolean_expression KWTHEN statement
        | KWIF boolean_expression KWTHEN closed_statement KWELSE open_statement
        ;

closed_if_statement : KWIF boolean_expression KWTHEN closed_statement
                        KWELSE closed_statement
        ;

assignment_statement : init_variable_access ASSIGNMENT expression
        ;

init_variable_access :
        variable_access { g_service->startName($1);
                        }
        | init_variable_access DOT variable_access            { g_service->qualifyName($2,$3); 
                                                                $$ = g_service->range($1,$3);
                                                              }
        | init_variable_access DOT error                 { g_service->qualifyName($2,$2);
                                                           g_service->expectError( "qualified name","identifier" );
                                                           $$ = g_service->range($1,$3);
                                                         }
        ;

variable_access : IDENTIFIER
        | indexed_variable				
        | init_variable_access UPARROW
        ;


indexed_variable : init_variable_access LBRAC index_expression_list RBRAC
        ;

index_expression_list : index_expression_list COMMA index_expression
        | index_expression
        ;

index_expression : expression ;

identifierb : init_variable_access
			|
			;

procedure_statement : IDENTIFIER params
        | IDENTIFIER
        ;

params : LPAREN actual_parameter_list RPAREN	{ $$ = $3; g_service->matchPair($1,$3); }
	   | LPAREN error RPAREN					{ $$ = $3; 
												  g_service->syntaxError( "invalid parameter list", &$2 ) }
	   | LPAREN actual_parameter_list error		{ g_service->expectError( "paremeter list missing closing paren", ")" ) };

actual_parameter_list : actual_parameter_list COMMA actual_parameter
        | actual_parameter
        ;

/*
 * this forces you to check all this to be sure that only write and
 * writeln use the 2nd and 3rd forms, you really can't do it easily in
 * the grammar, especially since write and writeln aren't reserved
 */
actual_parameter : expression
        | expression COLON expression
        | expression COLON expression COLON expression
        ;

goto_statement : KWGOTO label
        ;

case_statement : KWCASE case_index KWOF case_list_element_list KWEND
        | KWCASE case_index KWOF case_list_element_list SEMICOLON KWEND
        | KWCASE case_index KWOF case_list_element_list SEMICOLON
                        otherwisepart statement KWEND
        | KWCASE case_index KWOF case_list_element_list SEMICOLON
                        otherwisepart statement SEMICOLON KWEND
        ;

case_index : expression ;

case_list_element_list : case_list_element_list SEMICOLON case_list_element
        | case_list_element
        ;

case_list_element : case_constant_list COLON statement
        ;

otherwisepart : KWOTHERWISE
        | KWOTHERWISE COLON
        ;

control_variable : IDENTIFIER ;

initial_value : expression ;

direction : KWTO
        | KWDOWNTO
        ;

final_value : expression ;

record_variable_list : record_variable_list COMMA init_variable_access
        | init_variable_access
        ;

boolean_expression : expression ;

expression : simple_expression
        | simple_expression relop simple_expression
        ;

simple_expression : term
        | simple_expression addop term
        ;

term : factor
        | term mulop factor
        ;

factor : sign factor
        | exponentiation
        ;
        
exponentiation : primary
        | primary STARSTAR exponentiation
        ;

primary : init_variable_access
        | unsigned_constant
        | function_designator
        | set_constructor
        | LPAREN expression RPAREN  { g_service->matchPair($1,$3); }
        | KWNOT primary
        ;

unsigned_constant : unsigned_number
        | CHARACTER_STRING
        | KWNIL
        ;

unsigned_number : unsigned_integer | unsigned_real ;

unsigned_integer : DIGSEQ
        ;

unsigned_real : REALNUMBER
        ;

/* functions with no params will be handled by plain identifier */
function_designator : IDENTIFIER params
        ;

set_constructor : LBRAC member_designator_list RBRAC
        | LBRAC RBRAC
        ;

member_designator_list : member_designator_list COMMA member_designator
        | member_designator
        ;

member_designator : member_designator DOTDOT expression
        | expression
        ;

addop: PLUS
        | MINUS
        | KWOR
        ;

mulop : STAR
        | SLASH
        | KWDIV
        | KWMOD
        | KWAND
        ;

relop : EQUAL
        | NOTEQUAL
        | LT
        | GT
        | LE
        | GE
        | KWIN
        ;




%%


extern int line_no;

