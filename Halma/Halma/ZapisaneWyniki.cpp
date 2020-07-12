#include "ZapisaneWyniki.h"

ZapisaneWyniki::ZapisaneWyniki(void)
{
	kursorek = NULL;
	bufor_wyniki = NULL;
	zapisane_wyniki = NULL;
}

ZapisaneWyniki::~ZapisaneWyniki(void)
{
	destroy_bitmap(bufor_wyniki);
	destroy_bitmap(zapisane_wyniki);
	destroy_bitmap(kursorek);
}

void ZapisaneWyniki::load_wyniki()
{
	bufor_wyniki = create_bitmap(640,480);
	zapisane_wyniki = load_bmp("grafika/zapisane.bmp", default_palette);
}

void ZapisaneWyniki::kursor_wyniki()
{
	kursorek = load_bmp("grafika/kursor.bmp", NULL);
	set_mouse_sprite(kursorek);
	unscare_mouse();
}

void ZapisaneWyniki::wczytaj()
{
	char p;

    ifstream plik;
    plik.open("zapisywanie.txt");

    if(!plik)
    {
		rest(200);
		allegro_message("nie znaleziono pliku");
    }
    else
    {
		int n=0,c=0;
		while(plik.good())
		{
				masked_blit(zapisane_wyniki,bufor_wyniki, 0,0,180,20, zapisane_wyniki->w,zapisane_wyniki->h);
				p=plik.get();
				n=n+10;
				if(p=='\n')
				{
					c=c+10;
					n=0;
				}
				textprintf_ex(bufor_wyniki,font,100+n,100+c,makecol(255,255,255),-1,"%c",p);
		}
		plik.close();
    }
}

void ZapisaneWyniki::wyniki()
{
	load_wyniki();
	kursor_wyniki();
	while(!key[KEY_ESC])
	{
		clear_to_color(bufor_wyniki, makecol(0,0,0));
		wczytaj();
		draw_sprite(bufor_wyniki,kursorek,mouse_x,mouse_y);
		blit(bufor_wyniki, screen, 0,0,0,0, 640, 480);
	}
}
