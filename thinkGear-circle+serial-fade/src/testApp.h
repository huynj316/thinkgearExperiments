#pragma once

#include "ofMain.h"
#include "ofxThinkGear.h"
#include "ofxTweenLite.h"

#define NUM_MSG_BYTES 3 //how many bytes we are expecting to receive

class testApp : public ofBaseApp
{


public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
	
	void sendToMotor(int val);
	
	
	//serial start
	bool		bSendSerialMessage;			// a flag for sending serial
	long		sentMsgTime;
	char		bytesRead[3];				// data from serial, we will be trying to read 3
	char		bytesReadString[4];			// a string needs a null terminator, so we need 3 + 1 bytes
	int			nBytesRead;					// how much did we read?
	int			nTimesRead;					// how many times did we read?
	float		readTime;					// when did we last read?				
	char		myByte;
	
	//set this array's length to the number of msg
	//bytes we are expecting to receive
	int bytesReceived[NUM_MSG_BYTES];
	
	//we'll use this to count how many msgs have been received so far
	//(for debugging)
	long numMsgRecvd;			// when did we last read?
	
	ofTrueTypeFont font;
	ofSerial	mySerial;
	//serial end
    
private:
    ofxThinkGear thinkGear;
    void attentionListener(float &param);
    void meditationListener(float &param); 
	void blinkListener(float &param);
    
    
    float atChangeTime;
    float meChangeTime;
    float attention;
    float meditation;
	float blink;
    float distAw;    
    float prevAw;
    float currAw;
    float distMw;
    float prevMw;
    float currMw;
	
	float radius;
	ofPoint pos;
	
};
