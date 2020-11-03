#include "LED_CHIP.h"


void LEDchip::cycle() {
	opcode = (memory[pc] << 8u) | memory[pc + 1];
	pc += 2;
	
	switch (opcode & 0xF000) {
		case 0x0000:
			switch(opcode & 0x000F) {
				case 0x0000:
					OP_00E0();
					break;
				case 0x000E:
					OP_00EE();
					break;
				default:
					break;
			}
		break;
		case 0x1000:
		
			OP_1nnn();
			break;
		case 0x2000:
			OP_2nnn();
			break;
		case 0x3000:
			OP_3xkk();
			break;
		case 0x4000:
			OP_4xkk();
			break;
		case 0x5000:
			OP_5xy0();
			break;
		case 0x6000:
			OP_6xkk();
			break;
		case 0x7000:
			OP_7xkk();
			break;
		case 0x8000:
			switch(opcode & 0x000F) {
				case 0x0000:
					OP_8xy0();
					break;
				case 0x0001:
					OP_8xy1();
					break;
				case 0x0002:
					OP_8xy2();
					break;
				case 0x0003:
					OP_8xy3();
					break;
				case 0x0004:
					OP_8xy4();
					break;
				case 0x0005:
					OP_8xy5();
					break;
				case 0x0006:
					OP_8xy6();
					break;
				case 0x0007:
					OP_8xy7();
					break;
				case 0x000E:
					OP_8xyE();
					break;
				default:
					break;
			}
			break;
		case 0x9000:
			OP_9xy0();
			break;
		
		case 0xA000:
			OP_Annn();
			break;
		case 0xB000:
			OP_Bnnn();
			break;
		case 0xC000:
			OP_Cxkk();
			break;
		case 0xD000:
			OP_Dxyn();
			break;
		case 0xE000:
			switch(opcode & 0x000F) {
					case 0x000E:
						OP_Ex9E();
						break;
					case 0x0001:
						OP_ExA1();
						break;
					default:
						break;
				}
			break;
			
			
		case 0xF000:
			switch(opcode & 0x000F) {
				case 0x0007:
					OP_Fx07();
					break;
				case 0x000A:
					OP_Fx0A();
					break;
				case 0x0005:
					switch(opcode & 0x00F0) {
						
						case 0x0010:
							OP_Fx15();
							break;
						case 0x0050:
							OP_Fx55();
							break;
						case 0x0060:
							OP_Fx65();
							break;
						break;
						
					}
					break;
				case 0x0008:
					OP_Fx18();
					break;
				case 0x000E:
					OP_Fx1E();
					break;
				case 0x0009:
					OP_Fx29();
					break;
				case 0x0003:
					OP_Fx33();
					break;
				break;
				
			break;
			}
		break;
		default:
			break;
		
	}
	
	if (delayTimer > 0 ){
		
		--delayTimer;
	}
	
	if(soundTimer > 0) {
		--soundTimer;
	}
	
	
}
