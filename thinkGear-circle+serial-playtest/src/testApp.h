#pragma once

#include "ofMain.h"
#include "ofxThinkGear.h"
#include "ofxTweenLite.h"

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
	
	
	//serial start
	bool		bSendSerialMessage;			// a flag for sending serial
	char		bytesRead[3];				// data from serial, we will be trying to read 3
	char		bytesReadString[4];			// a string needs a null terminator, so we need 3 + 1 bytes
	int			nBytesRead;					// how much did we read?
	int			nTimesRead;					// how many times did we read?
	float		readTime;					// when did we last read?				
	char		myByte;
	
	ofTrueTypeFont font;
	ofSerial	serial;
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
