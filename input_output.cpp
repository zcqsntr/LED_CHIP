
#include "led-matrix.h"
#include "mylib.h"
#include "libevdev.h"
#include <iostream>
#include "LED_CHIP.h"



using rgb_matrix::Font;
using rgb_matrix::Canvas;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Color;


void LEDchip::process_input() {
	list<ControllerInput> inputs = get_CHIP8_inputs(dev);
	
	
	for(const auto &input: inputs){
		
		
		switch(input.type) {
			
			case '1':
				switch (input.value) {
					case -1:
						keypad[0] = 1;
						break;
					case 1:
						keypad[1] = 1;
						break;
					case 0:
						keypad[0] = 0;
						keypad[1] = 0;
						break;
					default:
						break;
						
				}
				break;
			
			case '2':
				switch (input.value) {
					case -1:
						keypad[2] = 1;
						break;
					case 1:
						keypad[3] = 1;
						break;
					case 0:
						keypad[2] = 0;
						keypad[3] = 0;
						break;
					default:
						break;
						
				}
				break;
			case '3':
				switch (input.value) {
					case 1:
						keypad[4] = 1;
						break;
					case 0:
						keypad[4] = 0;
						break;
					default:
						break;
						
				}
				break;
			case '4':
				switch (input.value) {
					case 1:
						keypad[5] = 1;
						break;
					case 0:
						keypad[5] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'Q':
				switch (input.value) {
					case 1:
						keypad[6] = 1;
						break;
					case 0:
						keypad[6] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'W':
				switch (input.value) {
					case 1:
						keypad[7] = 1;
						break;
					case 0:
						keypad[7] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'E':
				switch (input.value) {
					case 1:
						keypad[8] = 1;
						break;
					case 0:
						keypad[8] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'R':
				switch (input.value) {
					case 1:
						keypad[9] = 1;
						break;
					case 0:
						keypad[9] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'A':
				switch (input.value) {
					case 1:
						keypad[9] = 1;
						break;
					case 0:
						keypad[9] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'S':
				switch (input.value) {
					case 1:
						keypad[9] = 1;
						break;
					case 0:
						keypad[9] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'D':
				switch (input.value) {
					case 1:
						keypad[9] = 1;
						break;
					case 0:
						keypad[9] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'F':
				switch (input.value) {
					case 1:
						keypad[9] = 1;
						break;
					case 0:
						keypad[9] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'Z':
				switch (input.value) {
					case 1:
						keypad[9] = 1;
						break;
					case 0:
						keypad[9] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'X':
				switch (input.value) {
					case 1:
						keypad[9] = 1;
						break;
					case 0:
						keypad[9] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'C':
				switch (input.value) {
					case 1:
						keypad[9] = 1;
						break;
					case 0:
						keypad[9] = 0;
						break;
					default:
						break;
						
				}
				break;
			case 'V':
				switch (input.value) {
					case 1:
						keypad[9] = 1;
						break;
					case 0:
						keypad[9] = 0;
						break;
					default:
						break;
						
				}
				break;
			default:
				break;
			
		}
	}
	
	
}


void LEDchip::draw_output() {
	
	Color colour = Color(0, 0, 255);
	Color bg_colour = Color(0,0,0);
	int row;
	int col;
	
	
	for (int i = 0; i < 32*64; i++){	
		row = i / 64;
			col = i % 64;
		if(video[i] == 0xFFFFFFFF){
			
			
			SetPixel(canvas, row, col, colour);
		} else if(video[i] == 0x00000000) {
			SetPixel(canvas, row, col, bg_colour);
		}
	}

}
