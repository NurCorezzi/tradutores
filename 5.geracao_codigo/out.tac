.code
main:
mov $0, 1
brz _L0, $0
mov $1, 1
mov $2, 2
add $3, $1, $2
print $3
println 
_L0:
mov $4, 0
brz _L1, $4
mov $5, 15
print $5
println 
_L1:
nop
