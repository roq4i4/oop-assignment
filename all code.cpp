// names:
// Habiba mohamed abdelglil hassan - 20250192 - filter 1,5
// Roqaia mohamed ismael - 20251149 - filter 4,8
// Reem Hamdy Tawfik Said Alrefaay - 20250823 - filter 3,7
// Rawan Ahmed Thabet Abd El Baset - 20250232 - filter 2,6,10,14

#include <iostream>
#include "image_class.h"
#include <string>
#include <cmath>
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

//filter3

void invert_image(Image& img){
for(int i=0;i<img.height;i++){
    for(int j=0;j<img.width;j++ ){
            for(int k=0;k<3;k++){
                    img(i,j,k)=255-img(i,j,k);
            }
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

//filter 7
void Darkenlighten_filter(Image& img){
char choice;
cout<<"Do you want to (D)arken or (L)ighten the image?";
cin>>choice;
for(int i=0;i<img.height;i++){
    for(int j=0;j<img.width;j++ ){
            for(int k=0;k<3;k++){
                    if (choice=='D' ||choice=='d'){
                    img(i,j,k)=img(i,j,k)/2;}
                    else if(choice=='L' ||choice=='l'){
                            int newval=img(i,j,k)+255-img(i,j,k)/2;
                            if( newval>255) newval=255;
                            img(i,j,k)=newval;
                    }
            }
    }
}
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

//filter 10
class EdgeFilter {
public:
    void apply(Image& img) {
        int threshold = 30 ;
        for (int x = 0; x< img.width - 1;++x){
            for (int y = 0; y < img.height; ++y) {
                
                int gray1 = (img.getPixel(x, y, 0) + img.getPixel(x, y, 1) + img.getPixel(x, y, 2)) / 3;
                int gray2 = (img.getPixel(x + 1, y, 0) + img.getPixel(x + 1, y, 1) + img.getPixel(x + 1, y, 2)) / 3;
                int difference = abs(gray1 - gray2);
                if (difference > threshold) {
                    img.setPixel(x, y, 0 , 0);
                    img.setPixel(x, y, 1 , 0);
                    img.setPixel(x, y, 2 , 0);
                } else {
                    img.setPixel(x, y, 0 , 255);
                    img.setPixel(x, y, 1 , 255);
                    img.setPixel(x, y, 2 , 255);
                }   
            }
        }
    }
}; 


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
cout<<"2.black and white\n" ;  
cout<<"3.invert_image\n";       
cout<<"4. frame\n" ;
cout<<"5. flip\n";
cout <<"6.rotate\n";
cout<<"7.Darkenlighten_filter\n";        
cout<<"8. resize\n" ;
cout<<" 10.detect\n" ;
  cin>> choice;
if(choice==1){
   grayscale_filter(img);  
}
else if(choice==2){
   blackandWhite_filter(img);
}  
else if(choice==3){
      invert_image(img);
} 
else if (choice==4){
        frameFilter(img);  
}
else if(choice==5){
   flip_filter(img);
}
else if(choice==6){
   rotate_filter(img);     
} 

else if(choice==7){
        Darkenlighten_filter(img);
}             
 else if (choice==8){
        resizeFilter(img);
} 
 else if (choice==10) { 
         detect(img);
 }        
else{
       cout<< "please enter a valid number!\n";
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
        cout << "image is not saved.\n";
}
    return 0;  
}



