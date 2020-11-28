.code
main:
mov $0, 10
nop
_i:
mema $1, 11
mov $1[0], 10
mov $1[1], 0.000000
mov $1[2], 0.000000
mov $1[3], 0.000000
mov $1[4], 0.000000
mov $1[5], 0.000000
mov $1[6], 0.000000
mov $1[7], 0.000000
mov $1[8], 0.000000
mov $1[9], 0.000000
mov $1[10], 0.000000
nop
mov $3, 0
mov $4, $1
mov $2, 0
mov $6, $3
mul $5, $2, 1
add $6, $5, 1
mov $7, $4
mov $8, 1.200000
mov $7[$6], $8
mov $9, 0
mov $10, $1
print '['
mov $13, $10
mov $11, $13[0]
mov $12, $9
add $12, $12, 1
mov $14, 1
_L0:
brz _L1, $11
mov $13, $13
mov $15, $13[$12]
print $15
print ','
print ' '
add $12, $12, $14
sub $11, $11, 1
jump _L0
_L1:
print '#'
print ']'
println 
mov $16, 0
mov $17, $1
print '['
mov $20, $17
mov $18, $20[0]
mov $19, $16
add $19, $19, 1
mov $21, 1
_L2:
brz _L3, $18
mov $20, $20
mov $22, $20[$19]
print $22
print ','
print ' '
add $19, $19, $21
sub $18, $18, 1
jump _L2
_L3:
print '#'
print ']'
println 
mov $24, 0
mov $25, $1
mov $23, 2
mov $27, $24
mul $26, $23, 1
add $27, $26, 1
mov $28, $25
mov $29, 1.500000
mov $28[$27], $29
mov $30, 0
mov $31, $1
print '['
mov $34, $31
mov $32, $34[0]
mov $33, $30
add $33, $33, 1
mov $35, 1
_L4:
brz _L5, $32
mov $34, $34
mov $36, $34[$33]
print $36
print ','
print ' '
add $33, $33, $35
sub $32, $32, 1
jump _L4
_L5:
print '#'
print ']'
println 
mov $38, 0
mov $39, $1
mov $37, 2
mov $41, $38
mul $40, $37, 1
add $41, $40, 1
mov $42, $39
mov $43, $42[$41]
print $43
println 
