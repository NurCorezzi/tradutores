%%

statements: %empty | statements statement;

statement: if_statement | noif_statement;

if_statement:
  "IF" '(' expression ')' statement
| "IF" '(' expression ')' noif_statement "ELSE" if_statement
;

noif_statement:
  "IF" '(' expression ')' noif_statement "ELSE" noif_statement
| "RETURN" ';'
| "{" statements "}"
;

expression: "IDENTIFIER";

// Statement         -> (Annos_ StatementPrefix):* Annos_ (StatementEnd | DanglingIf)  {% util.Statement %}
// StatementNoDangle -> (Annos_ StatementPrefix):* Annos_ (StatementEnd)               {% util.Statement %}

// StatementPrefix -> "if" _ "(" _ Expression _ ")" _ StatementNoDangle _ "else" _     {% util.IfElse %}
//                  | "while" _ "(" _ Expression _ ")" _                               {% util.While %}
//                  | "for" _ "(" (_ Simple):? _ ";" _ Expression _ ";" (_ Expression):? _ ")" _ {% util.For %}

// DanglingIf     -> "if" _ "(" _ Expression _ ")" _ Statement      {% util.IfStatement %}
// StatementEnd   -> Simple _ ";"                                   {% util.SimpleStatement %}
//                 | "return" (_ Expression):? _ ";"                {% util.ReturnStatement %}
//                 | BlockStatement                                 {% id %}
//                 | "break" _ ";"                                  {% util.BreakStatement %}
//                 | "continue" _ ";"                               {% util.ContinueStatement %}

statments: %empty | statments statment;

statment: statment_prefix statment_end | statment_prefix dangling_if;
statment_no_dangle: statment_prefix statment_end;

statment_prefix: IF OPEN_P CLOSE_P statment_no_dangle ELSE 
| WHILE OPEN_P CLOSE_P ;

dangling_if: IF OPEN_P CLOSE_P statment;
statment_end: OPEN_BRACE statments CLOSE_BRACE;

