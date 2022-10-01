.global _start

_start :

/*循环闪烁*/
main_loop :
	bl led_on
	bl delay
	bl led_off
	bl delay
	b main_loop


#define PACFG1		0x01C20804
#define PADAT		0x01C20810

#define PDCFG3		0x02000098
#define PDDAT		0x020000A0

led_on :
	ldr r0, = 0x01FFFFFF   /* 这里ldr 为伪指令 */
    ldr r1, = PDCFG3
    str r0, [r1]          /* 寄存器间接寻址 将r0的值给r1所指地址的内存中,配置GPIO PD22为输出模式  */

    ldr r0, = (1<<22) 	  /* PA22, 在数据寄存器的第22位输出高电平 */
    ldr r1, = PDDAT
    str r0, [r1]          /* 点亮 */
    mov pc, lr

led_off :
	ldr r0, = 0x01FFFFFF   /* 这里ldr 为伪指令 */
    ldr r1, = PDCFG3
    str r0, [r1]          /* 寄存器间接寻址 将r0的值给r1所指地址的内存中,配置GPIO PD22为输出模式  */

    ldr r0, = (0<<22)	 	  /* PD22, 在数据寄存器的第22位输出低电平 */
    ldr r1, = PDDAT
    str r0, [r1]          /* 灭灯 */
    mov pc, lr

delay:
    mov r2, #0x4000000
    mov r3, #0
delay_loop:
    sub r2, r2, #1    /* r2=r2-1  */
    cmp r2, r3        /* cmp 比较r2 r3 如果相等 Z 为1  */
    bne delay_loop    /* bne 为当Z为1时执行跳转  bne 为 b+后缀  */
    mov pc, lr        /* 函数调用返回  mov 为 寄存器间寻址  */    







