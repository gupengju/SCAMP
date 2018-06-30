#Make sure that this points to the cuda install you want to use
CUDA_DIRECTORY=C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v8.0
CC="$(CUDA_DIRECTORY)\bin\nvcc.exe"
ARCH=-gencode=arch=compute_61,code=sm_61
CFLAGS=-c -use_fast_math -lineinfo -O2 -std=c++11 $(ARCH) -I"$(CUDA_DIRECTORY)\include"

LDFLAGS=-L"$(CUDA_DIRECTORY)\lib\x64" -Llib -lcufft
SOURCES=fft_helper.cu tile.cu SCRIMP.cu
HEADERS=fft_helper.h tile.h SCRIMP.h
OBJECTS=getopt.obj SCRIMP.obj fft_helper.obj tile.obj kernels.obj
EXECUTABLE=SCRIMP-GPU

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)  $(SOURCES) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
    
getopt.obj: getopt.c
	$(CC) $< -o $@ -c
    
SCRIMP.obj: SCRIMP.cu SCRIMP.h
	$(CC) $(CFLAGS) SCRIMP.cu -o $@

tile.obj: tile.h tile.cu
	$(CC) $(CFLAGS) tile.cu -o $@

fft_helper.obj: fft_helper.h fft_helper.cu
	$(CC) $(CFLAGS) fft_helper.cu $@

kernels.obj: kernels.h kernels.cu
	$(CC) $(CFLAGS) kernels.cu $@


clean:
	rm -f *.obj
