.code
_dummya:
mov $0, #0
mov $1, #1
mov $3, $1[$0]
mov $2, 1
add $4, $3, $2
mov $5, #0
mov $6, #1
mov $8, $6[$5]
inttofl $9, $8
mov $7, 1.000000
add $10, $9, $7
mov $11, #4
mov $12, #5
mov $14, $12[$11]
mov $13, 1
and $15, $14, $13
mov $16, #2
mov $17, #3
mov $18, $17[$16]
fltoint $19, $18
return $19
_L0:
nop
return 
_dummyb:
mov $0, 1
inttofl $1, $0
return $1
_L1:
nop
return 
_dummyc:
mov $2, #0
mov $3, #1
mov $1, 1
mov $5, $2
mul $4, $1, 1
add $5, $4, 1
mov $6, $3
mov $8, $6[$5]
mov $7, 1
add $9, $8, $7
_L2:
nop
return 
main:
nop
_a0:
mov $0, 0
mema $1, 1
mov $1[0], 0.000000
nop
nop
_b1:
mov $2, 0
mema $3, 1
mov $3[0], 0
nop
nop
_c2:
mov $5, 0
mema $6, 4
mov $6[0], 3
mov $6[1], 0
mov $6[2], 0
mov $6[3], 0
nop
mov $7, $5
mov $8, $6
param $7
param $8
call _dummyc, 2
mov $9, $2
mov $10, $3
param $9
param $10
mov $11, $0
mov $12, $1
param $11
param $12
mov $13, $2
mov $14, $3
param $13
param $14
call _dummya, 6
pop $15
mov $16, $0
mov $17, $1
mov $18, 1
mema $21, 1
mov *$21, $18
param 0
param $21
mov $19, 2
inttofl $22, $19
mema $23, 1
mov *$23, $22
param 0
param $23
mov $20, 3.000000
fltoint $24, $20
mema $25, 1
mov *$25, $24
param 0
param $25
call _dummya, 6
pop $26
inttofl $27, $26
mov $17[$16], $27
mov $28, $2
mov $29, $3
call _dummyb, 0
pop $30
fltoint $31, $30
mov $29[$28], $31
mov $32, $0
mov $33, $1
mov $35, $33[$32]
mov $34, 1.000000
add $36, $35, $34
mov $37, $2
mov $38, $3
mov $40, $38[$37]
mov $39, 1
add $41, $40, $39
mov $42, 1
inttofl $44, $42
mov $43, 2.000000
add $45, $44, $43
print $45
println 
mov $46, 1.200000
mov $47, 1
mov $48, 2
slt $50, $47, $48
inttofl $52, $50
add $53, $46, $52
print $53
println 
mov $54, $0
mov $55, $1
mov $56, 1
inttofl $57, $56
mov $55[$54], $57
mov $58, $2
mov $59, $3
mov $60, 1.000000
fltoint $61, $60
mov $59[$58], $61
mov $62, $0
mov $63, $1
mov $64, $2
mov $65, $3
mov $66, $65[$64]
inttofl $67, $66
mov $63[$62], $67
mov $68, $2
mov $69, $3
mov $70, $0
mov $71, $1
mov $72, $71[$70]
fltoint $73, $72
mov $69[$68], $73
mov $74, $0
mov $75, $1
mov $77, $75[$74]
mov $76, 1.000000
add $78, $77, $76
mov $79, $2
mov $80, $3
mov $82, $80[$79]
mov $81, 1
add $83, $82, $81
_L3:
nop
