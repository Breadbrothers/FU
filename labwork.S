  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #
.global time2string
.global delay
hexasc:
        li      $t0,0xa
        andi    $a0,$a0,0xf
        bge     $a0,$t0,here
        nop  
        addi    $v0,$a0,0x30
        jr      $ra
        nop
  here:     
       addi     $v0,$a0,0x37
       jr         $ra
       nop 
 delay:
 	addi  $t5,$0,4000
 	addi   $t7,$a0,0		
 	while:
 	ble  $t7,$0,done
 	nop
 	addi $t7,$t7,-1
 	andi $t6,$t6,0
 	for:
 	addi $t6,$t6,1
 	bge  $t6,$t5,while
 	nop
 	j for
 	nop
 
 	done:
       jr $ra
       nop
       
time2string:
        PUSH $ra
        add    $t4,$0,$a0       
        andi   $a1,$a1,0xffff
        srl    $a0,$a1,12 
        jal    hexasc 
        nop
        sb     $v0,0($t4)
       
        srl    $a0,$a1,8
        jal    hexasc
        nop
        sb   $v0,1($t4)
        srl  $a0,$a1,4
        jal    hexasc
        nop
        sb   $v0,3($t4)
        
        andi  $a0,$a1,0xf
        jal    hexasc
        nop
        
        sb   $v0,4($t4)
        li   $v0,0x3a
        sb   $v0,2($t4)
        li   $v0,0
        sb   $v0,5($t4)
foo:
      POP $ra
        jr  $ra
        nop
        
     nop
