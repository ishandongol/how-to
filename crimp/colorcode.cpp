#include"crimp.h"

void colorcode(SDL_Renderer * texture_renderer, crimp table, crimp crimper, crimp jack, crimp utp,crimp table2, crimp bar, crimp *bar_slider)
{
    SDL_RenderClear(texture_renderer);
    table.render_media(texture_renderer);
    crimper.render_media(texture_renderer);
    jack.render_media(texture_renderer);
    utp.render_media(texture_renderer);
    table2.render_media(texture_renderer);
    bar.render_media(texture_renderer);
    bar_slider->render_media(texture_renderer);
}
