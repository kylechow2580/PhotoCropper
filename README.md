# Photo Cropper

This is a simple program to crop an image to the size that we need. And the original purpose of this program is that crop an image for machine learning data set.
Besides, this will also generate a txt file to show the info of the image.

1. This program is built by openCV.
2. Put all the images to "Input" folder.</br>
3. The filename for input should be {$i}.jpg. E.g 1.jpg, 2.jpg
4. No Error handling.

The txt output format is like below:
<br>
{n.jpg} {no. of object in the image} {top-left x-coordinate} {top-left y-coordinate} {bottom-right x-coordinate} {bottom-right y-coordinate}
<br>
e.g
<br>
1.jpg 1 0 0 81 118
<br>
2.jpg 1 0 0 239 188
<br>
3.jpg 1 0 0 189 116


<br>

![screenshot from 2017-03-24 02-38-50](https://cloud.githubusercontent.com/assets/10007461/24264332/09d49242-103b-11e7-8776-62fe361a601a.png)

![screenshot from 2017-03-24 02-34-52](https://cloud.githubusercontent.com/assets/10007461/24264172/83bb0376-103a-11e7-8f35-ae851fafaf23.png)
![screenshot from 2017-03-24 02-37-13](https://cloud.githubusercontent.com/assets/10007461/24264256/ce29d4fa-103a-11e7-9fd3-36f4ae0d4def.png)
