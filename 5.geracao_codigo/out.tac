.code
_nos:
mov $0, #0
brz _L0, $0
mov $1, #0
print $1
println 
mov $2, #0
mov $3, 1
sub $4, $2, $3
param $4
call _nos, 1
_L0:
nop
return 
main:
mov $0, 5
param $0
call _nos, 1
mov $1, 0
brz _L3, $1
nop
_i:
mov $3, 0
mema $4, 4
mov $4[0], 3
mov $4[1], 0
mov $4[2], 0
mov $4[3], 0
nop
mov $6, $3
mov $7, $4
mov $5, 2
mov $9, $6
mul $8, $5, 1
add $9, $8, 1
mov $10, $7
mov $11, 45
mov $10[$9], $11
mov $12, $3
mov $13, $4
print '['
mov $16, $13
mov $14, $16[0]
mov $15, $12
add $15, $15, 1
mov $17, 1
_L1:
brz _L2, $14
mov $16, $16
mov $18, $16[$15]
print $18
print ','
print ' '
add $15, $15, $17
sub $14, $14, 1
jump _L1
_L2:
print '#'
print ']'
println 
jump _L4
_L3:
mov $19, 22
print $19
println 
_L4:
mov $20, 5
param $20
call _nos, 1
_L5:
nop
