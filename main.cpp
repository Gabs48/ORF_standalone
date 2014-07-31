/*! 
* 	\file    main.cpp
* 	\author  Gabriel Urbain <gurbain@mit.edu> - Visitor student at MIT SSL
* 	\date    July 2014
* 	\version 0.1
* 	\brief   Main program for optical range finder and stereo cameras acquisition
*
* 	License: The MIT License (MIT)
* 	Copyright (c) 2014, Massachussets Institute of Technology
*/

// Project libs
#include "orf.h"
#include "utils.h"

using namespace std;
using namespace cv;

/* 
 * ORF utilization example:
 * - Create
 * - Initialize
 * - In a loop: capture, rectify and save
 * - Close
 */

// Create variables
ORF orf;

// Create a CTRL-C handler
void my_handler(int s){
	orf.closeOrf();
	exit(1);
}

// Main program: in case there is no CTRL-C handler, ORF should be declared inside 
int main(int argc, char **argv) {
	
	// Initialize
	int retVal = orf.initOrf();
	if (retVal!=0)
		return -1;
	
	// For catching a CTRL-C
	signal(SIGINT,my_handler);
	
	// Main loop
	while(true) {
		
		// Capture
		retVal = orf.saveRectifiedOrf();
		if (retVal!=0)
			break;
		
		// Handle ESC
		int c = cvWaitKey(1);
		if(c == 27) {
			DEBUG<<"Acquisition has been stopped by user"<<endl;
			break;
		}
 	}
 	
 	// Close cameras
 	orf.closeOrf();
	
	return 0;
}