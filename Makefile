CFLAGS=-Wall -O0 -g -Wextra -Wno-unused-parameter --std=c++17
CXX = g++
CXXFLAGS=$(CFLAGS)



# Where our library resides. You mostly only need to change the
# RGB_LIB_DISTRIBUTION, this is where the library is checked out.
RGB_LIB_DISTRIBUTION=/home/pi/Desktop/retro_matrix/rpi-rgb-led-matrix
RGB_INCDIR=$(RGB_LIB_DISTRIBUTION)/include
RGB_LIBDIR=$(RGB_LIB_DISTRIBUTION)/lib
RGB_LIBRARY_NAME=rgbmatrix


EVDEV_LIB_DISTRIBUTION=/usr/local
EVDEV_INCDIR=/usr/local/include/libevdev-1.0/libevdev
EVDEV_LIBDIR=/usr/local/lib
EVDEV_LIBRARY_NAME=evdev
EVDEV_LIBRARY=$(EVDEV_LIBDIR)/lib$(EVDEV_LIBRARY_NAME).a



MY_INCDIR = /home/pi/Desktop/retro_matrix/lib
MY_LIB = retromatrix

LDFLAGS+=-lstdc++fs
LDFLAGS+= -L$(MY_INCDIR) -l$(MY_LIB) 
LDFLAGS+=-L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -lrt -lm -lpthread
LDFLAGS+= -L$(EVDEV_LIBDIR) -l$(EVDEV_LIBRARY_NAME) 


all : run_LED_CHIP

run_LED_CHIP: run_LED_CHIP.o LED_CHIP.o load.o input_output.o instructions.o cycle.o $(RGB_LIBRARY) $(EVDEV_LIBRARY)
	$(CXX) run_LED_CHIP.o LED_CHIP.o load.o input_output.o instructions.o cycle.o -o $@ $(LDFLAGS) 

run_LED_CHIP.o: run_LED_CHIP.cpp
	$(CXX) -o run_LED_CHIP.o -I$(RGB_INCDIR) -I. -I$(MY_INCDIR)  -I$(EVDEV_INCDIR) $(CXXFLAGS) $(LDLIBS) -c run_LED_CHIP.cpp
	


LED_CHIP.o: LED_CHIP.cpp
	$(CXX) -o LED_CHIP.o -I$(RGB_INCDIR) -I. -I$(MY_INCDIR)  -I$(EVDEV_INCDIR) $(CXXFLAGS) $(LDLIBS) -c LED_CHIP.cpp
	
load.o: load.cpp 
	$(CXX) -o load.o -I$(MY_INCDIR) -I. -I$(RGB_INCDIR) -I$(EVDEV_INCDIR) $(CXXFLAGS) $(LDLIBS) -c load.cpp	
	
	
input_output.o: input_output.cpp 
	$(CXX) -o input_output.o -I$(MY_INCDIR) -I. -I$(RGB_INCDIR) -I$(EVDEV_INCDIR) $(CXXFLAGS) $(LDLIBS) -c input_output.cpp 
	
instructions.o: instructions.cpp 
	$(CXX) -o instructions.o -I$(MY_INCDIR) -I. -I$(RGB_INCDIR) -I$(EVDEV_INCDIR) $(CXXFLAGS) $(LDLIBS) -c instructions.cpp 
	
cycle.o: cycle.cpp 
	$(CXX) -o cycle.o -I$(MY_INCDIR) -I. -I$(RGB_INCDIR) -I$(EVDEV_INCDIR) $(CXXFLAGS) $(LDLIBS) -c cycle.cpp 

clean:
	rm *.o

FORCE:
.PHONY: FORCE
