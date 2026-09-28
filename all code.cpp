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
  cout<<"5. flip\n";
  cin>> choice;
if(choice==1){
   grayscale_filter(img);  
}
if(choice==5){
   flip_filter(img);
}

// take the new name
string filenameout;
    cout<<"please, enter your new image name: "<<endl;
    cin>>filenameout;
    img.saveImage(filenameout);
    return 0;  
}



