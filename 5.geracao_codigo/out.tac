.code
main:
nop
_g0:
mov $1, 0
mema $2, 10
mov $2[$1], 3
mov $3, $2[$1]
add $4, $1, 1
_L0:
brz _L1, $3
mov $2[$4], 0
add $5, $4, 1
add $6, $4, 2
add $9, 0, 1
mov $7, 0
mema $8, $9
mov $8[$7], 0
mov $10, $8[$7]
add $11, $7, 1
_L2:
brz _L3, $10
mov $8[$11], 0
add $11, $11, 1
sub $10, $10, 1
jump _L2
_L3:
nop
mov $8, $8
mov $2[$5], $8
add $14, 0, 1
mov $12, 0
mema $13, $14
mov $13[$12], 0
mov $15, $13[$12]
add $16, $12, 1
_L4:
brz _L5, $15
mov $13[$16], 0
add $16, $16, 1
sub $15, $15, 1
jump _L4
_L5:
nop
mov $13, $13
mov $2[$6], $13
add $4, $4, 3
sub $3, $3, 1
jump _L0
_L1:
nop
nop
mov $18, $1
mov $19, $2
mov $17, 0
mov $21, $18
mul $20, $17, 3
add $21, $20, 1
mov $22, $19
mov $24, $22[$21]
add $23, $24, 1
mov $22[$21], $23
add $25, $21, 1
add $28, $23, 1
mov $26, 0
mema $27, $28
mov $27[$26], $23
mov $29, $27[$26]
add $30, $26, 1
_L6:
brz _L7, $29
mov $27[$30], 0
add $30, $30, 1
sub $29, $29, 1
jump _L6
_L7:
nop
mov $27, $27
mov $31, 0
mov $32, $22[$25]
mov $33, $32[$31]
mov $34, 1
_L8:
sleq $35, $34, $33
brz _L9, $35
add $36, $31, $34
add $37, $26, $34
mov $38, $32[$36]
mov $27[$37], $38
add $34, $34, 1
jump _L8
_L9:
nop
memf $32
mov $22[$25], $27
add $39, $21, 2
add $42, $23, 1
mov $40, 0
mema $41, $42
mov $41[$40], $23
mov $43, $41[$40]
add $44, $40, 1
_L10:
brz _L11, $43
mov $41[$44], 0
add $44, $44, 1
sub $43, $43, 1
jump _L10
_L11:
nop
mov $41, $41
mov $45, 0
mov $46, $22[$39]
mov $47, $46[$45]
mov $48, 1
_L12:
sleq $49, $48, $47
brz _L13, $49
add $50, $45, $48
add $51, $40, $48
mov $52, $46[$50]
mov $41[$51], $52
add $48, $48, 1
jump _L12
_L13:
nop
memf $46
mov $22[$39], $41
add $55, 0, 1
mov $53, 0
mema $54, $55
mov $54[$53], 0
mov $56, $54[$53]
add $57, $53, 1
_L14:
brz _L15, $56
mov $54[$57], 0
add $57, $57, 1
sub $56, $56, 1
jump _L14
_L15:
nop
mov $54, $54
add $58, $40, $23
mov $41[$58], $54
mov $61, $1
mov $62, $2
mov $59, 0
mov $64, $61
mul $63, $59, 3
add $64, $63, 1
mov $65, $62
add $66, $64, 1
mov $67, 0
mov $68, $65[$66]
mov $60, 0
mov $70, $67
mul $69, $60, 1
add $70, $69, 1
mov $71, $68
scani $72
mov $71[$70], $72
mov $75, $1
mov $76, $2
mov $73, 0
mov $78, $75
mul $77, $73, 3
add $78, $77, 1
mov $79, $76
add $80, $78, 1
mov $81, 0
mov $82, $79[$80]
mov $74, 0
mov $84, $81
mul $83, $74, 1
add $84, $83, 1
mov $85, $82
mov $86, $85[$84]
print $86
println 
nop
_a1:
mov $88, 0
mema $89, 4
mov $89[$88], 3
mov $90, $89[$88]
add $91, $88, 1
_L16:
brz _L17, $90
mov $89[$91], 0
add $91, $91, 1
sub $90, $90, 1
jump _L16
_L17:
nop
nop
mov $93, $88
mov $94, $89
mov $92, 0
mov $96, $93
mul $95, $92, 1
add $96, $95, 1
mov $97, $94
scani $98
mov $97[$96], $98
mov $100, $88
mov $101, $89
mov $99, 0
mov $103, $100
mul $102, $99, 1
add $103, $102, 1
mov $104, $101
mov $105, $104[$103]
print $105
println 
nop
_b2:
mov $106, 0
mema $107, 1
mov $107[$106], 0
mov $107[$106], 0
nop
mov $108, $106
mov $109, $107
scani $110
mov $109[$108], $110
mov $111, $106
mov $112, $107
mov $113, $112[$111]
print $113
println 
nop
_c3:
mov $114, 0
mema $115, 1
mov $115[$114], 0
mov $115[$114], 0.000000
nop
mov $116, $114
mov $117, $115
scanf $118
mov $117[$116], $118
mov $119, $114
mov $120, $115
mov $121, $120[$119]
print $121
println 
_L18:
nop
