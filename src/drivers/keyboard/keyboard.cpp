#include "keyboard.h"
#include "drivers/vga/vga.h"
#include "drivers/io/io.h"

void detectar_teclado() {
    while(1) {
        uint8_t status = insb(0x64);
        if(status & 0x01) {
            uint8_t scancode = insb(0x60);

            if(scancode == 0x1E) {
                imprimir_texto("a");

            } else if(scancode == 0x30) {
                imprimir_texto("b");

            } else if(scancode == 0x2E) {
                imprimir_texto("c");

            } else if(scancode == 0x20) {
                imprimir_texto("d");

            } else if(scancode == 0x12) {
                imprimir_texto("e");

            } else if(scancode == 0x21) {
                imprimir_texto("f");

            } else if(scancode == 0x22) {
                imprimir_texto("g");

            } else if(scancode == 0x23) {
                imprimir_texto("h");

            } else if(scancode == 0x17) {
                imprimir_texto("i");

            } else if(scancode == 0x24) {
                imprimir_texto("j");

            } else if(scancode == 0x25) {
                imprimir_texto("k");

            } else if(scancode == 0x26) {
                imprimir_texto("l");

            } else if(scancode == 0x32) {
                imprimir_texto("m");

            } else if(scancode == 0x31) {
                imprimir_texto("n");

            } else if(scancode == 0x18) {
                imprimir_texto("o");

            } else if(scancode == 0x19) {
                imprimir_texto("p");

            } else if(scancode == 0x10) {
                imprimir_texto("q");

            } else if(scancode == 0x13) {
                imprimir_texto("r");

            } else if(scancode == 0x1F) {
                imprimir_texto("s");

            } else if(scancode == 0x14) {
                imprimir_texto("t");

            } else if(scancode == 0x16) {
                imprimir_texto("u");

            } else if(scancode == 0x2F) {
                imprimir_texto("v");

            } else if(scancode == 0x11) {
                imprimir_texto("w");

            } else if(scancode == 0x2D) {
                imprimir_texto("x");

            } else if(scancode == 0x15) {
                imprimir_texto("y");

            } else if(scancode == 0x2C) {
                imprimir_texto("z");

            } else if(scancode == 0x39) {
                imprimir_texto(" ");

            } else if(scancode == 0x1C) {
                imprimir_texto("\nMessageOS$ ");

            } else if(scancode == 0x0F) {
                imprimir_texto("    ");

            }
        }

    }
}
