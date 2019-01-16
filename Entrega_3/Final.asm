include macros2.asm 
include number.asm 

.model LARGE 
.386
.stack 200h

.data
salto_linea DB 13,10,"$" 
aux_decla_var dd ?
_0in dd 0.0
_1in dd 1.0
aux_pos dd ?
e dd ?
true dd ?
false dd ?
aux dd ?
id dd ?
id3 dd ?
id4 dd ?
id5 dd ?
id7 dd ?
id1 dd ?
id2 dd ?
_2 dd 2
_4 dd 4
_3 dd 3
_23 dd 23
_5 dd 5
@aux0 dd ?
@aux1 dd ?
@aux2 dd ?
@aux3 dd ?
@aux4 dd ?
@aux5 dd ?

.code
start:



mov ax,@data
mov ds,ax
mov es,ax

FINIT
FFREE

mov ax,0003h 
int 10h

label0:
FLD id2
FSTP _2
label3:
FLD id4
FSTP id2

label7:
FLD id5
FLD id4
FADD
FSTP @aux0

label8:
FLD id7
FSTP @aux0
label11:
FLD id3
FSTP _4
label14:
FLD aux_pos
FSTP false
label17:
FLD aux
FSTP id4

label20:
FLD _2
FLD id2
FMUL
FSTP @aux1

label22:
FLD @aux1
FSTP e
label25:
FLD aux
FLD e
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label28:
jne label33
label30:
FLD aux_pos
FSTP true
label33:
FLD _3
FSTP e
label36:
FLD aux
FLD e
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label39:
jne label44
label41:
FLD aux_pos
FSTP true
label44:
FLD id1
FLD _23
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label47:
jnb label52
label49:
FLD id
FSTP _2
label52:
FLD aux
FSTP false
label55:
FLD id4
FSTP id2
label59:
FLD id4
FLD 
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label62:
jnbe label75

label64:
FLD id4
FLD _2
FADD
FSTP @aux2

label67:
FLD id4
FLD 
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label70:
jnae label75
label72:
FLD aux
FSTP true
label75:
FLD aux_pos
FSTP false
label78:
FLD aux
FSTP id4

label81:
FLD _2
FLD id2
FMUL
FSTP @aux3

label83:
FLD @aux3
FSTP e
label86:
FLD aux
FLD e
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label89:
jne label94
label91:
FLD aux_pos
FSTP true
label94:
FLD _3
FSTP e
label97:
FLD aux
FLD e
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label100:
jne label105
label102:
FLD aux_pos
FSTP true
label105:
FLD id1
FLD _2
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label108:
jnb label167

label110:
DisplayFloat @aux2, 2

label112:
FLD aux
FSTP false
label115:
FLD id4
FSTP id2
label119:
FLD id4
FLD 
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label122:
jnbe label135

label124:
FLD id4
FLD _2
FADD
FSTP @aux4

label127:
FLD id4
FLD 
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label130:
jnae label135
label132:
FLD aux
FSTP true
label135:
FLD aux_pos
FSTP false
label138:
FLD aux
FSTP id4

label141:
FLD _2
FLD id2
FMUL
FSTP @aux5

label143:
FLD @aux5
FSTP e
label146:
FLD aux
FLD e
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label149:
jne label154
label151:
FLD aux_pos
FSTP true
label154:
FLD _3
FSTP e
label157:
FLD aux
FLD e
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label160:
jne label165
label162:
FLD aux_pos
FSTP true

label165:
GetFloat @aux4, 2

label167:
FLD id1
FLD _23
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label170:
jnb label175
label172:
FLD id
FSTP _2
label175:
FLD id3
FLD _2
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label178:
jne label192
label180:
FLD _3
FLD id4
FCOMP 
FSTSW ax
FFREE st(0)
sahf

label183:
jnbe label192

label185:
DisplayFloat id5, 2


label187:
DisplayFloat id3, 2

label189:
FLD ID2
FSTP _5

label192:
mov ax,4c00h
int 21h
jmp final_programa 


insertar_salto_linea:
mov ax,seg salto_linea
mov ds,ax 
mov dx,offset salto_linea 
mov ah,09 
int 21h 
ret 


final_programa:
end start

