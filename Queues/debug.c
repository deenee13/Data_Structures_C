

// Location where DMA will read data from
//// BUG: It should be from where it will write data
uint32_t *DMA_BUFF_SEND_ADDR = 0xDEADBEEF;
// Location where the length of the DMA buffer is stored
uint32_t *BUFF_LEN_ADDR = 0xDEADCAFE;

// Takes data from a buffer, writes it to the address stored at address
// 0xDEADBEEF, using the length value stored at 0xDEADCAFE
// Assume the caller is a parsing function that just populates addresses before
// calling the "write_buffer" routine.

//// BUG: Both the function should buf as const
//// BUG: dma_send_buffer this function can be static
int dma_send_buffer(uint8_t *buf, uint16_t len) {
    //// BUG: Null Checking on buf pointer
    //// BUG: We are not checking whether the value of BUFF_LEN_ADDR
    ////    is matching with the len
  uint8_t *ret = memcpy(DMA_BUFF_SEND_ADDR, buf, len);

  dma_set_send_rq();
    //// BUG: Function is always going to return false
  return ret == buf;
}

// Message that comes in on the wire
// [Command:4bytes][Length:2bytes][Value]
int dma_command(uint8_t *buf, uint16_t len) {
    //// BUG: 1. Null Checking on the buf pointer
    //// BUG: 2. Check if len is atleast 7 bytes long
    //// BUG: if it is smaller than that then it will cause problem
  uint32_t command = CMD_UNKNOWN;
  uint16_t length = 0;
  uint8_t *value = NULL;

//// BUG: This is wrong way of typecasting it will not give us expected data
//// *((uint32_t*)buf) this will give us expected data
//// BUG: further data
  command = (uint32_t)*buf;
  length = (uint16_t)*(buf + sizeof(command));
  value = buf + sizeof(command) + sizeof(length);

  //// BUG: We are assuming user will first do conf followed
  //// by the send what if we dont do in that way it could read
  //// unwanted data which can create problem
  switch (command) {
    case CMD_DMA_SEND:
    ////  BUG: There is no checking of the return value. How we will know
    //// whether the operation was successful or not
      dma_send_buffer(value, length);
      break;
    //// BUG: what if I call recv and will return ok.
    //// Which will receive wrong data
    case CMD_DMA_RECV:
      // FIXME: I'll figure this out later
      break;
    case CMD_DMA_CONF:
    //// BUG: Confirm with mamu once
      *BUFF_LEN_ADDR = value;
      break;
    default:
      return ERROR;
  }
  return OK;
}





#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h> 

/*
Status & Config Register (16 bits)
+-----------------------------------------------+
|15|14|13|12|11|10|09|08|07|06|05|04|03|02|01|00|
+-----------------------------------------------+
|          N/A          |    N/A       | mode|s |
+--------------------------------------+--------+
|     High Byte         |      Low Byte         |
+-----------------------+-----------------------+

struct bytes {
  lb;
  hb;

};

union StatusRegister {

  struct bytes;
  val;

}
StatusRegister
StatusRegister.val = 0x0000; 
printf("0x%.08x", StatusRegister.val) // 0x0000; 
StatusRegister.bytes.lb = 0xFF; 
printf("0x%.08x", StatusRegister.val) // 0x00FF; 
StatusRegister.bytes.hb = 0xAA; 
printf("0x%.08x", StatusRegister.val) // 0xAAFF; 

struct fields {
  uint8_t enable:1; 
  uint8_t mode: 2; 
  uint8_t unused:5
}

fields.enable = 1; 
fields.mode = 3; 
fields.unused = 0; 
*/


#define LSB_MASK 0xFF

struct _bytes {
  uint8_t lb;
  uint8_t hb;
};

union StatusRegister {
  struct _bits {
    uint8_t enable:1; 
    uint8_t mode: 2; 
    uint8_t unused:5;
  } bits;
  struct _bytes bytes;
  uint16_t val;
};

int main(void) {
  printf("Welcome to your Xilinx Coding Interview Deepen!\n");

  union StatusRegister instance_1;

  instance_1.val = 0XAAFF;
  printf("0x%.04x\n", instance_1.val);
  instance_1.bytes.hb = 0x55;
  printf("0x%.04x\n", instance_1.val);
  instance_1.bytes.lb = 0x33;
  printf("0x%.04x\n", instance_1.val);
  instance_1.bits.mode = 0; 
  printf("0x%.04x\n", instance_1.val);

  return 0;
}





