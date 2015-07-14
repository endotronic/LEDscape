#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>
#include <errno.h>
#include <random>
#include <unistd.h>
#include <vector>

#include "ledscape.h"
#include "screen.hh"

int main(int argc, const char ** argv)
{
	ledscape_config_t *config = &ledscape_matrix_default;
	ledscape_t *const leds = ledscape_init(config, 0);

	uint32_t * const p = (uint32_t*)calloc(32*32, 4);
	Screen *screen = new Screen(leds, p);
	screen->set_background_color(0);

	printf("init done\n");

	screen->draw_start();
	while (1)
	{
		int x = rand() % 32, y = rand() % 32, color = rand() % 0xFFFFFFFF;
	    screen->drawpixel(x, y, color);
	    screen->draw_end();
		//usleep(20000);
	}

	return EXIT_SUCCESS;
}
