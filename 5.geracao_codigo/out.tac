.code
main:
mov $0, 1
not $1, $0
brz _L0, $1
mov $2, 1
print $2
println 
_L0:
nop
