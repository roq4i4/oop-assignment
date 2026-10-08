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
    
    

