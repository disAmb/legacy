#ifndef _CONFIG_H
#define _CONFIG_H

// SPI
#define MC_MOSI    PB5
#define MC_SCK     PB7

#define MCP_CS_BIT    PB4
#define MCP_CS_PORT   PORTB

#define SPI_REG_PIN_MCP_INT  PINB
#define SPI_PIN_MCP_INT      PB2
//#define CAN_INTERRUPT


#define F_MCP F_CPU

//dimmer
#define NUM_DIMMER_CHANNELS 4

#endif // ifndef CONFIG_H
