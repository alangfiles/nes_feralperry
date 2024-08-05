;
; File generated by cc65 v 2.18 - Git c0a873e
;
	.fopt		compiler,"cc65 v 2.18 - Git c0a873e"
	.setcpu		"6502"
	.smart		on
	.autoimport	on
	.case		on
	.debuginfo	off
	.importzp	sp, sreg, regsave, regbank
	.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
	.macpack	longbranch
	.forceimport	__STARTUP__
	.import		_pal_bg
	.import		_pal_spr
	.import		_ppu_wait_nmi
	.import		_ppu_off
	.import		_ppu_on_all
	.import		_oam_clear
	.import		_oam_meta_spr
	.import		_pad_poll
	.import		_bank_spr
	.import		_vram_adr
	.import		_vram_put
	.import		_memcpy
	.import		_get_pad_new
	.import		_set_scroll_y
	.export		_YellowSpr
	.export		_BlueSpr
	.export		_pad1
	.export		_pad1_new
	.export		_collision
	.export		_collision_L
	.export		_collision_R
	.export		_collision_U
	.export		_collision_D
	.export		_which_bg
	.export		_p_maps
	.export		_coordinates
	.export		_temp1
	.export		_temp2
	.export		_temp3
	.export		_temp4
	.export		_temp_x
	.export		_temp_y
	.export		_c_map
	.export		_BoxGuy1
	.export		_c1
	.export		_c2
	.export		_c3
	.export		_c4
	.export		_All_Collision_Maps
	.export		_palette_bg
	.export		_palette_sp
	.export		_draw_bg
	.export		_draw_sprites
	.export		_movement
	.export		_bg_collision
	.export		_check_start
	.export		_main

.segment	"DATA"

_BoxGuy1:
	.byte	$40
	.byte	$50
	.byte	$0F
	.byte	$0E

.segment	"RODATA"

_YellowSpr:
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$08
	.byte	$00
	.byte	$00
	.byte	$40
	.byte	$00
	.byte	$08
	.byte	$10
	.byte	$00
	.byte	$08
	.byte	$08
	.byte	$10
	.byte	$40
	.byte	$80
_BlueSpr:
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$08
	.byte	$00
	.byte	$00
	.byte	$41
	.byte	$00
	.byte	$08
	.byte	$10
	.byte	$01
	.byte	$08
	.byte	$08
	.byte	$10
	.byte	$41
	.byte	$80
_c1:
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
_c2:
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
_c3:
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
_c4:
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
_All_Collision_Maps:
	.addr	_c1
	.addr	_c2
	.addr	_c3
	.addr	_c4
_palette_bg:
	.byte	$0F
	.byte	$00
	.byte	$10
	.byte	$30
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
_palette_sp:
	.byte	$0F
	.byte	$0F
	.byte	$0F
	.byte	$28
	.byte	$0F
	.byte	$0F
	.byte	$0F
	.byte	$12
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00

.segment	"BSS"

.segment	"ZEROPAGE"
_pad1:
	.res	1,$00
_pad1_new:
	.res	1,$00
_collision:
	.res	1,$00
_collision_L:
	.res	1,$00
_collision_R:
	.res	1,$00
_collision_U:
	.res	1,$00
_collision_D:
	.res	1,$00
_which_bg:
	.res	1,$00
_p_maps:
	.res	2,$00
_coordinates:
	.res	1,$00
_temp1:
	.res	1,$00
_temp2:
	.res	1,$00
_temp3:
	.res	1,$00
_temp4:
	.res	1,$00
_temp_x:
	.res	1,$00
_temp_y:
	.res	1,$00
.segment	"BSS"
_c_map:
	.res	240,$00

; ---------------------------------------------------------------
; void __near__ draw_bg (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_draw_bg: near

.segment	"CODE"

;
; ppu_off(); // screen off
;
	jsr     _ppu_off
;
; p_maps = All_Collision_Maps[which_bg];
;
	ldx     #$00
	lda     _which_bg
	asl     a
	bcc     L04E3
	inx
	clc
L04E3:	adc     #<(_All_Collision_Maps)
	sta     ptr1
	txa
	adc     #>(_All_Collision_Maps)
	sta     ptr1+1
	ldy     #$01
	lda     (ptr1),y
	sta     _p_maps+1
	dey
	lda     (ptr1),y
	sta     _p_maps
;
; memcpy (c_map, p_maps, 240);
;
	lda     #<(_c_map)
	ldx     #>(_c_map)
	jsr     pushax
	lda     _p_maps
	ldx     _p_maps+1
	jsr     pushax
	ldx     #$00
	lda     #$F0
	jsr     _memcpy
;
; vram_adr(NAMETABLE_A);
;
	ldx     #$20
	lda     #$00
	jsr     _vram_adr
;
; for(temp_y = 0; temp_y < 15; ++temp_y){
;
	lda     #$00
	sta     _temp_y
L04E4:	lda     _temp_y
	cmp     #$0F
	bcs     L0433
;
; for(temp_x = 0; temp_x < 16; ++temp_x){
;
	lda     #$00
	sta     _temp_x
L04E5:	lda     _temp_x
	cmp     #$10
	bcs     L04E7
;
; temp1 = (temp_y << 4) + temp_x;
;
	lda     _temp_y
	asl     a
	asl     a
	asl     a
	asl     a
	clc
	adc     _temp_x
	sta     _temp1
;
; if(c_map[temp1]){
;
	ldy     _temp1
	lda     _c_map,y
	beq     L04E6
;
; vram_put(0x10); // wall
;
	lda     #$10
	jsr     _vram_put
;
; vram_put(0x10);
;
	lda     #$10
;
; else{
;
	jmp     L04E1
;
; vram_put(0); // blank
;
L04E6:	jsr     _vram_put
;
; vram_put(0);
;
	lda     #$00
L04E1:	jsr     _vram_put
;
; for(temp_x = 0; temp_x < 16; ++temp_x){
;
	inc     _temp_x
	jmp     L04E5
;
; for(temp_x = 0; temp_x < 16; ++temp_x){
;
L04E7:	lda     #$00
	sta     _temp_x
L04E8:	lda     _temp_x
	cmp     #$10
	bcs     L04EA
;
; temp1 = (temp_y << 4) + temp_x;
;
	lda     _temp_y
	asl     a
	asl     a
	asl     a
	asl     a
	clc
	adc     _temp_x
	sta     _temp1
;
; if(c_map[temp1]){
;
	ldy     _temp1
	lda     _c_map,y
	beq     L04E9
;
; vram_put(0x10); // wall
;
	lda     #$10
	jsr     _vram_put
;
; vram_put(0x10);
;
	lda     #$10
;
; else{
;
	jmp     L04E2
;
; vram_put(0); // blank
;
L04E9:	jsr     _vram_put
;
; vram_put(0);
;
	lda     #$00
L04E2:	jsr     _vram_put
;
; for(temp_x = 0; temp_x < 16; ++temp_x){
;
	inc     _temp_x
	jmp     L04E8
;
; for(temp_y = 0; temp_y < 15; ++temp_y){
;
L04EA:	inc     _temp_y
	jmp     L04E4
;
; ppu_on_all(); // turn on screen
;
L0433:	jmp     _ppu_on_all

.endproc

; ---------------------------------------------------------------
; void __near__ draw_sprites (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_draw_sprites: near

.segment	"CODE"

;
; oam_clear();
;
	jsr     _oam_clear
;
; oam_meta_spr(BoxGuy1.X, BoxGuy1.Y, YellowSpr);
;
	jsr     decsp2
	lda     _BoxGuy1
	ldy     #$01
	sta     (sp),y
	lda     _BoxGuy1+1
	dey
	sta     (sp),y
	lda     #<(_YellowSpr)
	ldx     #>(_YellowSpr)
	jmp     _oam_meta_spr

.endproc

; ---------------------------------------------------------------
; void __near__ movement (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_movement: near

.segment	"CODE"

;
; if(pad1 & PAD_LEFT){
;
	lda     _pad1
	and     #$02
	beq     L04ED
;
; BoxGuy1.X -= 1;
;
	dec     _BoxGuy1
;
; else if (pad1 & PAD_RIGHT){
;
	jmp     L0477
L04ED:	lda     _pad1
	and     #$01
	beq     L0477
;
; BoxGuy1.X += 1;
;
	inc     _BoxGuy1
;
; bg_collision();
;
L0477:	jsr     _bg_collision
;
; if(collision_R) BoxGuy1.X -= 1;
;
	lda     _collision_R
	beq     L047C
	dec     _BoxGuy1
;
; if(collision_L) BoxGuy1.X += 1;
;
L047C:	lda     _collision_L
	beq     L0480
	inc     _BoxGuy1
;
; if(pad1 & PAD_UP){
;
L0480:	lda     _pad1
	and     #$08
	beq     L04EE
;
; BoxGuy1.Y -= 1;
;
	dec     _BoxGuy1+1
;
; else if (pad1 & PAD_DOWN){
;
	jmp     L0489
L04EE:	lda     _pad1
	and     #$04
	beq     L0489
;
; BoxGuy1.Y += 1;
;
	inc     _BoxGuy1+1
;
; bg_collision();
;
L0489:	jsr     _bg_collision
;
; if(collision_D) BoxGuy1.Y -= 1;
;
	lda     _collision_D
	beq     L048E
	dec     _BoxGuy1+1
;
; if(collision_U) BoxGuy1.Y += 1;
;
L048E:	lda     _collision_U
	beq     L0492
	inc     _BoxGuy1+1
;
; } 
;
L0492:	rts

.endproc

; ---------------------------------------------------------------
; void __near__ bg_collision (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_bg_collision: near

.segment	"CODE"

;
; collision_L = 0;
;
	lda     #$00
	sta     _collision_L
;
; collision_R = 0;
;
	sta     _collision_R
;
; collision_U = 0;
;
	sta     _collision_U
;
; collision_D = 0;
;
	sta     _collision_D
;
; temp_x = BoxGuy1.X; // left side
;
	lda     _BoxGuy1
	sta     _temp_x
;
; temp_y = BoxGuy1.Y; // top side
;
	lda     _BoxGuy1+1
	sta     _temp_y
;
; if(temp_y >= 0xf0) return;
;
	cmp     #$F0
	bcc     L04FC
;
; }
;
	rts
;
; coordinates = (temp_x >> 4) + (temp_y & 0xf0); // upper left
;
L04FC:	lda     _temp_x
	lsr     a
	lsr     a
	lsr     a
	lsr     a
	sta     ptr1
	lda     _temp_y
	and     #$F0
	clc
	adc     ptr1
	sta     _coordinates
;
; if(c_map[coordinates]){ // find a corner in the collision map
;
	ldy     _coordinates
	lda     _c_map,y
	beq     L04F6
;
; ++collision_L;
;
	inc     _collision_L
;
; ++collision_U;
;
	inc     _collision_U
;
; temp_x = BoxGuy1.X + BoxGuy1.width; // right side
;
L04F6:	lda     _BoxGuy1
	clc
	adc     _BoxGuy1+2
	sta     _temp_x
;
; coordinates = (temp_x >> 4) + (temp_y & 0xf0); // upper right
;
	lsr     a
	lsr     a
	lsr     a
	lsr     a
	sta     ptr1
	lda     _temp_y
	and     #$F0
	clc
	adc     ptr1
	sta     _coordinates
;
; if(c_map[coordinates]){
;
	ldy     _coordinates
	lda     _c_map,y
	beq     L04F8
;
; ++collision_R;
;
	inc     _collision_R
;
; ++collision_U;
;
	inc     _collision_U
;
; temp_y = BoxGuy1.Y + BoxGuy1.height; // bottom side
;
L04F8:	lda     _BoxGuy1+1
	clc
	adc     _BoxGuy1+3
	sta     _temp_y
;
; if(temp_y >= 0xf0) return;
;
	cmp     #$F0
	bcs     L04CF
;
; coordinates = (temp_x >> 4) + (temp_y & 0xf0); // bottom right
;
	lda     _temp_x
	lsr     a
	lsr     a
	lsr     a
	lsr     a
	sta     ptr1
	lda     _temp_y
	and     #$F0
	clc
	adc     ptr1
	sta     _coordinates
;
; if(c_map[coordinates]){
;
	ldy     _coordinates
	lda     _c_map,y
	beq     L04FA
;
; ++collision_R;
;
	inc     _collision_R
;
; ++collision_D;
;
	inc     _collision_D
;
; temp_x = BoxGuy1.X; // left side
;
L04FA:	lda     _BoxGuy1
	sta     _temp_x
;
; coordinates = (temp_x >> 4) + (temp_y & 0xf0); // bottom left
;
	lsr     a
	lsr     a
	lsr     a
	lsr     a
	sta     ptr1
	lda     _temp_y
	and     #$F0
	clc
	adc     ptr1
	sta     _coordinates
;
; if(c_map[coordinates]){
;
	ldy     _coordinates
	lda     _c_map,y
	beq     L04CF
;
; ++collision_L;
;
	inc     _collision_L
;
; ++collision_D;
;
	inc     _collision_D
;
; }
;
L04CF:	rts

.endproc

; ---------------------------------------------------------------
; void __near__ check_start (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_check_start: near

.segment	"CODE"

;
; if(pad1_new & PAD_START){
;
	lda     _pad1_new
	and     #$10
	beq     L04D6
;
; ++which_bg;
;
	inc     _which_bg
;
; if(which_bg >= 4) which_bg = 0;
;
	lda     _which_bg
	cmp     #$04
	bcc     L04D9
	lda     #$00
	sta     _which_bg
;
; draw_bg();
;
L04D9:	jmp     _draw_bg
;
; }
;
L04D6:	rts

.endproc

; ---------------------------------------------------------------
; void __near__ main (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_main: near

.segment	"CODE"

;
; ppu_off(); // screen off
;
	jsr     _ppu_off
;
; pal_bg(palette_bg);
;
	lda     #<(_palette_bg)
	ldx     #>(_palette_bg)
	jsr     _pal_bg
;
; pal_spr(palette_sp);
;
	lda     #<(_palette_sp)
	ldx     #>(_palette_sp)
	jsr     _pal_spr
;
; bank_spr(1);
;
	lda     #$01
	jsr     _bank_spr
;
; set_scroll_y(0xff); //shift the bg down 1 pixel
;
	ldx     #$00
	lda     #$FF
	jsr     _set_scroll_y
;
; draw_bg();
;
	jsr     _draw_bg
;
; ppu_wait_nmi(); // wait till beginning of the frame
;
L0419:	jsr     _ppu_wait_nmi
;
; pad1 = pad_poll(0); // read the first controller
;
	lda     #$00
	jsr     _pad_poll
	sta     _pad1
;
; pad1_new = get_pad_new(0); // newly pressed button. do pad_poll first
;
	lda     #$00
	jsr     _get_pad_new
	sta     _pad1_new
;
; movement();
;
	jsr     _movement
;
; draw_sprites();
;
	jsr     _draw_sprites
;
; check_start();
;
	jsr     _check_start
;
; while (1){
;
	jmp     L0419

.endproc
