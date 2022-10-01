#include "main.h"
void LED_Init(void);
void LED_Blink(void);
void gpio_init(void);
void uart_init(void);
void uart_transmit(char DAT);

static inline __attribute__((__always_inline__)) unsigned int read32(unsigned long long addr)
{
	return (*((volatile unsigned int *)(addr)));
}

static inline __attribute__((__always_inline__)) void write32(unsigned long long addr, unsigned int value)
{
	*((volatile unsigned int *)(addr)) = value;
}


int main(){
    int t = 5000000;
    
    LED_Init();
    while (t--){}

    LED_Blink();
    gpio_init();
    
    uart_init();
    LED_Blink();
    while (1)
    {
        uart_transmit('O');       
        uart_transmit('K');    
        uart_transmit('\r');    
        uart_transmit('\n');    
        // LED_Blink();
        
    }
    return 0;
}
void LED_Init(void){
    PDCFG3 = 0x01FFFFFF;
}
void LED_Blink(void){
        int i=1000000;
        PDDAT  = (1<<22) ;
        while (i--){}
        i = 1000000;
        PDDAT  = (0<<22) ;
        while (i--){}
        i = 1000000;
        PDDAT  = (1<<22) ;
        while (i--){}
        i = 1000000;
}

void gpio_init(void){
    PE_CFG0 = 0XFFFF66FF;                       //复用
    PE_PULL0 = 0x00000050;                      //上拉
}

void uart_init(void){
    // UART_BGR_REG = UART_BGR_REG | 0x00000001;   //使能UART0时钟
    // UART_FCR    = UART_FCR  |   0x00000001;       //Tx/Tx FIFO
    // UART_HALT   = UART_HALT |   0x00000001;       //Write UART_HALT[HALT_TX] to 1 to disable TX transfer;
    // UART_LCR    = UART_LCR  |   0x00000080;       //Set UART_LCR[DLAB] to 1, remain default configuration for other bits; set 0x00 offset address to the UART_DLL register, set 0x04 offset address to the UART_DLH register;
    // UART_DLL    = UART_DLH  |   0x00000000;       //Write the high 8-bit of divisor
    // UART_DLL    = UART_DLL  |   0x0000000D;       //Write the low 8-bit of divisor
    // UART_LCR    = UART_LCR  |   0x00000000;       
    // UART_HALT   = UART_HALT |   0x00000000;       //enable Tx transfer
    // UART_LCR    = UART_LCR  |   0x00000003;       // 8 bits
    // UART_MCR    = UART_MCR  |   0x00000000;       //


    unsigned long long addr;
	unsigned int  val;

	/* Config GPIOE2 and GPIOE3 to txd0 and rxd0 */
	addr = 0x020000c0 + 0x0;
	val = read32(addr);
	val &= ~(0xf << ((2 & 0x7) << 2));
	val |= ((0x6 & 0xf) << ((2 & 0x7) << 2));
	write32(addr, val);

	val = read32(addr);
	val &= ~(0xf << ((3 & 0x7) << 2));
	val |= ((0x6 & 0xf) << ((3 & 0x7) << 2));
	write32(addr, val);

	/* Open the clock gate for uart0 */
	addr = 0x0200190c;
	val = read32(addr);
	val |= 1 << 0;
	write32(addr, val);

	/* Deassert uart0 reset */
	addr = 0x0200190c;
	val = read32(addr);
	val |= 1 << 16;
	write32(addr, val);

	/* Config uart0 to 115200-8-1-0 */
	addr = 0x02500000;
	write32(addr + 0x04, 0x0);
	write32(addr + 0x08, 0xf7);
	write32(addr + 0x10, 0x0);
	val = read32(addr + 0x0c);
	val |= (1 << 7);
	write32(addr + 0x0c, val);
	write32(addr + 0x00, 0xd & 0xff);
	write32(addr + 0x04, (0xd >> 8) & 0xff);
	val = read32(addr + 0x0c);
	val &= ~(1 << 7);
	write32(addr + 0x0c, val);
	val = read32(addr + 0x0c);
	val &= ~0x1f;
	val |= (0x3 << 0) | (0 << 2) | (0x0 << 3);
	write32(addr + 0x0c, val);

}

void uart_transmit(char DAT){
    // UART_THR = DAT;
    // // while (!(UART_USR&0X00000002))
    // // {
    //     /* code */
    //     LED_Blink();
    // // }
    

	unsigned long long addr = 0x02500000;

	while((read32(addr + 0x7c) & (0x1 << 1)) == 0);
	write32(addr + 0x00, DAT);



}

