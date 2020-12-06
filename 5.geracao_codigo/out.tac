.code
main:
mov $0, 0
brz _L3, $0
jump _L4
_L3:
mov $1, 0
brz _L2, $1
jump _L4
_L2:
mov $2, 1
brz _L4, $2
mov $3, 1
print $3
println 
nop
_i0:
mov $4, 0
mema $5, 1
mov $5[0], 0
nop
mov $6, $4
mov $7, $5
mov $8, 10
mov $7[$6], $8
_L0:
mov $9, $4
mov $10, $5
mov $21, $10[$9]
brz _L4, $21
mov $11, $4
mov $12, $5
mov $13, $12[$11]
print $13
println 
mov $14, $4
mov $15, $5
mov $16, $4
mov $17, $5
mov $19, $17[$16]
mov $18, 1
sub $20, $19, $18
mov $15[$14], $20
_L1:
jump _L0
_L4:
nop
_i1:
mov $23, 0
mema $24, 4
mov $24[0], 3
mov $24[1], 0
mov $24[2], 0
mov $24[3], 0
nop
mov $25, $23
mov $26, $24
print '['
mov $29, $26
mov $27, $29[0]
mov $28, $25
add $28, $28, 1
mov $30, 1
_L5:
brz _L6, $27
mov $29, $29
mov $31, $29[$28]
print $31
print ','
print ' '
add $28, $28, $30
sub $27, $27, 1
jump _L5
_L6:
print '#'
print ']'
println 
_L7:
nop
