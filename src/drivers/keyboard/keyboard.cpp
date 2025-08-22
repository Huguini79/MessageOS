#include "keyboard.h"
#include "drivers/vga/vga.h"
#include "drivers/io/io.h"

char comando[100];

int pos;

void agregar_caracter(char c) {
    comando[pos++] = c;
    comando[pos] = '\0';
}

char tolower(char s1)
{
    if (s1 >= 65 && s1 <= 90)
    {
        s1 += 32;
    }

    return s1;
}

void itoa(int num, char* buffer) {
    int i = 0;
    int isNegative = 0;

    if (num == 0) {
        buffer[i++] = '0';
        buffer[i] = '\0';
        return;
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num > 0) {
        buffer[i++] = (num % 10) + '0';
        num = num / 10;
    }

    if (isNegative)
        buffer[i++] = '-';

    buffer[i] = '\0';

    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }
}

int strnlen(const char* ptr, int max)
{
    int i = 0;
    for (i = 0; i < max; i++)
    {
        if (ptr[i] == 0)
            break;
    }

    return i;
}

int strnlen_terminator(const char* str, int max, char terminator)
{
    int i = 0;
    for(i = 0; i < max; i++)
    {
        if (str[i] == '\0' || str[i] == terminator)
            break;
    }

    return i;
}

int istrncmp(const char* s1, const char* s2, int n)
{
    unsigned char u1, u2;
    while(n-- > 0)
    {
        u1 = (unsigned char)*s1++;
        u2 = (unsigned char)*s2++;
        if (u1 != u2 && tolower(u1) != tolower(u2))
            return u1 - u2;
        if (u1 == '\0')
            return 0;
    }

    return 0;
}
int strncmp(const char* str1, const char* str2, int n)
{
    unsigned char u1, u2;

    while(n-- > 0)
    {
        u1 = (unsigned char)*str1++;
        u2 = (unsigned char)*str2++;
        if (u1 != u2)
            return u1 - u2;
        if (u1 == '\0')
            return 0;
    }

    return 0;
}

char* strcpy(char* dest, const char* src)
{
    char* res = dest;
    while(*src != 0)
    {
        *dest = *src;
        src += 1;
        dest += 1;
    }

    *dest = 0x00;

    return res;
}

char* strncpy(char* dest, const char* src, int count)
{
    int i = 0;
    for (i = 0; i < count-1; i++)
    {
        if (src[i] == 0x00)
            break;

        dest[i] = src[i];
    }

    dest[i] = 0x00;
    return dest;
}

bool isdigit(char c)
{
    return c >= 48 && c <= 57;
}
int tonumericdigit(char c)
{
    return c - 48;
}

void detectar_teclado() {
    while(1) {
        uint8_t status = insb(0x64);
        if(status & 0x01) {
            uint8_t scancode = insb(0x60);

            if(scancode == 0x1E) {
                imprimir_texto("a");
                agregar_caracter('a');

            } else if(scancode == 0x30) {
                imprimir_texto("b");
                agregar_caracter('b');

            } else if(scancode == 0x2E) {
                imprimir_texto("c");
                agregar_caracter('c');


            } else if(scancode == 0x20) {
                imprimir_texto("d");
                agregar_caracter('d');


            } else if(scancode == 0x12) {
                imprimir_texto("e");
                agregar_caracter('e');


            } else if(scancode == 0x21) {
                imprimir_texto("f");
                agregar_caracter('f');


            } else if(scancode == 0x22) {
                imprimir_texto("g");
                agregar_caracter('g');


            } else if(scancode == 0x23) {
                imprimir_texto("h");
                agregar_caracter('h');


            } else if(scancode == 0x17) {
                imprimir_texto("i");
                agregar_caracter('i');


            } else if(scancode == 0x24) {
                imprimir_texto("j");
                agregar_caracter('j');


            } else if(scancode == 0x25) {
                imprimir_texto("k");
                agregar_caracter('k');


            } else if(scancode == 0x26) {
                imprimir_texto("l");
                agregar_caracter('l');


            } else if(scancode == 0x32) {
                imprimir_texto("m");
                agregar_caracter('m');


            } else if(scancode == 0x31) {
                imprimir_texto("n");
                agregar_caracter('n');


            } else if(scancode == 0x18) {
                imprimir_texto("o");
                agregar_caracter('o');


            } else if(scancode == 0x19) {
                imprimir_texto("p");
                agregar_caracter('p');


            } else if(scancode == 0x10) {
                imprimir_texto("q");
                agregar_caracter('q');


            } else if(scancode == 0x13) {
                imprimir_texto("r");
                agregar_caracter('r');


            } else if(scancode == 0x1F) {
                imprimir_texto("s");
                agregar_caracter('s');


            } else if(scancode == 0x14) {
                imprimir_texto("t");
                agregar_caracter('t');


            } else if(scancode == 0x16) {
                imprimir_texto("u");
                agregar_caracter('u');


            } else if(scancode == 0x2F) {
                imprimir_texto("v");
                agregar_caracter('v');


            } else if(scancode == 0x11) {
                imprimir_texto("w");
                agregar_caracter('w');


            } else if(scancode == 0x2D) {
                imprimir_texto("x");
                agregar_caracter('x');


            } else if(scancode == 0x15) {
                imprimir_texto("y");
                agregar_caracter('y');


            } else if(scancode == 0x2C) {
                imprimir_texto("z");
                agregar_caracter('z');


            } else if(scancode == 0x39) {
                imprimir_texto(" ");

            } else if(scancode == 0x0F) {
                imprimir_texto("    ");

            } else if(scancode == 0x34) {
                imprimir_texto(".");

            } else if(scancode == 0x38) {
                limpiar_pantalla();
                imprimir_texto("MessageOS$ ");

            } else if(scancode == 0x1A) {
                imprimir_texto("[");

            } else if(scancode == 0x1B) {
                imprimir_texto("]");

            } else if(scancode == 0x0D) {
                imprimir_texto("=");

            } else if(scancode == 0x27) {
                imprimir_texto(";");

            } else if(scancode == 0x33) {
                imprimir_texto(",");

            } else if(scancode == 0x0C) {
                imprimir_texto("-");

            } else if(scancode == 0x4E) {
                imprimir_texto("+");

            } else if(scancode == 0x1C) {
                if(strncmp(comando, "hola", 4) == 0) {
                    imprimir_texto("\nHola, prueba exitosa\n\n");

                } else if(strncmp(comando, "sorpresa", 8) == 0) {
                    limpiar_pantalla();
                    for(int i = 0; i <= 50; i++) {
                        imprimir_texto("..MessageOS..");
                    }
                    imprimir_texto("\n\n");
                }
                else if(strncmp(comando, "help", 4) == 0) {
                    limpiar_pantalla();
                    imprimir_texto("Ayuda:\n1) hola - El primer comando creado para el sistema operativo, uno de prueba\n2) sorpresa - comando sorpresa\n3) numfull - Cubrir toda la pantalla con numeros, para despues quitar los numeros, presiona ALT o introduce el comando clear\n4) clear - Limpiar la pantalla\n5) creditos - Creditos del desarrollo del sistema operativo");
                    imprimir_texto("\n\n");
                }
                else if(strncmp(comando, "numfull", 7) == 0) {
                    limpiar_pantalla();
                    for(int i = 0; i <= 150; i++) {
                        imprimir_texto("1234567890");
                    }
                    imprimir_texto("\n\n");
                }
                else if(strncmp(comando, "creditos", 8) == 0) {
                    limpiar_pantalla();
                    imprimir_texto("Programador: Huguini79\nTiempo de desarrollo de MessageOS: 1 dia\nLenguajes de programacion utilizados: Ensamblador y C++");
                    imprimir_texto("\n\n");
                }
                else if(strncmp(comando, "clear", 5) == 0) {
                    limpiar_pantalla();
                }
                else if(strncmp(comando, "", 1) == 0) {
                    imprimir_texto("\n");
                }
                else {
                    imprimir_texto("\nComando no reconocido\n\n");
                }
                pos = 0;
                comando[0] = '\0';
                imprimir_texto("MessageOS$ ");

            }

    }
}
}
