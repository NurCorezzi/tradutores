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
nop
_i1:
mov $14, 0
mema $15, 1
mov $15[$14], 0
mov $15[$14], 0
nop
nop
_sz2:
mov $16, 0
mema $17, 1
mov $17[$16], 0
mov $17[$16], 0
nop
mov $18, $16
mov $19, $17
mov $20, 5
mov $19[$18], $20
mov $21, $14
mov $22, $15
mov $23, 0
mov $22[$21], $23
_L14:
nop
mov $24, $14
mov $25, $15
mov $28, $25[$24]
mov $26, $16
mov $27, $17
mov $29, $27[$26]
slt $31, $28, $29
brz _L24, $31
mov $40, $0
mov $41, $1
mov $43, $41[$40]
add $42, $43, 1
mov $41[$40], $42
add $44, $40, 1
add $47, $42, 1
mov $45, 0
mema $46, $47
mov $46[$45], $42
mov $48, $46[$45]
add $49, $45, 1
_L4:
brz _L5, $48
mov $46[$49], 0
add $49, $49, 1
sub $48, $48, 1
jump _L4
_L5:
nop
mov $46, $46
mov $50, 0
mov $51, $41[$44]
mov $52, $51[$50]
mov $53, 1
_L6:
sleq $54, $53, $52
brz _L7, $54
add $55, $50, $53
add $56, $45, $53
mov $57, $51[$55]
mov $46[$56], $57
add $53, $53, 1
jump _L6
_L7:
nop
memf $51
mov $41[$44], $46
add $58, $40, 2
add $61, $42, 1
mov $59, 0
mema $60, $61
mov $60[$59], $42
mov $62, $60[$59]
add $63, $59, 1
_L8:
brz _L9, $62
mov $60[$63], 0
add $63, $63, 1
sub $62, $62, 1
jump _L8
_L9:
nop
mov $60, $60
mov $64, 0
mov $65, $41[$58]
mov $66, $65[$64]
mov $67, 1
_L10:
sleq $68, $67, $66
brz _L11, $68
add $69, $64, $67
add $70, $59, $67
mov $71, $65[$69]
mov $60[$70], $71
add $67, $67, 1
jump _L10
_L11:
nop
memf $65
mov $41[$58], $60
add $74, 0, 1
mov $72, 0
mema $73, $74
mov $73[$72], 0
mov $75, $73[$72]
add $76, $72, 1
_L12:
brz _L13, $75
mov $73[$76], 0
add $76, $76, 1
sub $75, $75, 1
jump _L12
_L13:
nop
mov $73, $73
add $77, $59, $42
mov $60[$77], $73
mov $81, $0
mov $82, $1
add $83, $81, 1
mov $84, 0
mov $85, $82[$83]
mov $78, $14
mov $79, $15
mov $80, $79[$78]
mov $87, $84
mul $86, $80, 1
add $87, $86, 1
mov $88, $85
mov $89, $14
mov $90, $15
mov $91, $90[$89]
mov $88[$87], $91
mov $92, $88[$87]
print $92
println 
_L15:
nop
mov $33, $14
mov $34, $15
mov $35, $14
mov $36, $15
mov $38, $36[$35]
mov $37, 1
add $39, $38, $37
mov $34[$33], $39
jump _L14
_L24:
mov $93, $14
mov $94, $15
mov $95, 0
mov $94[$93], $95
_L22:
nop
mov $96, $14
mov $97, $15
mov $100, $97[$96]
mov $98, $16
mov $99, $17
mov $101, $99[$98]
slt $103, $100, $101
brz _L32, $103
nop
_j3:
mov $112, 0
mema $113, 1
mov $113[$112], 0
mov $113[$112], 0
nop
mov $114, $112
mov $115, $113
mov $116, 0
mov $115[$114], $116
_L20:
nop
mov $117, $112
mov $118, $113
mov $121, $118[$117]
mov $119, $16
mov $120, $17
mov $122, $120[$119]
slt $124, $121, $122
brz _L23, $124
mov $133, $0
mov $134, $1
mov $135, $14
mov $136, $15
mov $139, $136[$135]
mov $137, $112
mov $138, $113
mov $140, $138[$137]
add $141, $133, 2
mov $142, $134[$141]
mov $144, 0
add $143, $139, 1
mov $145, $142[$143]
mov $147, $145[$144]
add $146, $147, 1
add $150, $146, 1
mov $148, 0
mema $149, $150
mov $149[$148], $146
mov $151, $149[$148]
add $152, $148, 1
_L16:
brz _L17, $151
mov $149[$152], 0
add $152, $152, 1
sub $151, $151, 1
jump _L16
_L17:
nop
mov $149, $149
mov $153, $145[$144]
mov $154, 1
_L18:
sleq $155, $154, $153
brz _L19, $155
add $156, $144, $154
add $157, $148, $154
mov $158, $145[$156]
mov $149[$157], $158
add $154, $154, 1
jump _L18
_L19:
nop
memf $145
mov $142[$143], $149
mov $149[$146], $140
_L21:
nop
mov $126, $112
mov $127, $113
mov $128, $112
mov $129, $113
mov $131, $129[$128]
mov $130, 1
add $132, $131, $130
mov $127[$126], $132
jump _L20
_L23:
nop
mov $105, $14
mov $106, $15
mov $107, $14
mov $108, $15
mov $110, $108[$107]
mov $109, 1
add $111, $110, $109
mov $106[$105], $111
jump _L22
_L32:
mov $159, $0
mov $160, $1
print 'G'
print 'R'
print 'A'
print 'P'
print 'H'
print ' '
print '{'
println 
mov $161, $160[$159]
brz _L25, $161
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
add $162, $159, 1
mov $163, 0
mov $164, $160[$162]
print '['
mov $166, $163
mov $167, $164
mov $165, $167[$166]
add $166, $166, 1
mov $168, 1
_L26:
brz _L27, $165
mov $167, $167
mov $169, $167[$166]
print $169
print ','
print ' '
add $166, $166, $168
sub $165, $165, 1
jump _L26
_L27:
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
println 
print ' '
add $170, $159, 2
mov $171, 0
mov $172, $160[$170]
print '['
mov $174, $171
mov $175, $172
mov $173, $175[$174]
add $174, $174, 1
mov $176, 1
_L28:
brz _L29, $173
mov $175, $175
mov $177, $175[$174]
mov $179, $177
print 'A'
print 'R'
print 'R'
print 'A'
print 'Y'
print ':'
print ' '
print '['
mov $181, $178
mov $182, $179
mov $180, $182[$181]
add $181, $181, 1
mov $183, 1
_L30:
brz _L31, $180
mov $182, $182
mov $184, $182[$181]
print $184
print ','
print ' '
add $181, $181, $183
sub $180, $180, 1
jump _L30
_L31:
print '#'
print ']'
println 
print ','
print ' '
add $174, $174, $176
sub $173, $173, 1
jump _L28
_L29:
print '#'
print ']'
println 
_L25:
nop
print '}'
println 
_L33:
nop
