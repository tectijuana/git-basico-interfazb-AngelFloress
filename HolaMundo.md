 Title: Hola mundo en ARM					Filename: holamundo.s
# Author:Jose Angel Flores Gomez				Date: 08/04/2022
# Description: Mostrar HOLA MUNDO
# Input: -
# Output: HOLA MUNDO

 .global _start
############################# Code segment ####################################
_start:
  MOV R7, #4 ###;- cargar el valor de datos que esta en esta posicion en la secuencia de instrucciones
  MOV R0, #1 ###;- cargar el valor de datos que esta en esta posicion en la secuencia de instrucciones
  MOV R2, #12 ###;- parametro
  LDR R1, =string ###parametro y direccion de la cadena
  SWI 0 ### señal de interrupcion al O.S.
  MOV R7, #1 ### salir del programa y matar el proceso
  SWI 0 ### señal de interrupcion al O.S. para la terminacion
############################# Data segment ###################################
  .data
string:
  .ascii "HOLA MUNDO"
  
 ////////////
 .data

/* Data segment: define our message string and calculate its length */
msg:
    .ascii      "Hello, ARM!\n"
len = . - msg

.text

/* Our application's entry point. */
.globl _start
_start:
    /* syscall write(int fd, const void *buf, size_t count) */
    mov     %r0, $1     /* fd := STDOUT_FILENO */
    ldr     %r1, =msg   /* buf := msg */
    ldr     %r2, =len   /* count := len */
    mov     %r7, $4     /* write is syscall #4 */
    swi     $0          /* invoke syscall */

    /* syscall exit(int status) */
    mov     %r0, $0     /* status := 0 */
    mov     %r7, $1     /* exit is syscall #1 */
    swi     $0          /* invoke syscall */
