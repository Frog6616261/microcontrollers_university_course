                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module timer
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _Interrupts_Init
                                     12 	.globl _Timers_Init
                                     13 	.globl _SPIF
                                     14 	.globl _WCOL
                                     15 	.globl _MODF
                                     16 	.globl _RXOVRN
                                     17 	.globl _NSSMD1
                                     18 	.globl _NSSMD0
                                     19 	.globl _TXBMT
                                     20 	.globl _SPIEN
                                     21 	.globl _AD0EN
                                     22 	.globl _AD0TM
                                     23 	.globl _AD0INT
                                     24 	.globl _AD0BUSY
                                     25 	.globl _AD0WINT
                                     26 	.globl _AD0CM2
                                     27 	.globl _AD0CM1
                                     28 	.globl _AD0CM0
                                     29 	.globl _CF
                                     30 	.globl _CR
                                     31 	.globl _CCF5
                                     32 	.globl _CCF4
                                     33 	.globl _CCF3
                                     34 	.globl _CCF2
                                     35 	.globl _CCF1
                                     36 	.globl _CCF0
                                     37 	.globl _CY
                                     38 	.globl _AC
                                     39 	.globl _F0
                                     40 	.globl _RS1
                                     41 	.globl _RS0
                                     42 	.globl _OV
                                     43 	.globl _F1
                                     44 	.globl _P
                                     45 	.globl _TF2H
                                     46 	.globl _TF2L
                                     47 	.globl _TF2LEN
                                     48 	.globl _TF2CEN
                                     49 	.globl _T2SPLIT
                                     50 	.globl _TR2
                                     51 	.globl _T2XCLK
                                     52 	.globl _MASTER
                                     53 	.globl _TXMODE
                                     54 	.globl _STA
                                     55 	.globl _STO
                                     56 	.globl _ACKRQ
                                     57 	.globl _ARBLOST
                                     58 	.globl _ACK
                                     59 	.globl _SI
                                     60 	.globl _PSPI0
                                     61 	.globl _PT2
                                     62 	.globl _PS0
                                     63 	.globl _PT1
                                     64 	.globl _PX1
                                     65 	.globl _PT0
                                     66 	.globl _PX0
                                     67 	.globl _P3_7
                                     68 	.globl _P3_6
                                     69 	.globl _P3_5
                                     70 	.globl _P3_4
                                     71 	.globl _P3_3
                                     72 	.globl _P3_2
                                     73 	.globl _P3_1
                                     74 	.globl _P3_0
                                     75 	.globl _EA
                                     76 	.globl _ESPI0
                                     77 	.globl _ET2
                                     78 	.globl _ES0
                                     79 	.globl _ET1
                                     80 	.globl _EX1
                                     81 	.globl _ET0
                                     82 	.globl _EX0
                                     83 	.globl _P2_7
                                     84 	.globl _P2_6
                                     85 	.globl _P2_5
                                     86 	.globl _P2_4
                                     87 	.globl _P2_3
                                     88 	.globl _P2_2
                                     89 	.globl _P2_1
                                     90 	.globl _P2_0
                                     91 	.globl _S0MODE
                                     92 	.globl _MCE0
                                     93 	.globl _REN0
                                     94 	.globl _TB80
                                     95 	.globl _RB80
                                     96 	.globl _TI0
                                     97 	.globl _RI0
                                     98 	.globl _P1_7
                                     99 	.globl _P1_6
                                    100 	.globl _P1_5
                                    101 	.globl _P1_4
                                    102 	.globl _P1_3
                                    103 	.globl _P1_2
                                    104 	.globl _P1_1
                                    105 	.globl _P1_0
                                    106 	.globl _TF1
                                    107 	.globl _TR1
                                    108 	.globl _TF0
                                    109 	.globl _TR0
                                    110 	.globl _IE1
                                    111 	.globl _IT1
                                    112 	.globl _IE0
                                    113 	.globl _IT0
                                    114 	.globl _P0_7
                                    115 	.globl _P0_6
                                    116 	.globl _P0_5
                                    117 	.globl _P0_4
                                    118 	.globl _P0_3
                                    119 	.globl _P0_2
                                    120 	.globl _P0_1
                                    121 	.globl _P0_0
                                    122 	.globl _EMI0TC
                                    123 	.globl _P3MDIN
                                    124 	.globl _P2MDIN
                                    125 	.globl _P1MDIN
                                    126 	.globl _P0MDIN
                                    127 	.globl _SFR0CN
                                    128 	.globl _XBR1
                                    129 	.globl _XBR0
                                    130 	.globl _P3SKIP
                                    131 	.globl _P2SKIP
                                    132 	.globl _P1SKIP
                                    133 	.globl _P0SKIP
                                    134 	.globl _CCH0MA
                                    135 	.globl _CCH0LC
                                    136 	.globl _EIP2
                                    137 	.globl _EIP1
                                    138 	.globl _CCH0TN
                                    139 	.globl _EMI0CF
                                    140 	.globl _OSCICL
                                    141 	.globl _OSCICN
                                    142 	.globl _OSCXCN
                                    143 	.globl _PLL0CN
                                    144 	.globl _PLL0FLT
                                    145 	.globl _PLL0MUL
                                    146 	.globl _P3MDOUT
                                    147 	.globl _P4MDOUT
                                    148 	.globl _OSCLCN
                                    149 	.globl _FLSTAT
                                    150 	.globl _PLL0DIV
                                    151 	.globl _P2MDOUT
                                    152 	.globl _P1MDOUT
                                    153 	.globl _P0MDOUT
                                    154 	.globl _CLKSEL
                                    155 	.globl _CCH0CN
                                    156 	.globl _P0MASK
                                    157 	.globl _P0MAT
                                    158 	.globl _MAC0BH
                                    159 	.globl _MAC0BL
                                    160 	.globl _P1MASK
                                    161 	.globl _P1MAT
                                    162 	.globl _MAC0CF
                                    163 	.globl _MAC0OVR
                                    164 	.globl _MAC0ACC3
                                    165 	.globl _MAC0ACC2
                                    166 	.globl _MAC0ACC1
                                    167 	.globl _MAC0ACC0
                                    168 	.globl _MAC0ACC
                                    169 	.globl _MAC0STA
                                    170 	.globl _FLKEY
                                    171 	.globl _FLSCL
                                    172 	.globl _P2MASK
                                    173 	.globl _P2MAT
                                    174 	.globl _MAC0RNDH
                                    175 	.globl _MAC0RNDL
                                    176 	.globl _MAC0RND
                                    177 	.globl _MAC0AH
                                    178 	.globl _MAC0AL
                                    179 	.globl _MAC0A
                                    180 	.globl _PSCTL
                                    181 	.globl _VDM0CN
                                    182 	.globl _PCA0CPH4
                                    183 	.globl _PCA0CPL4
                                    184 	.globl _PCA0CP4
                                    185 	.globl _PCA0CPH0
                                    186 	.globl _PCA0CPL0
                                    187 	.globl _PCA0CP0
                                    188 	.globl _PCA0H
                                    189 	.globl _PCA0L
                                    190 	.globl _PCA0
                                    191 	.globl _SPI0CN
                                    192 	.globl _PCA0CPH5
                                    193 	.globl _PCA0CPL5
                                    194 	.globl _PCA0CP5
                                    195 	.globl _B
                                    196 	.globl _RSTSRC
                                    197 	.globl _PCA0CPH3
                                    198 	.globl _PCA0CPL3
                                    199 	.globl _PCA0CP3
                                    200 	.globl _PCA0CPH2
                                    201 	.globl _PCA0CPL2
                                    202 	.globl _PCA0CP2
                                    203 	.globl _PCA0CPH1
                                    204 	.globl _PCA0CPL1
                                    205 	.globl _PCA0CP1
                                    206 	.globl _ADC0CN
                                    207 	.globl _EIE2
                                    208 	.globl _EIE1
                                    209 	.globl _IT01CF
                                    210 	.globl _ACC
                                    211 	.globl _PCA0CPM5
                                    212 	.globl _PCA0CPM4
                                    213 	.globl _PCA0CPM3
                                    214 	.globl _PCA0CPM2
                                    215 	.globl _PCA0CPM1
                                    216 	.globl _PCA0CPM0
                                    217 	.globl _PCA0MD
                                    218 	.globl _PCA0CN
                                    219 	.globl _REF0CN
                                    220 	.globl _PSW
                                    221 	.globl _TMR2H
                                    222 	.globl _TMR2L
                                    223 	.globl _TMR2
                                    224 	.globl _TMR2RLH
                                    225 	.globl _TMR2RLL
                                    226 	.globl _TMR2RL
                                    227 	.globl _TMR2CN
                                    228 	.globl _ADC0LTH
                                    229 	.globl _ADC0LTL
                                    230 	.globl _ADC0LT
                                    231 	.globl _ADC0GTH
                                    232 	.globl _ADC0GTL
                                    233 	.globl _ADC0GT
                                    234 	.globl _SMB0DAT
                                    235 	.globl _SMB0CF
                                    236 	.globl _SMB0CN
                                    237 	.globl _ADC0H
                                    238 	.globl _ADC0L
                                    239 	.globl _ADC0
                                    240 	.globl _ADC0CF
                                    241 	.globl _AMX0P
                                    242 	.globl _AMX0N
                                    243 	.globl _IDA0CN
                                    244 	.globl _IP
                                    245 	.globl _P4
                                    246 	.globl _P3
                                    247 	.globl __XPAGE
                                    248 	.globl _EMI0CN
                                    249 	.globl _IE
                                    250 	.globl _SFRPAGE
                                    251 	.globl _SPI0DAT
                                    252 	.globl _SPI0CKR
                                    253 	.globl _SPI0CFG
                                    254 	.globl _P2
                                    255 	.globl _CPT0MX
                                    256 	.globl _CPT1MX
                                    257 	.globl _CPT0MD
                                    258 	.globl _CPT1MD
                                    259 	.globl _CPT0CN
                                    260 	.globl _CPT1CN
                                    261 	.globl _SBUF0
                                    262 	.globl _SCON0
                                    263 	.globl _IDA0H
                                    264 	.globl _IDA0L
                                    265 	.globl _IDA0
                                    266 	.globl _TMR3H
                                    267 	.globl _TMR3L
                                    268 	.globl _TMR3
                                    269 	.globl _TMR3RLH
                                    270 	.globl _TMR3RLL
                                    271 	.globl _TMR3RL
                                    272 	.globl _TMR3CN
                                    273 	.globl _P1
                                    274 	.globl _CKCON
                                    275 	.globl _TH1
                                    276 	.globl _TL1
                                    277 	.globl _TMR1
                                    278 	.globl _TH0
                                    279 	.globl _TL0
                                    280 	.globl _TMR0
                                    281 	.globl _TMOD
                                    282 	.globl _TCON
                                    283 	.globl _PCON
                                    284 	.globl _SFRLAST
                                    285 	.globl _SFRNEXT
                                    286 	.globl _DPH
                                    287 	.globl _DPL
                                    288 	.globl _SP
                                    289 	.globl _P0
                                    290 ;--------------------------------------------------------
                                    291 ; special function registers
                                    292 ;--------------------------------------------------------
                                    293 	.area RSEG    (ABS,DATA)
      000000                        294 	.org 0x0000
                           000080   295 _P0	=	0x0080
                           000081   296 _SP	=	0x0081
                           000082   297 _DPL	=	0x0082
                           000083   298 _DPH	=	0x0083
                           000085   299 _SFRNEXT	=	0x0085
                           000086   300 _SFRLAST	=	0x0086
                           000087   301 _PCON	=	0x0087
                           000088   302 _TCON	=	0x0088
                           000089   303 _TMOD	=	0x0089
                           008C8A   304 _TMR0	=	0x8c8a
                           00008A   305 _TL0	=	0x008a
                           00008C   306 _TH0	=	0x008c
                           008D8B   307 _TMR1	=	0x8d8b
                           00008B   308 _TL1	=	0x008b
                           00008D   309 _TH1	=	0x008d
                           00008E   310 _CKCON	=	0x008e
                           000090   311 _P1	=	0x0090
                           000091   312 _TMR3CN	=	0x0091
                           009392   313 _TMR3RL	=	0x9392
                           000092   314 _TMR3RLL	=	0x0092
                           000093   315 _TMR3RLH	=	0x0093
                           009594   316 _TMR3	=	0x9594
                           000094   317 _TMR3L	=	0x0094
                           000095   318 _TMR3H	=	0x0095
                           009796   319 _IDA0	=	0x9796
                           000096   320 _IDA0L	=	0x0096
                           000097   321 _IDA0H	=	0x0097
                           000098   322 _SCON0	=	0x0098
                           000099   323 _SBUF0	=	0x0099
                           00009A   324 _CPT1CN	=	0x009a
                           00009B   325 _CPT0CN	=	0x009b
                           00009C   326 _CPT1MD	=	0x009c
                           00009D   327 _CPT0MD	=	0x009d
                           00009E   328 _CPT1MX	=	0x009e
                           00009F   329 _CPT0MX	=	0x009f
                           0000A0   330 _P2	=	0x00a0
                           0000A1   331 _SPI0CFG	=	0x00a1
                           0000A2   332 _SPI0CKR	=	0x00a2
                           0000A3   333 _SPI0DAT	=	0x00a3
                           0000A7   334 _SFRPAGE	=	0x00a7
                           0000A8   335 _IE	=	0x00a8
                           0000AA   336 _EMI0CN	=	0x00aa
                           0000AA   337 __XPAGE	=	0x00aa
                           0000B0   338 _P3	=	0x00b0
                           0000B5   339 _P4	=	0x00b5
                           0000B8   340 _IP	=	0x00b8
                           0000B9   341 _IDA0CN	=	0x00b9
                           0000BA   342 _AMX0N	=	0x00ba
                           0000BB   343 _AMX0P	=	0x00bb
                           0000BC   344 _ADC0CF	=	0x00bc
                           00BEBD   345 _ADC0	=	0xbebd
                           0000BD   346 _ADC0L	=	0x00bd
                           0000BE   347 _ADC0H	=	0x00be
                           0000C0   348 _SMB0CN	=	0x00c0
                           0000C1   349 _SMB0CF	=	0x00c1
                           0000C2   350 _SMB0DAT	=	0x00c2
                           00C4C3   351 _ADC0GT	=	0xc4c3
                           0000C3   352 _ADC0GTL	=	0x00c3
                           0000C4   353 _ADC0GTH	=	0x00c4
                           00C6C5   354 _ADC0LT	=	0xc6c5
                           0000C5   355 _ADC0LTL	=	0x00c5
                           0000C6   356 _ADC0LTH	=	0x00c6
                           0000C8   357 _TMR2CN	=	0x00c8
                           00CBCA   358 _TMR2RL	=	0xcbca
                           0000CA   359 _TMR2RLL	=	0x00ca
                           0000CB   360 _TMR2RLH	=	0x00cb
                           00CDCC   361 _TMR2	=	0xcdcc
                           0000CC   362 _TMR2L	=	0x00cc
                           0000CD   363 _TMR2H	=	0x00cd
                           0000D0   364 _PSW	=	0x00d0
                           0000D1   365 _REF0CN	=	0x00d1
                           0000D8   366 _PCA0CN	=	0x00d8
                           0000D9   367 _PCA0MD	=	0x00d9
                           0000DA   368 _PCA0CPM0	=	0x00da
                           0000DB   369 _PCA0CPM1	=	0x00db
                           0000DC   370 _PCA0CPM2	=	0x00dc
                           0000DD   371 _PCA0CPM3	=	0x00dd
                           0000DE   372 _PCA0CPM4	=	0x00de
                           0000DF   373 _PCA0CPM5	=	0x00df
                           0000E0   374 _ACC	=	0x00e0
                           0000E4   375 _IT01CF	=	0x00e4
                           0000E6   376 _EIE1	=	0x00e6
                           0000E7   377 _EIE2	=	0x00e7
                           0000E8   378 _ADC0CN	=	0x00e8
                           00EAE9   379 _PCA0CP1	=	0xeae9
                           0000E9   380 _PCA0CPL1	=	0x00e9
                           0000EA   381 _PCA0CPH1	=	0x00ea
                           00ECEB   382 _PCA0CP2	=	0xeceb
                           0000EB   383 _PCA0CPL2	=	0x00eb
                           0000EC   384 _PCA0CPH2	=	0x00ec
                           00EEED   385 _PCA0CP3	=	0xeeed
                           0000ED   386 _PCA0CPL3	=	0x00ed
                           0000EE   387 _PCA0CPH3	=	0x00ee
                           0000EF   388 _RSTSRC	=	0x00ef
                           0000F0   389 _B	=	0x00f0
                           00F6F5   390 _PCA0CP5	=	0xf6f5
                           0000F5   391 _PCA0CPL5	=	0x00f5
                           0000F6   392 _PCA0CPH5	=	0x00f6
                           0000F8   393 _SPI0CN	=	0x00f8
                           00FAF9   394 _PCA0	=	0xfaf9
                           0000F9   395 _PCA0L	=	0x00f9
                           0000FA   396 _PCA0H	=	0x00fa
                           00FCFB   397 _PCA0CP0	=	0xfcfb
                           0000FB   398 _PCA0CPL0	=	0x00fb
                           0000FC   399 _PCA0CPH0	=	0x00fc
                           00FEFD   400 _PCA0CP4	=	0xfefd
                           0000FD   401 _PCA0CPL4	=	0x00fd
                           0000FE   402 _PCA0CPH4	=	0x00fe
                           0000FF   403 _VDM0CN	=	0x00ff
                           00008F   404 _PSCTL	=	0x008f
                           00A5A4   405 _MAC0A	=	0xa5a4
                           0000A4   406 _MAC0AL	=	0x00a4
                           0000A5   407 _MAC0AH	=	0x00a5
                           00AFAE   408 _MAC0RND	=	0xafae
                           0000AE   409 _MAC0RNDL	=	0x00ae
                           0000AF   410 _MAC0RNDH	=	0x00af
                           0000B1   411 _P2MAT	=	0x00b1
                           0000B2   412 _P2MASK	=	0x00b2
                           0000B6   413 _FLSCL	=	0x00b6
                           0000B7   414 _FLKEY	=	0x00b7
                           0000CF   415 _MAC0STA	=	0x00cf
                           D5D4D3D2   416 _MAC0ACC	=	0xd5d4d3d2
                           0000D2   417 _MAC0ACC0	=	0x00d2
                           0000D3   418 _MAC0ACC1	=	0x00d3
                           0000D4   419 _MAC0ACC2	=	0x00d4
                           0000D5   420 _MAC0ACC3	=	0x00d5
                           0000D6   421 _MAC0OVR	=	0x00d6
                           0000D7   422 _MAC0CF	=	0x00d7
                           0000E1   423 _P1MAT	=	0x00e1
                           0000E2   424 _P1MASK	=	0x00e2
                           0000F1   425 _MAC0BL	=	0x00f1
                           0000F2   426 _MAC0BH	=	0x00f2
                           0000F3   427 _P0MAT	=	0x00f3
                           0000F4   428 _P0MASK	=	0x00f4
                           000084   429 _CCH0CN	=	0x0084
                           00008F   430 _CLKSEL	=	0x008f
                           0000A4   431 _P0MDOUT	=	0x00a4
                           0000A5   432 _P1MDOUT	=	0x00a5
                           0000A6   433 _P2MDOUT	=	0x00a6
                           0000A9   434 _PLL0DIV	=	0x00a9
                           0000AC   435 _FLSTAT	=	0x00ac
                           0000AD   436 _OSCLCN	=	0x00ad
                           0000AE   437 _P4MDOUT	=	0x00ae
                           0000AF   438 _P3MDOUT	=	0x00af
                           0000B1   439 _PLL0MUL	=	0x00b1
                           0000B2   440 _PLL0FLT	=	0x00b2
                           0000B3   441 _PLL0CN	=	0x00b3
                           0000B6   442 _OSCXCN	=	0x00b6
                           0000B7   443 _OSCICN	=	0x00b7
                           0000BF   444 _OSCICL	=	0x00bf
                           0000C7   445 _EMI0CF	=	0x00c7
                           0000C9   446 _CCH0TN	=	0x00c9
                           0000CE   447 _EIP1	=	0x00ce
                           0000CF   448 _EIP2	=	0x00cf
                           0000D2   449 _CCH0LC	=	0x00d2
                           0000D3   450 _CCH0MA	=	0x00d3
                           0000D4   451 _P0SKIP	=	0x00d4
                           0000D5   452 _P1SKIP	=	0x00d5
                           0000D6   453 _P2SKIP	=	0x00d6
                           0000D7   454 _P3SKIP	=	0x00d7
                           0000E1   455 _XBR0	=	0x00e1
                           0000E2   456 _XBR1	=	0x00e2
                           0000E5   457 _SFR0CN	=	0x00e5
                           0000F1   458 _P0MDIN	=	0x00f1
                           0000F2   459 _P1MDIN	=	0x00f2
                           0000F3   460 _P2MDIN	=	0x00f3
                           0000F4   461 _P3MDIN	=	0x00f4
                           0000F7   462 _EMI0TC	=	0x00f7
                                    463 ;--------------------------------------------------------
                                    464 ; special function bits
                                    465 ;--------------------------------------------------------
                                    466 	.area RSEG    (ABS,DATA)
      000000                        467 	.org 0x0000
                           000080   468 _P0_0	=	0x0080
                           000081   469 _P0_1	=	0x0081
                           000082   470 _P0_2	=	0x0082
                           000083   471 _P0_3	=	0x0083
                           000084   472 _P0_4	=	0x0084
                           000085   473 _P0_5	=	0x0085
                           000086   474 _P0_6	=	0x0086
                           000087   475 _P0_7	=	0x0087
                           000088   476 _IT0	=	0x0088
                           000089   477 _IE0	=	0x0089
                           00008A   478 _IT1	=	0x008a
                           00008B   479 _IE1	=	0x008b
                           00008C   480 _TR0	=	0x008c
                           00008D   481 _TF0	=	0x008d
                           00008E   482 _TR1	=	0x008e
                           00008F   483 _TF1	=	0x008f
                           000090   484 _P1_0	=	0x0090
                           000091   485 _P1_1	=	0x0091
                           000092   486 _P1_2	=	0x0092
                           000093   487 _P1_3	=	0x0093
                           000094   488 _P1_4	=	0x0094
                           000095   489 _P1_5	=	0x0095
                           000096   490 _P1_6	=	0x0096
                           000097   491 _P1_7	=	0x0097
                           000098   492 _RI0	=	0x0098
                           000099   493 _TI0	=	0x0099
                           00009A   494 _RB80	=	0x009a
                           00009B   495 _TB80	=	0x009b
                           00009C   496 _REN0	=	0x009c
                           00009D   497 _MCE0	=	0x009d
                           00009F   498 _S0MODE	=	0x009f
                           0000A0   499 _P2_0	=	0x00a0
                           0000A1   500 _P2_1	=	0x00a1
                           0000A2   501 _P2_2	=	0x00a2
                           0000A3   502 _P2_3	=	0x00a3
                           0000A4   503 _P2_4	=	0x00a4
                           0000A5   504 _P2_5	=	0x00a5
                           0000A6   505 _P2_6	=	0x00a6
                           0000A7   506 _P2_7	=	0x00a7
                           0000A8   507 _EX0	=	0x00a8
                           0000A9   508 _ET0	=	0x00a9
                           0000AA   509 _EX1	=	0x00aa
                           0000AB   510 _ET1	=	0x00ab
                           0000AC   511 _ES0	=	0x00ac
                           0000AD   512 _ET2	=	0x00ad
                           0000AE   513 _ESPI0	=	0x00ae
                           0000AF   514 _EA	=	0x00af
                           0000B0   515 _P3_0	=	0x00b0
                           0000B1   516 _P3_1	=	0x00b1
                           0000B2   517 _P3_2	=	0x00b2
                           0000B3   518 _P3_3	=	0x00b3
                           0000B4   519 _P3_4	=	0x00b4
                           0000B5   520 _P3_5	=	0x00b5
                           0000B6   521 _P3_6	=	0x00b6
                           0000B7   522 _P3_7	=	0x00b7
                           0000B8   523 _PX0	=	0x00b8
                           0000B9   524 _PT0	=	0x00b9
                           0000BA   525 _PX1	=	0x00ba
                           0000BB   526 _PT1	=	0x00bb
                           0000BC   527 _PS0	=	0x00bc
                           0000BD   528 _PT2	=	0x00bd
                           0000BE   529 _PSPI0	=	0x00be
                           0000C0   530 _SI	=	0x00c0
                           0000C1   531 _ACK	=	0x00c1
                           0000C2   532 _ARBLOST	=	0x00c2
                           0000C3   533 _ACKRQ	=	0x00c3
                           0000C4   534 _STO	=	0x00c4
                           0000C5   535 _STA	=	0x00c5
                           0000C6   536 _TXMODE	=	0x00c6
                           0000C7   537 _MASTER	=	0x00c7
                           0000C8   538 _T2XCLK	=	0x00c8
                           0000CA   539 _TR2	=	0x00ca
                           0000CB   540 _T2SPLIT	=	0x00cb
                           0000CC   541 _TF2CEN	=	0x00cc
                           0000CD   542 _TF2LEN	=	0x00cd
                           0000CE   543 _TF2L	=	0x00ce
                           0000CF   544 _TF2H	=	0x00cf
                           0000D0   545 _P	=	0x00d0
                           0000D1   546 _F1	=	0x00d1
                           0000D2   547 _OV	=	0x00d2
                           0000D3   548 _RS0	=	0x00d3
                           0000D4   549 _RS1	=	0x00d4
                           0000D5   550 _F0	=	0x00d5
                           0000D6   551 _AC	=	0x00d6
                           0000D7   552 _CY	=	0x00d7
                           0000D8   553 _CCF0	=	0x00d8
                           0000D9   554 _CCF1	=	0x00d9
                           0000DA   555 _CCF2	=	0x00da
                           0000DB   556 _CCF3	=	0x00db
                           0000DC   557 _CCF4	=	0x00dc
                           0000DD   558 _CCF5	=	0x00dd
                           0000DE   559 _CR	=	0x00de
                           0000DF   560 _CF	=	0x00df
                           0000E8   561 _AD0CM0	=	0x00e8
                           0000E9   562 _AD0CM1	=	0x00e9
                           0000EA   563 _AD0CM2	=	0x00ea
                           0000EB   564 _AD0WINT	=	0x00eb
                           0000EC   565 _AD0BUSY	=	0x00ec
                           0000ED   566 _AD0INT	=	0x00ed
                           0000EE   567 _AD0TM	=	0x00ee
                           0000EF   568 _AD0EN	=	0x00ef
                           0000F8   569 _SPIEN	=	0x00f8
                           0000F9   570 _TXBMT	=	0x00f9
                           0000FA   571 _NSSMD0	=	0x00fa
                           0000FB   572 _NSSMD1	=	0x00fb
                           0000FC   573 _RXOVRN	=	0x00fc
                           0000FD   574 _MODF	=	0x00fd
                           0000FE   575 _WCOL	=	0x00fe
                           0000FF   576 _SPIF	=	0x00ff
                                    577 ;--------------------------------------------------------
                                    578 ; overlayable register banks
                                    579 ;--------------------------------------------------------
                                    580 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        581 	.ds 8
                                    582 ;--------------------------------------------------------
                                    583 ; internal ram data
                                    584 ;--------------------------------------------------------
                                    585 	.area DSEG    (DATA)
                                    586 ;--------------------------------------------------------
                                    587 ; overlayable items in internal ram
                                    588 ;--------------------------------------------------------
                                    589 ;--------------------------------------------------------
                                    590 ; indirectly addressable internal ram data
                                    591 ;--------------------------------------------------------
                                    592 	.area ISEG    (DATA)
                                    593 ;--------------------------------------------------------
                                    594 ; absolute internal ram data
                                    595 ;--------------------------------------------------------
                                    596 	.area IABS    (ABS,DATA)
                                    597 	.area IABS    (ABS,DATA)
                                    598 ;--------------------------------------------------------
                                    599 ; bit data
                                    600 ;--------------------------------------------------------
                                    601 	.area BSEG    (BIT)
                                    602 ;--------------------------------------------------------
                                    603 ; paged external ram data
                                    604 ;--------------------------------------------------------
                                    605 	.area PSEG    (PAG,XDATA)
                                    606 ;--------------------------------------------------------
                                    607 ; external ram data
                                    608 ;--------------------------------------------------------
                                    609 	.area XSEG    (XDATA)
                                    610 ;--------------------------------------------------------
                                    611 ; absolute external ram data
                                    612 ;--------------------------------------------------------
                                    613 	.area XABS    (ABS,XDATA)
                                    614 ;--------------------------------------------------------
                                    615 ; external initialized ram data
                                    616 ;--------------------------------------------------------
                                    617 	.area XISEG   (XDATA)
                                    618 	.area HOME    (CODE)
                                    619 	.area GSINIT0 (CODE)
                                    620 	.area GSINIT1 (CODE)
                                    621 	.area GSINIT2 (CODE)
                                    622 	.area GSINIT3 (CODE)
                                    623 	.area GSINIT4 (CODE)
                                    624 	.area GSINIT5 (CODE)
                                    625 	.area GSINIT  (CODE)
                                    626 	.area GSFINAL (CODE)
                                    627 	.area CSEG    (CODE)
                                    628 ;--------------------------------------------------------
                                    629 ; global & static initialisations
                                    630 ;--------------------------------------------------------
                                    631 	.area HOME    (CODE)
                                    632 	.area GSINIT  (CODE)
                                    633 	.area GSFINAL (CODE)
                                    634 	.area GSINIT  (CODE)
                                    635 ;--------------------------------------------------------
                                    636 ; Home
                                    637 ;--------------------------------------------------------
                                    638 	.area HOME    (CODE)
                                    639 	.area HOME    (CODE)
                                    640 ;--------------------------------------------------------
                                    641 ; code
                                    642 ;--------------------------------------------------------
                                    643 	.area CSEG    (CODE)
                                    644 ;------------------------------------------------------------
                                    645 ;Allocation info for local variables in function 'Timers_Init'
                                    646 ;------------------------------------------------------------
                                    647 ;	drivers/timer/timer.c:4: void Timers_Init()
                                    648 ;	-----------------------------------------
                                    649 ;	 function Timers_Init
                                    650 ;	-----------------------------------------
      0002FD                        651 _Timers_Init:
                           000007   652 	ar7 = 0x07
                           000006   653 	ar6 = 0x06
                           000005   654 	ar5 = 0x05
                           000004   655 	ar4 = 0x04
                           000003   656 	ar3 = 0x03
                           000002   657 	ar2 = 0x02
                           000001   658 	ar1 = 0x01
                           000000   659 	ar0 = 0x00
                                    660 ;	drivers/timer/timer.c:6: TCON      = 0x50;
      0002FD 75 88 50         [24]  661 	mov	_TCON,#0x50
                                    662 ;	drivers/timer/timer.c:7: TMOD      = 0x11;
      000300 75 89 11         [24]  663 	mov	_TMOD,#0x11
                                    664 ;	drivers/timer/timer.c:8: CKCON     = 0x02;
      000303 75 8E 02         [24]  665 	mov	_CKCON,#0x02
                                    666 ;	drivers/timer/timer.c:10: TL0       = 0xff; 
      000306 75 8A FF         [24]  667 	mov	_TL0,#0xff
                                    668 ;	drivers/timer/timer.c:11: TH0       = 0xf6; 
      000309 75 8C F6         [24]  669 	mov	_TH0,#0xf6
                                    670 ;	drivers/timer/timer.c:12: }
      00030C 22               [24]  671 	ret
                                    672 ;------------------------------------------------------------
                                    673 ;Allocation info for local variables in function 'Interrupts_Init'
                                    674 ;------------------------------------------------------------
                                    675 ;	drivers/timer/timer.c:15: void Interrupts_Init()
                                    676 ;	-----------------------------------------
                                    677 ;	 function Interrupts_Init
                                    678 ;	-----------------------------------------
      00030D                        679 _Interrupts_Init:
                                    680 ;	drivers/timer/timer.c:17: IE        = 0x8A;
      00030D 75 A8 8A         [24]  681 	mov	_IE,#0x8a
                                    682 ;	drivers/timer/timer.c:18: }
      000310 22               [24]  683 	ret
                                    684 	.area CSEG    (CODE)
                                    685 	.area CONST   (CODE)
                                    686 	.area XINIT   (CODE)
                                    687 	.area CABS    (ABS,CODE)
