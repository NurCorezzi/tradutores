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
mov $47, $0
mov $48, $1
add $49, $47, 1
mov $50, 0
mov $51, $48[$49]
mov $46, 0
mov $53, $50
mul $52, $46, 1
add $53, $52, 1
mov $54, $51
mov $55, 1
mov $54[$53], $55
mov $56, $0
mov $57, $1
print 'G'
print 'R'
print 'A'
print 'P'
print 'H'
print ' '
print '{'
println 
mov $58, $57[$56]
brz _L12, $58
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
add $59, $56, 1
mov $60, 0
mov $61, $57[$59]
print '['
mov $63, $60
mov $64, $61
mov $62, $64[$63]
add $63, $63, 1
mov $65, 1
_L13:
brz _L14, $62
mov $64, $64
mov $66, $64[$63]
print $66
print ','
print ' '
add $63, $63, $65
sub $62, $62, 1
jump _L13
_L14:
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
add $67, $56, 2
mov $68, 0
mov $69, $57[$67]
print '['
mov $71, $68
mov $72, $69
mov $70, $72[$71]
add $71, $71, 1
mov $73, 1
_L15:
brz _L16, $70
mov $72, $72
print 'A'
print 'R'
print 'R'
print 'A'
print 'Y'
print ':'
print ' '
print '['
mov $75, $71
mov $76, $72
mov $74, $76[$75]
add $75, $75, 1
mov $77, 1
_L17:
brz _L18, $74
mov $76, $76
mov $78, $76[$75]
print $78
print ','
print ' '
add $75, $75, $77
sub $74, $74, 1
jump _L17
_L18:
print '#'
print ']'
print ','
print ' '
add $71, $71, $73
sub $70, $70, 1
jump _L15
_L16:
print '#'
print ']'
println 
_L12:
nop
print '}'
println 
mov $79, $0
mov $80, $1
mov $82, $80[$79]
add $81, $82, 1
mov $80[$79], $81
add $83, $79, 1
add $86, $81, 1
mov $84, 0
mema $85, $86
mov $85[$84], $81
mov $87, $85[$84]
add $88, $84, 1
_L19:
brz _L20, $87
mov $85[$88], 0
add $88, $88, 1
sub $87, $87, 1
jump _L19
_L20:
nop
mov $85, $85
mov $89, 0
mov $90, $80[$83]
mov $91, $90[$89]
mov $92, 1
_L21:
sleq $93, $92, $91
brz _L22, $93
add $94, $89, $92
add $95, $84, $92
mov $96, $90[$94]
mov $85[$95], $96
add $92, $92, 1
jump _L21
_L22:
nop
memf $90
mov $80[$83], $85
add $97, $79, 2
add $100, $81, 1
mov $98, 0
mema $99, $100
mov $99[$98], $81
mov $101, $99[$98]
add $102, $98, 1
_L23:
brz _L24, $101
mov $99[$102], 0
add $102, $102, 1
sub $101, $101, 1
jump _L23
_L24:
nop
mov $99, $99
mov $103, 0
mov $104, $80[$97]
mov $105, $104[$103]
mov $106, 1
_L25:
sleq $107, $106, $105
brz _L26, $107
add $108, $103, $106
add $109, $98, $106
mov $110, $104[$108]
mov $99[$109], $110
add $106, $106, 1
jump _L25
_L26:
nop
memf $104
mov $80[$97], $99
mov $112, $0
mov $113, $1
add $114, $112, 1
mov $115, 0
mov $116, $113[$114]
mov $111, 1
mov $118, $115
mul $117, $111, 1
add $118, $117, 1
mov $119, $116
mov $120, 2
mov $119[$118], $120
mov $121, $0
mov $122, $1
print 'G'
print 'R'
print 'A'
print 'P'
print 'H'
print ' '
print '{'
println 
mov $123, $122[$121]
brz _L27, $123
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
add $124, $121, 1
mov $125, 0
mov $126, $122[$124]
print '['
mov $128, $125
mov $129, $126
mov $127, $129[$128]
add $128, $128, 1
mov $130, 1
_L28:
brz _L29, $127
mov $129, $129
mov $131, $129[$128]
print $131
print ','
print ' '
add $128, $128, $130
sub $127, $127, 1
jump _L28
_L29:
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
add $132, $121, 2
mov $133, 0
mov $134, $122[$132]
print '['
mov $136, $133
mov $137, $134
mov $135, $137[$136]
add $136, $136, 1
mov $138, 1
_L30:
brz _L31, $135
mov $137, $137
print 'A'
print 'R'
print 'R'
print 'A'
print 'Y'
print ':'
print ' '
print '['
mov $140, $136
mov $141, $137
mov $139, $141[$140]
add $140, $140, 1
mov $142, 1
_L32:
brz _L33, $139
mov $141, $141
mov $143, $141[$140]
print $143
print ','
print ' '
add $140, $140, $142
sub $139, $139, 1
jump _L32
_L33:
print '#'
print ']'
print ','
print ' '
add $136, $136, $138
sub $135, $135, 1
jump _L30
_L31:
print '#'
print ']'
println 
_L27:
nop
print '}'
println 
mov $144, $0
mov $145, $1
mov $147, $145[$144]
add $146, $147, 1
mov $145[$144], $146
add $148, $144, 1
add $151, $146, 1
mov $149, 0
mema $150, $151
mov $150[$149], $146
mov $152, $150[$149]
add $153, $149, 1
_L34:
brz _L35, $152
mov $150[$153], 0
add $153, $153, 1
sub $152, $152, 1
jump _L34
_L35:
nop
mov $150, $150
mov $154, 0
mov $155, $145[$148]
mov $156, $155[$154]
mov $157, 1
_L36:
sleq $158, $157, $156
brz _L37, $158
add $159, $154, $157
add $160, $149, $157
mov $161, $155[$159]
mov $150[$160], $161
add $157, $157, 1
jump _L36
_L37:
nop
memf $155
mov $145[$148], $150
add $162, $144, 2
add $165, $146, 1
mov $163, 0
mema $164, $165
mov $164[$163], $146
mov $166, $164[$163]
add $167, $163, 1
_L38:
brz _L39, $166
mov $164[$167], 0
add $167, $167, 1
sub $166, $166, 1
jump _L38
_L39:
nop
mov $164, $164
mov $168, 0
mov $169, $145[$162]
mov $170, $169[$168]
mov $171, 1
_L40:
sleq $172, $171, $170
brz _L41, $172
add $173, $168, $171
add $174, $163, $171
mov $175, $169[$173]
mov $164[$174], $175
add $171, $171, 1
jump _L40
_L41:
nop
memf $169
mov $145[$162], $164
mov $177, $0
mov $178, $1
add $179, $177, 1
mov $180, 0
mov $181, $178[$179]
mov $176, 2
mov $183, $180
mul $182, $176, 1
add $183, $182, 1
mov $184, $181
mov $185, 3
mov $184[$183], $185
mov $186, $0
mov $187, $1
print 'G'
print 'R'
print 'A'
print 'P'
print 'H'
print ' '
print '{'
println 
mov $188, $187[$186]
brz _L42, $188
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
add $189, $186, 1
mov $190, 0
mov $191, $187[$189]
print '['
mov $193, $190
mov $194, $191
mov $192, $194[$193]
add $193, $193, 1
mov $195, 1
_L43:
brz _L44, $192
mov $194, $194
mov $196, $194[$193]
print $196
print ','
print ' '
add $193, $193, $195
sub $192, $192, 1
jump _L43
_L44:
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
add $197, $186, 2
mov $198, 0
mov $199, $187[$197]
print '['
mov $201, $198
mov $202, $199
mov $200, $202[$201]
add $201, $201, 1
mov $203, 1
_L45:
brz _L46, $200
mov $202, $202
print 'A'
print 'R'
print 'R'
print 'A'
print 'Y'
print ':'
print ' '
print '['
mov $205, $201
mov $206, $202
mov $204, $206[$205]
add $205, $205, 1
mov $207, 1
_L47:
brz _L48, $204
mov $206, $206
mov $208, $206[$205]
print $208
print ','
print ' '
add $205, $205, $207
sub $204, $204, 1
jump _L47
_L48:
print '#'
print ']'
print ','
print ' '
add $201, $201, $203
sub $200, $200, 1
jump _L45
_L46:
print '#'
print ']'
println 
_L42:
nop
print '}'
println 
_L49:
nop
