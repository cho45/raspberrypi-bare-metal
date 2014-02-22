require "pathname"

def which(name)
	ret = ENV["PATH"].split(/:/).map {|i|
		File.expand_path(name, i)
	}.find {|i|
		File.exist?(i) && File.executable?(i)
	} or raise "#{name} is not in PATH"
end

ARMGCC_ROOT = Pathname(which("arm-none-eabi-gcc")).parent.parent

AOPS = "-mcpu=arm1176jzf-s -mfloat-abi=softfp -mfpu=vfp --warn --fatal-warnings "

COPS = "-Wall -nostartfiles -ffreestanding"

CFLAGS = "-mcpu=arm1176jzf-s -mtune=arm1176jzf-s -mfloat-abi=softfp -mfpu=vfp -O0 -ggdb -g"

LIB = "-L#{ARMGCC_ROOT}/arm-none-eabi/lib/ -L#{ARMGCC_ROOT}/lib/gcc/arm-none-eabi/4.7.3"

task :default => "kernel.img"

task :clean  do
	rm FileList["*.o"]
	rm FileList["*.elf"].exclude("start.elf")
	rm "kernel.img"
end

task :install => %w"kernel.img bootcode.bin start.elf" do
	copy_to = ENV["dest"] or raise "ENV['dest'] is required"
	cp %w"kernel.img bootcode.bin start.elf", copy_to
	sh %{ diskutil eject /Volumes/SD }
end

file "vectors.o" => "vectors.s" do
	sh %{ arm-none-eabi-as #{AOPS} vectors.s -o vectors.o }
end
file "main.o" => "main.c" do
	sh %{ arm-none-eabi-gcc #{COPS} #{CFLAGS} -c main.c -o main.o }
end

file "main.elf" => %w"memmap vectors.o main.o" do
	sh %{ arm-none-eabi-ld vectors.o main.o -Map=main.map -T memmap -o main.elf #{LIB} -lc -lm -lgcc  }
end

file "kernel.img" => "main.elf" do
	sh %{ arm-none-eabi-objcopy main.elf -O binary kernel.img }
end

file "bootcode.bin" do
	sh %{ wget https://github.com/raspberrypi/firmware/raw/master/boot/bootcode.bin }
end

file "start.elf" do
	sh %{ wget https://github.com/raspberrypi/firmware/raw/master/boot/start.elf }
end
