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
      000041                         40 _get_word_value_PARM_2:
      000041                         41 	.ds 2
      000043                         42 _get_word_value_PARM_3:
      000043                         43 	.ds 2
      000045                         44 _get_word_value_PARM_4:
      000045                         45 	.ds 3
      000048                         46 _get_word_value_current_index_65536_4:
      000048                         47 	.ds 2
      00004A                         48 _get_word_value_part_65536_4:
      00004A                         49 	.ds 2
      00004C                         50 _get_word_value_sloc0_1_0:
      00004C                         51 	.ds 3
                                     52 	.area	OSEG    (OVR,DATA)
      000041                         53 _get_word_length_PARM_2:
      000041                         54 	.ds 3
      000044                         55 _get_word_length_parts_count_65536_10:
      000044                         56 	.ds 2
      000046                         57 _get_word_length_total_65536_11:
      000046                         58 	.ds 2
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
      0001DA                        129 _get_word_value:
                           000007   130 	ar7 = 0x07
                           000006   131 	ar6 = 0x06
                           000005   132 	ar5 = 0x05
                           000004   133 	ar4 = 0x04
                           000003   134 	ar3 = 0x03
                           000002   135 	ar2 = 0x02
                           000001   136 	ar1 = 0x01
                           000000   137 	ar0 = 0x00
      0001DA AE 82            [24]  138 	mov	r6,dpl
                                    139 ;	src/word_funcs.c:9: if (index < 0) {
      0001DC E5 83            [12]  140 	mov	a,dph
      0001DE FF               [12]  141 	mov	r7,a
      0001DF 30 E7 0C         [24]  142 	jnb	acc.7,00102$
                                    143 ;	src/word_funcs.c:10: current_index = word_size + index; 
      0001E2 EE               [12]  144 	mov	a,r6
      0001E3 25 41            [12]  145 	add	a,_get_word_value_PARM_2
      0001E5 F5 48            [12]  146 	mov	_get_word_value_current_index_65536_4,a
      0001E7 EF               [12]  147 	mov	a,r7
      0001E8 35 42            [12]  148 	addc	a,(_get_word_value_PARM_2 + 1)
      0001EA F5 49            [12]  149 	mov	(_get_word_value_current_index_65536_4 + 1),a
      0001EC 80 04            [24]  150 	sjmp	00115$
      0001EE                        151 00102$:
                                    152 ;	src/word_funcs.c:12: current_index = index;
      0001EE 8E 48            [24]  153 	mov	_get_word_value_current_index_65536_4,r6
      0001F0 8F 49            [24]  154 	mov	(_get_word_value_current_index_65536_4 + 1),r7
                                    155 ;	src/word_funcs.c:15: for(part = 0; part < parts_count; part++) {
      0001F2                        156 00115$:
      0001F2 E4               [12]  157 	clr	a
      0001F3 F5 4A            [12]  158 	mov	_get_word_value_part_65536_4,a
      0001F5 F5 4B            [12]  159 	mov	(_get_word_value_part_65536_4 + 1),a
      0001F7 7A 00            [12]  160 	mov	r2,#0x00
      0001F9 7B 00            [12]  161 	mov	r3,#0x00
      0001FB                        162 00108$:
      0001FB C3               [12]  163 	clr	c
      0001FC E5 4A            [12]  164 	mov	a,_get_word_value_part_65536_4
      0001FE 95 43            [12]  165 	subb	a,_get_word_value_PARM_3
      000200 E5 4B            [12]  166 	mov	a,(_get_word_value_part_65536_4 + 1)
      000202 64 80            [12]  167 	xrl	a,#0x80
      000204 85 44 F0         [24]  168 	mov	b,(_get_word_value_PARM_3 + 1)
      000207 63 F0 80         [24]  169 	xrl	b,#0x80
      00020A 95 F0            [12]  170 	subb	a,b
      00020C 40 03            [24]  171 	jc	00129$
      00020E 02 02 96         [24]  172 	ljmp	00106$
      000211                        173 00129$:
                                    174 ;	src/word_funcs.c:16: if(current_index < (word_parts[part]).size) {
      000211 EA               [12]  175 	mov	a,r2
      000212 25 45            [12]  176 	add	a,_get_word_value_PARM_4
      000214 F5 4C            [12]  177 	mov	_get_word_value_sloc0_1_0,a
      000216 EB               [12]  178 	mov	a,r3
      000217 35 46            [12]  179 	addc	a,(_get_word_value_PARM_4 + 1)
      000219 F5 4D            [12]  180 	mov	(_get_word_value_sloc0_1_0 + 1),a
      00021B 85 47 4E         [24]  181 	mov	(_get_word_value_sloc0_1_0 + 2),(_get_word_value_PARM_4 + 2)
      00021E 74 03            [12]  182 	mov	a,#0x03
      000220 25 4C            [12]  183 	add	a,_get_word_value_sloc0_1_0
      000222 F8               [12]  184 	mov	r0,a
      000223 E4               [12]  185 	clr	a
      000224 35 4D            [12]  186 	addc	a,(_get_word_value_sloc0_1_0 + 1)
      000226 F9               [12]  187 	mov	r1,a
      000227 AF 4E            [24]  188 	mov	r7,(_get_word_value_sloc0_1_0 + 2)
      000229 88 82            [24]  189 	mov	dpl,r0
      00022B 89 83            [24]  190 	mov	dph,r1
      00022D 8F F0            [24]  191 	mov	b,r7
      00022F 12 03 3E         [24]  192 	lcall	__gptrget
      000232 FE               [12]  193 	mov	r6,a
      000233 A3               [24]  194 	inc	dptr
      000234 12 03 3E         [24]  195 	lcall	__gptrget
      000237 FF               [12]  196 	mov	r7,a
      000238 C3               [12]  197 	clr	c
      000239 E5 48            [12]  198 	mov	a,_get_word_value_current_index_65536_4
      00023B 9E               [12]  199 	subb	a,r6
      00023C E5 49            [12]  200 	mov	a,(_get_word_value_current_index_65536_4 + 1)
      00023E 64 80            [12]  201 	xrl	a,#0x80
      000240 8F F0            [24]  202 	mov	b,r7
      000242 63 F0 80         [24]  203 	xrl	b,#0x80
      000245 95 F0            [12]  204 	subb	a,b
      000247 50 30            [24]  205 	jnc	00105$
                                    206 ;	src/word_funcs.c:17: return word_parts[part].data_[current_index];
      000249 85 4C 82         [24]  207 	mov	dpl,_get_word_value_sloc0_1_0
      00024C 85 4D 83         [24]  208 	mov	dph,(_get_word_value_sloc0_1_0 + 1)
      00024F 85 4E F0         [24]  209 	mov	b,(_get_word_value_sloc0_1_0 + 2)
      000252 12 03 3E         [24]  210 	lcall	__gptrget
      000255 F8               [12]  211 	mov	r0,a
      000256 A3               [24]  212 	inc	dptr
      000257 12 03 3E         [24]  213 	lcall	__gptrget
      00025A F9               [12]  214 	mov	r1,a
      00025B A3               [24]  215 	inc	dptr
      00025C 12 03 3E         [24]  216 	lcall	__gptrget
      00025F FD               [12]  217 	mov	r5,a
      000260 E5 48            [12]  218 	mov	a,_get_word_value_current_index_65536_4
      000262 28               [12]  219 	add	a,r0
      000263 F8               [12]  220 	mov	r0,a
      000264 E5 49            [12]  221 	mov	a,(_get_word_value_current_index_65536_4 + 1)
      000266 39               [12]  222 	addc	a,r1
      000267 F9               [12]  223 	mov	r1,a
      000268 88 82            [24]  224 	mov	dpl,r0
      00026A 89 83            [24]  225 	mov	dph,r1
      00026C 8D F0            [24]  226 	mov	b,r5
      00026E 12 03 3E         [24]  227 	lcall	__gptrget
      000271 F8               [12]  228 	mov	r0,a
      000272 7D 00            [12]  229 	mov	r5,#0x00
      000274 88 82            [24]  230 	mov	dpl,r0
      000276 8D 83            [24]  231 	mov	dph,r5
      000278 22               [24]  232 	ret
      000279                        233 00105$:
                                    234 ;	src/word_funcs.c:19: current_index -= word_parts[part].size;
      000279 E5 48            [12]  235 	mov	a,_get_word_value_current_index_65536_4
      00027B C3               [12]  236 	clr	c
      00027C 9E               [12]  237 	subb	a,r6
      00027D F5 48            [12]  238 	mov	_get_word_value_current_index_65536_4,a
      00027F E5 49            [12]  239 	mov	a,(_get_word_value_current_index_65536_4 + 1)
      000281 9F               [12]  240 	subb	a,r7
      000282 F5 49            [12]  241 	mov	(_get_word_value_current_index_65536_4 + 1),a
                                    242 ;	src/word_funcs.c:15: for(part = 0; part < parts_count; part++) {
      000284 74 05            [12]  243 	mov	a,#0x05
      000286 2A               [12]  244 	add	a,r2
      000287 FA               [12]  245 	mov	r2,a
      000288 E4               [12]  246 	clr	a
      000289 3B               [12]  247 	addc	a,r3
      00028A FB               [12]  248 	mov	r3,a
      00028B 05 4A            [12]  249 	inc	_get_word_value_part_65536_4
      00028D E4               [12]  250 	clr	a
      00028E B5 4A 02         [24]  251 	cjne	a,_get_word_value_part_65536_4,00131$
      000291 05 4B            [12]  252 	inc	(_get_word_value_part_65536_4 + 1)
      000293                        253 00131$:
      000293 02 01 FB         [24]  254 	ljmp	00108$
      000296                        255 00106$:
                                    256 ;	src/word_funcs.c:22: return 0;
      000296 90 00 00         [24]  257 	mov	dptr,#0x0000
                                    258 ;	src/word_funcs.c:23: }
      000299 22               [24]  259 	ret
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
      00029A                        272 _get_word_length:
      00029A 85 82 44         [24]  273 	mov	_get_word_length_parts_count_65536_10,dpl
      00029D 85 83 45         [24]  274 	mov	(_get_word_length_parts_count_65536_10 + 1),dph
                                    275 ;	src/word_funcs.c:27: int total = 0;
      0002A0 E4               [12]  276 	clr	a
      0002A1 F5 46            [12]  277 	mov	_get_word_length_total_65536_11,a
      0002A3 F5 47            [12]  278 	mov	(_get_word_length_total_65536_11 + 1),a
                                    279 ;	src/word_funcs.c:29: for(part = 0; part < parts_count; part++) {
      0002A5 7A 00            [12]  280 	mov	r2,#0x00
      0002A7 7B 00            [12]  281 	mov	r3,#0x00
      0002A9 78 00            [12]  282 	mov	r0,#0x00
      0002AB 79 00            [12]  283 	mov	r1,#0x00
      0002AD                        284 00103$:
      0002AD C3               [12]  285 	clr	c
      0002AE EA               [12]  286 	mov	a,r2
      0002AF 95 44            [12]  287 	subb	a,_get_word_length_parts_count_65536_10
      0002B1 EB               [12]  288 	mov	a,r3
      0002B2 64 80            [12]  289 	xrl	a,#0x80
      0002B4 85 45 F0         [24]  290 	mov	b,(_get_word_length_parts_count_65536_10 + 1)
      0002B7 63 F0 80         [24]  291 	xrl	b,#0x80
      0002BA 95 F0            [12]  292 	subb	a,b
      0002BC 50 38            [24]  293 	jnc	00101$
                                    294 ;	src/word_funcs.c:30: total += word_parts[part].size;
      0002BE E8               [12]  295 	mov	a,r0
      0002BF 25 41            [12]  296 	add	a,_get_word_length_PARM_2
      0002C1 FE               [12]  297 	mov	r6,a
      0002C2 E9               [12]  298 	mov	a,r1
      0002C3 35 42            [12]  299 	addc	a,(_get_word_length_PARM_2 + 1)
      0002C5 FD               [12]  300 	mov	r5,a
      0002C6 AF 43            [24]  301 	mov	r7,(_get_word_length_PARM_2 + 2)
      0002C8 74 03            [12]  302 	mov	a,#0x03
      0002CA 2E               [12]  303 	add	a,r6
      0002CB FE               [12]  304 	mov	r6,a
      0002CC E4               [12]  305 	clr	a
      0002CD 3D               [12]  306 	addc	a,r5
      0002CE FD               [12]  307 	mov	r5,a
      0002CF 8E 82            [24]  308 	mov	dpl,r6
      0002D1 8D 83            [24]  309 	mov	dph,r5
      0002D3 8F F0            [24]  310 	mov	b,r7
      0002D5 12 03 3E         [24]  311 	lcall	__gptrget
      0002D8 FE               [12]  312 	mov	r6,a
      0002D9 A3               [24]  313 	inc	dptr
      0002DA 12 03 3E         [24]  314 	lcall	__gptrget
      0002DD FD               [12]  315 	mov	r5,a
      0002DE EE               [12]  316 	mov	a,r6
      0002DF 25 46            [12]  317 	add	a,_get_word_length_total_65536_11
      0002E1 F5 46            [12]  318 	mov	_get_word_length_total_65536_11,a
      0002E3 ED               [12]  319 	mov	a,r5
      0002E4 35 47            [12]  320 	addc	a,(_get_word_length_total_65536_11 + 1)
      0002E6 F5 47            [12]  321 	mov	(_get_word_length_total_65536_11 + 1),a
                                    322 ;	src/word_funcs.c:29: for(part = 0; part < parts_count; part++) {
      0002E8 74 05            [12]  323 	mov	a,#0x05
      0002EA 28               [12]  324 	add	a,r0
      0002EB F8               [12]  325 	mov	r0,a
      0002EC E4               [12]  326 	clr	a
      0002ED 39               [12]  327 	addc	a,r1
      0002EE F9               [12]  328 	mov	r1,a
      0002EF 0A               [12]  329 	inc	r2
      0002F0 BA 00 BA         [24]  330 	cjne	r2,#0x00,00103$
      0002F3 0B               [12]  331 	inc	r3
      0002F4 80 B7            [24]  332 	sjmp	00103$
      0002F6                        333 00101$:
                                    334 ;	src/word_funcs.c:32: return total;
      0002F6 85 46 82         [24]  335 	mov	dpl,_get_word_length_total_65536_11
      0002F9 85 47 83         [24]  336 	mov	dph,(_get_word_length_total_65536_11 + 1)
                                    337 ;	src/word_funcs.c:33: }
      0002FC 22               [24]  338 	ret
                                    339 	.area CSEG    (CODE)
                                    340 	.area CONST   (CODE)
                                    341 	.area XINIT   (CODE)
                                    342 	.area CABS    (ABS,CODE)
