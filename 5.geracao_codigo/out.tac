.code
main:
nop
_g0:
mov $0, 0
mema $1, 3
mov $1[$0], 0
mov $1[$0], 0
add $2, $0, 1
add $3, $0, 2
add $6, 0, 1
mov $4, 0
mema $5, $6
mov $5[$4], 0
mov $7, $5[$4]
add $8, $4, 1
_L0:
brz _L1, $7
mov $5[$8], 0
add $8, $8, 1
sub $7, $7, 1
jump _L0
_L1:
nop
mov $5, $5
mov $1[$2], $5
add $11, 0, 1
mov $9, 0
mema $10, $11
mov $10[$9], 0
mov $12, $10[$9]
add $13, $9, 1
_L2:
brz _L3, $12
mov $10[$13], 0
add $13, $13, 1
sub $12, $12, 1
jump _L2
_L3:
nop
mov $10, $10
mov $1[$3], $10
nop
mov $14, $0
mov $15, $1
mov $17, $15[$14]
add $16, $17, 1
mov $15[$14], $16
add $18, $14, 1
add $21, $16, 1
mov $19, 0
mema $20, $21
mov $20[$19], $16
mov $22, $20[$19]
add $23, $19, 1
_L4:
brz _L5, $22
mov $20[$23], 0
add $23, $23, 1
sub $22, $22, 1
jump _L4
_L5:
nop
mov $20, $20
mov $24, 0
mov $25, $15[$18]
mov $26, $25[$24]
mov $27, 1
_L6:
sleq $28, $27, $26
brz _L7, $28
add $29, $24, $27
add $30, $19, $27
mov $31, $25[$29]
mov $20[$30], $31
add $27, $27, 1
jump _L6
_L7:
nop
memf $25
mov $15[$18], $20
add $32, $14, 2
add $35, $16, 1
mov $33, 0
mema $34, $35
mov $34[$33], $16
mov $36, $34[$33]
add $37, $33, 1
_L8:
brz _L9, $36
mov $34[$37], 0
add $37, $37, 1
sub $36, $36, 1
jump _L8
_L9:
nop
mov $34, $34
mov $38, 0
mov $39, $15[$32]
mov $40, $39[$38]
mov $41, 1
_L10:
sleq $42, $41, $40
brz _L11, $42
add $43, $38, $41
add $44, $33, $41
mov $45, $39[$43]
mov $34[$44], $45
add $41, $41, 1
jump _L10
_L11:
nop
memf $39
mov $15[$32], $34
add $48, 2, 1
mov $46, 0
mema $47, $48
mov $47[$46], 2
mov $49, $47[$46]
add $50, $46, 1
_L12:
brz _L13, $49
mov $47[$50], 0
add $50, $50, 1
sub $49, $49, 1
jump _L12
_L13:
nop
mov $47, $47
add $51, $33, $16
mov $34[$51], $47
mov $52, $0
mov $53, $1
mov $55, $53[$52]
add $54, $55, 1
mov $53[$52], $54
add $56, $52, 1
add $59, $54, 1
mov $57, 0
mema $58, $59
mov $58[$57], $54
mov $60, $58[$57]
add $61, $57, 1
_L14:
brz _L15, $60
mov $58[$61], 0
add $61, $61, 1
sub $60, $60, 1
jump _L14
_L15:
nop
mov $58, $58
mov $62, 0
mov $63, $53[$56]
mov $64, $63[$62]
mov $65, 1
_L16:
sleq $66, $65, $64
brz _L17, $66
add $67, $62, $65
add $68, $57, $65
mov $69, $63[$67]
mov $58[$68], $69
add $65, $65, 1
jump _L16
_L17:
nop
memf $63
mov $53[$56], $58
add $70, $52, 2
add $73, $54, 1
mov $71, 0
mema $72, $73
mov $72[$71], $54
mov $74, $72[$71]
add $75, $71, 1
_L18:
brz _L19, $74
mov $72[$75], 0
add $75, $75, 1
sub $74, $74, 1
jump _L18
_L19:
nop
mov $72, $72
mov $76, 0
mov $77, $53[$70]
mov $78, $77[$76]
mov $79, 1
_L20:
sleq $80, $79, $78
brz _L21, $80
add $81, $76, $79
add $82, $71, $79
mov $83, $77[$81]
mov $72[$82], $83
add $79, $79, 1
jump _L20
_L21:
nop
memf $77
mov $53[$70], $72
add $86, 2, 1
mov $84, 0
mema $85, $86
mov $85[$84], 2
mov $87, $85[$84]
add $88, $84, 1
_L22:
brz _L23, $87
mov $85[$88], 0
add $88, $88, 1
sub $87, $87, 1
jump _L22
_L23:
nop
mov $85, $85
add $89, $71, $54
mov $72[$89], $85
mov $90, $0
mov $91, $1
mov $93, $91[$90]
add $92, $93, 1
mov $91[$90], $92
add $94, $90, 1
add $97, $92, 1
mov $95, 0
mema $96, $97
mov $96[$95], $92
mov $98, $96[$95]
add $99, $95, 1
_L24:
brz _L25, $98
mov $96[$99], 0
add $99, $99, 1
sub $98, $98, 1
jump _L24
_L25:
nop
mov $96, $96
mov $100, 0
mov $101, $91[$94]
mov $102, $101[$100]
mov $103, 1
_L26:
sleq $104, $103, $102
brz _L27, $104
add $105, $100, $103
add $106, $95, $103
mov $107, $101[$105]
mov $96[$106], $107
add $103, $103, 1
jump _L26
_L27:
nop
memf $101
mov $91[$94], $96
add $108, $90, 2
add $111, $92, 1
mov $109, 0
mema $110, $111
mov $110[$109], $92
mov $112, $110[$109]
add $113, $109, 1
_L28:
brz _L29, $112
mov $110[$113], 0
add $113, $113, 1
sub $112, $112, 1
jump _L28
_L29:
nop
mov $110, $110
mov $114, 0
mov $115, $91[$108]
mov $116, $115[$114]
mov $117, 1
_L30:
sleq $118, $117, $116
brz _L31, $118
add $119, $114, $117
add $120, $109, $117
mov $121, $115[$119]
mov $110[$120], $121
add $117, $117, 1
jump _L30
_L31:
nop
memf $115
mov $91[$108], $110
add $124, 2, 1
mov $122, 0
mema $123, $124
mov $123[$122], 2
mov $125, $123[$122]
add $126, $122, 1
_L32:
brz _L33, $125
mov $123[$126], 0
add $126, $126, 1
sub $125, $125, 1
jump _L32
_L33:
nop
mov $123, $123
add $127, $109, $92
mov $110[$127], $123
mov $128, $0
mov $129, $1
print 'G'
print 'R'
print 'A'
print 'P'
print 'H'
print ' '
print '{'
println 
mov $130, $129[$128]
brz _L34, $130
print ' '
print ' '
print 'V'
print 'A'
print 'L'
print 'U'
print 'E'
print 'S'
print ':'
print ' '
add $131, $128, 1
mov $132, 0
mov $133, $129[$131]
print '['
mov $135, $132
mov $136, $133
mov $134, $136[$135]
add $135, $135, 1
mov $137, 1
_L35:
brz _L36, $134
mov $136, $136
mov $138, $136[$135]
print $138
print ','
print ' '
add $135, $135, $137
sub $134, $134, 1
jump _L35
_L36:
print '#'
print ']'
println 
print ' '
print ' '
print 'E'
print 'D'
print 'G'
print 'E'
print 'S'
print ':'
print ' '
add $139, $128, 2
mov $140, 0
mov $141, $129[$139]
print '['
mov $143, $140
mov $144, $141
mov $142, $144[$143]
add $143, $143, 1
mov $145, 1
_L37:
brz _L38, $142
mov $144, $144
mov $146, $144[$143]
mov $148, $146
print 'A'
print 'R'
print 'R'
print 'A'
print 'Y'
print ':'
print ' '
print '['
mov $150, $147
mov $151, $148
mov $149, $151[$150]
add $150, $150, 1
mov $152, 1
_L39:
brz _L40, $149
mov $151, $151
mov $153, $151[$150]
print $153
print ','
print ' '
add $150, $150, $152
sub $149, $149, 1
jump _L39
_L40:
print '#'
print ']'
print ','
print ' '
add $143, $143, $145
sub $142, $142, 1
jump _L37
_L38:
print '#'
print ']'
println 
_L34:
nop
print '}'
println 
_L41:
nop
