#include "LED_CHIP.h"
#include "led-matrix.h"

using rgb_matrix::Canvas;

LEDchip::LEDchip(rgb_matrix::Canvas* cv, char const* rom_file)  {

	canvas = cv;
	
	load_font();
	
	load_ROM(rom_file);
}
