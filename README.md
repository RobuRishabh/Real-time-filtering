# Real-time filtering
## Project Description
This project focuses on utilizing C++ and OpenCV to read, display, manipulate, and write images and videos. The main objectives include implementing functions to:
- Read images from a local file or video streams from a live camera.
- Display live video.
- Apply various filters and effects to the live video.
- Save images or videos.
- The project also involves getting familiar with OpenCV's built-in functions and understanding how to access and modify images by directly accessing pixels.
## Required Images
1. cvtColor grayscale: Convert the image to grayscale using the formula: value = 0.299 * R + 0.587 * G + 0.114 * B.
2. Customized grayscale: Compute the average value of the BGR channels and apply it to the destination image using the formula: value = (B + G + R) / 3.
3. Gaussian blur: Apply a separable Gaussian filter of size 1 x 5 by accessing and modifying each pixel directly.
4. Gradient magnitude: Apply SobelX and SobelY filters to the original image and calculate the gradient magnitude to highlight edges.
5. Blurred and quantized: Blur the image and quantize it with a level of 15, resulting in color blocks.
6. Cartoonized: Calculate the gradient magnitude of the original image, blur and quantize it (with a level of 15), and set pixels with a gradient magnitude greater than 15 to black.
7. negative: Produces the negative of an image by subtracting each channel value from 255.
8. sepia: Applies a sepia tone effect to an image by manipulating the color channels.

## Steps to run the program
1. For the code please see: " imgDisplay.cpp, vidDisplay.cpp, filters.cpp" file.
2. Also include "filters.h" file.
3. PDF named " PRCV_Assignment_1 " contains the report. The alignments of the images in the report are little bit distorted,
	 so I have mentioned in the report which figure to refer for which part.
4. By pressing these following keys we can implement particular filters:
	- KEY "g" - Displaying Greyscale live video
	- KEY "h" - Displaying Alternative greyscale live video
	- KEY "b" - Implementing a 5x5 Gaussian filter as separable 1x5 filters
	- KEY "x" - 3x3 Sobel X (Vertical Edge Detector)
	- KEY "y" - 3x3 Sobel Y (Horizontal Edge Detector)
	- KEY "m" - Implementing a function that generates a gradient magnitude image from the X and Y Sobel images
	- KEY "i" - Implementing a function that blurs and quantizes a color image
	- KEY "c" - Implementing a live video cartoonization function using the gradient magnitude and blur/quantize filters
	- KEY "p" - Implementing another effect - sparkles into the image where there are strong edges
	- KEY "f" - Mirroring the image in X and Z axis
	- KEY "n" - Generate negative of the image
	- KEY "w" - Apply warm/sepia/reddish-brown color to the image
	- KEY "s" - Save the image
	- KEY "q" - Quit the program

I used visualstudio IDE, for the project. for running the code, I just click on build the whole assignment and then click on the
"Local Windows Debugger".




## Reflection
This project provided an opportunity to become familiar with C++ and OpenCV while gaining practical experience in image and video manipulation. It involved implementing various filters and effects, understanding pixel-level operations, and handling different image frame types. Additionally, it allowed for experimentation with different techniques to achieve desired results, such as adjusting brightness, applying filters, and saving video sequences with proper frame replication. Overall, the project enhanced understanding of computer vision concepts and improved proficiency in C++ programming and OpenCV usage.

### Acknowledgments
- OpenCV Tutorials: https://docs.opencv.org/4.5.1/index.html
- Learn OpenCV: https://learnopencv.com/read-write-and-display-a-video-using-opencv-cpp-python/
- How to use Chrono library: https://www.techiedelight.com/measure-elapsed-time-program-chrono-library/
- Change brightness using OpenCV: https://www.opencv-srf.com/2018/02/change-brightness-of-images-and-videos.html



