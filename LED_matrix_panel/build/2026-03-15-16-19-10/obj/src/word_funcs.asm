;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (Linux)
;--------------------------------------------------------
	.module word_funcs
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _get_word_length_PARM_2
	.globl _get_word_value_PARM_4
	.globl _get_word_value_PARM_3
	.globl _get_word_value_PARM_2
	.globl _get_word_value
	.globl _get_word_length
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
_get_word_value_PARM_2:
	.ds 2
_get_word_value_PARM_3:
	.ds 2
_get_word_value_PARM_4:
	.ds 3
_get_word_value_current_index_65536_4:
	.ds 2
_get_word_value_part_65536_4:
	.ds 2
_get_word_value_sloc0_1_0:
	.ds 3
	.area	OSEG    (OVR,DATA)
_get_word_length_PARM_2:
	.ds 3
_get_word_length_parts_count_65536_10:
	.ds 2
_get_word_length_total_65536_11:
	.ds 2
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'get_word_value'
;------------------------------------------------------------
;word_size                 Allocated with name '_get_word_value_PARM_2'
;parts_count               Allocated with name '_get_word_value_PARM_3'
;word_parts                Allocated with name '_get_word_value_PARM_4'
;index                     Allocated to registers r6 r7 
;current_index             Allocated with name '_get_word_value_current_index_65536_4'
;part                      Allocated with name '_get_word_value_part_65536_4'
;sloc0                     Allocated with name '_get_word_value_sloc0_1_0'
;------------------------------------------------------------
;	src/word_funcs.c:5: int get_word_value(int index, int word_size, int parts_count, struct word_part* word_parts) {
;	-----------------------------------------
;	 function get_word_value
;	-----------------------------------------
_get_word_value:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r6,dpl
;	src/word_funcs.c:9: if (index < 0) {
	mov	a,dph
	mov	r7,a
	jnb	acc.7,00102$
;	src/word_funcs.c:10: current_index = word_size + index; 
	mov	a,r6
	add	a,_get_word_value_PARM_2
	mov	_get_word_value_current_index_65536_4,a
	mov	a,r7
	addc	a,(_get_word_value_PARM_2 + 1)
	mov	(_get_word_value_current_index_65536_4 + 1),a
	sjmp	00115$
00102$:
;	src/word_funcs.c:12: current_index = index;
	mov	_get_word_value_current_index_65536_4,r6
	mov	(_get_word_value_current_index_65536_4 + 1),r7
;	src/word_funcs.c:15: for(part = 0; part < parts_count; part++) {
00115$:
	clr	a
	mov	_get_word_value_part_65536_4,a
	mov	(_get_word_value_part_65536_4 + 1),a
	mov	r2,#0x00
	mov	r3,#0x00
00108$:
	clr	c
	mov	a,_get_word_value_part_65536_4
	subb	a,_get_word_value_PARM_3
	mov	a,(_get_word_value_part_65536_4 + 1)
	xrl	a,#0x80
	mov	b,(_get_word_value_PARM_3 + 1)
	xrl	b,#0x80
	subb	a,b
	jc	00129$
	ljmp	00106$
00129$:
;	src/word_funcs.c:16: if(current_index < (word_parts[part]).size) {
	mov	a,r2
	add	a,_get_word_value_PARM_4
	mov	_get_word_value_sloc0_1_0,a
	mov	a,r3
	addc	a,(_get_word_value_PARM_4 + 1)
	mov	(_get_word_value_sloc0_1_0 + 1),a
	mov	(_get_word_value_sloc0_1_0 + 2),(_get_word_value_PARM_4 + 2)
	mov	a,#0x03
	add	a,_get_word_value_sloc0_1_0
	mov	r0,a
	clr	a
	addc	a,(_get_word_value_sloc0_1_0 + 1)
	mov	r1,a
	mov	r7,(_get_word_value_sloc0_1_0 + 2)
	mov	dpl,r0
	mov	dph,r1
	mov	b,r7
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	clr	c
	mov	a,_get_word_value_current_index_65536_4
	subb	a,r6
	mov	a,(_get_word_value_current_index_65536_4 + 1)
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	00105$
;	src/word_funcs.c:17: return word_parts[part].data_[current_index];
	mov	dpl,_get_word_value_sloc0_1_0
	mov	dph,(_get_word_value_sloc0_1_0 + 1)
	mov	b,(_get_word_value_sloc0_1_0 + 2)
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	lcall	__gptrget
	mov	r1,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	mov	a,_get_word_value_current_index_65536_4
	add	a,r0
	mov	r0,a
	mov	a,(_get_word_value_current_index_65536_4 + 1)
	addc	a,r1
	mov	r1,a
	mov	dpl,r0
	mov	dph,r1
	mov	b,r5
	lcall	__gptrget
	mov	r0,a
	mov	r5,#0x00
	mov	dpl,r0
	mov	dph,r5
	ret
00105$:
;	src/word_funcs.c:19: current_index -= word_parts[part].size;
	mov	a,_get_word_value_current_index_65536_4
	clr	c
	subb	a,r6
	mov	_get_word_value_current_index_65536_4,a
	mov	a,(_get_word_value_current_index_65536_4 + 1)
	subb	a,r7
	mov	(_get_word_value_current_index_65536_4 + 1),a
;	src/word_funcs.c:15: for(part = 0; part < parts_count; part++) {
	mov	a,#0x05
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	inc	_get_word_value_part_65536_4
	clr	a
	cjne	a,_get_word_value_part_65536_4,00131$
	inc	(_get_word_value_part_65536_4 + 1)
00131$:
	ljmp	00108$
00106$:
;	src/word_funcs.c:22: return 0;
	mov	dptr,#0x0000
;	src/word_funcs.c:23: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'get_word_length'
;------------------------------------------------------------
;word_parts                Allocated with name '_get_word_length_PARM_2'
;parts_count               Allocated with name '_get_word_length_parts_count_65536_10'
;total                     Allocated with name '_get_word_length_total_65536_11'
;part                      Allocated to registers r2 r3 
;------------------------------------------------------------
;	src/word_funcs.c:26: int get_word_length(int parts_count, struct word_part* word_parts) {
;	-----------------------------------------
;	 function get_word_length
;	-----------------------------------------
_get_word_length:
	mov	_get_word_length_parts_count_65536_10,dpl
	mov	(_get_word_length_parts_count_65536_10 + 1),dph
;	src/word_funcs.c:27: int total = 0;
	clr	a
	mov	_get_word_length_total_65536_11,a
	mov	(_get_word_length_total_65536_11 + 1),a
;	src/word_funcs.c:29: for(part = 0; part < parts_count; part++) {
	mov	r2,#0x00
	mov	r3,#0x00
	mov	r0,#0x00
	mov	r1,#0x00
00103$:
	clr	c
	mov	a,r2
	subb	a,_get_word_length_parts_count_65536_10
	mov	a,r3
	xrl	a,#0x80
	mov	b,(_get_word_length_parts_count_65536_10 + 1)
	xrl	b,#0x80
	subb	a,b
	jnc	00101$
;	src/word_funcs.c:30: total += word_parts[part].size;
	mov	a,r0
	add	a,_get_word_length_PARM_2
	mov	r6,a
	mov	a,r1
	addc	a,(_get_word_length_PARM_2 + 1)
	mov	r5,a
	mov	r7,(_get_word_length_PARM_2 + 2)
	mov	a,#0x03
	add	a,r6
	mov	r6,a
	clr	a
	addc	a,r5
	mov	r5,a
	mov	dpl,r6
	mov	dph,r5
	mov	b,r7
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	mov	a,r6
	add	a,_get_word_length_total_65536_11
	mov	_get_word_length_total_65536_11,a
	mov	a,r5
	addc	a,(_get_word_length_total_65536_11 + 1)
	mov	(_get_word_length_total_65536_11 + 1),a
;	src/word_funcs.c:29: for(part = 0; part < parts_count; part++) {
	mov	a,#0x05
	add	a,r0
	mov	r0,a
	clr	a
	addc	a,r1
	mov	r1,a
	inc	r2
	cjne	r2,#0x00,00103$
	inc	r3
	sjmp	00103$
00101$:
;	src/word_funcs.c:32: return total;
	mov	dpl,_get_word_length_total_65536_11
	mov	dph,(_get_word_length_total_65536_11 + 1)
;	src/word_funcs.c:33: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
