#!/bin/sh
#!/bin/sh
mkdir -p $DERIVED_FILE_DIR
echo "" > $DERIVED_FILE_DIR/O2Defines_FreeType.h

if [ -d /Developer/Cocotron/1.0/Windows/i386/freetype-2.3.5 ]; then
	echo "FreeType 2.3.5 present."
	echo "#define FREETYPE_PRESENT 1" >> $DERIVED_FILE_DIR/O2Defines_FreeType.h
else
# Create empty libfreetype for link phase
 echo "FreeType 2.3.5 not found"
 touch $DERIVED_FILE_DIR/libfreetype.c
 /Developer/Cocotron/1.0/Windows/i386/gcc-4.3.1/bin/i386-mingw32msvc-gcc $DERIVED_FILE_DIR/libfreetype.c -c -o $DERIVED_FILE_DIR/libfreetype.o
 /Developer/Cocotron/1.0/Windows/i386/gcc-4.3.1/bin/i386-mingw32msvc-ar cr $DERIVED_FILE_DIR/libfreetype.a $DERIVED_FILE_DIR/libfreetype.o
fi

echo "" > $DERIVED_FILE_DIR/O2Defines_libjpeg.h
if [ -d /Developer/Cocotron/1.0/Windows/i386/libjpeg ]; then
	echo "libjpeg present."
	echo "#define LIBJPEG_PRESENT 1" >> $DERIVED_FILE_DIR/O2Defines_libjpeg.h
else
# Create empty libjpeg for link phase
 echo "libjpeg not found"
 touch $DERIVED_FILE_DIR/libjpeg.c
 /Developer/Cocotron/1.0/Windows/i386/gcc-4.3.1/bin/i386-mingw32msvc-gcc $DERIVED_FILE_DIR/libjpeg.c -c -o $DERIVED_FILE_DIR/libjpeg.o
 /Developer/Cocotron/1.0/Windows/i386/gcc-4.3.1/bin/i386-mingw32msvc-ar cr $DERIVED_FILE_DIR/libjpeg.a $DERIVED_FILE_DIR/libjpeg.o
fi

echo "" > $DERIVED_FILE_DIR/O2Defines_zlib.h
if [ -d /Developer/Cocotron/1.0/Windows/i386/zlib-1.2.5 ]; then
	echo "zlib present."
	echo "#define ZLIB_PRESENT 1" >> $DERIVED_FILE_DIR/O2Defines_zlib.h
else
# Create empty zlib for link phase
 echo "zlib not found"
 touch $DERIVED_FILE_DIR/zlib.c
 /Developer/Cocotron/1.0/Windows/i386/gcc-4.3.1/bin/i386-mingw32msvc-gcc $DERIVED_FILE_DIR/zlib.c -c -o $DERIVED_FILE_DIR/zlib.o
 /Developer/Cocotron/1.0/Windows/i386/gcc-4.3.1/bin/i386-mingw32msvc-ar cr $DERIVED_FILE_DIR/libz.a $DERIVED_FILE_DIR/zlib.o
fi

echo "" > $DERIVED_FILE_DIR/O2Defines_libpng.h
if [ -d /Developer/Cocotron/1.0/Windows/i386/libpng ]; then
	echo "libpng present."
	echo "#define LIBPNG_PRESENT 1" >> $DERIVED_FILE_DIR/O2Defines_libpng.h
else
# Create empty libpng for link phase
 echo "libpng not found"
 touch $DERIVED_FILE_DIR/libpng.c
 /Developer/Cocotron/1.0/Windows/i386/gcc-4.3.1/bin/i386-mingw32msvc-gcc $DERIVED_FILE_DIR/libpng.c -c -o $DERIVED_FILE_DIR/libpng.o
 /Developer/Cocotron/1.0/Windows/i386/gcc-4.3.1/bin/i386-mingw32msvc-ar cr $DERIVED_FILE_DIR/libpng.a $DERIVED_FILE_DIR/libpng.o
fi


