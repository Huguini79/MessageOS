clear
nasm -f elf32 src/kernel/kernel.asm -o build/kernel.asm.o
nasm -f elf32 src/drivers/io/io.asm -o build/io.asm.o
g++ -I./src -m32 -c src/kernel/kernel.cpp -o build/kernel.o
g++ -I./src -m32 -c src/drivers/vga/vga.cpp -o build/vga.o
g++ -I./src -m32 -c src/drivers/memory/memory.cpp -o build/memory.o
g++ -I./src -m32 -c src/drivers/keyboard/keyboard.cpp -o build/keyboard.o
ld -m elf_i386 -T src/linker/linker.ld -o iso/boot/kernel build/kernel.asm.o build/kernel.o build/vga.o build/io.asm.o build/memory.o build/keyboard.o
grub-mkrescue -o bin/MessageOS.iso iso
qemu-system-x86_64 -m 1024 bin/MessageOS.iso
