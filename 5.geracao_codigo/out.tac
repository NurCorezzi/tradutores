.code
_outro:
mov $0, #0
mov $1, #1
mov $3, $1[$0]
add $2, $3, 1
mov $1[$0], $2
add $4, $0, 1
add $7, $2, 1
mov $5, 0
mema $6, $7
mov $6[0], 0
mov $6[$5], $2
mov $8, 0
mov $9, $1[$4]
seq $10, 1, $2
brnz _L0, $10
mov $11, $9[$5]
mov $12, 1
_L1:
sleq $13, $12, $11
brz _L2, $13
add $14, $5, $12
add $15, $5, $12
mov $16, $9[$14]
mov $6[$15], $16
add $12, $12, 1
jump _L1
_L2:
nop
memf $9
_L0:
mov $1[$4], $6
mov $20, #0
mov $21, #1
add $22, $20, 1
mov $23, 0
mov $24, $21[$22]
mov $17, #2
mov $18, #3
mov $19, $18[$17]
mov $26, $23
mul $25, $19, 1
add $26, $25, 1
mov $27, $24
mov $28, #2
mov $29, #3
mov $30, $29[$28]
mov $27[$26], $30
mov $31, #0
mov $32, #1
print 'G'
print 'R'
print 'A'
print 'P'
print 'H'
print ':'
println 
print 'V'
print 'A'
print 'L'
print 'U'
print 'E'
print 'S'
print ':'
add $33, $31, 1
mov $34, 0
mov $35, $32[$33]
print '['
mov $37, $34
mov $38, $35
mov $36, $38[$37]
add $37, $37, 1
mov $39, 1
_L3:
brz _L4, $36
mov $38, $38
mov $40, $38[$37]
print $40
print ','
print ' '
add $37, $37, $39
sub $36, $36, 1
jump _L3
_L4:
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
_L5:
nop
return 
main:
nop
_a0:
mov $0, 0
mema $1, 3
mov $1[0], 0
nop
mov $2, $0
mov $3, $1
param $2
param $3
mov $4, 0
mema $5, 1
mov *$5, $4
param 0
param $5
call _outro, 4
mov $6, $0
mov $7, $1
param $6
param $7
mov $8, 1
mema $9, 1
mov *$9, $8
param 0
param $9
call _outro, 4
mov $10, $0
mov $11, $1
param $10
param $11
mov $12, 2
mema $13, 1
mov *$13, $12
param 0
param $13
call _outro, 4
mov $14, $0
mov $15, $1
param $14
param $15
mov $16, 3
mema $17, 1
mov *$17, $16
param 0
param $17
call _outro, 4
_L6:
nop
