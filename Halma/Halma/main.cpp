#include "ZasadyGry.h"  //zaimplementowano potrzebny plik nag³ówkowy

void init()
{
	allegro_init();  // inicjuje bibliotekê allegro
    set_color_depth(16); // ustawia odpowiedni¹ g³êbiê kolorów
	install_keyboard(); // instaluje klawiature
    set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 640, 480, 0, 0); // wyœwietla grê na pe³nym ekranie, oraz ustawia rozdzielczoœæ ekranu w jakim pracuej gra
	clear_to_color(screen, makecol(0,255,0));  //czyœci ekran na zielony kolor
	install_mouse();  //instaluje myszke
	show_mouse(screen);  //wyœwietla myszke na ekranie
}

int main()
{
	init(); //wywo³ano powy¿sz¹ funkcjê
	menu funkcjam; // stworzono obiekt klasy menu
	funkcjam.menu_glowne(); // wywo³ano funkcjê z klasy menu za pomoc¹ powy¿ej. stworzonego obiektu
	readkey(); //czyta czy zosta³ wciœniêty klawisz
    allegro_exit(); // zamyka biblioteke allegro
    return 0;
}
END_OF_MAIN(); // zamkniêto funkcjê main

