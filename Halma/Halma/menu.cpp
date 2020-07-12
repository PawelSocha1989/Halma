#include "menu.h"
#include "kasa.h"
#include "ZasadyGry.h"
#include "DwochGraczy.h"
#include "ZapisaneWyniki.h"

menu::menu(void)
{
	halma = NULL;
	bufor = NULL;
	bufor2 = NULL;
	menu1 = NULL;
	menu12 = NULL;
	menu13 = NULL;
	menu14 = NULL;
	menu15 = NULL;
	mouse_x=0;
	mouse_y=0;
	mouse_b=0;
	frame=0;
	gracz=0;
}

menu::~menu(void)
{
	destroy_bitmap(bufor);
	destroy_bitmap(bufor2);
	destroy_bitmap(halma);
	destroy_bitmap(menu1);
	destroy_bitmap(menu12);
	destroy_bitmap(menu13);
	destroy_bitmap(menu14);
	destroy_bitmap(menu15);
	destroy_bitmap(kursor);
}

void menu::menu_load()
{
	bufor = create_bitmap(640,480);
	bufor2 = create_bitmap(640,480);
	halma = load_bmp( "grafika/halma.bmp", default_palette );
	menu1 = load_bmp( "grafika/menu5.bmp", default_palette );
	menu12 = load_bmp( "grafika/menu2.bmp", default_palette );
	menu13 = load_bmp( "grafika/menu3.bmp", default_palette );
	menu14 = load_bmp( "grafika/menu4.bmp", default_palette );
	menu15 = load_bmp( "grafika/menu.bmp", default_palette );
}

void menu::menu_klawiatura()
{
		if(key[KEY_DOWN]) frame++;  //jeœli wciœniemy klawisz w dó³ to zwiêkszamy numer klatki
		if(key[KEY_UP]) frame--;   // jeœli wciœniemy klawisz w góre to zmniejszamy numer klatki

		if(frame > 8) frame=0;  //jeœli numer klatki jest wiekszy jak 8 to ustawia na zero dziêki temu mo¿emy u¿yæ tak zwanego zapêtlenia w menu
		if(frame < 0) frame=8;  //jeœli numer klatki jest mniejszy ni¿ 0 to ustawiany jest na numer 8
		clear_to_color(bufor, makecol(0,255,0));
		clear_to_color(bufor2, makecol(0,255,0));
		menu_tlo();
		masked_blit( bufor2, bufor, 0,0,0,0, 640,480);
		rest(3); //zatrzymuje program na 3 milisekundy

		if( frame<2) { draw_sprite(bufor, menu12, 200, 150);
			if(key[KEY_ENTER])
				{
					kasa money; //Stworzono obiekt klasy kasa
					money.glowna_kasa(); //funkcja obs³uguj¹ca funkcje odpowiadaj¹ce za losowanie monet¹
				}
		}

		else if( frame>=2 && frame<4) { draw_sprite(bufor, menu13, 200, 150);
				if(key[KEY_ENTER])
				{
					while(!key[KEY_ESC])
					{
						ZapisaneWyniki wyn; //Stworzono obiekt klasy ZapisaneWyniki
						wyn.wyniki();//funkcja odpowiadaj¹ca za wyœwietlanie wyników
					}
				}
		}
		else if( frame>=4 && frame<6) { draw_sprite(bufor, menu15, 200, 150);
				if(key[KEY_ENTER])
					{
						ZasadyGry zas;//Stworzono Obiekt klasy ZasadyGry
						zas.zasady_gry(); //funkcja odpowiada za wyœlwietlenie zasad gry
					}
		}

		else if( frame>=6 && frame<8) { draw_sprite(bufor, menu14, 200, 150);
										 if(key[KEY_ENTER]) exit(0);} //za pomoc¹ tej operacji zamykamy aplikacje

		menu_myszka();// funkcja obs³ufuj¹ca kolizje myszki
}

void menu::menu_myszka()
{
	if((mouse_x>=200)&&(mouse_x<=400)&&(mouse_y>=200)&&(mouse_y<=250)) //pozycje na które naje¿d¿a kursor
		{
			menu_tlo(); //wyœwietlanie ca³ej podstawowej grafiki na bufor2 wykorzystywanej w menu
			masked_blit( bufor2, bufor, 0,0,0,0, 640,480); //wyœwietlanie zawartoœci buforu2 na bufor co zapobiega miganiu ekranu
			masked_blit(menu12, bufor, 0,0,200,150, bufor->w, bufor->h);//wyœwitla sie grafika odpowiadaj¹ca za podœwieltenie odpowiedniego przycisku z g³ównego menu
			if(mouse_b==1) //jeœli wciœniemy lewy przycisk myszy to wykonuj¹ sie ponizsze operacje
			{
				kasa money; //stworzono obiekt klasy kasa
				money.glowna_kasa();//funkcja obs³uguj¹ca funkcje odpowiadaj¹ce za losowanie monet¹
			}
		}

	if((mouse_x>=180)&&(mouse_x<=430)&&(mouse_y>=250)&&(mouse_y<=290))
		{
			menu_tlo();
			masked_blit( bufor2, bufor, 0,0,0,0, 640,480);
			masked_blit(menu13, bufor, 0,0,200,150, bufor->w, bufor->h);
			if(mouse_b==1)
			{
				while(!key[KEY_ESC])
				{
					ZapisaneWyniki wyn; //Stworzono obiekt klasy ZapisaneWyniki
					wyn.wyniki();//funkcja odpowiadaj¹ca za wyœwietlanie wyników
				}
			}
		}

	if((mouse_x>=180)&&(mouse_x<=430)&&(mouse_y>=300)&&(mouse_y<=340))
		{
			menu_tlo();
			masked_blit( bufor2, bufor, 0,0,0,0, 640,480);
			masked_blit(menu15, bufor, 0,0,200,150, bufor->w, bufor->h);
			if(mouse_b==1)
			{
				ZasadyGry zas;//Stworzono Obiekt klasy ZasadyGry
				zas.zasady_gry(); //funkcja odpowiada za wyœlwietlenie zasad gry
			}

		}

	if((mouse_x>=250)&&(mouse_x<=370)&&(mouse_y>=350)&&(mouse_y<=390))
		{
			menu_tlo();
			masked_blit( bufor2, bufor, 0,0,0,0, 640,480);
			masked_blit(menu14, bufor, 0,0,200,150, bufor->w, bufor->h);
			if(mouse_b==1) exit(0); //za pomoc¹ tej operacji zamykamy aplikacje
		}
}

void menu::menu_tlo()
{
	masked_blit( halma, bufor2, 0,0,0,0, halma->w, halma->h);
	masked_blit( menu1, bufor2, 0,0,200,150, menu1->w, menu1->h);//wyœwietlam grafikê podsawowego menu

}

void menu::szachownica()//funkcja tworz¹ca widzian¹ w menu szachownicê za pomoc¹ kwadracików porozmieszczanych w odpowiednich pozycjach
{
	rectfill(bufor2, 200, 150, 440, 390, makecol(255, 255, 255));
	rectfill(bufor2, 200, 150, 230, 180, makecol(0, 0, 0));
	rectfill(bufor2, 260, 150, 290, 180, makecol(0, 0, 0));
	rectfill(bufor2, 320, 150, 350, 180, makecol(0, 0, 0));
	rectfill(bufor2, 380, 150, 410, 180, makecol(0, 0, 0));
	rectfill(bufor2, 230, 180, 260, 210, makecol(0, 0, 0));
	rectfill(bufor2, 290, 180, 320, 210, makecol(0, 0, 0));
	rectfill(bufor2, 350, 180, 380, 210, makecol(0, 0, 0));
	rectfill(bufor2, 410, 180, 440, 210, makecol(0, 0, 0));
	rectfill(bufor2, 200, 210, 230, 240, makecol(0, 0, 0));
	rectfill(bufor2, 260, 210, 290, 240, makecol(0, 0, 0));
	rectfill(bufor2, 320, 210, 350, 240, makecol(0, 0, 0));
	rectfill(bufor2, 380, 210, 410, 240, makecol(0, 0, 0));
	rectfill(bufor2, 230, 240, 260, 270, makecol(0, 0, 0));
	rectfill(bufor2, 290, 240, 320, 270, makecol(0, 0, 0));
	rectfill(bufor2, 350, 240, 380, 270, makecol(0, 0, 0));
	rectfill(bufor2, 410, 240, 440, 270, makecol(0, 0, 0));
	rectfill(bufor2, 200, 270, 230, 300, makecol(0, 0, 0));
	rectfill(bufor2, 260, 270, 290, 300, makecol(0, 0, 0));
	rectfill(bufor2, 320, 270, 350, 300, makecol(0, 0, 0));
	rectfill(bufor2, 380, 270, 410, 300, makecol(0, 0, 0));
	rectfill(bufor2, 230, 300, 260, 330, makecol(0, 0, 0));
	rectfill(bufor2, 290, 300, 320, 330, makecol(0, 0, 0));
	rectfill(bufor2, 350, 300, 380, 330, makecol(0, 0, 0));
	rectfill(bufor2, 410, 300, 440, 330, makecol(0, 0, 0));
	rectfill(bufor2, 200, 330, 230, 360, makecol(0, 0, 0));
	rectfill(bufor2, 260, 330, 290, 360, makecol(0, 0, 0));
	rectfill(bufor2, 320, 330, 350, 360, makecol(0, 0, 0));
	rectfill(bufor2, 380, 330, 410, 360, makecol(0, 0, 0));
	rectfill(bufor2, 230, 360, 260, 390, makecol(0, 0, 0));
	rectfill(bufor2, 290, 360, 320, 390, makecol(0, 0, 0));
	rectfill(bufor2, 350, 360, 380, 390, makecol(0, 0, 0));
	rectfill(bufor2, 410, 360, 440, 390, makecol(0, 0, 0));
}

void menu::menu_kursor()//funkcja odpowiadaj¹ca za za³adowanie grafiki kursora, zmiany poodstawowego kursora na obecny i na koniec wyœwietlenie go
{
	kursor = load_bmp("grafika/kursor.bmp", NULL);
	set_mouse_sprite(kursor);
	unscare_mouse();
}

void menu::menu_glowne()//funkcja ³aduj¹ca wszystkie powyrzsze funkcje i wyœwietlaj¹ca ich na ekran
{
	while(1)
	{
		menu_load();
		menu_kursor();
		menu_klawiatura();
		draw_sprite(bufor,kursor,mouse_x,mouse_y);
		masked_blit(bufor, screen, 0,0,0,0, bufor->w, bufor->h);
	}
}
