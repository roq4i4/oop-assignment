
// filter 11

void cropImage(Image&image){
int x,y,w,h;
cout<<"Enter x,y (the starting point):";
cin>>x>>y;
cout<<"Enter the width and height for the new image";
cin<<w<<h;

Image croppedImage (w,h);
for (int i=0,i<w,i++){
    for(int j=0,j<h,j++){
    for (int k=0,k<image.channels,k++){
    croppedImage.setpixel(i,j,k,Image.getpixel(x+i,y+j,k));
    }

    }

    }
    croppedImage.saveImage("cropped_jpg");
    cout<<"Image cropped!";
    }





// filter 15

void purplefilter (Image&image){
    for(int i=0,i<image.width,i++){
        for(int j=0,j<image.height,j++){

        unsigned int red = image.getpixel(i,j,0);
        unsigned int blue = image.getpivel(i,j,2);
        unsigned int green = image.getpixel(i,j,1);



unsigned int newred = red+35;
unsigned int newblue = blue+35;
unsigned int newgreen= (green>40)? (green-40) :0 ;



image.setpixel(i,j,0,newred);
image.setpixel(i,j,1,newgreen);
image.setpixel(i,j,2,newblue);

image.saveImage("purple_jpg");
cout<<"purple image saved successfully!";
}
    

    

