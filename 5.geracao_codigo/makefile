prog_name=tradutor.out
input_default=input_test.txt

prog_c1=./test/semantico/correto1.txt
prog_c2=./test/semantico/correto2.txt
prog_e1=./test/semantico/errado1.txt
prog_e2=./test/semantico/errado2.txt

all:
	bison -v -d -Wempty-rule -Wconflicts-sr --verbose gramatica.y
	flex definicao.l
	gcc -g -Wall -Wextra lex.yy.c gramatica.tab.c -o ${prog_name}

r:
	./${prog_name} < ${input_default}

tac: r
	../../tac-master/tac ./out.tac

check:
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./${prog_name} < ${input_default}
cc1:
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./${prog_name} < ${prog_c1}
cc2:
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./${prog_name} < ${prog_c2}
ce1:
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./${prog_name} < ${prog_e1}
ce2:
	valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./${prog_name} < ${prog_e2}

c1:
	./${prog_name} < ${prog_c1}
c2:
	./${prog_name} < ${prog_c2}
e1:
	./${prog_name} < ${prog_e1}
e2: 
	./${prog_name} < ${prog_e2}

clean:
	rm ./${prog_name} lex.yy.c 
