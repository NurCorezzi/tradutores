.code
_dummya:
nop
return 
_dummyb:
nop
return 
main:
mov $0, 1
param $0
mov $1, 2
inttofl $3, $1
param $3
mov $2, 3.000000
fltoint $4, $2
param $4
call _dummya, 3
mov $5, 1
inttofl $7, $5
mov $6, 2.000000
add $8, $7, $6
print $8
println 
mov $9, 1.200000
mov $10, 1
mov $11, 2
slt $13, $10, $11
inttofl $15, $13
add $16, $9, $15
print $16
println 
nop
_a:
mov $17, 0
mema $18, 1
mov $18[0], 0.000000
nop
nop
_b:
mov $19, 0
mema $20, 1
mov $20[0], 0
nop
mov $21, $17
mov $22, $18
mov $23, 1
inttofl $24, $23
mov $22[$21], $24
mov $25, $19
mov $26, $20
mov $27, 1.000000
fltoint $28, $27
mov $26[$25], $28
mov $29, $17
mov $30, $18
mov $31, $19
mov $32, $20
mov $33, $32[$31]
inttofl $34, $33
mov $30[$29], $34
mov $35, $19
mov $36, $20
mov $37, $17
mov $38, $18
mov $39, $38[$37]
fltoint $40, $39
mov $36[$35], $40
mov $41, $19
mov $42, $20
mov $44, $42[$41]
mov $43, 1
add $45, $44, $43
mov $46, $17
mov $47, $18
mov $49, $47[$46]
mov $48, 1.000000
add $50, $49, $48
_L2:
nop
