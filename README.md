# Real-time-filtering
Implemented a 5x5 Gaussian filter, 3x3 Sobel X and 3x3 Sobel Y, generated a gradient magnitude image from the X and Y Sobel images, blurred and quantized a color image, did live video cartoonization, put sparkles into the image where there are strong edges.

1. For the code please see: " imgDisplay.cpp, vidDisplay.cpp, filters.cpp" file.
2. Also include "filters.h" file.
3. PDF named " PRCV_Assignment_1 " contains the report. The alignments of the images in the report are little bit distorted,
	 so I have mentioned in the report which figure to refer for which part.
4. By pressing these following keys we can implement particular filters:

	KEY "g" - Displaying Greyscale live video
	KEY "h" - Displaying Alternative greyscale live video
	KEY "b" - Implementing a 5x5 Gaussian filter as separable 1x5 filters
	KEY "x" - 3x3 Sobel X (Vertical Edge Detector)
	KEY "y" - 3x3 Sobel Y (Horizontal Edge Detector)
	KEY "m" - Implementing a function that generates a gradient magnitude image from the X and Y Sobel images
	KEY "i" - Implementing a function that blurs and quantizes a color image
	KEY "c" - Implementing a live video cartoonization function using the gradient magnitude and blur/quantize filters
	KEY "p" - Implementing another effect - sparkles into the image where there are strong edges
	KEY "f" - Mirroring the image in X and Z axis

I used visualstudio IDE, for the project. for running the code, I just click on build the whole assignment and then click on the
"Local Windows Debugger".

