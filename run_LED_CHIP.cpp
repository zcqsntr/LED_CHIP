#include "LED_CHIP.h"
#include "led-matrix.h"
#include "graphics.h"
#include "mylib.h"

#include "libevdev.h"

#include <iostream>
#include <chrono>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

using rgb_matrix::Font;
using rgb_matrix::Canvas;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Color;
using namespace std;
int main(int argc, char *argv[])  {
	
    cout << 0;
    struct libevdev *dev = NULL;
    int fd;
    int rc = 1;
    // ps4 controller "/dev/input/event6"
    // keyboard "/dev/input/event0"
    
    cout << 1;
    fd = open("/dev/input/event1", O_RDONLY|O_NONBLOCK);
    rc = libevdev_new_from_fd(fd, &dev);
    
    
    RGBMatrix::Options defaults;
  defaults.hardware_mapping = "adafruit-hat";  // or e.g. "adafruit-hat"
  defaults.rows = 32;
  defaults.cols = 64;
  defaults.chain_length = 1;
  defaults.parallel = 1;
  defaults.show_refresh_rate = false;
  
  // use --led-slowdown-gpio=4
  
  Canvas *canvas = rgb_matrix::CreateMatrixFromFlags(&argc, &argv, &defaults);
  if (canvas == NULL)
    return 1;
	
	
	char const *rom_file = argv[1];
	
	
	LEDchip led_chip(canvas, "/home/pi/Desktop/LED_CHIP/ROMS/Tank.ch8");
	cout << 2;
	led_chip.dev = dev;
	cout << 3;
	int cycleDelay = 5; 
	
	auto lastCycleTime = std::chrono::high_resolution_clock::now();
	Color bg_color(0, 0, 0);
	ResetCanvas(canvas, 64, 64, bg_color);
	int m = 0;
	
	while (true) {
		
		auto currentTime = std::chrono::high_resolution_clock::now();
		float dt = std::chrono::duration<float, std::chrono::milliseconds::period>(currentTime - lastCycleTime).count();
		
		if (dt > cycleDelay)
		{
			
			
			lastCycleTime = currentTime;
			
			
			
			led_chip.process_input();
			led_chip.cycle();
			
			
			
			led_chip.draw_output();
		    
			
		}
		
		
		
	
		
	}
	
	
	return 0;
}
