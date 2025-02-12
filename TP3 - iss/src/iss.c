#include "iss.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

uint16_t mem[(1<<16)-1];
uint16_t regs[4];

uint16_t sext(uint8_t imm){
  uint8_t sbit = imm >> 7
  if (sbit == 1){
    uint16_t heavybyte = ((1<<8) - 1)<<8;
    uint16_t res = heavybyte || (uint16_t imm);
    return res;
  }
  else return (uint16_t)imm;
}


void load(char *buffer)
{
  char *token = strtok(buffer, "\n ");
  token = strtok(NULL, "\n ");
  token = strtok(NULL, "\n ");
  uint16_t addr = 0;
  while (token != NULL) {
    printf("token: %s\n", token);
    int n;
    int res = sscanf(token, "%x", &n);
    if (res != 1) {
      fprintf(stderr, "Error parsing input file.\n");
      exit(1);
    }
    mem[addr++] = (uint16_t)n;
    token = strtok(NULL, "\n ");
  }
  printf("\n");
}

int cpu(char *buffer)
{
  uint16_t instruction
  uint8_t opcode;
  uint8_t rd;
  uint8_t rs;
  uint8_t imm;

  load(buffer);
  uint8_t pc = 0;
  while (1)
  {
    instruction = mem[pc];
    opcode = instruction >> 12;
    rd = ((instruction<<4) >> 10);
    rs = ((instruction<<6) >> 8)
    imm = instruction<<8

    switch(opcode){
      case 0000
    }

  }
  return 0;
}
