prog_name 		= tradutor.out
input_default 	= ./test/input_test
gramar_name 	= gramatica

INC_DIR = ./include
IMPL_DIR= ./src

_IMPL	= code_gen.c ast.c scope.c stable.c type_expression.c
IMPL 	= $(patsubst %, $(IMPL_DIR)/%,$(_IMPL))

all: 
	bison -v -d -Wempty-rule -Wconflicts-sr --verbose ./src/sintax/$(gramar_name).y
	flex ./src/lex/definicao.l
	gcc -g -Wall -Wextra $(IMPL) lex.yy.c $(gramar_name).tab.c -I $(INC_DIR) -I. -o $(prog_name)

r:
	./${prog_name} < ${input_default}

tac: r out
 
out: 
	../../tac-master/tac ./out.tac

check:
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./${prog_name} < ${input_default}

c1:
	./${prog_name} < ./test/code_gen/cast
c2:
	./${prog_name} < ./test/code_gen/const
c3:
	./${prog_name} < ./test/code_gen/expression_aritmetic
c4:
	./${prog_name} < ./test/code_gen/expression_boolean
c5:
	./${prog_name} < ./test/code_gen/expression_relational
c6:
	./${prog_name} < ./test/code_gen/function_parameter
c7:
	./${prog_name} < ./test/code_gen/if_else
c8:
	./${prog_name} < ./test/code_gen/while_for

clean:
	rm -f ./${prog_name} lex.yy.c  $(gramar_name).*
