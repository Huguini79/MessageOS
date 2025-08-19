#include "kernel.h"
#include "drivers/vga/vga.h"
#include "drivers/io/io.h"
#include "drivers/keyboard/keyboard.h"

#include <stddef.h>
#include <stdint.h>

extern "C" void kernel_main() {
    terminal_initialize();
    imprimir_texto("BIENVENIDO A MessageOS");
    imprimir_texto("\n\n\n\nCreado por Huguini79 en ensamblador y en C++");
    imprimir_texto("\n\n\n\nMessageOS$ ");
    outb(0x60, 0xff);
    detectar_teclado();

}
