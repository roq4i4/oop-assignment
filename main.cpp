#include <iostream>
#include "Image_Class.h"

using namespace std;

int main() {
    Image image("FellAsleep.jpg");
    int angle;
    cout << "Enter an angle (90, 180, 270): ";
    cin >> angle;
    if (angle == 90) {
        Image image2 (image.height, image.width);
        for(int x = 0; x< image.width; ++x) {
            for(int y = 0; y < image.height; ++y) {
                for(int c = 0; c < 3; ++c) {

                    image2(y, image.width - x - 1, c) = image(x, y, c);
                }
            }
        }    
    image2.saveImage("FellAsleep90.png");
    } else if (angle == 180) {
        Image image2 (image.width, image.height);
        for(int x = 0; x< image.width; ++x) {
            for(int y = 0; y < image.height; ++y) {
                for(int c = 0; c < 3; ++c) {

                    image2(image.width - x - 1, image.height - y - 1, c) = image(x, y, c);
                }
            }
        }
        image2.saveImage("FellAsleep180.png");
    } else if (angle == 270) {
        Image image2 (image.height, image.width);
        for(int x = 0; x< image.width; ++x) {
            for(int y = 0; y < image.height; ++y) {
                for(int c = 0; c < 3; ++c) {

                    image2(y, image.width - x - 1, c) = image(x, y, c);
                }
            }
        }
        image2.saveImage("FellAsleep270.png");
    }
    return 0;
}
