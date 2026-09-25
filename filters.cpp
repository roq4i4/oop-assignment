#include<iostream>
#include "image_Class.h"
using namespace std;
//pink fillter

void pinkFilter(Image& img){
for(int i=0;i<img.height();i++){
    for(int j=0;j<img.width();j++ ){

        int r=img.getPixel(i,j,0)+50;
        int b=img.getPixel(i,j,2)+20;
        int g=img.getPixel(i,j,1);


   
if(r>255){
       r=255;
    }
if(b>255){
       b=255;
    }
    img.setPixel(i,j,0,r);
    img.setPixel(i,j,2,b);
    img.setPixel(i,j,1,g);
}
}
}

// vintage filter
void vintageFilter(Image& img){
for(int i=0;i<img.height();i++){
    for(int j=0;j<img.width();j++ ){

        int r=img.getPixel(i,j,0)+30;
        int g=img.getPixel(i,j,1)+15;
        int b=img.getPixel(i,j,2)-20;

        if(r>255){
            r=255;
        }
        if(g>255){
            g=255;
        }
        if(b<0){
            b=0;
        }
        img.setPixel(i,j,0,r);
        img.setPixel(i,j,2,b);
        img.setPixel(i,j,1,g);
    }
}
}