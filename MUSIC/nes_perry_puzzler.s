;this file for FamiTone2 library generated by text2data tool

nes_perry_puzzler_music_data:
	.byte 2
	.word @instruments
	.word @samples-3
	.word @song0ch0,@song0ch1,@song0ch2,@song0ch3,@song0ch4,307,256
	.word @song1ch0,@song1ch1,@song1ch2,@song1ch3,@song1ch4,307,256

@instruments:
	.byte $30 ;instrument $01
	.word @env3,@env0,@env5
	.byte $00
	.byte $b0 ;instrument $02
	.word @env1,@env0,@env0
	.byte $00
	.byte $30 ;instrument $04
	.word @env2,@env0,@env0
	.byte $00
	.byte $30 ;instrument $05
	.word @env4,@env0,@env0
	.byte $00

@samples:
@env0:
	.byte $c0,$00,$00
@env1:
	.byte $c8,$ce,$cd,$ca,$c9,$02,$c8,$c7,$c6,$c5,$c5,$c4,$c3,$c2,$c1,$c1
	.byte $c0,$00,$10
@env2:
	.byte $cf,$02,$cc,$c7,$c2,$c0,$00,$05
@env3:
	.byte $cd,$cf,$cc,$cb,$ca,$c9,$00,$05
@env4:
	.byte $ce,$cf,$cd,$cc,$cb,$ca,$c9,$c7,$c6,$c5,$c4,$c3,$c2,$c1,$c0,$00
	.byte $0e
@env5:
	.byte $c8,$c0,$00,$00


@song0ch0:
	.byte $fb,$06
@song0ch0loop:
@ref0:
	.byte $f9,$85
@ref1:
	.byte $f9,$85
@ref2:
	.byte $f9,$85
@ref3:
	.byte $f9,$85
@ref4:
	.byte $f9,$85
@ref5:
	.byte $f9,$85
@ref6:
	.byte $f9,$85
@ref7:
	.byte $f9,$85
	.byte $fd
	.word @song0ch0loop

@song0ch1:
@song0ch1loop:
@ref8:
	.byte $83,$82,$37,$3c,$89,$2b,$32,$89,$39,$40,$89,$2d,$32,$89,$3d,$45
	.byte $34,$85,$31,$37,$3e,$85,$39,$41,$48,$85,$2d,$32,$85
@ref9:
	.byte $83,$2b,$33,$3a,$85,$37,$3c,$89,$29,$2f,$36,$85,$33,$38,$89,$3d
	.byte $45,$34,$85,$31,$37,$3e,$85,$39,$41,$49,$25,$2d,$33,$3a,$81
@ref10:
	.byte $83,$37,$3c,$89,$2b,$32,$89,$39,$40,$89,$2d,$32,$89,$3d,$45,$34
	.byte $85,$31,$37,$3e,$85,$39,$41,$48,$85,$2d,$32,$85
@ref11:
	.byte $83,$2b,$33,$3a,$85,$37,$3c,$89,$29,$2f,$36,$85,$33,$39,$40,$85
	.byte $3d,$45,$34,$85,$31,$37,$3f,$32,$85,$3c,$85,$46,$8d
@ref12:
	.byte $2d,$31,$3f,$37,$37,$3f,$31,$2d,$3b,$37,$43,$31,$3b,$37,$31,$37
	.byte $2f,$35,$3d,$43,$3d,$43,$3d,$35,$2f,$39,$35,$41,$39,$41,$35,$2e
	.byte $81
@ref13:
	.byte $2d,$33,$3b,$33,$37,$3f,$45,$35,$2b,$3f,$39,$33,$35,$31,$3d,$43
	.byte $41,$29,$2f,$37,$1b,$2f,$3b,$41,$3f,$34,$85,$3e,$85,$31,$30,$85
	.byte $ff,$1c
	.word @ref10
	.byte $ff,$1f
	.word @ref9
	.byte $fd
	.word @song0ch1loop

@song0ch2:
@song0ch2loop:
@ref16:
	.byte $80,$2e,$8d,$28,$8d,$32,$8d,$24,$8d,$36,$8d,$28,$8d,$32,$8d,$24
	.byte $8d
@ref17:
	.byte $3c,$8d,$2e,$8d,$38,$8d,$2a,$8d,$36,$8d,$28,$8d,$32,$8d,$24,$8d
@ref18:
	.byte $2e,$8d,$28,$8d,$32,$8d,$24,$8d,$36,$8d,$28,$8d,$32,$8d,$24,$8d
@ref19:
	.byte $3c,$8d,$2e,$8d,$38,$8d,$2a,$8d,$36,$8d,$28,$8d,$1a,$85,$24,$85
	.byte $2e,$8d
@ref20:
	.byte $30,$8d,$30,$8d,$3a,$8d,$3a,$8d,$2e,$8d,$2e,$8d,$38,$8d,$38,$8d
@ref21:
	.byte $2c,$8d,$36,$8d,$2a,$8d,$34,$8d,$28,$8d,$32,$8d,$26,$8d,$30,$8d
	.byte $ff,$10
	.word @ref18
	.byte $ff,$10
	.word @ref17
	.byte $fd
	.word @song0ch2loop

@song0ch3:
@song0ch3loop:
@ref24:
	.byte $84,$20,$85,$86,$16,$85,$16,$85,$16,$85,$84,$20,$8d,$20,$85,$86
	.byte $16,$85,$84,$20,$85,$86,$16,$8d,$17,$17,$84,$20,$89,$21,$86,$16
	.byte $85,$16,$85
@ref25:
	.byte $84,$20,$85,$86,$16,$85,$16,$85,$16,$85,$84,$20,$8d,$20,$85,$86
	.byte $16,$85,$84,$20,$85,$86,$16,$8d,$16,$85,$84,$20,$8d,$86,$16,$85
	.byte $16,$85
	.byte $ff,$1b
	.word @ref24
	.byte $ff,$1a
	.word @ref25
@ref28:
	.byte $84,$20,$85,$86,$16,$85,$84,$20,$85,$86,$16,$85,$84,$20,$85,$86
	.byte $16,$85,$84,$21,$86,$17,$17,$17,$84,$20,$85,$86,$16,$85,$84,$20
	.byte $85,$86,$16,$85,$84,$21,$20,$85,$86,$17,$84,$20,$85,$86,$17,$84
	.byte $20,$81
@ref29:
	.byte $20,$85,$86,$17,$17,$84,$21,$86,$17,$16,$85,$84,$20,$85,$86,$16
	.byte $85,$84,$20,$85,$86,$16,$85,$84,$20,$85,$86,$16,$85,$84,$20,$85
	.byte $86,$16,$85,$84,$20,$85,$86,$17,$84,$21,$86,$17,$84,$21,$86,$16
	.byte $85
	.byte $ff,$1b
	.word @ref24
	.byte $ff,$1a
	.word @ref25
	.byte $fd
	.word @song0ch3loop

@song0ch4:
@song0ch4loop:
@ref32:
	.byte $f9,$85
@ref33:
	.byte $f9,$85
@ref34:
	.byte $f9,$85
@ref35:
	.byte $f9,$85
@ref36:
	.byte $f9,$85
@ref37:
	.byte $f9,$85
@ref38:
	.byte $f9,$85
@ref39:
	.byte $f9,$85
	.byte $fd
	.word @song0ch4loop


@song1ch0:
	.byte $fb,$07
@song1ch0loop:
@ref40:
	.byte $f9,$85
@ref41:
	.byte $f9,$85
@ref42:
	.byte $f9,$85
@ref43:
	.byte $f9,$85
@ref44:
	.byte $f9,$85
@ref45:
	.byte $f9,$85
	.byte $fd
	.word @song1ch0loop

@song1ch1:
@song1ch1loop:
@ref46:
	.byte $82,$32,$8d,$32,$8d,$36,$8d,$36,$8d,$36,$8d,$40,$8d,$32,$8d,$36
	.byte $85,$40,$85
@ref47:
	.byte $32,$8d,$32,$8d,$36,$8d,$36,$8d,$36,$8d,$40,$8d,$32,$8d,$40,$85
	.byte $33,$32,$81
@ref48:
	.byte $24,$8d,$24,$8d,$24,$8d,$24,$8d,$36,$8d,$36,$8d,$36,$8d,$28,$85
	.byte $28,$85
	.byte $ff,$12
	.word @ref48
@ref50:
	.byte $32,$8d,$32,$8d,$36,$8d,$36,$8d,$36,$8d,$40,$8d,$32,$8d,$36,$85
	.byte $40,$85
	.byte $ff,$12
	.word @ref50
	.byte $fd
	.word @song1ch1loop

@song1ch2:
@song1ch2loop:
@ref52:
	.byte $82,$52,$85,$58,$85,$5c,$85,$52,$85,$36,$85,$3e,$85,$44,$85,$5d
	.byte $63,$4e,$85,$54,$85,$4e,$85,$54,$85,$58,$85,$5c,$85,$55,$5d,$55
	.byte $4e,$81
@ref53:
	.byte $4b,$4f,$53,$59,$53,$4f,$4b,$4f,$4f,$53,$57,$5d,$57,$53,$4e,$85
	.byte $54,$85,$54,$85,$40,$85,$40,$85,$4a,$85,$58,$85,$40,$85,$33,$32
	.byte $81
@ref54:
	.byte $3d,$45,$4b,$45,$3b,$45,$3d,$3b,$3d,$45,$4b,$45,$4b,$4b,$45,$3b
	.byte $37,$3f,$45,$41,$3f,$3b,$37,$3b,$37,$3d,$3b,$3d,$4f,$49,$43,$48
	.byte $81
	.byte $ff,$21
	.word @ref54
@ref56:
	.byte $52,$85,$58,$85,$5c,$85,$52,$85,$36,$85,$3e,$85,$44,$85,$5d,$63
	.byte $4e,$85,$54,$85,$4e,$85,$54,$85,$58,$85,$5c,$85,$55,$5d,$55,$4e
	.byte $81
	.byte $ff,$21
	.word @ref56
	.byte $fd
	.word @song1ch2loop

@song1ch3:
@song1ch3loop:
@ref58:
	.byte $86,$1c,$95,$1d,$84,$03,$86,$1c,$95,$1d,$84,$03,$86,$1c,$95,$1d
	.byte $84,$03,$86,$1c,$95,$1d,$84,$02,$81
	.byte $ff,$11
	.word @ref58
	.byte $ff,$11
	.word @ref58
	.byte $ff,$11
	.word @ref58
	.byte $ff,$11
	.word @ref58
	.byte $ff,$11
	.word @ref58
	.byte $fd
	.word @song1ch3loop

@song1ch4:
@song1ch4loop:
@ref64:
	.byte $f9,$85
@ref65:
	.byte $f9,$85
@ref66:
	.byte $f9,$85
@ref67:
	.byte $f9,$85
@ref68:
	.byte $f9,$85
@ref69:
	.byte $f9,$85
	.byte $fd
	.word @song1ch4loop
