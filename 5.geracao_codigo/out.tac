.code
_print:
mov $2, #0
mov $3, #1
mov $1, 0
mov $5, $2
mul $4, $1, 3
add $5, $4, 1
mov $6, $3
print 'G'
print 'R'
print 'A'
print 'P'
print 'H'
print ':'
println 
mov $7, $6[$5]
brz _L0, $7
print 'V'
print 'A'
print 'L'
print 'U'
print 'E'
print 'S'
print ':'
add $8, $5, 1
mov $9, 0
mov $10, $6[$8]
print '['
mov $12, $9
mov $13, $10
mov $11, $13[$12]
add $12, $12, 1
mov $14, 1
_L1:
brz _L2, $11
mov $13, $13
mov $15, $13[$12]
print $15
print ','
print ' '
add $12, $12, $14
sub $11, $11, 1
jump _L1
_L2:
print '#'
print ']'
println 
print 'E'
print 'D'
print 'G'
print 'E'
print 'S'
print ':'
println 
_L0:
nop
print '='
print '='
print '='
print '='
print '='
print '='
print '='
print '='
println 
println 
_L3:
nop
return 
main:
nop
_a0:
mov $1, 0
mema $2, 7
mov $2[$1], 2
mov $3, $2[$1]
add $4, $1, 1
_L4:
brz _L5, $3
mov $2[$4], 0
add $4, $4, 3
sub $3, $3, 1
jump _L4
_L5:
nop
nop
mov $6, $1
mov $7, $2
mov $5, 0
mov $9, $6
mul $8, $5, 3
add $9, $8, 1
mov $10, $7
mov $12, $10[$9]
add $11, $12, 1
mov $10[$9], $11
add $13, $9, 1
add $16, $11, 1
mov $14, 0
mema $15, $16
mov $15[$14], $11
mov $17, $15[$14]
add $18, $14, 1
_L6:
brz _L7, $17
mov $15[$18], 0
add $18, $18, 1
sub $17, $17, 1
jump _L6
_L7:
nop
mov $19, 0
mov $20, $10[$13]
seq $21, 1, $11
brnz _L8, $21
mov $22, $20[$14]
mov $23, 1
_L9:
sleq $24, $23, $22
brz _L10, $24
add $25, $14, $23
add $26, $14, $23
mov $27, $20[$25]
mov $15[$26], $27
add $23, $23, 1
jump _L9
_L10:
nop
memf $20
_L8:
mov $10[$13], $15
mov $28, $1
mov $29, $2
param $28
param $29
call _print, 2
_L11:
nop
