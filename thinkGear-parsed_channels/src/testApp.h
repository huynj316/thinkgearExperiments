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
    
private:
    ofxThinkGear thinkGear;
    void attentionListener(float &param);
    void meditationListener(float &param); 
	void blinkListener(float &param);
	void rawListener(float &param);
	void deltaListener(float &param);
	void thetaListener(float &param);
	void alpha1Listener(float &param);
	void alpha2Listener(float &param);
	void beta1Listener(float &param);
	void beta2Listener(float &param);
	void gamma1Listener(float &param);
	void gamma2Listener(float &param);
    
    ofTrueTypeFont font;
    
    float atChangeTime;
    float meChangeTime;
	float raChangeTime;
	float deChangeTime;
    float thChangeTime;
	float a1ChangeTime;
	float a2ChangeTime;
    float b1ChangeTime;
	float b2ChangeTime;
	float g1ChangeTime;
    float g2ChangeTime;
	
	
    float attention;
    float meditation;
	float raw;
	float delta;
	float theta;
	float alpha1;
	float alpha2;
	float beta1;
	float beta2;
	float gamma1;
	float gamma2;
	
	//smooth Attn
    float distAw;    
    float prevAw;
    float currAw;
	//smooth Med
    float distMw;
    float prevMw;
    float currMw;
	//smooth Raw
	float distRw;
    float prevRw;
    float currRw;
	//smooth delta
	float distDw;
    float prevDw;
    float currDw;
	//smooth theta
	float distTw;
    float prevTw;
    float currTw;
	//smooth alpha1
	float distA1w;
    float prevA1w;
    float currA1w;
	//smooth alpha2
	float distA2w;
    float prevA2w;
    float currA2w;
	//smooth beta1
	float distB1w;
    float prevB1w;
    float currB1w;
	//smooth beta2
	float distB2w;
    float prevB2w;
    float currB2w;
	//smooth gamma1
	float distG1w;
    float prevG1w;
    float currG1w;
	//smooth gamma2
	float distG2w;
    float prevG2w;
    float currG2w;
};
