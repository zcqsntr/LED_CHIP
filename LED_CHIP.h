#include <cstdint>
#include "led-matrix.h"

using rgb_matrix::Canvas;

class LEDchip{

  public:
    uint8_t registers[16] = {};
	uint8_t memory[4096] = {};
	uint16_t index;
	uint16_t pc;
	uint16_t stack[16] = {};
	uint8_t sp;
	uint8_t delayTimer;
	uint8_t soundTimer;
	uint8_t keypad[16] = {};
	uint32_t video[64 * 32] = {};
	uint16_t opcode;

    unsigned int FONTSET_START_ADDRESS = 80;
    unsigned int START_ADDRESS = 0x200;
    
    
    struct libevdev *dev;
    
    void load_ROM(char const* filename);
    void load_font();
    void cycle();
    void process_input();
    void draw_output();
    
    Canvas *canvas;
    
    LEDchip(rgb_matrix::Canvas* cv, char const* rom_file);
    
    //instructions
    void OP_00E0();
    void OP_00EE();
    void OP_1nnn();
    void OP_2nnn();
    void OP_3xkk();
    void OP_4xkk();
    void OP_5xy0();
    void OP_6xkk();
    void OP_7xkk();
    void OP_8xy0();
    void OP_8xy1();
    void OP_8xy2();
    void OP_8xy3();
    void OP_8xy4();
    void OP_8xy5();
    void OP_8xy6();
    void OP_8xy7();
    void OP_8xyE();
    void OP_9xy0();
    void OP_Annn();
    void OP_Bnnn();
    void OP_Cxkk();
    void OP_Dxyn();
    void OP_Ex9E();
    void OP_ExA1();
    void OP_Fx07();
    void OP_Fx0A();
    void OP_Fx15();
    void OP_Fx18();
    void OP_Fx1E();
    void OP_Fx29();
    void OP_Fx33();
    void OP_Fx55();
    void OP_Fx65();
};
