#define GPIO_BASE 0x02000000
#define PDCFG3		    *(volatile unsigned int*)(GPIO_BASE+0x98)
#define PDDAT		    *(volatile unsigned int*)(GPIO_BASE+0xA0)


//gpio

#define PE_CFG0     *(volatile unsigned int*)(GPIO_BASE+0x00C0)
#define PE_CFG1     *(volatile unsigned int*)(GPIO_BASE+0x00C4)
#define PE_DAT      *(volatile unsigned int*)(GPIO_BASE+0x00D0)
#define PE_DRV0     *(volatile unsigned int*)(GPIO_BASE+0x00D4)
#define PE_DRV1     *(volatile unsigned int*)(GPIO_BASE+0x00D8)
#define PE_PULL0    *(volatile unsigned int*)(GPIO_BASE+0x00E4)

// uart
#define UART_BGR_REG  *(volatile unsigned int*)0x0200190C

#define UART0_BASE      0x02500000

#define UART_RBR        *(volatile unsigned int*)(UART0_BASE+0x0000)              // UART Receive Buffer Register
#define UART_THR        *(volatile unsigned int*)(UART0_BASE+0x0000)              // UART Transmit Holding Register
#define UART_DLL        *(volatile unsigned int*)(UART0_BASE+0x0000)              // UART Divisor Latch Low Register
#define UART_DLH        *(volatile unsigned int*)(UART0_BASE+0x0004)              // UART Divisor Latch High Register
#define UART_IER        *(volatile unsigned int*)(UART0_BASE+0x0004)              // UART Interrupt Enable Register
#define UART_IIR        *(volatile unsigned int*)(UART0_BASE+0x0008)              // UART Interrupt Identity Register
#define UART_FCR        *(volatile unsigned int*)(UART0_BASE+0x0008)              // UART FIFO Control Register
#define UART_LCR        *(volatile unsigned int*)(UART0_BASE+0x000C)              // UART Line Control Register
#define UART_MCR        *(volatile unsigned int*)(UART0_BASE+0x0010)              // UART Modem Control Register
#define UART_LSR        *(volatile unsigned int*)(UART0_BASE+0x0014)              // UART Line Status Register
#define UART_MSR        *(volatile unsigned int*)(UART0_BASE+0x0018)              // UART Modem Status Register
#define UART_SCH        *(volatile unsigned int*)(UART0_BASE+0x001C)              // UART Scratch Register
#define UART_USR        *(volatile unsigned int*)(UART0_BASE+0x007C)              // UART Status Register
#define UART_TFL        *(volatile unsigned int*)(UART0_BASE+0x0080)              // UART Transmit FIFO Level Register
#define UART_RFL        *(volatile unsigned int*)(UART0_BASE+0x0084)              // UART Receive FIFO Level Register
#define UART_HSK        *(volatile unsigned int*)(UART0_BASE+0x0088)              // UART DMA Handshake Configuration Register
#define UART_DMA_REQ_EN *(volatile unsigned int*)(UART0_BASE+0x008C)              // UART DMA Request Enable Register
#define UART_HALT       *(volatile unsigned int*)(UART0_BASE+0x00A4)              // UART Halt TX Register
#define UART_DBG_DLL    *(volatile unsigned int*)(UART0_BASE+0x00B0)              // UART Debug DLL Register
#define UART_DBG_DLH    *(volatile unsigned int*)(UART0_BASE+0x00B4)              // UART Debug DLH Register
#define UART_A_FCC      *(volatile unsigned int*)(UART0_BASE+0x00F0)              // UART FIFO Clock Control Register
#define UART_A_RXDMA_CTRL       *(volatile unsigned int*)(UART0_BASE+0x0100)      // UART RXDMA Control Register
#define UART_A_RXDMA_STR        *(volatile unsigned int*)(UART0_BASE+0x0104)      // UART RXDMA Start Register
#define UART_A_RXDMA_STA        *(volatile unsigned int*)(UART0_BASE+0x0108)      // UART RXDMA Status Register
#define UART_A_RXDMA_LMT        *(volatile unsigned int*)(UART0_BASE+0x010C)      // UART RXDMA Limit Register
#define UART_A_RXDMA_SADDRL     *(volatile unsigned int*)(UART0_BASE+0x0110)      // UART RXDMA Buffer Start Address Low Register
#define UART_A_RXDMA_SADDRH     *(volatile unsigned int*)(UART0_BASE+0x0114)      // UART RXDMA Buffer Start Address High Register
#define ART_A_RXDMA_BL          *(volatile unsigned int*)(UART0_BASE+0x0118)      // UART RXDMA Buffer Length Register
#define UART_A_RXDMA_IE         *(volatile unsigned int*)(UART0_BASE+0x0120)      // UART RXDMA Interrupt Enable Register
#define UART_A_RXDMA_IS         *(volatile unsigned int*)(UART0_BASE+0x0124)      // UART RXDMA Interrupt Status Register
#define UART_A_RXDMA_WADDRL     *(volatile unsigned int*)(UART0_BASE+0x0128)      // UART RXDMA Write Address Low Register
#define UART_A_RXDMA_WADDRH     *(volatile unsigned int*)(UART0_BASE+0x012C)      // UART RXDMA Write Address high Register
