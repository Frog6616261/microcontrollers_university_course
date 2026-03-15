                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module uart
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _uart_read_char
                                     12 	.globl _uart_send_char
                                     13 	.globl _uart_init
                                     14 	.globl _SPIF
                                     15 	.globl _WCOL
                                     16 	.globl _MODF
                                     17 	.globl _RXOVRN
                                     18 	.globl _NSSMD1
                                     19 	.globl _NSSMD0
                                     20 	.globl _TXBMT
                                     21 	.globl _SPIEN
                                     22 	.globl _AD0EN
                                     23 	.globl _AD0TM
                                     24 	.globl _AD0INT
                                     25 	.globl _AD0BUSY
                                     26 	.globl _AD0WINT
                                     27 	.globl _AD0CM2
                                     28 	.globl _AD0CM1
                                     29 	.globl _AD0CM0
                                     30 	.globl _CF
                                     31 	.globl _CR
                                     32 	.globl _CCF5
                                     33 	.globl _CCF4
                                     34 	.globl _CCF3
                                     35 	.globl _CCF2
                                     36 	.globl _CCF1
                                     37 	.globl _CCF0
                                     38 	.globl _CY
                                     39 	.globl _AC
                                     40 	.globl _F0
                                     41 	.globl _RS1
                                     42 	.globl _RS0
                                     43 	.globl _OV
                                     44 	.globl _F1
                                     45 	.globl _P
                                     46 	.globl _TF2H
                                     47 	.globl _TF2L
                                     48 	.globl _TF2LEN
                                     49 	.globl _TF2CEN
                                     50 	.globl _T2SPLIT
                                     51 	.globl _TR2
                                     52 	.globl _T2XCLK
                                     53 	.globl _MASTER
                                     54 	.globl _TXMODE
                                     55 	.globl _STA
                                     56 	.globl _STO
                                     57 	.globl _ACKRQ
                                     58 	.globl _ARBLOST
                                     59 	.globl _ACK
                                     60 	.globl _SI
                                     61 	.globl _PSPI0
                                     62 	.globl _PT2
                                     63 	.globl _PS0
                                     64 	.globl _PT1
                                     65 	.globl _PX1
                                     66 	.globl _PT0
                                     67 	.globl _PX0
                                     68 	.globl _P3_7
                                     69 	.globl _P3_6
                                     70 	.globl _P3_5
                                     71 	.globl _P3_4
                                     72 	.globl _P3_3
                                     73 	.globl _P3_2
                                     74 	.globl _P3_1
                                     75 	.globl _P3_0
                                     76 	.globl _EA
                                     77 	.globl _ESPI0
                                     78 	.globl _ET2
                                     79 	.globl _ES0
                                     80 	.globl _ET1
                                     81 	.globl _EX1
                                     82 	.globl _ET0
                                     83 	.globl _EX0
                                     84 	.globl _P2_7
                                     85 	.globl _P2_6
                                     86 	.globl _P2_5
                                     87 	.globl _P2_4
                                     88 	.globl _P2_3
                                     89 	.globl _P2_2
                                     90 	.globl _P2_1
                                     91 	.globl _P2_0
                                     92 	.globl _S0MODE
                                     93 	.globl _MCE0
                                     94 	.globl _REN0
                                     95 	.globl _TB80
                                     96 	.globl _RB80
                                     97 	.globl _TI0
                                     98 	.globl _RI0
                                     99 	.globl _P1_7
                                    100 	.globl _P1_6
                                    101 	.globl _P1_5
                                    102 	.globl _P1_4
                                    103 	.globl _P1_3
                                    104 	.globl _P1_2
                                    105 	.globl _P1_1
                                    106 	.globl _P1_0
                                    107 	.globl _TF1
                                    108 	.globl _TR1
                                    109 	.globl _TF0
                                    110 	.globl _TR0
                                    111 	.globl _IE1
                                    112 	.globl _IT1
                                    113 	.globl _IE0
                                    114 	.globl _IT0
                                    115 	.globl _P0_7
                                    116 	.globl _P0_6
                                    117 	.globl _P0_5
                                    118 	.globl _P0_4
                                    119 	.globl _P0_3
                                    120 	.globl _P0_2
                                    121 	.globl _P0_1
                                    122 	.globl _P0_0
                                    123 	.globl _EMI0TC
                                    124 	.globl _P3MDIN
                                    125 	.globl _P2MDIN
                                    126 	.globl _P1MDIN
                                    127 	.globl _P0MDIN
                                    128 	.globl _SFR0CN
                                    129 	.globl _XBR1
                                    130 	.globl _XBR0
                                    131 	.globl _P3SKIP
                                    132 	.globl _P2SKIP
                                    133 	.globl _P1SKIP
                                    134 	.globl _P0SKIP
                                    135 	.globl _CCH0MA
                                    136 	.globl _CCH0LC
                                    137 	.globl _EIP2
                                    138 	.globl _EIP1
                                    139 	.globl _CCH0TN
                                    140 	.globl _EMI0CF
                                    141 	.globl _OSCICL
                                    142 	.globl _OSCICN
                                    143 	.globl _OSCXCN
                                    144 	.globl _PLL0CN
                                    145 	.globl _PLL0FLT
                                    146 	.globl _PLL0MUL
                                    147 	.globl _P3MDOUT
                                    148 	.globl _P4MDOUT
                                    149 	.globl _OSCLCN
                                    150 	.globl _FLSTAT
                                    151 	.globl _PLL0DIV
                                    152 	.globl _P2MDOUT
                                    153 	.globl _P1MDOUT
                                    154 	.globl _P0MDOUT
                                    155 	.globl _CLKSEL
                                    156 	.globl _CCH0CN
                                    157 	.globl _P0MASK
                                    158 	.globl _P0MAT
                                    159 	.globl _MAC0BH
                                    160 	.globl _MAC0BL
                                    161 	.globl _P1MASK
                                    162 	.globl _P1MAT
                                    163 	.globl _MAC0CF
                                    164 	.globl _MAC0OVR
                                    165 	.globl _MAC0ACC3
                                    166 	.globl _MAC0ACC2
                                    167 	.globl _MAC0ACC1
                                    168 	.globl _MAC0ACC0
                                    169 	.globl _MAC0ACC
                                    170 	.globl _MAC0STA
                                    171 	.globl _FLKEY
                                    172 	.globl _FLSCL
                                    173 	.globl _P2MASK
                                    174 	.globl _P2MAT
                                    175 	.globl _MAC0RNDH
                                    176 	.globl _MAC0RNDL
                                    177 	.globl _MAC0RND
                                    178 	.globl _MAC0AH
                                    179 	.globl _MAC0AL
                                    180 	.globl _MAC0A
                                    181 	.globl _PSCTL
                                    182 	.globl _VDM0CN
                                    183 	.globl _PCA0CPH4
                                    184 	.globl _PCA0CPL4
                                    185 	.globl _PCA0CP4
                                    186 	.globl _PCA0CPH0
                                    187 	.globl _PCA0CPL0
                                    188 	.globl _PCA0CP0
                                    189 	.globl _PCA0H
                                    190 	.globl _PCA0L
                                    191 	.globl _PCA0
                                    192 	.globl _SPI0CN
                                    193 	.globl _PCA0CPH5
                                    194 	.globl _PCA0CPL5
                                    195 	.globl _PCA0CP5
                                    196 	.globl _B
                                    197 	.globl _RSTSRC
                                    198 	.globl _PCA0CPH3
                                    199 	.globl _PCA0CPL3
                                    200 	.globl _PCA0CP3
                                    201 	.globl _PCA0CPH2
                                    202 	.globl _PCA0CPL2
                                    203 	.globl _PCA0CP2
                                    204 	.globl _PCA0CPH1
                                    205 	.globl _PCA0CPL1
                                    206 	.globl _PCA0CP1
                                    207 	.globl _ADC0CN
                                    208 	.globl _EIE2
                                    209 	.globl _EIE1
                                    210 	.globl _IT01CF
                                    211 	.globl _ACC
                                    212 	.globl _PCA0CPM5
                                    213 	.globl _PCA0CPM4
                                    214 	.globl _PCA0CPM3
                                    215 	.globl _PCA0CPM2
                                    216 	.globl _PCA0CPM1
                                    217 	.globl _PCA0CPM0
                                    218 	.globl _PCA0MD
                                    219 	.globl _PCA0CN
                                    220 	.globl _REF0CN
                                    221 	.globl _PSW
                                    222 	.globl _TMR2H
                                    223 	.globl _TMR2L
                                    224 	.globl _TMR2
                                    225 	.globl _TMR2RLH
                                    226 	.globl _TMR2RLL
                                    227 	.globl _TMR2RL
                                    228 	.globl _TMR2CN
                                    229 	.globl _ADC0LTH
                                    230 	.globl _ADC0LTL
                                    231 	.globl _ADC0LT
                                    232 	.globl _ADC0GTH
                                    233 	.globl _ADC0GTL
                                    234 	.globl _ADC0GT
                                    235 	.globl _SMB0DAT
                                    236 	.globl _SMB0CF
                                    237 	.globl _SMB0CN
                                    238 	.globl _ADC0H
                                    239 	.globl _ADC0L
                                    240 	.globl _ADC0
                                    241 	.globl _ADC0CF
                                    242 	.globl _AMX0P
                                    243 	.globl _AMX0N
                                    244 	.globl _IDA0CN
                                    245 	.globl _IP
                                    246 	.globl _P4
                                    247 	.globl _P3
                                    248 	.globl __XPAGE
                                    249 	.globl _EMI0CN
                                    250 	.globl _IE
                                    251 	.globl _SFRPAGE
                                    252 	.globl _SPI0DAT
                                    253 	.globl _SPI0CKR
                                    254 	.globl _SPI0CFG
                                    255 	.globl _P2
                                    256 	.globl _CPT0MX
                                    257 	.globl _CPT1MX
                                    258 	.globl _CPT0MD
                                    259 	.globl _CPT1MD
                                    260 	.globl _CPT0CN
                                    261 	.globl _CPT1CN
                                    262 	.globl _SBUF0
                                    263 	.globl _SCON0
                                    264 	.globl _IDA0H
                                    265 	.globl _IDA0L
                                    266 	.globl _IDA0
                                    267 	.globl _TMR3H
                                    268 	.globl _TMR3L
                                    269 	.globl _TMR3
                                    270 	.globl _TMR3RLH
                                    271 	.globl _TMR3RLL
                                    272 	.globl _TMR3RL
                                    273 	.globl _TMR3CN
                                    274 	.globl _P1
                                    275 	.globl _CKCON
                                    276 	.globl _TH1
                                    277 	.globl _TL1
                                    278 	.globl _TMR1
                                    279 	.globl _TH0
                                    280 	.globl _TL0
                                    281 	.globl _TMR0
                                    282 	.globl _TMOD
                                    283 	.globl _TCON
                                    284 	.globl _PCON
                                    285 	.globl _SFRLAST
                                    286 	.globl _SFRNEXT
                                    287 	.globl _DPH
                                    288 	.globl _DPL
                                    289 	.globl _SP
                                    290 	.globl _P0
                                    291 ;--------------------------------------------------------
                                    292 ; special function registers
                                    293 ;--------------------------------------------------------
                                    294 	.area RSEG    (ABS,DATA)
      000000                        295 	.org 0x0000
                           000080   296 _P0	=	0x0080
                           000081   297 _SP	=	0x0081
                           000082   298 _DPL	=	0x0082
                           000083   299 _DPH	=	0x0083
                           000085   300 _SFRNEXT	=	0x0085
                           000086   301 _SFRLAST	=	0x0086
                           000087   302 _PCON	=	0x0087
                           000088   303 _TCON	=	0x0088
                           000089   304 _TMOD	=	0x0089
                           008C8A   305 _TMR0	=	0x8c8a
                           00008A   306 _TL0	=	0x008a
                           00008C   307 _TH0	=	0x008c
                           008D8B   308 _TMR1	=	0x8d8b
                           00008B   309 _TL1	=	0x008b
                           00008D   310 _TH1	=	0x008d
                           00008E   311 _CKCON	=	0x008e
                           000090   312 _P1	=	0x0090
                           000091   313 _TMR3CN	=	0x0091
                           009392   314 _TMR3RL	=	0x9392
                           000092   315 _TMR3RLL	=	0x0092
                           000093   316 _TMR3RLH	=	0x0093
                           009594   317 _TMR3	=	0x9594
                           000094   318 _TMR3L	=	0x0094
                           000095   319 _TMR3H	=	0x0095
                           009796   320 _IDA0	=	0x9796
                           000096   321 _IDA0L	=	0x0096
                           000097   322 _IDA0H	=	0x0097
                           000098   323 _SCON0	=	0x0098
                           000099   324 _SBUF0	=	0x0099
                           00009A   325 _CPT1CN	=	0x009a
                           00009B   326 _CPT0CN	=	0x009b
                           00009C   327 _CPT1MD	=	0x009c
                           00009D   328 _CPT0MD	=	0x009d
                           00009E   329 _CPT1MX	=	0x009e
                           00009F   330 _CPT0MX	=	0x009f
                           0000A0   331 _P2	=	0x00a0
                           0000A1   332 _SPI0CFG	=	0x00a1
                           0000A2   333 _SPI0CKR	=	0x00a2
                           0000A3   334 _SPI0DAT	=	0x00a3
                           0000A7   335 _SFRPAGE	=	0x00a7
                           0000A8   336 _IE	=	0x00a8
                           0000AA   337 _EMI0CN	=	0x00aa
                           0000AA   338 __XPAGE	=	0x00aa
                           0000B0   339 _P3	=	0x00b0
                           0000B5   340 _P4	=	0x00b5
                           0000B8   341 _IP	=	0x00b8
                           0000B9   342 _IDA0CN	=	0x00b9
                           0000BA   343 _AMX0N	=	0x00ba
                           0000BB   344 _AMX0P	=	0x00bb
                           0000BC   345 _ADC0CF	=	0x00bc
                           00BEBD   346 _ADC0	=	0xbebd
                           0000BD   347 _ADC0L	=	0x00bd
                           0000BE   348 _ADC0H	=	0x00be
                           0000C0   349 _SMB0CN	=	0x00c0
                           0000C1   350 _SMB0CF	=	0x00c1
                           0000C2   351 _SMB0DAT	=	0x00c2
                           00C4C3   352 _ADC0GT	=	0xc4c3
                           0000C3   353 _ADC0GTL	=	0x00c3
                           0000C4   354 _ADC0GTH	=	0x00c4
                           00C6C5   355 _ADC0LT	=	0xc6c5
                           0000C5   356 _ADC0LTL	=	0x00c5
                           0000C6   357 _ADC0LTH	=	0x00c6
                           0000C8   358 _TMR2CN	=	0x00c8
                           00CBCA   359 _TMR2RL	=	0xcbca
                           0000CA   360 _TMR2RLL	=	0x00ca
                           0000CB   361 _TMR2RLH	=	0x00cb
                           00CDCC   362 _TMR2	=	0xcdcc
                           0000CC   363 _TMR2L	=	0x00cc
                           0000CD   364 _TMR2H	=	0x00cd
                           0000D0   365 _PSW	=	0x00d0
                           0000D1   366 _REF0CN	=	0x00d1
                           0000D8   367 _PCA0CN	=	0x00d8
                           0000D9   368 _PCA0MD	=	0x00d9
                           0000DA   369 _PCA0CPM0	=	0x00da
                           0000DB   370 _PCA0CPM1	=	0x00db
                           0000DC   371 _PCA0CPM2	=	0x00dc
                           0000DD   372 _PCA0CPM3	=	0x00dd
                           0000DE   373 _PCA0CPM4	=	0x00de
                           0000DF   374 _PCA0CPM5	=	0x00df
                           0000E0   375 _ACC	=	0x00e0
                           0000E4   376 _IT01CF	=	0x00e4
                           0000E6   377 _EIE1	=	0x00e6
                           0000E7   378 _EIE2	=	0x00e7
                           0000E8   379 _ADC0CN	=	0x00e8
                           00EAE9   380 _PCA0CP1	=	0xeae9
                           0000E9   381 _PCA0CPL1	=	0x00e9
                           0000EA   382 _PCA0CPH1	=	0x00ea
                           00ECEB   383 _PCA0CP2	=	0xeceb
                           0000EB   384 _PCA0CPL2	=	0x00eb
                           0000EC   385 _PCA0CPH2	=	0x00ec
                           00EEED   386 _PCA0CP3	=	0xeeed
                           0000ED   387 _PCA0CPL3	=	0x00ed
                           0000EE   388 _PCA0CPH3	=	0x00ee
                           0000EF   389 _RSTSRC	=	0x00ef
                           0000F0   390 _B	=	0x00f0
                           00F6F5   391 _PCA0CP5	=	0xf6f5
                           0000F5   392 _PCA0CPL5	=	0x00f5
                           0000F6   393 _PCA0CPH5	=	0x00f6
                           0000F8   394 _SPI0CN	=	0x00f8
                           00FAF9   395 _PCA0	=	0xfaf9
                           0000F9   396 _PCA0L	=	0x00f9
                           0000FA   397 _PCA0H	=	0x00fa
                           00FCFB   398 _PCA0CP0	=	0xfcfb
                           0000FB   399 _PCA0CPL0	=	0x00fb
                           0000FC   400 _PCA0CPH0	=	0x00fc
                           00FEFD   401 _PCA0CP4	=	0xfefd
                           0000FD   402 _PCA0CPL4	=	0x00fd
                           0000FE   403 _PCA0CPH4	=	0x00fe
                           0000FF   404 _VDM0CN	=	0x00ff
                           00008F   405 _PSCTL	=	0x008f
                           00A5A4   406 _MAC0A	=	0xa5a4
                           0000A4   407 _MAC0AL	=	0x00a4
                           0000A5   408 _MAC0AH	=	0x00a5
                           00AFAE   409 _MAC0RND	=	0xafae
                           0000AE   410 _MAC0RNDL	=	0x00ae
                           0000AF   411 _MAC0RNDH	=	0x00af
                           0000B1   412 _P2MAT	=	0x00b1
                           0000B2   413 _P2MASK	=	0x00b2
                           0000B6   414 _FLSCL	=	0x00b6
                           0000B7   415 _FLKEY	=	0x00b7
                           0000CF   416 _MAC0STA	=	0x00cf
                           D5D4D3D2   417 _MAC0ACC	=	0xd5d4d3d2
                           0000D2   418 _MAC0ACC0	=	0x00d2
                           0000D3   419 _MAC0ACC1	=	0x00d3
                           0000D4   420 _MAC0ACC2	=	0x00d4
                           0000D5   421 _MAC0ACC3	=	0x00d5
                           0000D6   422 _MAC0OVR	=	0x00d6
                           0000D7   423 _MAC0CF	=	0x00d7
                           0000E1   424 _P1MAT	=	0x00e1
                           0000E2   425 _P1MASK	=	0x00e2
                           0000F1   426 _MAC0BL	=	0x00f1
                           0000F2   427 _MAC0BH	=	0x00f2
                           0000F3   428 _P0MAT	=	0x00f3
                           0000F4   429 _P0MASK	=	0x00f4
                           000084   430 _CCH0CN	=	0x0084
                           00008F   431 _CLKSEL	=	0x008f
                           0000A4   432 _P0MDOUT	=	0x00a4
                           0000A5   433 _P1MDOUT	=	0x00a5
                           0000A6   434 _P2MDOUT	=	0x00a6
                           0000A9   435 _PLL0DIV	=	0x00a9
                           0000AC   436 _FLSTAT	=	0x00ac
                           0000AD   437 _OSCLCN	=	0x00ad
                           0000AE   438 _P4MDOUT	=	0x00ae
                           0000AF   439 _P3MDOUT	=	0x00af
                           0000B1   440 _PLL0MUL	=	0x00b1
                           0000B2   441 _PLL0FLT	=	0x00b2
                           0000B3   442 _PLL0CN	=	0x00b3
                           0000B6   443 _OSCXCN	=	0x00b6
                           0000B7   444 _OSCICN	=	0x00b7
                           0000BF   445 _OSCICL	=	0x00bf
                           0000C7   446 _EMI0CF	=	0x00c7
                           0000C9   447 _CCH0TN	=	0x00c9
                           0000CE   448 _EIP1	=	0x00ce
                           0000CF   449 _EIP2	=	0x00cf
                           0000D2   450 _CCH0LC	=	0x00d2
                           0000D3   451 _CCH0MA	=	0x00d3
                           0000D4   452 _P0SKIP	=	0x00d4
                           0000D5   453 _P1SKIP	=	0x00d5
                           0000D6   454 _P2SKIP	=	0x00d6
                           0000D7   455 _P3SKIP	=	0x00d7
                           0000E1   456 _XBR0	=	0x00e1
                           0000E2   457 _XBR1	=	0x00e2
                           0000E5   458 _SFR0CN	=	0x00e5
                           0000F1   459 _P0MDIN	=	0x00f1
                           0000F2   460 _P1MDIN	=	0x00f2
                           0000F3   461 _P2MDIN	=	0x00f3
                           0000F4   462 _P3MDIN	=	0x00f4
                           0000F7   463 _EMI0TC	=	0x00f7
                                    464 ;--------------------------------------------------------
                                    465 ; special function bits
                                    466 ;--------------------------------------------------------
                                    467 	.area RSEG    (ABS,DATA)
      000000                        468 	.org 0x0000
                           000080   469 _P0_0	=	0x0080
                           000081   470 _P0_1	=	0x0081
                           000082   471 _P0_2	=	0x0082
                           000083   472 _P0_3	=	0x0083
                           000084   473 _P0_4	=	0x0084
                           000085   474 _P0_5	=	0x0085
                           000086   475 _P0_6	=	0x0086
                           000087   476 _P0_7	=	0x0087
                           000088   477 _IT0	=	0x0088
                           000089   478 _IE0	=	0x0089
                           00008A   479 _IT1	=	0x008a
                           00008B   480 _IE1	=	0x008b
                           00008C   481 _TR0	=	0x008c
                           00008D   482 _TF0	=	0x008d
                           00008E   483 _TR1	=	0x008e
                           00008F   484 _TF1	=	0x008f
                           000090   485 _P1_0	=	0x0090
                           000091   486 _P1_1	=	0x0091
                           000092   487 _P1_2	=	0x0092
                           000093   488 _P1_3	=	0x0093
                           000094   489 _P1_4	=	0x0094
                           000095   490 _P1_5	=	0x0095
                           000096   491 _P1_6	=	0x0096
                           000097   492 _P1_7	=	0x0097
                           000098   493 _RI0	=	0x0098
                           000099   494 _TI0	=	0x0099
                           00009A   495 _RB80	=	0x009a
                           00009B   496 _TB80	=	0x009b
                           00009C   497 _REN0	=	0x009c
                           00009D   498 _MCE0	=	0x009d
                           00009F   499 _S0MODE	=	0x009f
                           0000A0   500 _P2_0	=	0x00a0
                           0000A1   501 _P2_1	=	0x00a1
                           0000A2   502 _P2_2	=	0x00a2
                           0000A3   503 _P2_3	=	0x00a3
                           0000A4   504 _P2_4	=	0x00a4
                           0000A5   505 _P2_5	=	0x00a5
                           0000A6   506 _P2_6	=	0x00a6
                           0000A7   507 _P2_7	=	0x00a7
                           0000A8   508 _EX0	=	0x00a8
                           0000A9   509 _ET0	=	0x00a9
                           0000AA   510 _EX1	=	0x00aa
                           0000AB   511 _ET1	=	0x00ab
                           0000AC   512 _ES0	=	0x00ac
                           0000AD   513 _ET2	=	0x00ad
                           0000AE   514 _ESPI0	=	0x00ae
                           0000AF   515 _EA	=	0x00af
                           0000B0   516 _P3_0	=	0x00b0
                           0000B1   517 _P3_1	=	0x00b1
                           0000B2   518 _P3_2	=	0x00b2
                           0000B3   519 _P3_3	=	0x00b3
                           0000B4   520 _P3_4	=	0x00b4
                           0000B5   521 _P3_5	=	0x00b5
                           0000B6   522 _P3_6	=	0x00b6
                           0000B7   523 _P3_7	=	0x00b7
                           0000B8   524 _PX0	=	0x00b8
                           0000B9   525 _PT0	=	0x00b9
                           0000BA   526 _PX1	=	0x00ba
                           0000BB   527 _PT1	=	0x00bb
                           0000BC   528 _PS0	=	0x00bc
                           0000BD   529 _PT2	=	0x00bd
                           0000BE   530 _PSPI0	=	0x00be
                           0000C0   531 _SI	=	0x00c0
                           0000C1   532 _ACK	=	0x00c1
                           0000C2   533 _ARBLOST	=	0x00c2
                           0000C3   534 _ACKRQ	=	0x00c3
                           0000C4   535 _STO	=	0x00c4
                           0000C5   536 _STA	=	0x00c5
                           0000C6   537 _TXMODE	=	0x00c6
                           0000C7   538 _MASTER	=	0x00c7
                           0000C8   539 _T2XCLK	=	0x00c8
                           0000CA   540 _TR2	=	0x00ca
                           0000CB   541 _T2SPLIT	=	0x00cb
                           0000CC   542 _TF2CEN	=	0x00cc
                           0000CD   543 _TF2LEN	=	0x00cd
                           0000CE   544 _TF2L	=	0x00ce
                           0000CF   545 _TF2H	=	0x00cf
                           0000D0   546 _P	=	0x00d0
                           0000D1   547 _F1	=	0x00d1
                           0000D2   548 _OV	=	0x00d2
                           0000D3   549 _RS0	=	0x00d3
                           0000D4   550 _RS1	=	0x00d4
                           0000D5   551 _F0	=	0x00d5
                           0000D6   552 _AC	=	0x00d6
                           0000D7   553 _CY	=	0x00d7
                           0000D8   554 _CCF0	=	0x00d8
                           0000D9   555 _CCF1	=	0x00d9
                           0000DA   556 _CCF2	=	0x00da
                           0000DB   557 _CCF3	=	0x00db
                           0000DC   558 _CCF4	=	0x00dc
                           0000DD   559 _CCF5	=	0x00dd
                           0000DE   560 _CR	=	0x00de
                           0000DF   561 _CF	=	0x00df
                           0000E8   562 _AD0CM0	=	0x00e8
                           0000E9   563 _AD0CM1	=	0x00e9
                           0000EA   564 _AD0CM2	=	0x00ea
                           0000EB   565 _AD0WINT	=	0x00eb
                           0000EC   566 _AD0BUSY	=	0x00ec
                           0000ED   567 _AD0INT	=	0x00ed
                           0000EE   568 _AD0TM	=	0x00ee
                           0000EF   569 _AD0EN	=	0x00ef
                           0000F8   570 _SPIEN	=	0x00f8
                           0000F9   571 _TXBMT	=	0x00f9
                           0000FA   572 _NSSMD0	=	0x00fa
                           0000FB   573 _NSSMD1	=	0x00fb
                           0000FC   574 _RXOVRN	=	0x00fc
                           0000FD   575 _MODF	=	0x00fd
                           0000FE   576 _WCOL	=	0x00fe
                           0000FF   577 _SPIF	=	0x00ff
                                    578 ;--------------------------------------------------------
                                    579 ; overlayable register banks
                                    580 ;--------------------------------------------------------
                                    581 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        582 	.ds 8
                                    583 ;--------------------------------------------------------
                                    584 ; internal ram data
                                    585 ;--------------------------------------------------------
                                    586 	.area DSEG    (DATA)
                                    587 ;--------------------------------------------------------
                                    588 ; overlayable items in internal ram
                                    589 ;--------------------------------------------------------
                                    590 	.area	OSEG    (OVR,DATA)
                                    591 ;--------------------------------------------------------
                                    592 ; indirectly addressable internal ram data
                                    593 ;--------------------------------------------------------
                                    594 	.area ISEG    (DATA)
                                    595 ;--------------------------------------------------------
                                    596 ; absolute internal ram data
                                    597 ;--------------------------------------------------------
                                    598 	.area IABS    (ABS,DATA)
                                    599 	.area IABS    (ABS,DATA)
                                    600 ;--------------------------------------------------------
                                    601 ; bit data
                                    602 ;--------------------------------------------------------
                                    603 	.area BSEG    (BIT)
                                    604 ;--------------------------------------------------------
                                    605 ; paged external ram data
                                    606 ;--------------------------------------------------------
                                    607 	.area PSEG    (PAG,XDATA)
                                    608 ;--------------------------------------------------------
                                    609 ; external ram data
                                    610 ;--------------------------------------------------------
                                    611 	.area XSEG    (XDATA)
                                    612 ;--------------------------------------------------------
                                    613 ; absolute external ram data
                                    614 ;--------------------------------------------------------
                                    615 	.area XABS    (ABS,XDATA)
                                    616 ;--------------------------------------------------------
                                    617 ; external initialized ram data
                                    618 ;--------------------------------------------------------
                                    619 	.area XISEG   (XDATA)
                                    620 	.area HOME    (CODE)
                                    621 	.area GSINIT0 (CODE)
                                    622 	.area GSINIT1 (CODE)
                                    623 	.area GSINIT2 (CODE)
                                    624 	.area GSINIT3 (CODE)
                                    625 	.area GSINIT4 (CODE)
                                    626 	.area GSINIT5 (CODE)
                                    627 	.area GSINIT  (CODE)
                                    628 	.area GSFINAL (CODE)
                                    629 	.area CSEG    (CODE)
                                    630 ;--------------------------------------------------------
                                    631 ; global & static initialisations
                                    632 ;--------------------------------------------------------
                                    633 	.area HOME    (CODE)
                                    634 	.area GSINIT  (CODE)
                                    635 	.area GSFINAL (CODE)
                                    636 	.area GSINIT  (CODE)
                                    637 ;--------------------------------------------------------
                                    638 ; Home
                                    639 ;--------------------------------------------------------
                                    640 	.area HOME    (CODE)
                                    641 	.area HOME    (CODE)
                                    642 ;--------------------------------------------------------
                                    643 ; code
                                    644 ;--------------------------------------------------------
                                    645 	.area CSEG    (CODE)
                                    646 ;------------------------------------------------------------
                                    647 ;Allocation info for local variables in function 'uart_init'
                                    648 ;------------------------------------------------------------
                                    649 ;	drivers/uart/uart.c:5: void uart_init(void){
                                    650 ;	-----------------------------------------
                                    651 ;	 function uart_init
                                    652 ;	-----------------------------------------
      00028B                        653 _uart_init:
                           000007   654 	ar7 = 0x07
                           000006   655 	ar6 = 0x06
                           000005   656 	ar5 = 0x05
                           000004   657 	ar4 = 0x04
                           000003   658 	ar3 = 0x03
                           000002   659 	ar2 = 0x02
                           000001   660 	ar1 = 0x01
                           000000   661 	ar0 = 0x00
                                    662 ;	drivers/uart/uart.c:6: PCA0MD &= ~0x40;   // отключить watchdog
      00028B 53 D9 BF         [24]  663 	anl	_PCA0MD,#0xbf
                                    664 ;	drivers/uart/uart.c:9: SCON0 = 0x10;      // REN0 = 1, mode 1
      00028E 75 98 10         [24]  665 	mov	_SCON0,#0x10
                                    666 ;	drivers/uart/uart.c:12: TMOD &= ~0xF0;
      000291 53 89 0F         [24]  667 	anl	_TMOD,#0x0f
                                    668 ;	drivers/uart/uart.c:13: TMOD |=  0x20;     // Timer1 mode 2
      000294 43 89 20         [24]  669 	orl	_TMOD,#0x20
                                    670 ;	drivers/uart/uart.c:17: CKCON &= ~0x0B;    // Timer1 тактируется от SYSCLK/12
      000297 53 8E F4         [24]  671 	anl	_CKCON,#0xf4
                                    672 ;	drivers/uart/uart.c:18: TH1 = 0x96;
      00029A 75 8D 96         [24]  673 	mov	_TH1,#0x96
                                    674 ;	drivers/uart/uart.c:19: TL1 = 0x96;
      00029D 75 8B 96         [24]  675 	mov	_TL1,#0x96
                                    676 ;	drivers/uart/uart.c:21: TR1 = 1;           // запустить Timer1
                                    677 ;	assignBit
      0002A0 D2 8E            [12]  678 	setb	_TR1
                                    679 ;	drivers/uart/uart.c:22: TI0 = 1;           // передатчик готов
                                    680 ;	assignBit
      0002A2 D2 99            [12]  681 	setb	_TI0
                                    682 ;	drivers/uart/uart.c:23: }
      0002A4 22               [24]  683 	ret
                                    684 ;------------------------------------------------------------
                                    685 ;Allocation info for local variables in function 'uart_send_char'
                                    686 ;------------------------------------------------------------
                                    687 ;c                         Allocated to registers r7 
                                    688 ;------------------------------------------------------------
                                    689 ;	drivers/uart/uart.c:25: void uart_send_char(char c){
                                    690 ;	-----------------------------------------
                                    691 ;	 function uart_send_char
                                    692 ;	-----------------------------------------
      0002A5                        693 _uart_send_char:
      0002A5 AF 82            [24]  694 	mov	r7,dpl
                                    695 ;	drivers/uart/uart.c:26: while (TI0 == 0);
      0002A7                        696 00101$:
                                    697 ;	drivers/uart/uart.c:27: TI0 = 0;
                                    698 ;	assignBit
      0002A7 10 99 02         [24]  699 	jbc	_TI0,00114$
      0002AA 80 FB            [24]  700 	sjmp	00101$
      0002AC                        701 00114$:
                                    702 ;	drivers/uart/uart.c:28: SBUF0 = c;
      0002AC 8F 99            [24]  703 	mov	_SBUF0,r7
                                    704 ;	drivers/uart/uart.c:29: }
      0002AE 22               [24]  705 	ret
                                    706 ;------------------------------------------------------------
                                    707 ;Allocation info for local variables in function 'uart_read_char'
                                    708 ;------------------------------------------------------------
                                    709 ;	drivers/uart/uart.c:31: char uart_read_char(void){
                                    710 ;	-----------------------------------------
                                    711 ;	 function uart_read_char
                                    712 ;	-----------------------------------------
      0002AF                        713 _uart_read_char:
                                    714 ;	drivers/uart/uart.c:32: while (RI0 == 0);
      0002AF                        715 00101$:
                                    716 ;	drivers/uart/uart.c:33: RI0 = 0;
                                    717 ;	assignBit
      0002AF 10 98 02         [24]  718 	jbc	_RI0,00114$
      0002B2 80 FB            [24]  719 	sjmp	00101$
      0002B4                        720 00114$:
                                    721 ;	drivers/uart/uart.c:34: return SBUF0;
      0002B4 85 99 82         [24]  722 	mov	dpl,_SBUF0
                                    723 ;	drivers/uart/uart.c:35: }
      0002B7 22               [24]  724 	ret
                                    725 	.area CSEG    (CODE)
                                    726 	.area CONST   (CODE)
                                    727 	.area XINIT   (CODE)
                                    728 	.area CABS    (ABS,CODE)
