#include "fractol.h"

// static void classify_set(t_fractol *a, char **argv){

// }

static void fractal_init(t_fractol *a, int argc, char **argv){
    // classify_set(&a, argv);
}

int main(int argc, char **argv){
    t_fractol a;

    if (argc < 2)
        exit(1);

    fractal_init(&a, argc, argv);

}