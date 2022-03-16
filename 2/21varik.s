.data

print:
        .string "minimuma: %d\nmaximuma: %d\n"

arr:
	.long 1, 2, 3, 40, 5, -6, 7, -8, 9, 10
arr_end:
z
.text
.globl main
.type main, @function

main:
	movl $0, %ecx 		/* в регистре ecx будем хранить значение максимума, пока что поместим туда число 0 */
	movl $0, %edx 		/* в регистре edx будем хранить значение минимума, пока что поместим туда число 0 */
	movl $arr, %ebx  	/* вebx, ложим наш массив */
	movl (%ebx), %eax  /* в eax ложим первый элемент массива */

jmp bound /* безусловный переход к функции bound  */

search_max:   				/* функиця search_max */
	cmpl (%ebx), %ecx 		/* сравниваем два значения(элемент массива и max), ВАЖНО что %ebx ссылается на первый элемент в массиве, и он ПИШЕТСЯ В КРУГЛЫХ СКОБКАХ */
	jg search_min  		 /* если (%ebx) < max */
	jl max        		  /* (%ebx) > max */
	je next_element		 /* (%ebx) == max */

search_min:
	cmpl (%ebx), %edx		/* сравниваем два значения (элемент массива и min), ВАЖНО что %ebx ссылается на первый элемент в массиве, и он ПИШЕТСЯ В КРУГЛЫХ СКОБКАХ */
	jg min 					/* если (%ebx) < min */
	jl next_element          /* если (%ebx) > min */
	je next_element			 /* если (%ebx) == min */

max:
        movl (%ebx), %ecx 	/* ecx = ecx + ebx */
        jmp next_element 	/* безусловный переход к функции next_elements */


min:
        movl (%ebx), %edx /* edx = edx + ebx */
        jmp next_element /* безусловный переход к функции next_elements */


next_element:
	addl $4, %ebx /* переходим к адресу след эл-та массива; */
    movl (%ebx), %eax /* в eax ложим следующий элемент массива */

bound:
	cmpl $arr_end, %ebx /* сравнить адрес текущего элемента массива и адрес конца массива*/
	jne search_max   	/* если не равны, то переходим снова к функции search_max*/


/* Следующие строчки кода, а именно push, call и ret связаны между собой, но понять точно, как они связаны, это хрень какая то  */
push %edx    /* кладем в стек значение регистра edx */
push %ecx		/* кладем в стек значение регистра ecx */
push $print		/* кладем в стек функцию print */	
call printf		/* вызываем системную функцию printf для вывода на экран ХЗ */	

addl $12, %esp	/* очищаем регистр, который отвечает за стек */
ret 			/* конец программы */