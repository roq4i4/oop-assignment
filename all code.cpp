// names:
// Habiba mohamed abdelglil hassan , 20250192 , filter 1,5
//Roqaia mohamed ismael, 20251149 , filter 4,8

#include <iostream>
#include "image_class.h"
#include <string>
using namespace std;

// filter1
void grayscale_filter(Image& img){
for(int i=0;i<img.width;i++){
        for(int j=0;j<img.height;j++){
            int avr=0;
            for(int k=0;k<3;k++){
                avr+=img(i,j,k);
            }    
                avr=avr/3;
              for(int k=0;k<3;k++){
                    img(i,j,k)=avr;
                  }    
        }
    } 
}

 //filter2
    void blackandWhite_filter(Image& img) {
    for (int x = 0; x < img.width; ++x) {
        for (int y = 0; y < img.height; ++y) {
                        
                int avg = (img(x, y, 0) + img(x, y, 1) + img(x, y, 2)) / 3;
                int val = (avg > 127) ? 255 : 0;
                img(x,y,0)  = val;
                img(x,y,1)  = val;
                img(x,y,2)  = val;
            
        }
    }
} 
//filter4
void frameFilter(Image & img) {

    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            for (int k = 0; k < 3; k++) {
                if (i < 30 || img.width - 30 < i ||
                    img.height - 30 < j || j < 30) {
                  if (i % 2 == 0 || j % 2 == 0) {
                        img(j,i,k) = 255;
                    }
                    else {
                        img(j,i,k) = 0;
                    }
                }
            }
        }
    }
}

// filter5
void flip_filter(Image& img){
Image imagenew = img;
    cout<<"Do you want to flip it Horizontally or Vertically?"<<endl;
                string type;
                cin>>type;
    for(int i=0 ;i<img.width ;i++){
        for(int j=0 ; j<img.height ; j++){
            for(int k=0; k<3 ;k++){
                if(type=="Horizontally" || type== "horizontally"){
                    imagenew(img.width-1-i,j,k)=img(i,j,k);
                }
                else{
                    imagenew(i,img.height-1-j,k)=img(i,j,k);
                }
            }
        }
    }
    img = imagenew;
}
//filter6
    void rotate_filter(Image& img) {
    int angle;
    cout << "Enter an angle (90, 180, 270): ";
    cin >> angle;
    if (angle != 90 && angle != 180 && angle != 270) {
        cout << "Invalid angle. Please enter 90, 180, or 270." << endl;
        return;
    }
    int newWidth = (angle == 180) ? img.width : img.height;
    int newHeight = (angle == 180) ? img.height : img.width;
    Image img2(newWidth, newHeight);

    for(int x = 0; x < img.width; ++x) {
        for (int y = 0; y < img.height; ++y) {
            for (int c = 0; c < 3; ++c) {
                if (angle == 90) {
                    img2(img.height - 1 - y, x, c) = img(x, y, c);
                } else if (angle == 180) {
                    img2(img.width - 1 - x, img.height - 1 - y, c) = img(x, y, c);
                } else if (angle == 270) {
                    img2(y,img.width - 1 - x, c) = img(x, y, c);
                }
            }
        }
    }
    img = img2;
}    
//filter8
void resizeFilter(Image & img) {




    int newWidth, newHeight;

    cout<<"Enter new width: ";
    cin>>newWidth;

    cout<<"Enter new height: ";
    cin>>newHeight;

    Image resized(newWidth, newHeight);

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {

            int X = i * img.width / newWidth;
            int Y = j * img.height / newHeight;

            for (int k = 0; k < 3; k++) {
                resized(j, i, k) = img(Y, X, k);
            }
        }
    }
}
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
// main functoin
int main(){
string filename;
cout<<"please, enter your image name: "<<endl;
cin>>filename;
Image img(filename);

//calling functoins
int choice;
cout<<"choice a filter:  "<<endl;
  cout<<"1. grayscale\n";
  cout<<"4. frame\n" ;
  cout<<"5. flip\n";
  cout<<"8. resize\n" ;     
  cin>> choice;
if(choice==1){
   grayscale_filter(img);  
}
if(choice==2)
   blackandwhite_filter(img);
}        
if(choice==5){
   flip_filter(img);
}
if(choice==6){
   rotate_filter(img)     
}        
if (choice==8){
        resizeFilter(img);
}        
if (choice==4){
        frameFilter(img);
}  
else{
       cout<< "please enter a valid number!\n"
}
        

// take the new name
string filenameout;
    cout<<"please, enter your new image name: "<<endl;
    cin>>filenameout;
char answer;
cout<<"do you want to save the new image? (y/n):";
cin>> answer;
if (answer =='y'|| answer=='Y'){
    img.saveImage(filenameout);
cout << "image saved successfully!\n";
}else {
        cout << "image was not saved.\n"
}
    return 0;  
}



