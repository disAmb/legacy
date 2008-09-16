/* defines for the nakkaloader protocol
 **/

#define NLPROTO_WAIT          0x00   /* slave waiting for master to respond */
#define NLPROTO_EEPROM_READ   0x01   /* read an eeprom page from device */
#define NLPROTO_ERROR         0x02
#define NLPROTO_PAGE_CHKSUM   0x03   /* checksum command */
#define NLPROTO_MASTER_EHLO   0x04   /* ehlo response from master/flashing device */
#define NLPROTO_SLAVE_CONFIG  0x05   /* slave sends its configuration */
#define NLPROTO_PAGE_COMMITED 0x06   /* device has written the page */

/* write operations */
#define NLPROTO_EEPROM_WRITE  0x10
#define NLPROTO_PAGE_FILL     0x11
#define NLPROTO_PAGE_COMMIT   0x12   /* checksum correct, go on and flash */
#define NLPROTO_BOOT          0x13   /* boot the application */

typedef struct
{
	uint8_t pkttype;
	uint8_t payload[RFM12_RX_BUFFER_SIZE-1];
} nl_packet;

typedef struct
{
	uint16_t pagesize;
	uint8_t rxbufsize;
	uint8_t version;
} nl_config;

typedef struct
{
	uint32_t pagenum;
	uint16_t addr_start;
	uint16_t addr_end;
} nl_flashcmd;

/* nakkaloader version */
#define NL_VERSION 0x00
