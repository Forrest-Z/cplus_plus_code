OBJ=$(patsubst %.cpp,%.o,$(wildcard *.cpp))
PROGRAM=img_convert
CFLAGS= -std=c++17 
LDFLAGS= -L ../opencv-3.4.3 -lopencv_core -lopencv_calib3d \
 -lopencv_imgproc -lopencv_stitching -lopencv_ml \
 -lopencv_superres -lopencv_features2d -lopencv_objdetect \
 -lopencv_flann -lopencv_photo -lopencv_video \
 -lopencv_videostab -lopencv_highgui

%.o: %.cpp
	$(CXX) $(CFLAGS) $< -c -o $@

$(PROGRAM): $(OBJ)
	$(CXX) -o $(PROGRAM) $(OBJ) $(LDFLAGS)

all: $(PROGRAM)

.PHONY: clean
clean:
	rm -f $(PROGRAM) *.o
install: $(PROGRAM)
	cp $(PROGRAM) /usr/local/bin
