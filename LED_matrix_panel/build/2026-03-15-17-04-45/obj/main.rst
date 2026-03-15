                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _word_parts
                                     12 	.globl _font_space
                                     13 	.globl _font_Z
                                     14 	.globl _font_Y
                                     15 	.globl _font_X
                                     16 	.globl _font_W
                                     17 	.globl _font_V
                                     18 	.globl _font_U
                                     19 	.globl _font_T
                                     20 	.globl _font_S
                                     21 	.globl _font_R
                                     22 	.globl _font_Q
                                     23 	.globl _font_P
                                     24 	.globl _font_O
                                     25 	.globl _font_N
                                     26 	.globl _font_M
                                     27 	.globl _font_L
                                     28 	.globl _font_K
                                     29 	.globl _font_J
                                     30 	.globl _font_I
                                     31 	.globl _font_H
                                     32 	.globl _font_G
                                     33 	.globl _font_F
                                     34 	.globl _font_E
                                     35 	.globl _font_D
                                     36 	.globl _font_C
                                     37 	.globl _font_B
                                     38 	.globl _font_A
                                     39 	.globl _Timer_ISR
                                     40 	.globl _main
                                     41 	.globl _Interrupts_Init
                                     42 	.globl _Timers_Init
                                     43 	.globl _get_word_length
                                     44 	.globl _get_word_value
                                     45 	.globl _SPIF
                                     46 	.globl _WCOL
                                     47 	.globl _MODF
                                     48 	.globl _RXOVRN
                                     49 	.globl _NSSMD1
                                     50 	.globl _NSSMD0
                                     51 	.globl _TXBMT
                                     52 	.globl _SPIEN
                                     53 	.globl _AD0EN
                                     54 	.globl _AD0TM
                                     55 	.globl _AD0INT
                                     56 	.globl _AD0BUSY
                                     57 	.globl _AD0WINT
                                     58 	.globl _AD0CM2
                                     59 	.globl _AD0CM1
                                     60 	.globl _AD0CM0
                                     61 	.globl _CF
                                     62 	.globl _CR
                                     63 	.globl _CCF5
                                     64 	.globl _CCF4
                                     65 	.globl _CCF3
                                     66 	.globl _CCF2
                                     67 	.globl _CCF1
                                     68 	.globl _CCF0
                                     69 	.globl _CY
                                     70 	.globl _AC
                                     71 	.globl _F0
                                     72 	.globl _RS1
                                     73 	.globl _RS0
                                     74 	.globl _OV
                                     75 	.globl _F1
                                     76 	.globl _P
                                     77 	.globl _TF2H
                                     78 	.globl _TF2L
                                     79 	.globl _TF2LEN
                                     80 	.globl _TF2CEN
                                     81 	.globl _T2SPLIT
                                     82 	.globl _TR2
                                     83 	.globl _T2XCLK
                                     84 	.globl _MASTER
                                     85 	.globl _TXMODE
                                     86 	.globl _STA
                                     87 	.globl _STO
                                     88 	.globl _ACKRQ
                                     89 	.globl _ARBLOST
                                     90 	.globl _ACK
                                     91 	.globl _SI
                                     92 	.globl _PSPI0
                                     93 	.globl _PT2
                                     94 	.globl _PS0
                                     95 	.globl _PT1
                                     96 	.globl _PX1
                                     97 	.globl _PT0
                                     98 	.globl _PX0
                                     99 	.globl _P3_7
                                    100 	.globl _P3_6
                                    101 	.globl _P3_5
                                    102 	.globl _P3_4
                                    103 	.globl _P3_3
                                    104 	.globl _P3_2
                                    105 	.globl _P3_1
                                    106 	.globl _P3_0
                                    107 	.globl _EA
                                    108 	.globl _ESPI0
                                    109 	.globl _ET2
                                    110 	.globl _ES0
                                    111 	.globl _ET1
                                    112 	.globl _EX1
                                    113 	.globl _ET0
                                    114 	.globl _EX0
                                    115 	.globl _P2_7
                                    116 	.globl _P2_6
                                    117 	.globl _P2_5
                                    118 	.globl _P2_4
                                    119 	.globl _P2_3
                                    120 	.globl _P2_2
                                    121 	.globl _P2_1
                                    122 	.globl _P2_0
                                    123 	.globl _S0MODE
                                    124 	.globl _MCE0
                                    125 	.globl _REN0
                                    126 	.globl _TB80
                                    127 	.globl _RB80
                                    128 	.globl _TI0
                                    129 	.globl _RI0
                                    130 	.globl _P1_7
                                    131 	.globl _P1_6
                                    132 	.globl _P1_5
                                    133 	.globl _P1_4
                                    134 	.globl _P1_3
                                    135 	.globl _P1_2
                                    136 	.globl _P1_1
                                    137 	.globl _P1_0
                                    138 	.globl _TF1
                                    139 	.globl _TR1
                                    140 	.globl _TF0
                                    141 	.globl _TR0
                                    142 	.globl _IE1
                                    143 	.globl _IT1
                                    144 	.globl _IE0
                                    145 	.globl _IT0
                                    146 	.globl _P0_7
                                    147 	.globl _P0_6
                                    148 	.globl _P0_5
                                    149 	.globl _P0_4
                                    150 	.globl _P0_3
                                    151 	.globl _P0_2
                                    152 	.globl _P0_1
                                    153 	.globl _P0_0
                                    154 	.globl _EMI0TC
                                    155 	.globl _P3MDIN
                                    156 	.globl _P2MDIN
                                    157 	.globl _P1MDIN
                                    158 	.globl _P0MDIN
                                    159 	.globl _SFR0CN
                                    160 	.globl _XBR1
                                    161 	.globl _XBR0
                                    162 	.globl _P3SKIP
                                    163 	.globl _P2SKIP
                                    164 	.globl _P1SKIP
                                    165 	.globl _P0SKIP
                                    166 	.globl _CCH0MA
                                    167 	.globl _CCH0LC
                                    168 	.globl _EIP2
                                    169 	.globl _EIP1
                                    170 	.globl _CCH0TN
                                    171 	.globl _EMI0CF
                                    172 	.globl _OSCICL
                                    173 	.globl _OSCICN
                                    174 	.globl _OSCXCN
                                    175 	.globl _PLL0CN
                                    176 	.globl _PLL0FLT
                                    177 	.globl _PLL0MUL
                                    178 	.globl _P3MDOUT
                                    179 	.globl _P4MDOUT
                                    180 	.globl _OSCLCN
                                    181 	.globl _FLSTAT
                                    182 	.globl _PLL0DIV
                                    183 	.globl _P2MDOUT
                                    184 	.globl _P1MDOUT
                                    185 	.globl _P0MDOUT
                                    186 	.globl _CLKSEL
                                    187 	.globl _CCH0CN
                                    188 	.globl _P0MASK
                                    189 	.globl _P0MAT
                                    190 	.globl _MAC0BH
                                    191 	.globl _MAC0BL
                                    192 	.globl _P1MASK
                                    193 	.globl _P1MAT
                                    194 	.globl _MAC0CF
                                    195 	.globl _MAC0OVR
                                    196 	.globl _MAC0ACC3
                                    197 	.globl _MAC0ACC2
                                    198 	.globl _MAC0ACC1
                                    199 	.globl _MAC0ACC0
                                    200 	.globl _MAC0ACC
                                    201 	.globl _MAC0STA
                                    202 	.globl _FLKEY
                                    203 	.globl _FLSCL
                                    204 	.globl _P2MASK
                                    205 	.globl _P2MAT
                                    206 	.globl _MAC0RNDH
                                    207 	.globl _MAC0RNDL
                                    208 	.globl _MAC0RND
                                    209 	.globl _MAC0AH
                                    210 	.globl _MAC0AL
                                    211 	.globl _MAC0A
                                    212 	.globl _PSCTL
                                    213 	.globl _VDM0CN
                                    214 	.globl _PCA0CPH4
                                    215 	.globl _PCA0CPL4
                                    216 	.globl _PCA0CP4
                                    217 	.globl _PCA0CPH0
                                    218 	.globl _PCA0CPL0
                                    219 	.globl _PCA0CP0
                                    220 	.globl _PCA0H
                                    221 	.globl _PCA0L
                                    222 	.globl _PCA0
                                    223 	.globl _SPI0CN
                                    224 	.globl _PCA0CPH5
                                    225 	.globl _PCA0CPL5
                                    226 	.globl _PCA0CP5
                                    227 	.globl _B
                                    228 	.globl _RSTSRC
                                    229 	.globl _PCA0CPH3
                                    230 	.globl _PCA0CPL3
                                    231 	.globl _PCA0CP3
                                    232 	.globl _PCA0CPH2
                                    233 	.globl _PCA0CPL2
                                    234 	.globl _PCA0CP2
                                    235 	.globl _PCA0CPH1
                                    236 	.globl _PCA0CPL1
                                    237 	.globl _PCA0CP1
                                    238 	.globl _ADC0CN
                                    239 	.globl _EIE2
                                    240 	.globl _EIE1
                                    241 	.globl _IT01CF
                                    242 	.globl _ACC
                                    243 	.globl _PCA0CPM5
                                    244 	.globl _PCA0CPM4
                                    245 	.globl _PCA0CPM3
                                    246 	.globl _PCA0CPM2
                                    247 	.globl _PCA0CPM1
                                    248 	.globl _PCA0CPM0
                                    249 	.globl _PCA0MD
                                    250 	.globl _PCA0CN
                                    251 	.globl _REF0CN
                                    252 	.globl _PSW
                                    253 	.globl _TMR2H
                                    254 	.globl _TMR2L
                                    255 	.globl _TMR2
                                    256 	.globl _TMR2RLH
                                    257 	.globl _TMR2RLL
                                    258 	.globl _TMR2RL
                                    259 	.globl _TMR2CN
                                    260 	.globl _ADC0LTH
                                    261 	.globl _ADC0LTL
                                    262 	.globl _ADC0LT
                                    263 	.globl _ADC0GTH
                                    264 	.globl _ADC0GTL
                                    265 	.globl _ADC0GT
                                    266 	.globl _SMB0DAT
                                    267 	.globl _SMB0CF
                                    268 	.globl _SMB0CN
                                    269 	.globl _ADC0H
                                    270 	.globl _ADC0L
                                    271 	.globl _ADC0
                                    272 	.globl _ADC0CF
                                    273 	.globl _AMX0P
                                    274 	.globl _AMX0N
                                    275 	.globl _IDA0CN
                                    276 	.globl _IP
                                    277 	.globl _P4
                                    278 	.globl _P3
                                    279 	.globl __XPAGE
                                    280 	.globl _EMI0CN
                                    281 	.globl _IE
                                    282 	.globl _SFRPAGE
                                    283 	.globl _SPI0DAT
                                    284 	.globl _SPI0CKR
                                    285 	.globl _SPI0CFG
                                    286 	.globl _P2
                                    287 	.globl _CPT0MX
                                    288 	.globl _CPT1MX
                                    289 	.globl _CPT0MD
                                    290 	.globl _CPT1MD
                                    291 	.globl _CPT0CN
                                    292 	.globl _CPT1CN
                                    293 	.globl _SBUF0
                                    294 	.globl _SCON0
                                    295 	.globl _IDA0H
                                    296 	.globl _IDA0L
                                    297 	.globl _IDA0
                                    298 	.globl _TMR3H
                                    299 	.globl _TMR3L
                                    300 	.globl _TMR3
                                    301 	.globl _TMR3RLH
                                    302 	.globl _TMR3RLL
                                    303 	.globl _TMR3RL
                                    304 	.globl _TMR3CN
                                    305 	.globl _P1
                                    306 	.globl _CKCON
                                    307 	.globl _TH1
                                    308 	.globl _TL1
                                    309 	.globl _TMR1
                                    310 	.globl _TH0
                                    311 	.globl _TL0
                                    312 	.globl _TMR0
                                    313 	.globl _TMOD
                                    314 	.globl _TCON
                                    315 	.globl _PCON
                                    316 	.globl _SFRLAST
                                    317 	.globl _SFRNEXT
                                    318 	.globl _DPH
                                    319 	.globl _DPL
                                    320 	.globl _SP
                                    321 	.globl _P0
                                    322 	.globl _g_word_size
                                    323 	.globl _g_delta_time_for_word
                                    324 	.globl _g_cur_time_for_word
                                    325 	.globl _g_parts_count
                                    326 	.globl _g_cursor
                                    327 	.globl _g_delta_pos
                                    328 	.globl _PORT_Init
                                    329 	.globl _Init_Device
                                    330 ;--------------------------------------------------------
                                    331 ; special function registers
                                    332 ;--------------------------------------------------------
                                    333 	.area RSEG    (ABS,DATA)
      000000                        334 	.org 0x0000
                           000080   335 _P0	=	0x0080
                           000081   336 _SP	=	0x0081
                           000082   337 _DPL	=	0x0082
                           000083   338 _DPH	=	0x0083
                           000085   339 _SFRNEXT	=	0x0085
                           000086   340 _SFRLAST	=	0x0086
                           000087   341 _PCON	=	0x0087
                           000088   342 _TCON	=	0x0088
                           000089   343 _TMOD	=	0x0089
                           008C8A   344 _TMR0	=	0x8c8a
                           00008A   345 _TL0	=	0x008a
                           00008C   346 _TH0	=	0x008c
                           008D8B   347 _TMR1	=	0x8d8b
                           00008B   348 _TL1	=	0x008b
                           00008D   349 _TH1	=	0x008d
                           00008E   350 _CKCON	=	0x008e
                           000090   351 _P1	=	0x0090
                           000091   352 _TMR3CN	=	0x0091
                           009392   353 _TMR3RL	=	0x9392
                           000092   354 _TMR3RLL	=	0x0092
                           000093   355 _TMR3RLH	=	0x0093
                           009594   356 _TMR3	=	0x9594
                           000094   357 _TMR3L	=	0x0094
                           000095   358 _TMR3H	=	0x0095
                           009796   359 _IDA0	=	0x9796
                           000096   360 _IDA0L	=	0x0096
                           000097   361 _IDA0H	=	0x0097
                           000098   362 _SCON0	=	0x0098
                           000099   363 _SBUF0	=	0x0099
                           00009A   364 _CPT1CN	=	0x009a
                           00009B   365 _CPT0CN	=	0x009b
                           00009C   366 _CPT1MD	=	0x009c
                           00009D   367 _CPT0MD	=	0x009d
                           00009E   368 _CPT1MX	=	0x009e
                           00009F   369 _CPT0MX	=	0x009f
                           0000A0   370 _P2	=	0x00a0
                           0000A1   371 _SPI0CFG	=	0x00a1
                           0000A2   372 _SPI0CKR	=	0x00a2
                           0000A3   373 _SPI0DAT	=	0x00a3
                           0000A7   374 _SFRPAGE	=	0x00a7
                           0000A8   375 _IE	=	0x00a8
                           0000AA   376 _EMI0CN	=	0x00aa
                           0000AA   377 __XPAGE	=	0x00aa
                           0000B0   378 _P3	=	0x00b0
                           0000B5   379 _P4	=	0x00b5
                           0000B8   380 _IP	=	0x00b8
                           0000B9   381 _IDA0CN	=	0x00b9
                           0000BA   382 _AMX0N	=	0x00ba
                           0000BB   383 _AMX0P	=	0x00bb
                           0000BC   384 _ADC0CF	=	0x00bc
                           00BEBD   385 _ADC0	=	0xbebd
                           0000BD   386 _ADC0L	=	0x00bd
                           0000BE   387 _ADC0H	=	0x00be
                           0000C0   388 _SMB0CN	=	0x00c0
                           0000C1   389 _SMB0CF	=	0x00c1
                           0000C2   390 _SMB0DAT	=	0x00c2
                           00C4C3   391 _ADC0GT	=	0xc4c3
                           0000C3   392 _ADC0GTL	=	0x00c3
                           0000C4   393 _ADC0GTH	=	0x00c4
                           00C6C5   394 _ADC0LT	=	0xc6c5
                           0000C5   395 _ADC0LTL	=	0x00c5
                           0000C6   396 _ADC0LTH	=	0x00c6
                           0000C8   397 _TMR2CN	=	0x00c8
                           00CBCA   398 _TMR2RL	=	0xcbca
                           0000CA   399 _TMR2RLL	=	0x00ca
                           0000CB   400 _TMR2RLH	=	0x00cb
                           00CDCC   401 _TMR2	=	0xcdcc
                           0000CC   402 _TMR2L	=	0x00cc
                           0000CD   403 _TMR2H	=	0x00cd
                           0000D0   404 _PSW	=	0x00d0
                           0000D1   405 _REF0CN	=	0x00d1
                           0000D8   406 _PCA0CN	=	0x00d8
                           0000D9   407 _PCA0MD	=	0x00d9
                           0000DA   408 _PCA0CPM0	=	0x00da
                           0000DB   409 _PCA0CPM1	=	0x00db
                           0000DC   410 _PCA0CPM2	=	0x00dc
                           0000DD   411 _PCA0CPM3	=	0x00dd
                           0000DE   412 _PCA0CPM4	=	0x00de
                           0000DF   413 _PCA0CPM5	=	0x00df
                           0000E0   414 _ACC	=	0x00e0
                           0000E4   415 _IT01CF	=	0x00e4
                           0000E6   416 _EIE1	=	0x00e6
                           0000E7   417 _EIE2	=	0x00e7
                           0000E8   418 _ADC0CN	=	0x00e8
                           00EAE9   419 _PCA0CP1	=	0xeae9
                           0000E9   420 _PCA0CPL1	=	0x00e9
                           0000EA   421 _PCA0CPH1	=	0x00ea
                           00ECEB   422 _PCA0CP2	=	0xeceb
                           0000EB   423 _PCA0CPL2	=	0x00eb
                           0000EC   424 _PCA0CPH2	=	0x00ec
                           00EEED   425 _PCA0CP3	=	0xeeed
                           0000ED   426 _PCA0CPL3	=	0x00ed
                           0000EE   427 _PCA0CPH3	=	0x00ee
                           0000EF   428 _RSTSRC	=	0x00ef
                           0000F0   429 _B	=	0x00f0
                           00F6F5   430 _PCA0CP5	=	0xf6f5
                           0000F5   431 _PCA0CPL5	=	0x00f5
                           0000F6   432 _PCA0CPH5	=	0x00f6
                           0000F8   433 _SPI0CN	=	0x00f8
                           00FAF9   434 _PCA0	=	0xfaf9
                           0000F9   435 _PCA0L	=	0x00f9
                           0000FA   436 _PCA0H	=	0x00fa
                           00FCFB   437 _PCA0CP0	=	0xfcfb
                           0000FB   438 _PCA0CPL0	=	0x00fb
                           0000FC   439 _PCA0CPH0	=	0x00fc
                           00FEFD   440 _PCA0CP4	=	0xfefd
                           0000FD   441 _PCA0CPL4	=	0x00fd
                           0000FE   442 _PCA0CPH4	=	0x00fe
                           0000FF   443 _VDM0CN	=	0x00ff
                           00008F   444 _PSCTL	=	0x008f
                           00A5A4   445 _MAC0A	=	0xa5a4
                           0000A4   446 _MAC0AL	=	0x00a4
                           0000A5   447 _MAC0AH	=	0x00a5
                           00AFAE   448 _MAC0RND	=	0xafae
                           0000AE   449 _MAC0RNDL	=	0x00ae
                           0000AF   450 _MAC0RNDH	=	0x00af
                           0000B1   451 _P2MAT	=	0x00b1
                           0000B2   452 _P2MASK	=	0x00b2
                           0000B6   453 _FLSCL	=	0x00b6
                           0000B7   454 _FLKEY	=	0x00b7
                           0000CF   455 _MAC0STA	=	0x00cf
                           D5D4D3D2   456 _MAC0ACC	=	0xd5d4d3d2
                           0000D2   457 _MAC0ACC0	=	0x00d2
                           0000D3   458 _MAC0ACC1	=	0x00d3
                           0000D4   459 _MAC0ACC2	=	0x00d4
                           0000D5   460 _MAC0ACC3	=	0x00d5
                           0000D6   461 _MAC0OVR	=	0x00d6
                           0000D7   462 _MAC0CF	=	0x00d7
                           0000E1   463 _P1MAT	=	0x00e1
                           0000E2   464 _P1MASK	=	0x00e2
                           0000F1   465 _MAC0BL	=	0x00f1
                           0000F2   466 _MAC0BH	=	0x00f2
                           0000F3   467 _P0MAT	=	0x00f3
                           0000F4   468 _P0MASK	=	0x00f4
                           000084   469 _CCH0CN	=	0x0084
                           00008F   470 _CLKSEL	=	0x008f
                           0000A4   471 _P0MDOUT	=	0x00a4
                           0000A5   472 _P1MDOUT	=	0x00a5
                           0000A6   473 _P2MDOUT	=	0x00a6
                           0000A9   474 _PLL0DIV	=	0x00a9
                           0000AC   475 _FLSTAT	=	0x00ac
                           0000AD   476 _OSCLCN	=	0x00ad
                           0000AE   477 _P4MDOUT	=	0x00ae
                           0000AF   478 _P3MDOUT	=	0x00af
                           0000B1   479 _PLL0MUL	=	0x00b1
                           0000B2   480 _PLL0FLT	=	0x00b2
                           0000B3   481 _PLL0CN	=	0x00b3
                           0000B6   482 _OSCXCN	=	0x00b6
                           0000B7   483 _OSCICN	=	0x00b7
                           0000BF   484 _OSCICL	=	0x00bf
                           0000C7   485 _EMI0CF	=	0x00c7
                           0000C9   486 _CCH0TN	=	0x00c9
                           0000CE   487 _EIP1	=	0x00ce
                           0000CF   488 _EIP2	=	0x00cf
                           0000D2   489 _CCH0LC	=	0x00d2
                           0000D3   490 _CCH0MA	=	0x00d3
                           0000D4   491 _P0SKIP	=	0x00d4
                           0000D5   492 _P1SKIP	=	0x00d5
                           0000D6   493 _P2SKIP	=	0x00d6
                           0000D7   494 _P3SKIP	=	0x00d7
                           0000E1   495 _XBR0	=	0x00e1
                           0000E2   496 _XBR1	=	0x00e2
                           0000E5   497 _SFR0CN	=	0x00e5
                           0000F1   498 _P0MDIN	=	0x00f1
                           0000F2   499 _P1MDIN	=	0x00f2
                           0000F3   500 _P2MDIN	=	0x00f3
                           0000F4   501 _P3MDIN	=	0x00f4
                           0000F7   502 _EMI0TC	=	0x00f7
                                    503 ;--------------------------------------------------------
                                    504 ; special function bits
                                    505 ;--------------------------------------------------------
                                    506 	.area RSEG    (ABS,DATA)
      000000                        507 	.org 0x0000
                           000080   508 _P0_0	=	0x0080
                           000081   509 _P0_1	=	0x0081
                           000082   510 _P0_2	=	0x0082
                           000083   511 _P0_3	=	0x0083
                           000084   512 _P0_4	=	0x0084
                           000085   513 _P0_5	=	0x0085
                           000086   514 _P0_6	=	0x0086
                           000087   515 _P0_7	=	0x0087
                           000088   516 _IT0	=	0x0088
                           000089   517 _IE0	=	0x0089
                           00008A   518 _IT1	=	0x008a
                           00008B   519 _IE1	=	0x008b
                           00008C   520 _TR0	=	0x008c
                           00008D   521 _TF0	=	0x008d
                           00008E   522 _TR1	=	0x008e
                           00008F   523 _TF1	=	0x008f
                           000090   524 _P1_0	=	0x0090
                           000091   525 _P1_1	=	0x0091
                           000092   526 _P1_2	=	0x0092
                           000093   527 _P1_3	=	0x0093
                           000094   528 _P1_4	=	0x0094
                           000095   529 _P1_5	=	0x0095
                           000096   530 _P1_6	=	0x0096
                           000097   531 _P1_7	=	0x0097
                           000098   532 _RI0	=	0x0098
                           000099   533 _TI0	=	0x0099
                           00009A   534 _RB80	=	0x009a
                           00009B   535 _TB80	=	0x009b
                           00009C   536 _REN0	=	0x009c
                           00009D   537 _MCE0	=	0x009d
                           00009F   538 _S0MODE	=	0x009f
                           0000A0   539 _P2_0	=	0x00a0
                           0000A1   540 _P2_1	=	0x00a1
                           0000A2   541 _P2_2	=	0x00a2
                           0000A3   542 _P2_3	=	0x00a3
                           0000A4   543 _P2_4	=	0x00a4
                           0000A5   544 _P2_5	=	0x00a5
                           0000A6   545 _P2_6	=	0x00a6
                           0000A7   546 _P2_7	=	0x00a7
                           0000A8   547 _EX0	=	0x00a8
                           0000A9   548 _ET0	=	0x00a9
                           0000AA   549 _EX1	=	0x00aa
                           0000AB   550 _ET1	=	0x00ab
                           0000AC   551 _ES0	=	0x00ac
                           0000AD   552 _ET2	=	0x00ad
                           0000AE   553 _ESPI0	=	0x00ae
                           0000AF   554 _EA	=	0x00af
                           0000B0   555 _P3_0	=	0x00b0
                           0000B1   556 _P3_1	=	0x00b1
                           0000B2   557 _P3_2	=	0x00b2
                           0000B3   558 _P3_3	=	0x00b3
                           0000B4   559 _P3_4	=	0x00b4
                           0000B5   560 _P3_5	=	0x00b5
                           0000B6   561 _P3_6	=	0x00b6
                           0000B7   562 _P3_7	=	0x00b7
                           0000B8   563 _PX0	=	0x00b8
                           0000B9   564 _PT0	=	0x00b9
                           0000BA   565 _PX1	=	0x00ba
                           0000BB   566 _PT1	=	0x00bb
                           0000BC   567 _PS0	=	0x00bc
                           0000BD   568 _PT2	=	0x00bd
                           0000BE   569 _PSPI0	=	0x00be
                           0000C0   570 _SI	=	0x00c0
                           0000C1   571 _ACK	=	0x00c1
                           0000C2   572 _ARBLOST	=	0x00c2
                           0000C3   573 _ACKRQ	=	0x00c3
                           0000C4   574 _STO	=	0x00c4
                           0000C5   575 _STA	=	0x00c5
                           0000C6   576 _TXMODE	=	0x00c6
                           0000C7   577 _MASTER	=	0x00c7
                           0000C8   578 _T2XCLK	=	0x00c8
                           0000CA   579 _TR2	=	0x00ca
                           0000CB   580 _T2SPLIT	=	0x00cb
                           0000CC   581 _TF2CEN	=	0x00cc
                           0000CD   582 _TF2LEN	=	0x00cd
                           0000CE   583 _TF2L	=	0x00ce
                           0000CF   584 _TF2H	=	0x00cf
                           0000D0   585 _P	=	0x00d0
                           0000D1   586 _F1	=	0x00d1
                           0000D2   587 _OV	=	0x00d2
                           0000D3   588 _RS0	=	0x00d3
                           0000D4   589 _RS1	=	0x00d4
                           0000D5   590 _F0	=	0x00d5
                           0000D6   591 _AC	=	0x00d6
                           0000D7   592 _CY	=	0x00d7
                           0000D8   593 _CCF0	=	0x00d8
                           0000D9   594 _CCF1	=	0x00d9
                           0000DA   595 _CCF2	=	0x00da
                           0000DB   596 _CCF3	=	0x00db
                           0000DC   597 _CCF4	=	0x00dc
                           0000DD   598 _CCF5	=	0x00dd
                           0000DE   599 _CR	=	0x00de
                           0000DF   600 _CF	=	0x00df
                           0000E8   601 _AD0CM0	=	0x00e8
                           0000E9   602 _AD0CM1	=	0x00e9
                           0000EA   603 _AD0CM2	=	0x00ea
                           0000EB   604 _AD0WINT	=	0x00eb
                           0000EC   605 _AD0BUSY	=	0x00ec
                           0000ED   606 _AD0INT	=	0x00ed
                           0000EE   607 _AD0TM	=	0x00ee
                           0000EF   608 _AD0EN	=	0x00ef
                           0000F8   609 _SPIEN	=	0x00f8
                           0000F9   610 _TXBMT	=	0x00f9
                           0000FA   611 _NSSMD0	=	0x00fa
                           0000FB   612 _NSSMD1	=	0x00fb
                           0000FC   613 _RXOVRN	=	0x00fc
                           0000FD   614 _MODF	=	0x00fd
                           0000FE   615 _WCOL	=	0x00fe
                           0000FF   616 _SPIF	=	0x00ff
                                    617 ;--------------------------------------------------------
                                    618 ; overlayable register banks
                                    619 ;--------------------------------------------------------
                                    620 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        621 	.ds 8
                                    622 ;--------------------------------------------------------
                                    623 ; internal ram data
                                    624 ;--------------------------------------------------------
                                    625 	.area DSEG    (DATA)
      000008                        626 _g_delta_pos::
      000008                        627 	.ds 2
      00000A                        628 _g_cursor::
      00000A                        629 	.ds 2
      00000C                        630 _g_parts_count::
      00000C                        631 	.ds 2
      00000E                        632 _g_cur_time_for_word::
      00000E                        633 	.ds 2
      000010                        634 _g_delta_time_for_word::
      000010                        635 	.ds 2
      000012                        636 _g_word_size::
      000012                        637 	.ds 2
                                    638 ;--------------------------------------------------------
                                    639 ; overlayable items in internal ram
                                    640 ;--------------------------------------------------------
                                    641 	.area	OSEG    (OVR,DATA)
                                    642 ;--------------------------------------------------------
                                    643 ; Stack segment in internal ram
                                    644 ;--------------------------------------------------------
                                    645 	.area	SSEG
      000022                        646 __start__stack:
      000022                        647 	.ds	1
                                    648 
                                    649 ;--------------------------------------------------------
                                    650 ; indirectly addressable internal ram data
                                    651 ;--------------------------------------------------------
                                    652 	.area ISEG    (DATA)
                                    653 ;--------------------------------------------------------
                                    654 ; absolute internal ram data
                                    655 ;--------------------------------------------------------
                                    656 	.area IABS    (ABS,DATA)
                                    657 	.area IABS    (ABS,DATA)
                                    658 ;--------------------------------------------------------
                                    659 ; bit data
                                    660 ;--------------------------------------------------------
                                    661 	.area BSEG    (BIT)
                                    662 ;--------------------------------------------------------
                                    663 ; paged external ram data
                                    664 ;--------------------------------------------------------
                                    665 	.area PSEG    (PAG,XDATA)
                                    666 ;--------------------------------------------------------
                                    667 ; external ram data
                                    668 ;--------------------------------------------------------
                                    669 	.area XSEG    (XDATA)
                                    670 ;--------------------------------------------------------
                                    671 ; absolute external ram data
                                    672 ;--------------------------------------------------------
                                    673 	.area XABS    (ABS,XDATA)
                                    674 ;--------------------------------------------------------
                                    675 ; external initialized ram data
                                    676 ;--------------------------------------------------------
                                    677 	.area XISEG   (XDATA)
                                    678 	.area HOME    (CODE)
                                    679 	.area GSINIT0 (CODE)
                                    680 	.area GSINIT1 (CODE)
                                    681 	.area GSINIT2 (CODE)
                                    682 	.area GSINIT3 (CODE)
                                    683 	.area GSINIT4 (CODE)
                                    684 	.area GSINIT5 (CODE)
                                    685 	.area GSINIT  (CODE)
                                    686 	.area GSFINAL (CODE)
                                    687 	.area CSEG    (CODE)
                                    688 ;--------------------------------------------------------
                                    689 ; interrupt vector
                                    690 ;--------------------------------------------------------
                                    691 	.area HOME    (CODE)
      000000                        692 __interrupt_vect:
      000000 02 00 06         [24]  693 	ljmp	__sdcc_gsinit_startup
                                    694 ;--------------------------------------------------------
                                    695 ; global & static initialisations
                                    696 ;--------------------------------------------------------
                                    697 	.area HOME    (CODE)
                                    698 	.area GSINIT  (CODE)
                                    699 	.area GSFINAL (CODE)
                                    700 	.area GSINIT  (CODE)
                                    701 	.globl __sdcc_gsinit_startup
                                    702 	.globl __sdcc_program_startup
                                    703 	.globl __start__stack
                                    704 	.globl __mcs51_genXINIT
                                    705 	.globl __mcs51_genXRAMCLEAR
                                    706 	.globl __mcs51_genRAMCLEAR
                                    707 ;	main.c:35: int g_delta_pos = 0;
      00005F E4               [12]  708 	clr	a
      000060 F5 08            [12]  709 	mov	_g_delta_pos,a
      000062 F5 09            [12]  710 	mov	(_g_delta_pos + 1),a
                                    711 ;	main.c:36: int g_cursor = 0;
      000064 F5 0A            [12]  712 	mov	_g_cursor,a
      000066 F5 0B            [12]  713 	mov	(_g_cursor + 1),a
                                    714 ;	main.c:37: int g_parts_count = 9;
      000068 75 0C 09         [24]  715 	mov	_g_parts_count,#0x09
                                    716 ;	1-genFromRTrack replaced	mov	(_g_parts_count + 1),#0x00
      00006B F5 0D            [12]  717 	mov	(_g_parts_count + 1),a
                                    718 ;	main.c:38: unsigned int g_cur_time_for_word = 0;
      00006D F5 0E            [12]  719 	mov	_g_cur_time_for_word,a
      00006F F5 0F            [12]  720 	mov	(_g_cur_time_for_word + 1),a
                                    721 ;	main.c:39: unsigned int g_delta_time_for_word = 100;
      000071 75 10 64         [24]  722 	mov	_g_delta_time_for_word,#0x64
                                    723 ;	1-genFromRTrack replaced	mov	(_g_delta_time_for_word + 1),#0x00
      000074 F5 11            [12]  724 	mov	(_g_delta_time_for_word + 1),a
                                    725 ;	main.c:40: int g_word_size = 0;
      000076 F5 12            [12]  726 	mov	_g_word_size,a
      000078 F5 13            [12]  727 	mov	(_g_word_size + 1),a
                                    728 	.area GSFINAL (CODE)
      00007A 02 00 03         [24]  729 	ljmp	__sdcc_program_startup
                                    730 ;--------------------------------------------------------
                                    731 ; Home
                                    732 ;--------------------------------------------------------
                                    733 	.area HOME    (CODE)
                                    734 	.area HOME    (CODE)
      000003                        735 __sdcc_program_startup:
      000003 02 00 7D         [24]  736 	ljmp	_main
                                    737 ;	return from main will return to caller
                                    738 ;--------------------------------------------------------
                                    739 ; code
                                    740 ;--------------------------------------------------------
                                    741 	.area CSEG    (CODE)
                                    742 ;------------------------------------------------------------
                                    743 ;Allocation info for local variables in function 'main'
                                    744 ;------------------------------------------------------------
                                    745 ;	main.c:48: void main (void) 
                                    746 ;	-----------------------------------------
                                    747 ;	 function main
                                    748 ;	-----------------------------------------
      00007D                        749 _main:
                           000007   750 	ar7 = 0x07
                           000006   751 	ar6 = 0x06
                           000005   752 	ar5 = 0x05
                           000004   753 	ar4 = 0x04
                           000003   754 	ar3 = 0x03
                           000002   755 	ar2 = 0x02
                           000001   756 	ar1 = 0x01
                           000000   757 	ar0 = 0x00
                                    758 ;	main.c:52: PCA0MD &= ~0x40;                    // WDTE = 0 (clear watchdog timer
      00007D 53 D9 BF         [24]  759 	anl	_PCA0MD,#0xbf
                                    760 ;	main.c:54: PORT_Init ();
      000080 12 00 BD         [24]  761 	lcall	_PORT_Init
                                    762 ;	main.c:55: Init_Device();
      000083 12 01 4E         [24]  763 	lcall	_Init_Device
                                    764 ;	main.c:57: P2 = 0x00;
      000086 75 A0 00         [24]  765 	mov	_P2,#0x00
                                    766 ;	main.c:58: CLR = 0;
                                    767 ;	assignBit
      000089 C2 97            [12]  768 	clr	_P1_7
                                    769 ;	main.c:59: g_cursor = 0;
      00008B E4               [12]  770 	clr	a
      00008C F5 0A            [12]  771 	mov	_g_cursor,a
      00008E F5 0B            [12]  772 	mov	(_g_cursor + 1),a
                                    773 ;	main.c:61: g_word_size = get_word_length(g_parts_count, word_parts);
      000090 75 14 B5         [24]  774 	mov	_get_word_length_PARM_2,#_word_parts
      000093 75 15 03         [24]  775 	mov	(_get_word_length_PARM_2 + 1),#(_word_parts >> 8)
      000096 75 16 80         [24]  776 	mov	(_get_word_length_PARM_2 + 2),#0x80
      000099 85 0C 82         [24]  777 	mov	dpl,_g_parts_count
      00009C 85 0D 83         [24]  778 	mov	dph,(_g_parts_count + 1)
      00009F 12 02 14         [24]  779 	lcall	_get_word_length
      0000A2 85 82 12         [24]  780 	mov	_g_word_size,dpl
      0000A5 85 83 13         [24]  781 	mov	(_g_word_size + 1),dph
                                    782 ;	main.c:63: if (g_word_size < 47) {
      0000A8 C3               [12]  783 	clr	c
      0000A9 E5 12            [12]  784 	mov	a,_g_word_size
      0000AB 94 2F            [12]  785 	subb	a,#0x2f
      0000AD E5 13            [12]  786 	mov	a,(_g_word_size + 1)
      0000AF 64 80            [12]  787 	xrl	a,#0x80
      0000B1 94 80            [12]  788 	subb	a,#0x80
      0000B3 50 06            [24]  789 	jnc	00104$
                                    790 ;	main.c:64: g_word_size = 47; 
      0000B5 75 12 2F         [24]  791 	mov	_g_word_size,#0x2f
      0000B8 75 13 00         [24]  792 	mov	(_g_word_size + 1),#0x00
                                    793 ;	main.c:67: while (1) {
      0000BB                        794 00104$:
                                    795 ;	main.c:70: }
      0000BB 80 FE            [24]  796 	sjmp	00104$
                                    797 ;------------------------------------------------------------
                                    798 ;Allocation info for local variables in function 'PORT_Init'
                                    799 ;------------------------------------------------------------
                                    800 ;SFRPAGE_save              Allocated to registers r7 
                                    801 ;SFRPAGE_for_XBR1          Allocated to registers 
                                    802 ;------------------------------------------------------------
                                    803 ;	main.c:73: void PORT_Init (void)
                                    804 ;	-----------------------------------------
                                    805 ;	 function PORT_Init
                                    806 ;	-----------------------------------------
      0000BD                        807 _PORT_Init:
                                    808 ;	main.c:75: unsigned char SFRPAGE_save = SFRPAGE; // Save the current SFRPAGE
      0000BD AF A7            [24]  809 	mov	r7,_SFRPAGE
                                    810 ;	main.c:79: SFRPAGE = SFRPAGE_for_XBR1;              // Switch to the necessary SFRPAGE
      0000BF 75 A7 0F         [24]  811 	mov	_SFRPAGE,#0x0f
                                    812 ;	main.c:81: XBR1    = 0x40;                     // Enable crossbar and weak pull-ups
      0000C2 75 E2 40         [24]  813 	mov	_XBR1,#0x40
                                    814 ;	main.c:83: SFRPAGE = SFRPAGE_save;             // Restore the SFRPAGE
      0000C5 8F A7            [24]  815 	mov	_SFRPAGE,r7
                                    816 ;	main.c:84: }
      0000C7 22               [24]  817 	ret
                                    818 ;------------------------------------------------------------
                                    819 ;Allocation info for local variables in function 'Timer_ISR'
                                    820 ;------------------------------------------------------------
                                    821 ;	main.c:87: void Timer_ISR(void) //interrupt 1
                                    822 ;	-----------------------------------------
                                    823 ;	 function Timer_ISR
                                    824 ;	-----------------------------------------
      0000C8                        825 _Timer_ISR:
                                    826 ;	main.c:89: P2 = ~(get_word_value((g_cursor-g_delta_pos), g_word_size, g_parts_count, word_parts));
      0000C8 E5 0A            [12]  827 	mov	a,_g_cursor
      0000CA C3               [12]  828 	clr	c
      0000CB 95 08            [12]  829 	subb	a,_g_delta_pos
      0000CD F5 82            [12]  830 	mov	dpl,a
      0000CF E5 0B            [12]  831 	mov	a,(_g_cursor + 1)
      0000D1 95 09            [12]  832 	subb	a,(_g_delta_pos + 1)
      0000D3 F5 83            [12]  833 	mov	dph,a
      0000D5 75 18 B5         [24]  834 	mov	_get_word_value_PARM_4,#_word_parts
      0000D8 75 19 03         [24]  835 	mov	(_get_word_value_PARM_4 + 1),#(_word_parts >> 8)
      0000DB 75 1A 80         [24]  836 	mov	(_get_word_value_PARM_4 + 2),#0x80
      0000DE 85 12 14         [24]  837 	mov	_get_word_value_PARM_2,_g_word_size
      0000E1 85 13 15         [24]  838 	mov	(_get_word_value_PARM_2 + 1),(_g_word_size + 1)
      0000E4 85 0C 16         [24]  839 	mov	_get_word_value_PARM_3,_g_parts_count
      0000E7 85 0D 17         [24]  840 	mov	(_get_word_value_PARM_3 + 1),(_g_parts_count + 1)
      0000EA 12 01 54         [24]  841 	lcall	_get_word_value
      0000ED AE 82            [24]  842 	mov	r6,dpl
      0000EF EE               [12]  843 	mov	a,r6
      0000F0 F4               [12]  844 	cpl	a
      0000F1 F5 A0            [12]  845 	mov	_P2,a
                                    846 ;	main.c:92: CLK = 0;
                                    847 ;	assignBit
      0000F3 C2 A7            [12]  848 	clr	_P2_7
                                    849 ;	main.c:93: CLK = 1;
                                    850 ;	assignBit
      0000F5 D2 A7            [12]  851 	setb	_P2_7
                                    852 ;	main.c:95: if (g_cursor < 48) {
      0000F7 C3               [12]  853 	clr	c
      0000F8 E5 0A            [12]  854 	mov	a,_g_cursor
      0000FA 94 30            [12]  855 	subb	a,#0x30
      0000FC E5 0B            [12]  856 	mov	a,(_g_cursor + 1)
      0000FE 64 80            [12]  857 	xrl	a,#0x80
      000100 94 80            [12]  858 	subb	a,#0x80
      000102 50 0A            [24]  859 	jnc	00102$
                                    860 ;	main.c:96: g_cursor++; 
      000104 05 0A            [12]  861 	inc	_g_cursor
      000106 E4               [12]  862 	clr	a
      000107 B5 0A 09         [24]  863 	cjne	a,_g_cursor,00103$
      00010A 05 0B            [12]  864 	inc	(_g_cursor + 1)
      00010C 80 05            [24]  865 	sjmp	00103$
      00010E                        866 00102$:
                                    867 ;	main.c:98: g_cursor = 0; 
      00010E E4               [12]  868 	clr	a
      00010F F5 0A            [12]  869 	mov	_g_cursor,a
      000111 F5 0B            [12]  870 	mov	(_g_cursor + 1),a
      000113                        871 00103$:
                                    872 ;	main.c:102: if (g_cur_time_for_word == g_delta_time_for_word)
      000113 E5 10            [12]  873 	mov	a,_g_delta_time_for_word
      000115 B5 0E 0A         [24]  874 	cjne	a,_g_cur_time_for_word,00105$
      000118 E5 11            [12]  875 	mov	a,(_g_delta_time_for_word + 1)
      00011A B5 0F 05         [24]  876 	cjne	a,(_g_cur_time_for_word + 1),00105$
                                    877 ;	main.c:103: g_cur_time_for_word = 0;
      00011D E4               [12]  878 	clr	a
      00011E F5 0E            [12]  879 	mov	_g_cur_time_for_word,a
      000120 F5 0F            [12]  880 	mov	(_g_cur_time_for_word + 1),a
      000122                        881 00105$:
                                    882 ;	main.c:104: g_delta_pos++;
      000122 05 08            [12]  883 	inc	_g_delta_pos
      000124 E4               [12]  884 	clr	a
      000125 B5 08 02         [24]  885 	cjne	a,_g_delta_pos,00126$
      000128 05 09            [12]  886 	inc	(_g_delta_pos + 1)
      00012A                        887 00126$:
                                    888 ;	main.c:106: if (g_delta_pos == g_word_size){
      00012A E5 12            [12]  889 	mov	a,_g_word_size
      00012C B5 08 0A         [24]  890 	cjne	a,_g_delta_pos,00107$
      00012F E5 13            [12]  891 	mov	a,(_g_word_size + 1)
      000131 B5 09 05         [24]  892 	cjne	a,(_g_delta_pos + 1),00107$
                                    893 ;	main.c:107: g_delta_pos = 0;
      000134 E4               [12]  894 	clr	a
      000135 F5 08            [12]  895 	mov	_g_delta_pos,a
      000137 F5 09            [12]  896 	mov	(_g_delta_pos + 1),a
      000139                        897 00107$:
                                    898 ;	main.c:110: TL1       = 0x00; 
      000139 75 8B 00         [24]  899 	mov	_TL1,#0x00
                                    900 ;	main.c:111: TH1       = 0xC0;
      00013C 75 8D C0         [24]  901 	mov	_TH1,#0xc0
                                    902 ;	main.c:113: g_cur_time_for_word++;
      00013F 05 0E            [12]  903 	inc	_g_cur_time_for_word
      000141 E4               [12]  904 	clr	a
      000142 B5 0E 02         [24]  905 	cjne	a,_g_cur_time_for_word,00129$
      000145 05 0F            [12]  906 	inc	(_g_cur_time_for_word + 1)
      000147                        907 00129$:
                                    908 ;	main.c:115: TL0       = 0xee; 
      000147 75 8A EE         [24]  909 	mov	_TL0,#0xee
                                    910 ;	main.c:116: TH0       = 0xff; 
      00014A 75 8C FF         [24]  911 	mov	_TH0,#0xff
                                    912 ;	main.c:117: }
      00014D 22               [24]  913 	ret
                                    914 ;------------------------------------------------------------
                                    915 ;Allocation info for local variables in function 'Init_Device'
                                    916 ;------------------------------------------------------------
                                    917 ;	main.c:122: void Init_Device(void)
                                    918 ;	-----------------------------------------
                                    919 ;	 function Init_Device
                                    920 ;	-----------------------------------------
      00014E                        921 _Init_Device:
                                    922 ;	main.c:124: Timers_Init();
      00014E 12 02 77         [24]  923 	lcall	_Timers_Init
                                    924 ;	main.c:125: Interrupts_Init();     
                                    925 ;	main.c:126: }
      000151 02 02 87         [24]  926 	ljmp	_Interrupts_Init
                                    927 	.area CSEG    (CODE)
                                    928 	.area CONST   (CODE)
      0002D8                        929 _font_A:
      0002D8 8E                     930 	.db #0x8e	; 142
      0002D9 12                     931 	.db #0x12	; 18
      0002DA 11                     932 	.db #0x11	; 17
      0002DB 11                     933 	.db #0x11	; 17
      0002DC 11                     934 	.db #0x11	; 17
      0002DD 12                     935 	.db #0x12	; 18
      0002DE 8E                     936 	.db #0x8e	; 142
      0002DF 00                     937 	.db #0x00	; 0
      0002E0                        938 _font_B:
      0002E0 8F                     939 	.db #0x8f	; 143
      0002E1 49                     940 	.db #0x49	; 73	'I'
      0002E2 49                     941 	.db #0x49	; 73	'I'
      0002E3 49                     942 	.db #0x49	; 73	'I'
      0002E4 49                     943 	.db #0x49	; 73	'I'
      0002E5 49                     944 	.db #0x49	; 73	'I'
      0002E6 36                     945 	.db #0x36	; 54	'6'
      0002E7 00                     946 	.db #0x00	; 0
      0002E8                        947 _font_C:
      0002E8 1C                     948 	.db #0x1c	; 28
      0002E9 22                     949 	.db #0x22	; 34
      0002EA 41                     950 	.db #0x41	; 65	'A'
      0002EB 41                     951 	.db #0x41	; 65	'A'
      0002EC 41                     952 	.db #0x41	; 65	'A'
      0002ED 41                     953 	.db #0x41	; 65	'A'
      0002EE 22                     954 	.db #0x22	; 34
      0002EF 00                     955 	.db #0x00	; 0
      0002F0                        956 _font_D:
      0002F0 7F                     957 	.db #0x7f	; 127
      0002F1 41                     958 	.db #0x41	; 65	'A'
      0002F2 41                     959 	.db #0x41	; 65	'A'
      0002F3 41                     960 	.db #0x41	; 65	'A'
      0002F4 41                     961 	.db #0x41	; 65	'A'
      0002F5 22                     962 	.db #0x22	; 34
      0002F6 1C                     963 	.db #0x1c	; 28
      0002F7 00                     964 	.db #0x00	; 0
      0002F8                        965 _font_E:
      0002F8 7F                     966 	.db #0x7f	; 127
      0002F9 49                     967 	.db #0x49	; 73	'I'
      0002FA 49                     968 	.db #0x49	; 73	'I'
      0002FB 49                     969 	.db #0x49	; 73	'I'
      0002FC 49                     970 	.db #0x49	; 73	'I'
      0002FD 49                     971 	.db #0x49	; 73	'I'
      0002FE 41                     972 	.db #0x41	; 65	'A'
      0002FF 00                     973 	.db #0x00	; 0
      000300                        974 _font_F:
      000300 FF                     975 	.db #0xff	; 255
      000301 90                     976 	.db #0x90	; 144
      000302 90                     977 	.db #0x90	; 144
      000303 90                     978 	.db #0x90	; 144
      000304 90                     979 	.db #0x90	; 144
      000305 90                     980 	.db #0x90	; 144
      000306 80                     981 	.db #0x80	; 128
      000307 00                     982 	.db #0x00	; 0
      000308                        983 _font_G:
      000308 78                     984 	.db #0x78	; 120	'x'
      000309 84                     985 	.db #0x84	; 132
      00030A 02                     986 	.db #0x02	; 2
      00030B 12                     987 	.db #0x12	; 18
      00030C 12                     988 	.db #0x12	; 18
      00030D 12                     989 	.db #0x12	; 18
      00030E 9C                     990 	.db #0x9c	; 156
      00030F 00                     991 	.db #0x00	; 0
      000310                        992 _font_H:
      000310 7F                     993 	.db #0x7f	; 127
      000311 08                     994 	.db #0x08	; 8
      000312 08                     995 	.db #0x08	; 8
      000313 08                     996 	.db #0x08	; 8
      000314 08                     997 	.db #0x08	; 8
      000315 7F                     998 	.db #0x7f	; 127
      000316 00                     999 	.db #0x00	; 0
      000317                       1000 _font_I:
      000317 41                    1001 	.db #0x41	; 65	'A'
      000318 41                    1002 	.db #0x41	; 65	'A'
      000319 41                    1003 	.db #0x41	; 65	'A'
      00031A 7F                    1004 	.db #0x7f	; 127
      00031B 41                    1005 	.db #0x41	; 65	'A'
      00031C 41                    1006 	.db #0x41	; 65	'A'
      00031D 41                    1007 	.db #0x41	; 65	'A'
      00031E 00                    1008 	.db #0x00	; 0
      00031F                       1009 _font_J:
      00031F 20                    1010 	.db #0x20	; 32
      000320 40                    1011 	.db #0x40	; 64
      000321 80                    1012 	.db #0x80	; 128
      000322 80                    1013 	.db #0x80	; 128
      000323 41                    1014 	.db #0x41	; 65	'A'
      000324 3F                    1015 	.db #0x3f	; 63
      000325 01                    1016 	.db #0x01	; 1
      000326 01                    1017 	.db #0x01	; 1
      000327 00                    1018 	.db #0x00	; 0
      000328                       1019 _font_K:
      000328 FF                    1020 	.db #0xff	; 255
      000329 10                    1021 	.db #0x10	; 16
      00032A 10                    1022 	.db #0x10	; 16
      00032B 28                    1023 	.db #0x28	; 40
      00032C 44                    1024 	.db #0x44	; 68	'D'
      00032D 82                    1025 	.db #0x82	; 130
      00032E 81                    1026 	.db #0x81	; 129
      00032F 00                    1027 	.db #0x00	; 0
      000330                       1028 _font_L:
      000330 7F                    1029 	.db #0x7f	; 127
      000331 40                    1030 	.db #0x40	; 64
      000332 40                    1031 	.db #0x40	; 64
      000333 40                    1032 	.db #0x40	; 64
      000334 40                    1033 	.db #0x40	; 64
      000335 40                    1034 	.db #0x40	; 64
      000336 00                    1035 	.db #0x00	; 0
      000337                       1036 _font_M:
      000337 FF                    1037 	.db #0xff	; 255
      000338 02                    1038 	.db #0x02	; 2
      000339 04                    1039 	.db #0x04	; 4
      00033A 08                    1040 	.db #0x08	; 8
      00033B 08                    1041 	.db #0x08	; 8
      00033C 04                    1042 	.db #0x04	; 4
      00033D 02                    1043 	.db #0x02	; 2
      00033E FF                    1044 	.db #0xff	; 255
      00033F 00                    1045 	.db #0x00	; 0
      000340                       1046 _font_N:
      000340 FF                    1047 	.db #0xff	; 255
      000341 02                    1048 	.db #0x02	; 2
      000342 04                    1049 	.db #0x04	; 4
      000343 08                    1050 	.db #0x08	; 8
      000344 10                    1051 	.db #0x10	; 16
      000345 20                    1052 	.db #0x20	; 32
      000346 40                    1053 	.db #0x40	; 64
      000347 FF                    1054 	.db #0xff	; 255
      000348 00                    1055 	.db #0x00	; 0
      000349                       1056 _font_O:
      000349 3C                    1057 	.db #0x3c	; 60
      00034A 42                    1058 	.db #0x42	; 66	'B'
      00034B 81                    1059 	.db #0x81	; 129
      00034C 81                    1060 	.db #0x81	; 129
      00034D 81                    1061 	.db #0x81	; 129
      00034E 81                    1062 	.db #0x81	; 129
      00034F 42                    1063 	.db #0x42	; 66	'B'
      000350 3C                    1064 	.db #0x3c	; 60
      000351 00                    1065 	.db #0x00	; 0
      000352                       1066 _font_P:
      000352 FF                    1067 	.db #0xff	; 255
      000353 09                    1068 	.db #0x09	; 9
      000354 09                    1069 	.db #0x09	; 9
      000355 09                    1070 	.db #0x09	; 9
      000356 09                    1071 	.db #0x09	; 9
      000357 09                    1072 	.db #0x09	; 9
      000358 06                    1073 	.db #0x06	; 6
      000359 00                    1074 	.db #0x00	; 0
      00035A                       1075 _font_Q:
      00035A 3C                    1076 	.db #0x3c	; 60
      00035B 42                    1077 	.db #0x42	; 66	'B'
      00035C 81                    1078 	.db #0x81	; 129
      00035D 81                    1079 	.db #0x81	; 129
      00035E 81                    1080 	.db #0x81	; 129
      00035F A1                    1081 	.db #0xa1	; 161
      000360 42                    1082 	.db #0x42	; 66	'B'
      000361 BC                    1083 	.db #0xbc	; 188
      000362 00                    1084 	.db #0x00	; 0
      000363                       1085 _font_R:
      000363 FF                    1086 	.db #0xff	; 255
      000364 09                    1087 	.db #0x09	; 9
      000365 09                    1088 	.db #0x09	; 9
      000366 19                    1089 	.db #0x19	; 25
      000367 29                    1090 	.db #0x29	; 41
      000368 49                    1091 	.db #0x49	; 73	'I'
      000369 86                    1092 	.db #0x86	; 134
      00036A 00                    1093 	.db #0x00	; 0
      00036B                       1094 _font_S:
      00036B 46                    1095 	.db #0x46	; 70	'F'
      00036C 89                    1096 	.db #0x89	; 137
      00036D 89                    1097 	.db #0x89	; 137
      00036E 89                    1098 	.db #0x89	; 137
      00036F 89                    1099 	.db #0x89	; 137
      000370 89                    1100 	.db #0x89	; 137
      000371 72                    1101 	.db #0x72	; 114	'r'
      000372 00                    1102 	.db #0x00	; 0
      000373                       1103 _font_T:
      000373 01                    1104 	.db #0x01	; 1
      000374 01                    1105 	.db #0x01	; 1
      000375 01                    1106 	.db #0x01	; 1
      000376 FF                    1107 	.db #0xff	; 255
      000377 01                    1108 	.db #0x01	; 1
      000378 01                    1109 	.db #0x01	; 1
      000379 01                    1110 	.db #0x01	; 1
      00037A 01                    1111 	.db #0x01	; 1
      00037B 00                    1112 	.db #0x00	; 0
      00037C                       1113 _font_U:
      00037C 3F                    1114 	.db #0x3f	; 63
      00037D 40                    1115 	.db #0x40	; 64
      00037E 80                    1116 	.db #0x80	; 128
      00037F 80                    1117 	.db #0x80	; 128
      000380 80                    1118 	.db #0x80	; 128
      000381 80                    1119 	.db #0x80	; 128
      000382 40                    1120 	.db #0x40	; 64
      000383 3F                    1121 	.db #0x3f	; 63
      000384 00                    1122 	.db #0x00	; 0
      000385                       1123 _font_V:
      000385 03                    1124 	.db #0x03	; 3
      000386 0C                    1125 	.db #0x0c	; 12
      000387 30                    1126 	.db #0x30	; 48	'0'
      000388 C0                    1127 	.db #0xc0	; 192
      000389 C0                    1128 	.db #0xc0	; 192
      00038A 30                    1129 	.db #0x30	; 48	'0'
      00038B 0C                    1130 	.db #0x0c	; 12
      00038C 03                    1131 	.db #0x03	; 3
      00038D 00                    1132 	.db #0x00	; 0
      00038E                       1133 _font_W:
      00038E FF                    1134 	.db #0xff	; 255
      00038F 20                    1135 	.db #0x20	; 32
      000390 10                    1136 	.db #0x10	; 16
      000391 08                    1137 	.db #0x08	; 8
      000392 08                    1138 	.db #0x08	; 8
      000393 10                    1139 	.db #0x10	; 16
      000394 20                    1140 	.db #0x20	; 32
      000395 FF                    1141 	.db #0xff	; 255
      000396 00                    1142 	.db #0x00	; 0
      000397                       1143 _font_X:
      000397 81                    1144 	.db #0x81	; 129
      000398 42                    1145 	.db #0x42	; 66	'B'
      000399 24                    1146 	.db #0x24	; 36
      00039A 18                    1147 	.db #0x18	; 24
      00039B 18                    1148 	.db #0x18	; 24
      00039C 24                    1149 	.db #0x24	; 36
      00039D 42                    1150 	.db #0x42	; 66	'B'
      00039E 81                    1151 	.db #0x81	; 129
      00039F 00                    1152 	.db #0x00	; 0
      0003A0                       1153 _font_Y:
      0003A0 01                    1154 	.db #0x01	; 1
      0003A1 02                    1155 	.db #0x02	; 2
      0003A2 04                    1156 	.db #0x04	; 4
      0003A3 F8                    1157 	.db #0xf8	; 248
      0003A4 08                    1158 	.db #0x08	; 8
      0003A5 04                    1159 	.db #0x04	; 4
      0003A6 02                    1160 	.db #0x02	; 2
      0003A7 01                    1161 	.db #0x01	; 1
      0003A8 00                    1162 	.db #0x00	; 0
      0003A9                       1163 _font_Z:
      0003A9 81                    1164 	.db #0x81	; 129
      0003AA C1                    1165 	.db #0xc1	; 193
      0003AB A1                    1166 	.db #0xa1	; 161
      0003AC 91                    1167 	.db #0x91	; 145
      0003AD 89                    1168 	.db #0x89	; 137
      0003AE 85                    1169 	.db #0x85	; 133
      0003AF 83                    1170 	.db #0x83	; 131
      0003B0 81                    1171 	.db #0x81	; 129
      0003B1 00                    1172 	.db #0x00	; 0
      0003B2                       1173 _font_space:
      0003B2 00                    1174 	.db #0x00	; 0
      0003B3 00                    1175 	.db #0x00	; 0
      0003B4 00                    1176 	.db #0x00	; 0
      0003B5                       1177 _word_parts:
      0003B5 37 03 80              1178 	.byte _font_M, (_font_M >> 8),#0x80
      0003B8 09 00                 1179 	.byte #0x09, #0x00	;  9
      0003BA 17 03 80              1180 	.byte _font_I, (_font_I >> 8),#0x80
      0003BD 08 00                 1181 	.byte #0x08, #0x00	;  8
      0003BF E8 02 80              1182 	.byte _font_C, (_font_C >> 8),#0x80
      0003C2 08 00                 1183 	.byte #0x08, #0x00	;  8
      0003C4 10 03 80              1184 	.byte _font_H, (_font_H >> 8),#0x80
      0003C7 07 00                 1185 	.byte #0x07, #0x00	;  7
      0003C9 F8 02 80              1186 	.byte _font_E, (_font_E >> 8),#0x80
      0003CC 08 00                 1187 	.byte #0x08, #0x00	;  8
      0003CE 30 03 80              1188 	.byte _font_L, (_font_L >> 8),#0x80
      0003D1 07 00                 1189 	.byte #0x07, #0x00	;  7
      0003D3 30 03 80              1190 	.byte _font_L, (_font_L >> 8),#0x80
      0003D6 07 00                 1191 	.byte #0x07, #0x00	;  7
      0003D8 F8 02 80              1192 	.byte _font_E, (_font_E >> 8),#0x80
      0003DB 08 00                 1193 	.byte #0x08, #0x00	;  8
      0003DD B2 03 80              1194 	.byte _font_space, (_font_space >> 8),#0x80
      0003E0 03 00                 1195 	.byte #0x03, #0x00	;  3
                                   1196 	.area XINIT   (CODE)
                                   1197 	.area CABS    (ABS,CODE)
