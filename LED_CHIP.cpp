


class LEDchip {

  public:
    unsigned char memory[4096];

    unsigned char data_registers[16];
    unsigned short address_register;

    unsigned short program_counter;
    unsigned short stack_pointer;
    unsigned short stack[16];

    unsigned char pixels[64 * 32];
    unsigned short opcode;

    unsigned char delay_timer;
    unsigned char sound_timer;

    unsigned char keys[16];

};
