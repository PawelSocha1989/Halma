#include "ZasadyGry.h" //zaimplementowano potrzebny plik nag³ówkowy

ZasadyGry::ZasadyGry(void)
{
	zasady = NULL;
	zasady1 = NULL;
	bufor_zasady = NULL;
	kursor_zas = NULL;
}


ZasadyGry::~ZasadyGry(void)
{
	destroy_bitmap(bufor_zasady);
	destroy_bitmap(zasady);
	destroy_bitmap(zasady1);
	destroy_bitmap(kursor_zas);
}

void ZasadyGry::load_zasady()
{
	bufor_zasady = create_bitmap(640,480);
	zasady = load_bmp("grafika/zasady.bmp", default_palette);
	zasady1 = load_bmp("grafika/zasadygry.bmp", default_palette);
}

void ZasadyGry::kursor_zasady()
{
	kursor_zas = load_bmp("grafika/kursor.bmp", NULL);
	set_mouse_sprite(kursor_zas);
	unscare_mouse();
}

void ZasadyGry::zasady_gry()
{
	load_zasady();
	kursor_zasady();
	while(!key[KEY_ESC])
	{
		clear_to_color(bufor_zasady, makecol(0,0,0));
		masked_blit(zasady1,bufor_zasady, 0,0,271,5, zasady1->w,zasady1->h);
		masked_blit(zasady,bufor_zasady, 0,0,80,40, zasady->w,zasady->h);
		draw_sprite(bufor_zasady,kursor_zas,mouse_x,mouse_y);
		blit(bufor_zasady, screen, 0,0,0,0, 640, 480);
	}
}