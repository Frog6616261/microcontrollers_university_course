;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _font_space
	.globl _font_Z
	.globl _font_Y
	.globl _font_X
	.globl _font_W
	.globl _font_V
	.globl _font_U
	.globl _font_T
	.globl _font_S
	.globl _font_R
	.globl _font_Q
	.globl _font_P
	.globl _font_O
	.globl _font_N
	.globl _font_M
	.globl _font_L
	.globl _font_K
	.globl _font_J
	.globl _font_I
	.globl _font_H
	.globl _font_G
	.globl _font_F
	.globl _font_E
	.globl _font_D
	.globl _font_C
	.globl _font_B
	.globl _font_A
	.globl _Timer_ISR
	.globl _main
	.globl _Interrupts_Init
	.globl _Timers_Init
	.globl _get_word_length
	.globl _get_word_value
	.globl _TTT
	.globl _CLR
	.globl _CLK
	.globl _SPIF
	.globl _WCOL
	.globl _MODF
	.globl _RXOVRN
	.globl _NSSMD1
	.globl _NSSMD0
	.globl _TXBMT
	.globl _SPIEN
	.globl _AD0EN
	.globl _AD0TM
	.globl _AD0INT
	.globl _AD0BUSY
	.globl _AD0WINT
	.globl _AD0CM2
	.globl _AD0CM1
	.globl _AD0CM0
	.globl _CF
	.globl _CR
	.globl _CCF5
	.globl _CCF4
	.globl _CCF3
	.globl _CCF2
	.globl _CCF1
	.globl _CCF0
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _TF2H
	.globl _TF2L
	.globl _TF2LEN
	.globl _TF2CEN
	.globl _T2SPLIT
	.globl _TR2
	.globl _T2XCLK
	.globl _MASTER
	.globl _TXMODE
	.globl _STA
	.globl _STO
	.globl _ACKRQ
	.globl _ARBLOST
	.globl _ACK
	.globl _SI
	.globl _PSPI0
	.globl _PT2
	.globl _PS0
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ESPI0
	.globl _ET2
	.globl _ES0
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _S0MODE
	.globl _MCE0
	.globl _REN0
	.globl _TB80
	.globl _RB80
	.globl _TI0
	.globl _RI0
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _EMI0TC
	.globl _P3MDIN
	.globl _P2MDIN
	.globl _P1MDIN
	.globl _P0MDIN
	.globl _SFR0CN
	.globl _XBR1
	.globl _XBR0
	.globl _P3SKIP
	.globl _P2SKIP
	.globl _P1SKIP
	.globl _P0SKIP
	.globl _CCH0MA
	.globl _CCH0LC
	.globl _EIP2
	.globl _EIP1
	.globl _CCH0TN
	.globl _EMI0CF
	.globl _OSCICL
	.globl _OSCICN
	.globl _OSCXCN
	.globl _PLL0CN
	.globl _PLL0FLT
	.globl _PLL0MUL
	.globl _P3MDOUT
	.globl _P4MDOUT
	.globl _OSCLCN
	.globl _FLSTAT
	.globl _PLL0DIV
	.globl _P2MDOUT
	.globl _P1MDOUT
	.globl _P0MDOUT
	.globl _CLKSEL
	.globl _CCH0CN
	.globl _P0MASK
	.globl _P0MAT
	.globl _MAC0BH
	.globl _MAC0BL
	.globl _P1MASK
	.globl _P1MAT
	.globl _MAC0CF
	.globl _MAC0OVR
	.globl _MAC0ACC3
	.globl _MAC0ACC2
	.globl _MAC0ACC1
	.globl _MAC0ACC0
	.globl _MAC0ACC
	.globl _MAC0STA
	.globl _FLKEY
	.globl _FLSCL
	.globl _P2MASK
	.globl _P2MAT
	.globl _MAC0RNDH
	.globl _MAC0RNDL
	.globl _MAC0RND
	.globl _MAC0AH
	.globl _MAC0AL
	.globl _MAC0A
	.globl _PSCTL
	.globl _VDM0CN
	.globl _PCA0CPH4
	.globl _PCA0CPL4
	.globl _PCA0CP4
	.globl _PCA0CPH0
	.globl _PCA0CPL0
	.globl _PCA0CP0
	.globl _PCA0H
	.globl _PCA0L
	.globl _PCA0
	.globl _SPI0CN
	.globl _PCA0CPH5
	.globl _PCA0CPL5
	.globl _PCA0CP5
	.globl _B
	.globl _RSTSRC
	.globl _PCA0CPH3
	.globl _PCA0CPL3
	.globl _PCA0CP3
	.globl _PCA0CPH2
	.globl _PCA0CPL2
	.globl _PCA0CP2
	.globl _PCA0CPH1
	.globl _PCA0CPL1
	.globl _PCA0CP1
	.globl _ADC0CN
	.globl _EIE2
	.globl _EIE1
	.globl _IT01CF
	.globl _ACC
	.globl _PCA0CPM5
	.globl _PCA0CPM4
	.globl _PCA0CPM3
	.globl _PCA0CPM2
	.globl _PCA0CPM1
	.globl _PCA0CPM0
	.globl _PCA0MD
	.globl _PCA0CN
	.globl _REF0CN
	.globl _PSW
	.globl _TMR2H
	.globl _TMR2L
	.globl _TMR2
	.globl _TMR2RLH
	.globl _TMR2RLL
	.globl _TMR2RL
	.globl _TMR2CN
	.globl _ADC0LTH
	.globl _ADC0LTL
	.globl _ADC0LT
	.globl _ADC0GTH
	.globl _ADC0GTL
	.globl _ADC0GT
	.globl _SMB0DAT
	.globl _SMB0CF
	.globl _SMB0CN
	.globl _ADC0H
	.globl _ADC0L
	.globl _ADC0
	.globl _ADC0CF
	.globl _AMX0P
	.globl _AMX0N
	.globl _IDA0CN
	.globl _IP
	.globl _P4
	.globl _P3
	.globl __XPAGE
	.globl _EMI0CN
	.globl _IE
	.globl _SFRPAGE
	.globl _SPI0DAT
	.globl _SPI0CKR
	.globl _SPI0CFG
	.globl _P2
	.globl _CPT0MX
	.globl _CPT1MX
	.globl _CPT0MD
	.globl _CPT1MD
	.globl _CPT0CN
	.globl _CPT1CN
	.globl _SBUF0
	.globl _SCON0
	.globl _IDA0H
	.globl _IDA0L
	.globl _IDA0
	.globl _TMR3H
	.globl _TMR3L
	.globl _TMR3
	.globl _TMR3RLH
	.globl _TMR3RLL
	.globl _TMR3RL
	.globl _TMR3CN
	.globl _P1
	.globl _CKCON
	.globl _TH1
	.globl _TL1
	.globl _TMR1
	.globl _TH0
	.globl _TL0
	.globl _TMR0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _SFRLAST
	.globl _SFRNEXT
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _g_word_size
	.globl _g_delta_time_for_word
	.globl _g_cur_time_for_word
	.globl _g_parts_count
	.globl _g_cursor
	.globl _g_delta_pos
	.globl _word_parts
	.globl _PORT_Init
	.globl _Init_Device
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_SFRNEXT	=	0x0085
_SFRLAST	=	0x0086
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TMR0	=	0x8c8a
_TL0	=	0x008a
_TH0	=	0x008c
_TMR1	=	0x8d8b
_TL1	=	0x008b
_TH1	=	0x008d
_CKCON	=	0x008e
_P1	=	0x0090
_TMR3CN	=	0x0091
_TMR3RL	=	0x9392
_TMR3RLL	=	0x0092
_TMR3RLH	=	0x0093
_TMR3	=	0x9594
_TMR3L	=	0x0094
_TMR3H	=	0x0095
_IDA0	=	0x9796
_IDA0L	=	0x0096
_IDA0H	=	0x0097
_SCON0	=	0x0098
_SBUF0	=	0x0099
_CPT1CN	=	0x009a
_CPT0CN	=	0x009b
_CPT1MD	=	0x009c
_CPT0MD	=	0x009d
_CPT1MX	=	0x009e
_CPT0MX	=	0x009f
_P2	=	0x00a0
_SPI0CFG	=	0x00a1
_SPI0CKR	=	0x00a2
_SPI0DAT	=	0x00a3
_SFRPAGE	=	0x00a7
_IE	=	0x00a8
_EMI0CN	=	0x00aa
__XPAGE	=	0x00aa
_P3	=	0x00b0
_P4	=	0x00b5
_IP	=	0x00b8
_IDA0CN	=	0x00b9
_AMX0N	=	0x00ba
_AMX0P	=	0x00bb
_ADC0CF	=	0x00bc
_ADC0	=	0xbebd
_ADC0L	=	0x00bd
_ADC0H	=	0x00be
_SMB0CN	=	0x00c0
_SMB0CF	=	0x00c1
_SMB0DAT	=	0x00c2
_ADC0GT	=	0xc4c3
_ADC0GTL	=	0x00c3
_ADC0GTH	=	0x00c4
_ADC0LT	=	0xc6c5
_ADC0LTL	=	0x00c5
_ADC0LTH	=	0x00c6
_TMR2CN	=	0x00c8
_TMR2RL	=	0xcbca
_TMR2RLL	=	0x00ca
_TMR2RLH	=	0x00cb
_TMR2	=	0xcdcc
_TMR2L	=	0x00cc
_TMR2H	=	0x00cd
_PSW	=	0x00d0
_REF0CN	=	0x00d1
_PCA0CN	=	0x00d8
_PCA0MD	=	0x00d9
_PCA0CPM0	=	0x00da
_PCA0CPM1	=	0x00db
_PCA0CPM2	=	0x00dc
_PCA0CPM3	=	0x00dd
_PCA0CPM4	=	0x00de
_PCA0CPM5	=	0x00df
_ACC	=	0x00e0
_IT01CF	=	0x00e4
_EIE1	=	0x00e6
_EIE2	=	0x00e7
_ADC0CN	=	0x00e8
_PCA0CP1	=	0xeae9
_PCA0CPL1	=	0x00e9
_PCA0CPH1	=	0x00ea
_PCA0CP2	=	0xeceb
_PCA0CPL2	=	0x00eb
_PCA0CPH2	=	0x00ec
_PCA0CP3	=	0xeeed
_PCA0CPL3	=	0x00ed
_PCA0CPH3	=	0x00ee
_RSTSRC	=	0x00ef
_B	=	0x00f0
_PCA0CP5	=	0xf6f5
_PCA0CPL5	=	0x00f5
_PCA0CPH5	=	0x00f6
_SPI0CN	=	0x00f8
_PCA0	=	0xfaf9
_PCA0L	=	0x00f9
_PCA0H	=	0x00fa
_PCA0CP0	=	0xfcfb
_PCA0CPL0	=	0x00fb
_PCA0CPH0	=	0x00fc
_PCA0CP4	=	0xfefd
_PCA0CPL4	=	0x00fd
_PCA0CPH4	=	0x00fe
_VDM0CN	=	0x00ff
_PSCTL	=	0x008f
_MAC0A	=	0xa5a4
_MAC0AL	=	0x00a4
_MAC0AH	=	0x00a5
_MAC0RND	=	0xafae
_MAC0RNDL	=	0x00ae
_MAC0RNDH	=	0x00af
_P2MAT	=	0x00b1
_P2MASK	=	0x00b2
_FLSCL	=	0x00b6
_FLKEY	=	0x00b7
_MAC0STA	=	0x00cf
_MAC0ACC	=	0xd5d4d3d2
_MAC0ACC0	=	0x00d2
_MAC0ACC1	=	0x00d3
_MAC0ACC2	=	0x00d4
_MAC0ACC3	=	0x00d5
_MAC0OVR	=	0x00d6
_MAC0CF	=	0x00d7
_P1MAT	=	0x00e1
_P1MASK	=	0x00e2
_MAC0BL	=	0x00f1
_MAC0BH	=	0x00f2
_P0MAT	=	0x00f3
_P0MASK	=	0x00f4
_CCH0CN	=	0x0084
_CLKSEL	=	0x008f
_P0MDOUT	=	0x00a4
_P1MDOUT	=	0x00a5
_P2MDOUT	=	0x00a6
_PLL0DIV	=	0x00a9
_FLSTAT	=	0x00ac
_OSCLCN	=	0x00ad
_P4MDOUT	=	0x00ae
_P3MDOUT	=	0x00af
_PLL0MUL	=	0x00b1
_PLL0FLT	=	0x00b2
_PLL0CN	=	0x00b3
_OSCXCN	=	0x00b6
_OSCICN	=	0x00b7
_OSCICL	=	0x00bf
_EMI0CF	=	0x00c7
_CCH0TN	=	0x00c9
_EIP1	=	0x00ce
_EIP2	=	0x00cf
_CCH0LC	=	0x00d2
_CCH0MA	=	0x00d3
_P0SKIP	=	0x00d4
_P1SKIP	=	0x00d5
_P2SKIP	=	0x00d6
_P3SKIP	=	0x00d7
_XBR0	=	0x00e1
_XBR1	=	0x00e2
_SFR0CN	=	0x00e5
_P0MDIN	=	0x00f1
_P1MDIN	=	0x00f2
_P2MDIN	=	0x00f3
_P3MDIN	=	0x00f4
_EMI0TC	=	0x00f7
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI0	=	0x0098
_TI0	=	0x0099
_RB80	=	0x009a
_TB80	=	0x009b
_REN0	=	0x009c
_MCE0	=	0x009d
_S0MODE	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES0	=	0x00ac
_ET2	=	0x00ad
_ESPI0	=	0x00ae
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS0	=	0x00bc
_PT2	=	0x00bd
_PSPI0	=	0x00be
_SI	=	0x00c0
_ACK	=	0x00c1
_ARBLOST	=	0x00c2
_ACKRQ	=	0x00c3
_STO	=	0x00c4
_STA	=	0x00c5
_TXMODE	=	0x00c6
_MASTER	=	0x00c7
_T2XCLK	=	0x00c8
_TR2	=	0x00ca
_T2SPLIT	=	0x00cb
_TF2CEN	=	0x00cc
_TF2LEN	=	0x00cd
_TF2L	=	0x00ce
_TF2H	=	0x00cf
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
_CCF0	=	0x00d8
_CCF1	=	0x00d9
_CCF2	=	0x00da
_CCF3	=	0x00db
_CCF4	=	0x00dc
_CCF5	=	0x00dd
_CR	=	0x00de
_CF	=	0x00df
_AD0CM0	=	0x00e8
_AD0CM1	=	0x00e9
_AD0CM2	=	0x00ea
_AD0WINT	=	0x00eb
_AD0BUSY	=	0x00ec
_AD0INT	=	0x00ed
_AD0TM	=	0x00ee
_AD0EN	=	0x00ef
_SPIEN	=	0x00f8
_TXBMT	=	0x00f9
_NSSMD0	=	0x00fa
_NSSMD1	=	0x00fb
_RXOVRN	=	0x00fc
_MODF	=	0x00fd
_WCOL	=	0x00fe
_SPIF	=	0x00ff
_CLK::
	.ds 1
_CLR::
	.ds 1
_TTT::
	.ds 1
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_word_parts::
	.ds 45
_g_delta_pos::
	.ds 2
_g_cursor::
	.ds 2
_g_parts_count::
	.ds 2
_g_cur_time_for_word::
	.ds 2
_g_delta_time_for_word::
	.ds 2
_g_word_size::
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

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
; interrupt vector
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
;	main.c:20: struct word_part word_parts[] = {  
	mov	(_word_parts + 0),#_font_M
	mov	(_word_parts + 1),#(_font_M >> 8)
	mov	(_word_parts + 2),#0x80
	mov	((_word_parts + 0x0003) + 0),#0x09
	mov	((_word_parts + 0x0003) + 1),#0x00
	mov	((_word_parts + 0x0005) + 0),#_font_I
	mov	((_word_parts + 0x0005) + 1),#(_font_I >> 8)
	mov	((_word_parts + 0x0005) + 2),#0x80
	mov	((_word_parts + 0x0008) + 0),#0x08
	mov	((_word_parts + 0x0008) + 1),#0x00
	mov	((_word_parts + 0x000a) + 0),#_font_C
	mov	((_word_parts + 0x000a) + 1),#(_font_C >> 8)
	mov	((_word_parts + 0x000a) + 2),#0x80
	mov	((_word_parts + 0x000d) + 0),#0x08
	mov	((_word_parts + 0x000d) + 1),#0x00
	mov	((_word_parts + 0x000f) + 0),#_font_H
	mov	((_word_parts + 0x000f) + 1),#(_font_H >> 8)
	mov	((_word_parts + 0x000f) + 2),#0x80
	mov	((_word_parts + 0x0012) + 0),#0x07
	mov	((_word_parts + 0x0012) + 1),#0x00
	mov	((_word_parts + 0x0014) + 0),#_font_E
	mov	((_word_parts + 0x0014) + 1),#(_font_E >> 8)
	mov	((_word_parts + 0x0014) + 2),#0x80
	mov	((_word_parts + 0x0017) + 0),#0x08
	mov	((_word_parts + 0x0017) + 1),#0x00
	mov	((_word_parts + 0x0019) + 0),#_font_L
	mov	((_word_parts + 0x0019) + 1),#(_font_L >> 8)
	mov	((_word_parts + 0x0019) + 2),#0x80
	mov	((_word_parts + 0x001c) + 0),#0x07
	mov	((_word_parts + 0x001c) + 1),#0x00
	mov	((_word_parts + 0x001e) + 0),#_font_L
	mov	((_word_parts + 0x001e) + 1),#(_font_L >> 8)
	mov	((_word_parts + 0x001e) + 2),#0x80
	mov	((_word_parts + 0x0021) + 0),#0x07
	mov	((_word_parts + 0x0021) + 1),#0x00
	mov	((_word_parts + 0x0023) + 0),#_font_E
	mov	((_word_parts + 0x0023) + 1),#(_font_E >> 8)
	mov	((_word_parts + 0x0023) + 2),#0x80
	mov	((_word_parts + 0x0026) + 0),#0x08
	mov	((_word_parts + 0x0026) + 1),#0x00
	mov	((_word_parts + 0x0028) + 0),#_font_space
	mov	((_word_parts + 0x0028) + 1),#(_font_space >> 8)
	mov	((_word_parts + 0x0028) + 2),#0x80
	mov	((_word_parts + 0x002b) + 0),#0x03
	mov	((_word_parts + 0x002b) + 1),#0x00
;	main.c:32: int g_delta_pos = 0;
	clr	a
	mov	_g_delta_pos,a
	mov	(_g_delta_pos + 1),a
;	main.c:33: int g_cursor = 0;
	mov	_g_cursor,a
	mov	(_g_cursor + 1),a
;	main.c:34: int g_parts_count = 9;
	mov	_g_parts_count,#0x09
;	1-genFromRTrack replaced	mov	(_g_parts_count + 1),#0x00
	mov	(_g_parts_count + 1),a
;	main.c:35: unsigned int g_cur_time_for_word = 0;
	mov	_g_cur_time_for_word,a
	mov	(_g_cur_time_for_word + 1),a
;	main.c:36: unsigned int g_delta_time_for_word = 100;
	mov	_g_delta_time_for_word,#0x64
;	1-genFromRTrack replaced	mov	(_g_delta_time_for_word + 1),#0x00
	mov	(_g_delta_time_for_word + 1),a
;	main.c:37: int g_word_size = 0;
	mov	_g_word_size,a
	mov	(_g_word_size + 1),a
;	main.c:14: __sbit CLK = P2^7;
	mov	a,#0x07
	xrl	a,_P2
;	assignBit
	mov	r7,a
	add	a,#0xff
	mov	_CLK,c
;	main.c:15: __sbit CLR = P1^7;
	mov	a,#0x07
	xrl	a,_P1
;	assignBit
	mov	r7,a
	add	a,#0xff
	mov	_CLR,c
;	main.c:16: __sbit TTT = P2^0;
;	assignBit
	mov	a,_P2
	mov	r7,a
	add	a,#0xff
	mov	_TTT,c
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'Timers_Init'
;------------------------------------------------------------
;	drivers/timer/timer.h:6: void Timers_Init()
;	-----------------------------------------
;	 function Timers_Init
;	-----------------------------------------
_Timers_Init:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	drivers/timer/timer.h:8: TCON      = 0x50;
	mov	_TCON,#0x50
;	drivers/timer/timer.h:9: TMOD      = 0x11;
	mov	_TMOD,#0x11
;	drivers/timer/timer.h:10: CKCON     = 0x02;
	mov	_CKCON,#0x02
;	drivers/timer/timer.h:12: TL0       = 0xff; 
	mov	_TL0,#0xff
;	drivers/timer/timer.h:13: TH0       = 0xf6; 
	mov	_TH0,#0xf6
;	drivers/timer/timer.h:14: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Interrupts_Init'
;------------------------------------------------------------
;	drivers/timer/timer.h:17: void Interrupts_Init()
;	-----------------------------------------
;	 function Interrupts_Init
;	-----------------------------------------
_Interrupts_Init:
;	drivers/timer/timer.h:19: IE        = 0x8A;
	mov	_IE,#0x8a
;	drivers/timer/timer.h:20: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;	main.c:45: int main (void) 
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	main.c:49: PCA0MD &= ~0x40;                    // WDTE = 0 (clear watchdog timer
	anl	_PCA0MD,#0xbf
;	main.c:51: PORT_Init ();
	lcall	_PORT_Init
;	main.c:52: Init_Device();
	lcall	_Init_Device
;	main.c:54: P2 = 0x00;
	mov	_P2,#0x00
;	main.c:55: CLR = 0;
;	assignBit
	clr	_CLR
;	main.c:56: g_cursor = 0;
	clr	a
	mov	_g_cursor,a
	mov	(_g_cursor + 1),a
;	main.c:58: g_word_size = get_word_length(g_parts_count, word_parts);
	mov	_get_word_length_PARM_2,#_word_parts
;	1-genFromRTrack replaced	mov	(_get_word_length_PARM_2 + 1),#0x00
	mov	(_get_word_length_PARM_2 + 1),a
	mov	(_get_word_length_PARM_2 + 2),#0x40
	mov	dpl,_g_parts_count
	mov	dph,(_g_parts_count + 1)
	lcall	_get_word_length
	mov	_g_word_size,dpl
	mov	(_g_word_size + 1),dph
;	main.c:60: if (g_word_size < 47) {
	clr	c
	mov	a,_g_word_size
	subb	a,#0x2f
	mov	a,(_g_word_size + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00104$
;	main.c:61: g_word_size = 47; 
	mov	_g_word_size,#0x2f
	mov	(_g_word_size + 1),#0x00
;	main.c:64: while (1) {
00104$:
;	main.c:67: return 0;
;	main.c:68: }
	sjmp	00104$
;------------------------------------------------------------
;Allocation info for local variables in function 'PORT_Init'
;------------------------------------------------------------
;SFRPAGE_save              Allocated to registers r7 
;SFRPAGE_for_XBR1          Allocated to registers 
;------------------------------------------------------------
;	main.c:71: void PORT_Init (void)
;	-----------------------------------------
;	 function PORT_Init
;	-----------------------------------------
_PORT_Init:
;	main.c:73: unsigned char SFRPAGE_save = SFRPAGE; // Save the current SFRPAGE
	mov	r7,_SFRPAGE
;	main.c:77: SFRPAGE = SFRPAGE_for_XBR1;              // Switch to the necessary SFRPAGE
	mov	_SFRPAGE,#0x0f
;	main.c:79: XBR1    = 0x40;                     // Enable crossbar and weak pull-ups
	mov	_XBR1,#0x40
;	main.c:81: SFRPAGE = SFRPAGE_save;             // Restore the SFRPAGE
	mov	_SFRPAGE,r7
;	main.c:82: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Timer_ISR'
;------------------------------------------------------------
;	main.c:85: void Timer_ISR(void) //interrupt 1
;	-----------------------------------------
;	 function Timer_ISR
;	-----------------------------------------
_Timer_ISR:
;	main.c:87: P2 = ~(get_word_value((g_cursor-g_delta_pos), g_word_size, g_parts_count, word_parts));
	mov	a,_g_cursor
	clr	c
	subb	a,_g_delta_pos
	mov	dpl,a
	mov	a,(_g_cursor + 1)
	subb	a,(_g_delta_pos + 1)
	mov	dph,a
	mov	_get_word_value_PARM_4,#_word_parts
	mov	(_get_word_value_PARM_4 + 1),#0x00
	mov	(_get_word_value_PARM_4 + 2),#0x40
	mov	_get_word_value_PARM_2,_g_word_size
	mov	(_get_word_value_PARM_2 + 1),(_g_word_size + 1)
	mov	_get_word_value_PARM_3,_g_parts_count
	mov	(_get_word_value_PARM_3 + 1),(_g_parts_count + 1)
	lcall	_get_word_value
	mov	r6,dpl
	mov	a,r6
	cpl	a
	mov	_P2,a
;	main.c:90: CLK = 0;
;	assignBit
	clr	_CLK
;	main.c:91: CLK = 1;
;	assignBit
	setb	_CLK
;	main.c:93: if (g_cursor < 48) {
	clr	c
	mov	a,_g_cursor
	subb	a,#0x30
	mov	a,(_g_cursor + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00102$
;	main.c:94: g_cursor++; 
	inc	_g_cursor
	clr	a
	cjne	a,_g_cursor,00103$
	inc	(_g_cursor + 1)
	sjmp	00103$
00102$:
;	main.c:96: g_cursor = 0; 
	clr	a
	mov	_g_cursor,a
	mov	(_g_cursor + 1),a
00103$:
;	main.c:100: if (g_cur_time_for_word == g_delta_time_for_word)
	mov	a,_g_delta_time_for_word
	cjne	a,_g_cur_time_for_word,00105$
	mov	a,(_g_delta_time_for_word + 1)
	cjne	a,(_g_cur_time_for_word + 1),00105$
;	main.c:101: g_cur_time_for_word = 0;
	clr	a
	mov	_g_cur_time_for_word,a
	mov	(_g_cur_time_for_word + 1),a
00105$:
;	main.c:102: g_delta_pos++;
	inc	_g_delta_pos
	clr	a
	cjne	a,_g_delta_pos,00126$
	inc	(_g_delta_pos + 1)
00126$:
;	main.c:104: if (g_delta_pos == g_word_size){
	mov	a,_g_word_size
	cjne	a,_g_delta_pos,00107$
	mov	a,(_g_word_size + 1)
	cjne	a,(_g_delta_pos + 1),00107$
;	main.c:105: g_delta_pos = 0;
	clr	a
	mov	_g_delta_pos,a
	mov	(_g_delta_pos + 1),a
00107$:
;	main.c:108: TL1       = 0x00; 
	mov	_TL1,#0x00
;	main.c:109: TH1       = 0xC0;
	mov	_TH1,#0xc0
;	main.c:111: g_cur_time_for_word++;
	inc	_g_cur_time_for_word
	clr	a
	cjne	a,_g_cur_time_for_word,00129$
	inc	(_g_cur_time_for_word + 1)
00129$:
;	main.c:113: TL0       = 0xee; 
	mov	_TL0,#0xee
;	main.c:114: TH0       = 0xff; 
	mov	_TH0,#0xff
;	main.c:115: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Init_Device'
;------------------------------------------------------------
;	main.c:120: void Init_Device(void)
;	-----------------------------------------
;	 function Init_Device
;	-----------------------------------------
_Init_Device:
;	main.c:122: Timers_Init();
	lcall	_Timers_Init
;	main.c:123: Interrupts_Init();     
;	main.c:124: }
	ljmp	_Interrupts_Init
	.area CSEG    (CODE)
	.area CONST   (CODE)
_font_A:
	.db #0x8e	; 142
	.db #0x12	; 18
	.db #0x11	; 17
	.db #0x11	; 17
	.db #0x11	; 17
	.db #0x12	; 18
	.db #0x8e	; 142
	.db #0x00	; 0
_font_B:
	.db #0x8f	; 143
	.db #0x49	; 73	'I'
	.db #0x49	; 73	'I'
	.db #0x49	; 73	'I'
	.db #0x49	; 73	'I'
	.db #0x49	; 73	'I'
	.db #0x36	; 54	'6'
	.db #0x00	; 0
_font_C:
	.db #0x1c	; 28
	.db #0x22	; 34
	.db #0x41	; 65	'A'
	.db #0x41	; 65	'A'
	.db #0x41	; 65	'A'
	.db #0x41	; 65	'A'
	.db #0x22	; 34
	.db #0x00	; 0
_font_D:
	.db #0x7f	; 127
	.db #0x41	; 65	'A'
	.db #0x41	; 65	'A'
	.db #0x41	; 65	'A'
	.db #0x41	; 65	'A'
	.db #0x22	; 34
	.db #0x1c	; 28
	.db #0x00	; 0
_font_E:
	.db #0x7f	; 127
	.db #0x49	; 73	'I'
	.db #0x49	; 73	'I'
	.db #0x49	; 73	'I'
	.db #0x49	; 73	'I'
	.db #0x49	; 73	'I'
	.db #0x41	; 65	'A'
	.db #0x00	; 0
_font_F:
	.db #0xff	; 255
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x80	; 128
	.db #0x00	; 0
_font_G:
	.db #0x78	; 120	'x'
	.db #0x84	; 132
	.db #0x02	; 2
	.db #0x12	; 18
	.db #0x12	; 18
	.db #0x12	; 18
	.db #0x9c	; 156
	.db #0x00	; 0
_font_H:
	.db #0x7f	; 127
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x7f	; 127
	.db #0x00	; 0
_font_I:
	.db #0x41	; 65	'A'
	.db #0x41	; 65	'A'
	.db #0x41	; 65	'A'
	.db #0x7f	; 127
	.db #0x41	; 65	'A'
	.db #0x41	; 65	'A'
	.db #0x41	; 65	'A'
	.db #0x00	; 0
_font_J:
	.db #0x20	; 32
	.db #0x40	; 64
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0x41	; 65	'A'
	.db #0x3f	; 63
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x00	; 0
_font_K:
	.db #0xff	; 255
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x28	; 40
	.db #0x44	; 68	'D'
	.db #0x82	; 130
	.db #0x81	; 129
	.db #0x00	; 0
_font_L:
	.db #0x7f	; 127
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x00	; 0
_font_M:
	.db #0xff	; 255
	.db #0x02	; 2
	.db #0x04	; 4
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x04	; 4
	.db #0x02	; 2
	.db #0xff	; 255
	.db #0x00	; 0
_font_N:
	.db #0xff	; 255
	.db #0x02	; 2
	.db #0x04	; 4
	.db #0x08	; 8
	.db #0x10	; 16
	.db #0x20	; 32
	.db #0x40	; 64
	.db #0xff	; 255
	.db #0x00	; 0
_font_O:
	.db #0x3c	; 60
	.db #0x42	; 66	'B'
	.db #0x81	; 129
	.db #0x81	; 129
	.db #0x81	; 129
	.db #0x81	; 129
	.db #0x42	; 66	'B'
	.db #0x3c	; 60
	.db #0x00	; 0
_font_P:
	.db #0xff	; 255
	.db #0x09	; 9
	.db #0x09	; 9
	.db #0x09	; 9
	.db #0x09	; 9
	.db #0x09	; 9
	.db #0x06	; 6
	.db #0x00	; 0
_font_Q:
	.db #0x3c	; 60
	.db #0x42	; 66	'B'
	.db #0x81	; 129
	.db #0x81	; 129
	.db #0x81	; 129
	.db #0xa1	; 161
	.db #0x42	; 66	'B'
	.db #0xbc	; 188
	.db #0x00	; 0
_font_R:
	.db #0xff	; 255
	.db #0x09	; 9
	.db #0x09	; 9
	.db #0x19	; 25
	.db #0x29	; 41
	.db #0x49	; 73	'I'
	.db #0x86	; 134
	.db #0x00	; 0
_font_S:
	.db #0x46	; 70	'F'
	.db #0x89	; 137
	.db #0x89	; 137
	.db #0x89	; 137
	.db #0x89	; 137
	.db #0x89	; 137
	.db #0x72	; 114	'r'
	.db #0x00	; 0
_font_T:
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x00	; 0
_font_U:
	.db #0x3f	; 63
	.db #0x40	; 64
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0x3f	; 63
	.db #0x00	; 0
_font_V:
	.db #0x03	; 3
	.db #0x0c	; 12
	.db #0x30	; 48	'0'
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x30	; 48	'0'
	.db #0x0c	; 12
	.db #0x03	; 3
	.db #0x00	; 0
_font_W:
	.db #0xff	; 255
	.db #0x20	; 32
	.db #0x10	; 16
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x10	; 16
	.db #0x20	; 32
	.db #0xff	; 255
	.db #0x00	; 0
_font_X:
	.db #0x81	; 129
	.db #0x42	; 66	'B'
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x42	; 66	'B'
	.db #0x81	; 129
	.db #0x00	; 0
_font_Y:
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x04	; 4
	.db #0xf8	; 248
	.db #0x08	; 8
	.db #0x04	; 4
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x00	; 0
_font_Z:
	.db #0x81	; 129
	.db #0xc1	; 193
	.db #0xa1	; 161
	.db #0x91	; 145
	.db #0x89	; 137
	.db #0x85	; 133
	.db #0x83	; 131
	.db #0x81	; 129
	.db #0x00	; 0
_font_space:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
