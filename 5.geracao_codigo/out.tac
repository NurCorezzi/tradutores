.code
main:
mov $0, 2
nop
_i:
mema $1, 3
mov $1[0], 2
mov $1[1], 0.000000
mov $1[2], 0.000000
nop
mov $3, 0
mov $4, $1
mov $2, 0
mov $6, $3
mul $5, $2, 1
add $6, $5, 1
mov $7, $4
mov $8, $7[$6]
print $8
println 
