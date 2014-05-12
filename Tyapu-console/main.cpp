#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char *argv[])
{
    std::cout << "Bienvenido a Tyapu, el mejor reproductor de música del NO mercado.\n";

    std::string command;

    while(command != "salir"){
        std::cin >> command;

        if(command == "ayuda"){
            std::cout << "agregar <ruta>               Agrega de manera recursiva los archivos de una ruta.\n";
        }

        if(command == "huevoDePascuas"){
            std::cout << "Acá tenes tu huevo\n";
            sleep(2);
            std::cout << "******** @-@-@*********\n";
            std::cout << "****** @————–—–@*******\n";
            std::cout << "**** @————————––—@*****\n";
            std::cout << "*** @——- Felices——@****\n";
            std::cout << "** @——– Pascuas——–—@***\n";
            std::cout << "** @——(\\(\\——————–——@***\n";
            std::cout << "** @——(^.^)—–—————–@***\n";
            std::cout << "** @—*(..(“)(“).———@***\n";
            std::cout << "*** @—————————–———@****\n";
            std::cout << "***** @———————–—@******\n";
            std::cout << "******* @-@-@-@********\n";
        }
    }
}
