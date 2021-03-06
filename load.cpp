#include <fstream>
#include "LED_CHIP.h" 
#include <iostream>



void LEDchip::load_ROM(char const* filename) {
	
	std::ifstream file(filename, std::ios::binary | std::ios::ate);
	std:: cout << "LOADING rom";
	if(file.is_open()) {
		std::streampos size = file.tellg();
		char* buffer = new char[size];
		
		
		file.seekg(0, std::ios::beg);
		file.read(buffer, size);
		file.close();
	
		for(long i = 0; i < size; i++){
			
			memory[START_ADDRESS + i] = buffer[i];
			
			
		}
		
		delete[] buffer;
	}else {
		std:: cout << "ROM NOT LOADED";
	}
	
	
}


void LEDchip::load_font() {
	pc = START_ADDRESS;
	int FONTSET_SIZE = 80;
	
	unsigned char fontset[FONTSET_SIZE] = {
		0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
		0x20, 0x60, 0x20, 0x20, 0x70, // 1
		0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
		0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
		0x90, 0x90, 0xF0, 0x10, 0x10, // 4
		0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
		0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
		0xF0, 0x10, 0x20, 0x40, 0x40, // 7
		0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
		0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
		0xF0, 0x90, 0xF0, 0x90, 0x90, // A
		0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
		0xF0, 0x80, 0x80, 0x80, 0xF0, // C
		0xE0, 0x90, 0x90, 0x90, 0xE0, // D
		0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
		0xF0, 0x80, 0xF0, 0x80, 0x80  // F
	};
	
	unsigned char f = fontset[0];
	unsigned char g = memory[FONTSET_START_ADDRESS ];
	std::cout<<g<<f;
	for (int i = 0; i < FONTSET_SIZE; ++i)
	{
		
		
		memory[FONTSET_START_ADDRESS + i] = fontset[i];
	}
	
	
}
