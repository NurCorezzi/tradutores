.code
main:
mov $0, 0
brz _L0, $0
mov $1, 1
mov $2, 2
add $3, $1, $2
print $3
println 
_L0:
nop
