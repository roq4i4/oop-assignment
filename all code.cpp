// names:
// Habiba mohamed abdelglil hassan - 20250192 - filter 1,5,9,13,17,18
// Roqaia mohamed ismael - 20251149 - filter 4,8 ,12,16,17,18
// Reem Hamdy Tawfik Said Alrefaay - 20250823 - filter 3,7,11,15,17,18
// Rawan Ahmed Thabet Abd El Baset - 20250232 - filter 2,6,10,14,17,18

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

// filter 9
void merge(Image& img , Image& img2){
    if(img.width==img2.width && img.height==img2.height){
        for(int i=0; i< img.width ; i++){
            for(int j=0 ; j<img.height ; j++){
                for(int k=0;k<3 ; k++){
                    img(i,j,k)=(img(i,j,k) + img2(i,j,k))/2;
                }
            }
        }
    }
    else{
        cout<<"the sizes of two images don't match"<<endl;
        int  the_choice;
        cout<<"1. Resize\n";        
        cout<<"2. Apply to Common Area\n" ; 
        cin>> the_choice;


        if (the_choice==1){
            int max_w=max(img.width , img2.width);
            int max_L=max(img.height , img2.height);
            Image newimg2(max_w, max_L);

            float stepx1 = (float)img.width / max_w;
            float stepy1 = (float)img.height / max_L;

            float stepx2 = (float)img2.width / max_w;
            float stepy2 = (float)img2.height / max_L;

            for(int i=0; i< max_w ; i++){
                for(int j=0 ; j< max_L ; j++){

                    int i1= i*stepx1;
                    int j1= j*stepy1;

                    int i2= i*stepx2;
                    int j2= j*stepy2;

                    for(int k=0; k<3 ; k++){
                    newimg2(i,j,k) = (img(i1,j1,k) + img2(i2,j2,k))/2;
                    }
                }
            }
            img=newimg2;
        }



        if(the_choice==2){
            int min_w=min(img.width , img2.width);
            int min_L=min(img.height , img2.height);
            Image newimg(min_w, min_L);

            for(int i=0; i< min_w ; i++){
                for(int j=0 ; j< min_L ; j++){
                    for(int k=0 ; k<3 ; k++){
                    newimg(i,j,k) = (img(i,j,k) + img2(i,j,k))/2;
                    }
                }
            }
            img=newimg;
        }
    }     
}

//filter 10
class EdgeFilter {
public:
    void detect(Image& img) {
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





// filter 11

void cropImage(Image&img){
int x,y,w,h;
cout<<"Enter x,y (the starting point):";
cin>>x>>y;
cout<<"Enter the width and height for the new image";
cin>>w>>h;

Image croppedImage (w,h);
for (int i=0;i<w;i++){
    for(int j=0;j<h;j++){
    for (int k=0;k<img.channels;k++){
    croppedImage.setPixel(i,j,k,img.getPixel(x+i,y+j,k));
    }

    }

    }
    
    }

//filter 12
    void blur(Image& img)
    {
        int width = img.width;
        int height = img.height;
 Image original = img;

 for (int i = 1; i < height - 1; i++) {
 for (int j = 1; j < width - 1; j++) {
for (int k = 0; k < 3; k++) {
int sum = 0;
 for (int x = -1; x <= 1; x++){
 for (int y = -1; y <= 1; y++) {
 sum += original.getPixel( j + y, i + x, k );
 } }
 img.setPixel(j, i, k, sum / 9); } } }}

// filter 13
void sunlight(Image& img){
    for(int i=0;i<img.width;i++){
        for(int j=0;j<img.height;j++){
            
                int red= img(i,j,0)*1.20 + 10;
                img(i,j,0)= min(255 , red);

                int green= img(i,j,1)*1.05 +5;
                img(i,j,1)= min(255 , green);

                int blue= img(i,j,2)*0.8;
                img(i,j,2)=min(255,max(0,blue));
        }
    }     
}
//filter 14
class tvFilter {
public:
    void old(Image& img) {
        for (int x=0; x< img.width ; x++) {
            for (int y=0; y< img.height; y+= 2) {
                for (int c=0; c< img.channels; c++) {
                    int p = img.getPixel(x, y, c);
                    img.setPixel(x, y, c, p / 2);
                }
            }
        }
    }
};

// filter 15

void purplefilter (Image&img){
    for(int i=0;i<img.width;i++){
        for(int j=0;j<img.height;j++){

        unsigned int red = img.getPixel(i,j,0);
        unsigned int blue = img.getPixel(i,j,2);
        unsigned int green = img.getPixel(i,j,1);



unsigned int newred = red+35;
unsigned int newblue = blue+35;
unsigned int newgreen= (green>40)? (green-40) :0 ;



img.setPixel(i,j,0,newred);
img.setPixel(i,j,1,newgreen);
img.setPixel(i,j,2,newblue);

            
        }
    }

}

//filter16
void infrared(Image& img){

    int width=img.width;
    int height=img.height;
    for (int i=0; i < height; i++){
        for (int j=0; j < width; j++){
            int r = img.getPixel(j, i, 0);
            int g = img.getPixel(j, i, 1);
            int b = img.getPixel(j, i, 2);
            img.setPixel(j, i, 0, 255);
            img.setPixel(j, i, 1, r);
            img.setPixel(j, i, 2, b / 3);

        }
    }
}
//filter 17 
void skew(Image &img)
{
    int degree;

    cout << "Enter skew angle (1-90): ";
    cin >> degree;

    if (degree < 1 || degree > 90)
    {
        cout << "Invalid angle!" << endl;
        return;
    }

    Image temp = img;

    int width = img.width;
    int height = img.height;

    double angle = degree * 3.14159265 / 180.0;
    double skew = tan(angle);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int shift = (height - 1 - i) * skew;
            int newX = j + shift;

            if (newX >= 0 && newX < width)
            {
                temp(i, newX) = img(i, j);
            }
        }
    }

    img = temp;
}
//filter 18
void oilPainting(Image &img)
{
    Image temp = img;

    int width = img.width;
    int height = img.height;

    int radius = 3;

    for (int i = radius; i < height - radius; i++)
    {
        for (int j = radius; j < width - radius; j++)
        {
            int red[256] = {0};
            int green[256] = {0};
            int blue[256] = {0};

            for (int x = -radius; x <= radius; x++)
            {
                for (int y = -radius; y <= radius; y++)
                {
                    unsigned char r, g, b;

                    img(i + x, j + y, r, g, b);

                    red[r]++;
                    green[g]++;
                    blue[b]++;
                }
            }

            int maxR = 0, maxG = 0, maxB = 0;
            int bestR = 0, bestG = 0, bestB = 0;

            for (int k = 0; k < 256; k++)
            {
                if (red[k] > maxR)
                {
                    maxR = red[k];
                    bestR = k;
                }

                if (green[k] > maxG)
                {
                    maxG = green[k];
                    bestG = k;
                }

                if (blue[k] > maxB)
                {
                    maxB = blue[k];
                    bestB = k;
                }
            }

            temp(i, j, bestR, bestG, bestB);
        }
    }

    img = temp;
}



// main functoin
int main(){
string filename;
cout<<"please, enter your image name: "<<endl;
cin>>filename;
Image img(filename);

//calling functoins
int choice;
cout<<"choose a filter:  "<<endl;
cout<<"1. grayscale\n";        
cout<<"2.black and white\n" ;  
cout<<"3.invert image\n";       
cout<<"4. frame\n" ;
cout<<"5. flip\n";
cout <<"6.rotate\n";
cout<<"7.Darken & lighten \n";        
cout<<"8. resize\n" ;
cout<<"9.merge\n";        
cout<<" 10.detect\n" ;
cout<<"11crop\n";
 cout<<"12.blur\n" ;      
cout<<"13.sunlight\n";        
cout<<" 14.old\n" ; 
 cout <<"15.purple\n";      
cout<< "16.infrared\n";
 cout<< "17.skewing\n";       
cout <<"18.oil painting\n"
cin >> choice;

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
else if (choice==9){
    string filename2;
    cout << "enter your second image name"<<endl;
    cin>> filename2; 
    Image img2(filename2);
    merge(img , img2);     
 }          
 else if (choice==10) { 
         EdgeFilter edgeFilter;
         edgeFilter.detect(img);
 }
         else if (choice==11){
             cropImage(img);
         }
 else if (choice==12){ blur(img);
 }
 else if (choice==13){
         sunlight(img);
 }        
  else if (choice==14) {
          tvFilter filter;
          filter.old(img);
          
  }
 else if (choice ==15){
                  purplefilter(img);
                  
          }
 else if (choice==16){
         infrared(img);
 }
else if (choice == 17){
            skew(img)
         }
else if (choice == 18){
                oilPainting(img)
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




