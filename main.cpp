#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
using namespace cv;

string window = "Picture";
Mat image, addedImage;
Point vertexUP(-1,-1);
Point vertexDown(-1,-1);
Scalar color(0,255,0);

void onMouse(int event,int x,int y,int flags,void* param);
int main(){

    ofstream fout;
    fout.open("Output/output.txt");

    for(int i=1;true;i++)
    {
        stringstream ss;
        ss << i << ".jpg";
	string inputImage = "Input/" + ss.str();
        image = imread(inputImage,1);
        addedImage = imread(ss.str(),1);
        
        namedWindow(window,1);
        setMouseCallback(window,onMouse,NULL);
        moveWindow(window,700,0);
        
        imshow(window,addedImage);
        if(waitKey(0) == 32)
        {
            Rect interestedArea(vertexUP,vertexDown);
            Mat savedImage = image(interestedArea);
            imwrite( "Output/" + ss.str(), savedImage );
            fout << ss.str() << " 1 0 0 " << vertexDown.x - vertexUP.x << " " << vertexDown.y - vertexUP.y << endl;
        }
    }
    
}
void onMouse(int event,int x,int y,int flag,void* param){
    cout << "x: " << x << " y: " << y << " event: " << event << " flag: " << flag << endl;
    if(event==1)
    {
        //得到左上角座標
        vertexUP.x = x;
        vertexUP.y = y;
    }
    if(event==0)
    {
        //得到右下角座標
        vertexDown.x = x;
        vertexDown.y = y;
    }
    if(flag==CV_EVENT_FLAG_LBUTTON && event==0)
    {
        //拖曳滑鼠
        //cout << vertexUP.x << " " << vertexUP.y << " " << vertexDown.x << " " << vertexDown.y << endl;
        addedImage = image.clone();
        rectangle(addedImage, vertexUP, vertexDown, color);
        imshow(window,addedImage);
    }
}
