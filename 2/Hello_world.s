.data

hello_world:
        .string "Hello world\n"


.text
.globl main
.type main, @function

main:
	push $hello_world		/* кладем в стек функцию hello_world */	
	call printf		/* передаем управление функции системной функции printf, и выводим из стека, наши адреса*/	

	addl $4, %esp	/* очищаем регистр, который отвечает за стек */
	ret 			/* возвращаем управление себе, и конец программы */