.code
_count:
mov $0, #0
mov $1, 0
seq $2, $0, $1
brz _L0, $2
mov $5, 0
return $5
jump _L1
_L0:
mov $6, #0
mov $7, 1
sub $8, $6, $7
param $8
call _count, 1
pop $9
mov $10, #0
add $11, $9, $10
return $11
_L1:
nop
return 
main:
nop
_a:
mov $0, 0
mema $1, 1
mov $1[0], 0
nop
mov $2, $0
mov $3, $1
mov $4, 10
param $4
call _count, 1
pop $5
mov $3[$2], $5
mov $6, $3[$2]
param $6
call _count, 1
pop $7
print $7
println 
_L2:
nop
