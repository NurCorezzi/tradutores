.code
main:
mov $0, 10
mov $1, 11
sleq $4, $0, $1
mov $5, 0
and $6, $4, $5
brz _L0, $6
mov $7, 1
print $7
println 
_L0:
nop
