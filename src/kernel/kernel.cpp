#include "kernel.h"
#include "drivers/vga/vga.h"
#include "drivers/io/io.h"
#include "drivers/keyboard/keyboard.h"
#include "drivers/disk/disk.h"

#include <stddef.h>
#include <stdint.h>

extern "C" void kernel_main() {
    terminal_initialize();
    imprimir_texto("BIENVENIDO A MessageOS");
    imprimir_texto("\nCreado por Huguini79 en ensamblador y en C++\n");
    imprimir_texto("Presiona ALT para limpiar la pantalla");
    imprimir_texto("\n\n\n\nMessageOS$ ");
    outb(0x60, 0xff);
    char buf[512];
    disk_read_sector(0, 1, buf);
    detectar_teclado();

}
