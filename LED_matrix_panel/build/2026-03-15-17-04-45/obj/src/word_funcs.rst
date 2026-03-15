                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module word_funcs
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _get_word_length_PARM_2
                                     12 	.globl _get_word_value_PARM_4
                                     13 	.globl _get_word_value_PARM_3
                                     14 	.globl _get_word_value_PARM_2
                                     15 	.globl _get_word_value
                                     16 	.globl _get_word_length
                                     17 ;--------------------------------------------------------
                                     18 ; special function registers
                                     19 ;--------------------------------------------------------
                                     20 	.area RSEG    (ABS,DATA)
      000000                         21 	.org 0x0000
                                     22 ;--------------------------------------------------------
                                     23 ; special function bits
                                     24 ;--------------------------------------------------------
                                     25 	.area RSEG    (ABS,DATA)
      000000                         26 	.org 0x0000
                                     27 ;--------------------------------------------------------
                                     28 ; overlayable register banks
                                     29 ;--------------------------------------------------------
                                     30 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                         31 	.ds 8
                                     32 ;--------------------------------------------------------
                                     33 ; internal ram data
                                     34 ;--------------------------------------------------------
                                     35 	.area DSEG    (DATA)
                                     36 ;--------------------------------------------------------
                                     37 ; overlayable items in internal ram
                                     38 ;--------------------------------------------------------
                                     39 	.area	OSEG    (OVR,DATA)
      000014                         40 _get_word_value_PARM_2:
      000014                         41 	.ds 2
      000016                         42 _get_word_value_PARM_3:
      000016                         43 	.ds 2
      000018                         44 _get_word_value_PARM_4:
      000018                         45 	.ds 3
      00001B                         46 _get_word_value_current_index_65536_4:
      00001B                         47 	.ds 2
      00001D                         48 _get_word_value_part_65536_4:
      00001D                         49 	.ds 2
      00001F                         50 _get_word_value_sloc0_1_0:
      00001F                         51 	.ds 3
                                     52 	.area	OSEG    (OVR,DATA)
      000014                         53 _get_word_length_PARM_2:
      000014                         54 	.ds 3
      000017                         55 _get_word_length_parts_count_65536_10:
      000017                         56 	.ds 2
      000019                         57 _get_word_length_total_65536_11:
      000019                         58 	.ds 2
                                     59 ;--------------------------------------------------------
                                     60 ; indirectly addressable internal ram data
                                     61 ;--------------------------------------------------------
                                     62 	.area ISEG    (DATA)
                                     63 ;--------------------------------------------------------
                                     64 ; absolute internal ram data
                                     65 ;--------------------------------------------------------
                                     66 	.area IABS    (ABS,DATA)
                                     67 	.area IABS    (ABS,DATA)
                                     68 ;--------------------------------------------------------
                                     69 ; bit data
                                     70 ;--------------------------------------------------------
                                     71 	.area BSEG    (BIT)
                                     72 ;--------------------------------------------------------
                                     73 ; paged external ram data
                                     74 ;--------------------------------------------------------
                                     75 	.area PSEG    (PAG,XDATA)
                                     76 ;--------------------------------------------------------
                                     77 ; external ram data
                                     78 ;--------------------------------------------------------
                                     79 	.area XSEG    (XDATA)
                                     80 ;--------------------------------------------------------
                                     81 ; absolute external ram data
                                     82 ;--------------------------------------------------------
                                     83 	.area XABS    (ABS,XDATA)
                                     84 ;--------------------------------------------------------
                                     85 ; external initialized ram data
                                     86 ;--------------------------------------------------------
                                     87 	.area XISEG   (XDATA)
                                     88 	.area HOME    (CODE)
                                     89 	.area GSINIT0 (CODE)
                                     90 	.area GSINIT1 (CODE)
                                     91 	.area GSINIT2 (CODE)
                                     92 	.area GSINIT3 (CODE)
                                     93 	.area GSINIT4 (CODE)
                                     94 	.area GSINIT5 (CODE)
                                     95 	.area GSINIT  (CODE)
                                     96 	.area GSFINAL (CODE)
                                     97 	.area CSEG    (CODE)
                                     98 ;--------------------------------------------------------
                                     99 ; global & static initialisations
                                    100 ;--------------------------------------------------------
                                    101 	.area HOME    (CODE)
                                    102 	.area GSINIT  (CODE)
                                    103 	.area GSFINAL (CODE)
                                    104 	.area GSINIT  (CODE)
                                    105 ;--------------------------------------------------------
                                    106 ; Home
                                    107 ;--------------------------------------------------------
                                    108 	.area HOME    (CODE)
                                    109 	.area HOME    (CODE)
                                    110 ;--------------------------------------------------------
                                    111 ; code
                                    112 ;--------------------------------------------------------
                                    113 	.area CSEG    (CODE)
                                    114 ;------------------------------------------------------------
                                    115 ;Allocation info for local variables in function 'get_word_value'
                                    116 ;------------------------------------------------------------
                                    117 ;word_size                 Allocated with name '_get_word_value_PARM_2'
                                    118 ;parts_count               Allocated with name '_get_word_value_PARM_3'
                                    119 ;word_parts                Allocated with name '_get_word_value_PARM_4'
                                    120 ;index                     Allocated to registers r6 r7 
                                    121 ;current_index             Allocated with name '_get_word_value_current_index_65536_4'
                                    122 ;part                      Allocated with name '_get_word_value_part_65536_4'
                                    123 ;sloc0                     Allocated with name '_get_word_value_sloc0_1_0'
                                    124 ;------------------------------------------------------------
                                    125 ;	src/word_funcs.c:5: int get_word_value(int index, int word_size, int parts_count, struct word_part* word_parts) {
                                    126 ;	-----------------------------------------
                                    127 ;	 function get_word_value
                                    128 ;	-----------------------------------------
      000154                        129 _get_word_value:
                           000007   130 	ar7 = 0x07
                           000006   131 	ar6 = 0x06
                           000005   132 	ar5 = 0x05
                           000004   133 	ar4 = 0x04
                           000003   134 	ar3 = 0x03
                           000002   135 	ar2 = 0x02
                           000001   136 	ar1 = 0x01
                           000000   137 	ar0 = 0x00
      000154 AE 82            [24]  138 	mov	r6,dpl
                                    139 ;	src/word_funcs.c:9: if (index < 0) {
      000156 E5 83            [12]  140 	mov	a,dph
      000158 FF               [12]  141 	mov	r7,a
      000159 30 E7 0C         [24]  142 	jnb	acc.7,00102$
                                    143 ;	src/word_funcs.c:10: current_index = word_size + index; 
      00015C EE               [12]  144 	mov	a,r6
      00015D 25 14            [12]  145 	add	a,_get_word_value_PARM_2
      00015F F5 1B            [12]  146 	mov	_get_word_value_current_index_65536_4,a
      000161 EF               [12]  147 	mov	a,r7
      000162 35 15            [12]  148 	addc	a,(_get_word_value_PARM_2 + 1)
      000164 F5 1C            [12]  149 	mov	(_get_word_value_current_index_65536_4 + 1),a
      000166 80 04            [24]  150 	sjmp	00115$
      000168                        151 00102$:
                                    152 ;	src/word_funcs.c:12: current_index = index;
      000168 8E 1B            [24]  153 	mov	_get_word_value_current_index_65536_4,r6
      00016A 8F 1C            [24]  154 	mov	(_get_word_value_current_index_65536_4 + 1),r7
                                    155 ;	src/word_funcs.c:15: for(part = 0; part < parts_count; part++) {
      00016C                        156 00115$:
      00016C E4               [12]  157 	clr	a
      00016D F5 1D            [12]  158 	mov	_get_word_value_part_65536_4,a
      00016F F5 1E            [12]  159 	mov	(_get_word_value_part_65536_4 + 1),a
      000171 7A 00            [12]  160 	mov	r2,#0x00
      000173 7B 00            [12]  161 	mov	r3,#0x00
      000175                        162 00108$:
      000175 C3               [12]  163 	clr	c
      000176 E5 1D            [12]  164 	mov	a,_get_word_value_part_65536_4
      000178 95 16            [12]  165 	subb	a,_get_word_value_PARM_3
      00017A E5 1E            [12]  166 	mov	a,(_get_word_value_part_65536_4 + 1)
      00017C 64 80            [12]  167 	xrl	a,#0x80
      00017E 85 17 F0         [24]  168 	mov	b,(_get_word_value_PARM_3 + 1)
      000181 63 F0 80         [24]  169 	xrl	b,#0x80
      000184 95 F0            [12]  170 	subb	a,b
      000186 40 03            [24]  171 	jc	00129$
      000188 02 02 10         [24]  172 	ljmp	00106$
      00018B                        173 00129$:
                                    174 ;	src/word_funcs.c:16: if(current_index < (word_parts[part]).size) {
      00018B EA               [12]  175 	mov	a,r2
      00018C 25 18            [12]  176 	add	a,_get_word_value_PARM_4
      00018E F5 1F            [12]  177 	mov	_get_word_value_sloc0_1_0,a
      000190 EB               [12]  178 	mov	a,r3
      000191 35 19            [12]  179 	addc	a,(_get_word_value_PARM_4 + 1)
      000193 F5 20            [12]  180 	mov	(_get_word_value_sloc0_1_0 + 1),a
      000195 85 1A 21         [24]  181 	mov	(_get_word_value_sloc0_1_0 + 2),(_get_word_value_PARM_4 + 2)
      000198 74 03            [12]  182 	mov	a,#0x03
      00019A 25 1F            [12]  183 	add	a,_get_word_value_sloc0_1_0
      00019C F8               [12]  184 	mov	r0,a
      00019D E4               [12]  185 	clr	a
      00019E 35 20            [12]  186 	addc	a,(_get_word_value_sloc0_1_0 + 1)
      0001A0 F9               [12]  187 	mov	r1,a
      0001A1 AF 21            [24]  188 	mov	r7,(_get_word_value_sloc0_1_0 + 2)
      0001A3 88 82            [24]  189 	mov	dpl,r0
      0001A5 89 83            [24]  190 	mov	dph,r1
      0001A7 8F F0            [24]  191 	mov	b,r7
      0001A9 12 02 B8         [24]  192 	lcall	__gptrget
      0001AC FE               [12]  193 	mov	r6,a
      0001AD A3               [24]  194 	inc	dptr
      0001AE 12 02 B8         [24]  195 	lcall	__gptrget
      0001B1 FF               [12]  196 	mov	r7,a
      0001B2 C3               [12]  197 	clr	c
      0001B3 E5 1B            [12]  198 	mov	a,_get_word_value_current_index_65536_4
      0001B5 9E               [12]  199 	subb	a,r6
      0001B6 E5 1C            [12]  200 	mov	a,(_get_word_value_current_index_65536_4 + 1)
      0001B8 64 80            [12]  201 	xrl	a,#0x80
      0001BA 8F F0            [24]  202 	mov	b,r7
      0001BC 63 F0 80         [24]  203 	xrl	b,#0x80
      0001BF 95 F0            [12]  204 	subb	a,b
      0001C1 50 30            [24]  205 	jnc	00105$
                                    206 ;	src/word_funcs.c:17: return word_parts[part].data_[current_index];
      0001C3 85 1F 82         [24]  207 	mov	dpl,_get_word_value_sloc0_1_0
      0001C6 85 20 83         [24]  208 	mov	dph,(_get_word_value_sloc0_1_0 + 1)
      0001C9 85 21 F0         [24]  209 	mov	b,(_get_word_value_sloc0_1_0 + 2)
      0001CC 12 02 B8         [24]  210 	lcall	__gptrget
      0001CF F8               [12]  211 	mov	r0,a
      0001D0 A3               [24]  212 	inc	dptr
      0001D1 12 02 B8         [24]  213 	lcall	__gptrget
      0001D4 F9               [12]  214 	mov	r1,a
      0001D5 A3               [24]  215 	inc	dptr
      0001D6 12 02 B8         [24]  216 	lcall	__gptrget
      0001D9 FD               [12]  217 	mov	r5,a
      0001DA E5 1B            [12]  218 	mov	a,_get_word_value_current_index_65536_4
      0001DC 28               [12]  219 	add	a,r0
      0001DD F8               [12]  220 	mov	r0,a
      0001DE E5 1C            [12]  221 	mov	a,(_get_word_value_current_index_65536_4 + 1)
      0001E0 39               [12]  222 	addc	a,r1
      0001E1 F9               [12]  223 	mov	r1,a
      0001E2 88 82            [24]  224 	mov	dpl,r0
      0001E4 89 83            [24]  225 	mov	dph,r1
      0001E6 8D F0            [24]  226 	mov	b,r5
      0001E8 12 02 B8         [24]  227 	lcall	__gptrget
      0001EB F8               [12]  228 	mov	r0,a
      0001EC 7D 00            [12]  229 	mov	r5,#0x00
      0001EE 88 82            [24]  230 	mov	dpl,r0
      0001F0 8D 83            [24]  231 	mov	dph,r5
      0001F2 22               [24]  232 	ret
      0001F3                        233 00105$:
                                    234 ;	src/word_funcs.c:19: current_index -= word_parts[part].size;
      0001F3 E5 1B            [12]  235 	mov	a,_get_word_value_current_index_65536_4
      0001F5 C3               [12]  236 	clr	c
      0001F6 9E               [12]  237 	subb	a,r6
      0001F7 F5 1B            [12]  238 	mov	_get_word_value_current_index_65536_4,a
      0001F9 E5 1C            [12]  239 	mov	a,(_get_word_value_current_index_65536_4 + 1)
      0001FB 9F               [12]  240 	subb	a,r7
      0001FC F5 1C            [12]  241 	mov	(_get_word_value_current_index_65536_4 + 1),a
                                    242 ;	src/word_funcs.c:15: for(part = 0; part < parts_count; part++) {
      0001FE 74 05            [12]  243 	mov	a,#0x05
      000200 2A               [12]  244 	add	a,r2
      000201 FA               [12]  245 	mov	r2,a
      000202 E4               [12]  246 	clr	a
      000203 3B               [12]  247 	addc	a,r3
      000204 FB               [12]  248 	mov	r3,a
      000205 05 1D            [12]  249 	inc	_get_word_value_part_65536_4
      000207 E4               [12]  250 	clr	a
      000208 B5 1D 02         [24]  251 	cjne	a,_get_word_value_part_65536_4,00131$
      00020B 05 1E            [12]  252 	inc	(_get_word_value_part_65536_4 + 1)
      00020D                        253 00131$:
      00020D 02 01 75         [24]  254 	ljmp	00108$
      000210                        255 00106$:
                                    256 ;	src/word_funcs.c:22: return 0;
      000210 90 00 00         [24]  257 	mov	dptr,#0x0000
                                    258 ;	src/word_funcs.c:23: }
      000213 22               [24]  259 	ret
                                    260 ;------------------------------------------------------------
                                    261 ;Allocation info for local variables in function 'get_word_length'
                                    262 ;------------------------------------------------------------
                                    263 ;word_parts                Allocated with name '_get_word_length_PARM_2'
                                    264 ;parts_count               Allocated with name '_get_word_length_parts_count_65536_10'
                                    265 ;total                     Allocated with name '_get_word_length_total_65536_11'
                                    266 ;part                      Allocated to registers r2 r3 
                                    267 ;------------------------------------------------------------
                                    268 ;	src/word_funcs.c:26: int get_word_length(int parts_count, struct word_part* word_parts) {
                                    269 ;	-----------------------------------------
                                    270 ;	 function get_word_length
                                    271 ;	-----------------------------------------
      000214                        272 _get_word_length:
      000214 85 82 17         [24]  273 	mov	_get_word_length_parts_count_65536_10,dpl
      000217 85 83 18         [24]  274 	mov	(_get_word_length_parts_count_65536_10 + 1),dph
                                    275 ;	src/word_funcs.c:27: int total = 0;
      00021A E4               [12]  276 	clr	a
      00021B F5 19            [12]  277 	mov	_get_word_length_total_65536_11,a
      00021D F5 1A            [12]  278 	mov	(_get_word_length_total_65536_11 + 1),a
                                    279 ;	src/word_funcs.c:29: for(part = 0; part < parts_count; part++) {
      00021F 7A 00            [12]  280 	mov	r2,#0x00
      000221 7B 00            [12]  281 	mov	r3,#0x00
      000223 78 00            [12]  282 	mov	r0,#0x00
      000225 79 00            [12]  283 	mov	r1,#0x00
      000227                        284 00103$:
      000227 C3               [12]  285 	clr	c
      000228 EA               [12]  286 	mov	a,r2
      000229 95 17            [12]  287 	subb	a,_get_word_length_parts_count_65536_10
      00022B EB               [12]  288 	mov	a,r3
      00022C 64 80            [12]  289 	xrl	a,#0x80
      00022E 85 18 F0         [24]  290 	mov	b,(_get_word_length_parts_count_65536_10 + 1)
      000231 63 F0 80         [24]  291 	xrl	b,#0x80
      000234 95 F0            [12]  292 	subb	a,b
      000236 50 38            [24]  293 	jnc	00101$
                                    294 ;	src/word_funcs.c:30: total += word_parts[part].size;
      000238 E8               [12]  295 	mov	a,r0
      000239 25 14            [12]  296 	add	a,_get_word_length_PARM_2
      00023B FE               [12]  297 	mov	r6,a
      00023C E9               [12]  298 	mov	a,r1
      00023D 35 15            [12]  299 	addc	a,(_get_word_length_PARM_2 + 1)
      00023F FD               [12]  300 	mov	r5,a
      000240 AF 16            [24]  301 	mov	r7,(_get_word_length_PARM_2 + 2)
      000242 74 03            [12]  302 	mov	a,#0x03
      000244 2E               [12]  303 	add	a,r6
      000245 FE               [12]  304 	mov	r6,a
      000246 E4               [12]  305 	clr	a
      000247 3D               [12]  306 	addc	a,r5
      000248 FD               [12]  307 	mov	r5,a
      000249 8E 82            [24]  308 	mov	dpl,r6
      00024B 8D 83            [24]  309 	mov	dph,r5
      00024D 8F F0            [24]  310 	mov	b,r7
      00024F 12 02 B8         [24]  311 	lcall	__gptrget
      000252 FE               [12]  312 	mov	r6,a
      000253 A3               [24]  313 	inc	dptr
      000254 12 02 B8         [24]  314 	lcall	__gptrget
      000257 FD               [12]  315 	mov	r5,a
      000258 EE               [12]  316 	mov	a,r6
      000259 25 19            [12]  317 	add	a,_get_word_length_total_65536_11
      00025B F5 19            [12]  318 	mov	_get_word_length_total_65536_11,a
      00025D ED               [12]  319 	mov	a,r5
      00025E 35 1A            [12]  320 	addc	a,(_get_word_length_total_65536_11 + 1)
      000260 F5 1A            [12]  321 	mov	(_get_word_length_total_65536_11 + 1),a
                                    322 ;	src/word_funcs.c:29: for(part = 0; part < parts_count; part++) {
      000262 74 05            [12]  323 	mov	a,#0x05
      000264 28               [12]  324 	add	a,r0
      000265 F8               [12]  325 	mov	r0,a
      000266 E4               [12]  326 	clr	a
      000267 39               [12]  327 	addc	a,r1
      000268 F9               [12]  328 	mov	r1,a
      000269 0A               [12]  329 	inc	r2
      00026A BA 00 BA         [24]  330 	cjne	r2,#0x00,00103$
      00026D 0B               [12]  331 	inc	r3
      00026E 80 B7            [24]  332 	sjmp	00103$
      000270                        333 00101$:
                                    334 ;	src/word_funcs.c:32: return total;
      000270 85 19 82         [24]  335 	mov	dpl,_get_word_length_total_65536_11
      000273 85 1A 83         [24]  336 	mov	dph,(_get_word_length_total_65536_11 + 1)
                                    337 ;	src/word_funcs.c:33: }
      000276 22               [24]  338 	ret
                                    339 	.area CSEG    (CODE)
                                    340 	.area CONST   (CODE)
                                    341 	.area XINIT   (CODE)
                                    342 	.area CABS    (ABS,CODE)
