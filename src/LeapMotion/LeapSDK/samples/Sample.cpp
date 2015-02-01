#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Leap.h"
#include <unistd.h>

using namespace Leap;
using std::cout;
using std::endl;


int main(){
  	FILE* serial;


	serial = fopen("/dev/ttyACM0", "w");
	Controller controller;	

	Frame frame = controller.frame() ;
	HandList hands = frame.hands();
	Hand hand = hands[0];

	Vector cur_palmPosition;
	Vector prev_palmPosition;
	Vector delta;
	
	char* protocol = new char[3];
	  
	while(hands.count() < 2 ){
		frame = controller.frame();
		hands = frame.hands();
		hand = hands[0];

		if( hand.isValid() ){
		  prev_palmPosition = cur_palmPosition;
		  cur_palmPosition = hand.palmPosition();
		  
		  delta = cur_palmPosition - prev_palmPosition;
		  for(int i = 0; i < 3; i++){
		    if(delta.x > 0)
		      protocol[0]='d';
		    else if(delta.x < 0)
		      protocol[0] = 'q';
		    else
		      protocol[0] = 's';
		  
                    if(delta.y > 0)
                      protocol[1]='d';
                    else if(delta.y < 0)
                      protocol[1] = 'q';
                    else
                      protocol[1] = 's';

                    if(delta.z > 0)
                      protocol[2]='d';
                    else if(delta.z < 0)
                      protocol[2] = 'q';
                    else
                      protocol[2] = 's';
		  }
		

		 /* 
		  if(prevZ != curZ){
		    deltaZ = curZ - prevZ;
		    fprintf(serial, "%s\n", protocol);
		  }*/
		
		fprintf(serial, "%c\n", protocol[0]);
		fprintf(serial, "%c\n", protocol[1]);
		fprintf(serial, "%c\n", protocol[2]);		
		}
		usleep(500000);	
	}
	fclose(serial);
	
	return 0;
}
