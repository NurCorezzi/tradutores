.code
main:
nop
_i:
mov $0, 0
mema $1, 1
mov $1[0], 0
nop
mov $2, $0
mov $3, $1
mov $4, 5
mov $3[$2], $4
_L0:
mov $5, $0
mov $6, $1
mov $9, $6[$5]
mov $7, $0
mov $8, $1
mov $10, $8[$7]
mul $11, $9, $10
mov $12, 5
slt $14, $11, $12
brz _L2, $14
mov $16, $0
mov $17, $1
mov $18, $17[$16]
print $18
println 
mov $19, $0
mov $20, $1
mov $21, $0
mov $22, $1
mov $24, $22[$21]
mov $23, 1
sub $25, $24, $23
mov $20[$19], $25
_L1:
jump _L0
_L2:
nop
