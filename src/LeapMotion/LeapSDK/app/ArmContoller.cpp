#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Leap.h"
#include <unistd.h>

using namespace Leap;
using std::cout;
using std::endl;

// Listener class which will run on change.
// class MotionListener : public Listener {
// 	public:
// 		virtual void onConnect(const Controller);
// 		virtual void onFrame(const Controller);
// };

// void MotionListener::onConnect(const Controller controller){
// 	cout << "Connected!";
// }

// void MotionListener::onFrame(const Controller controller){
	
// }

int main(){
  	FILE* serial;


	serial = fopen("/dev/ttyACM0", "w");
	//Sample Listener object
	//SampleListener listener;
	//Add a controller object
	Controller controller;	

	Frame frame = controller.frame() ;
	HandList hands = frame.hands();
	Hand hand = hands[0];
	Vector palmPosition;
	
	float prevX;
	float prevY;
	float prevZ;
	float curX;
    float curY;
    float curZ;

	float deltaZ;
	//Add the listener to the controller
	controller.addListener(listener);

	while(hands.count() < 2 ){
		frame = controller.frame();
		hands = frame.hands();
		hand = hands[0];

		if( hand.isValid() ){
			palmPosition = hand.palmPosition();
			
			prevX = curX;
			prevY = curY;
			prevZ = curZ;

			curX = palmPosition[0];
			curY = palmPosition[1];
			curZ = palmPosition[2];

	                cout << " Palm positionBases :" << endl
        		        << " x:" << curX << endl
               		        << " y:" << curY << endl
                        	<< " z:" << curZ << endl;
			if(prevZ != curZ){
			  deltaZ = curZ - prevZ;
			  fprintf(serial, "%f\n", deltaZ);
			}

		}
		usleep(50000);	

	}
	fclose(serial);
	//Keep this process running until Enter is pressed
	cout << "Press Enter to quit..." << endl;
	std::cin.get();

	return 0;
}
