# Real-time-filtering

Here, I have Implemented series of filter function :
1. 5x5 Gaussian filter
2. 3x3 Sobel X and 3x3 Sobel Y
3. Generated a gradient magnitude image from the X and Y Sobel images
4. Blurred and quantized a color image
5. Live video cartoonization
6. Put sparkles into the image where there are strong edges
7. Produce Negative of the image
8. Give a reddish-brown/warm/sepia effect to the image

# Procedure to run/analyze the code
1. PLease see the folder imgDisplay and vidDisplay
2. For the code please see: " imgDisplay, vidDisplay, filters.cpp" file.
3. Also include "filters.h" file.
4. PDF named " PRCV_Assignment_1 " contains the report. The alignments of the images in the report are little bit distorted,
	 so I have mentioned in the report which figure to refer for which part.
4. By pressing these following keys we can implement particular filters:
* **KEY "g" - Displaying Greyscale live video**
* **KEY "h" - Displaying Alternative greyscale live video**
* **KEY "b" - Implementing a 5x5 Gaussian filter as separable 1x5 filters**
* **KEY "x" - 3x3 Sobel X (Vertical Edge Detector)**
* **KEY "y" - 3x3 Sobel Y (Horizontal Edge Detector)**
* **KEY "m" - Implementing a function that generates a gradient magnitude image from the X and Y Sobel images**
* **KEY "i" - Implementing a function that blurs and quantizes a color image**
* **KEY "c" - Implementing a live video cartoonization function using the gradient magnitude and blur/quantize filters**
* **KEY "p" - Implementing another effect - sparkles into the image where there are strong edges**
* **KEY "f" - Mirroring the image in X and Z axis**
* **KEY "n" - Produce negative of the image**
* **KEY "w" - Give a sepia/warm/reddish-brown effect to the image**
5. CMake file is provided with the code


