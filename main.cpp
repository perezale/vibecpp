#include "bgfg_vibe.hpp"
using namespace cv;

int main(int argc, char ** argv)
{
    if ( argc == 1 ) {
        printf( "No arguments were passed.\n" );
        return -1;
    } 

    Mat frame;
    bgfg_vibe bgfg;
    VideoCapture cap(argv[1]);
    cap >> frame;
    bgfg.init_model(frame);
    for(;;)
    {
        cap>>frame; 
        Mat fg = *bgfg.fg(frame);
        imshow("fg",fg);
        waitKey(1);
    }
    return 0;
}