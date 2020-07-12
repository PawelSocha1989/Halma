#include "ZasadyGry.h"  //zaimplementowano potrzebny plik nag��wkowy

void init()
{
	allegro_init();  // inicjuje bibliotek� allegro
    set_color_depth(16); // ustawia odpowiedni� g��bi� kolor�w
	install_keyboard(); // instaluje klawiature
    set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 640, 480, 0, 0); // wy�wietla gr� na pe�nym ekranie, oraz ustawia rozdzielczo�� ekranu w jakim pracuej gra
	clear_to_color(screen, makecol(0,255,0));  //czy�ci ekran na zielony kolor
	install_mouse();  //instaluje myszke
	show_mouse(screen);  //wy�wietla myszke na ekranie
}

int main()
{
	init(); //wywo�ano powy�sz� funkcj�
	menu funkcjam; // stworzono obiekt klasy menu
	funkcjam.menu_glowne(); // wywo�ano funkcj� z klasy menu za pomoc� powy�ej. stworzonego obiektu
	readkey(); //czyta czy zosta� wci�ni�ty klawisz
    allegro_exit(); // zamyka biblioteke allegro
    return 0;
}
END_OF_MAIN(); // zamkni�to funkcj� main

