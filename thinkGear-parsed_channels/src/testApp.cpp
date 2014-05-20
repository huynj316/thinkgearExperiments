#include "testApp.h"

void testApp::setup()
{
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    
    thinkGear.setup();
    ofAddListener(thinkGear.attentionChangeEvent, this, &testApp::attentionListener);
    ofAddListener(thinkGear.meditationChangeEvent, this, &testApp::meditationListener);
	ofAddListener(thinkGear.blinkChangeEvent, this, &testApp::blinkListener);
	ofAddListener(thinkGear.rawChangeEvent, this, &testApp::rawListener);
	ofAddListener(thinkGear.deltaChangeEvent, this, &testApp::deltaListener);
	ofAddListener(thinkGear.thetaChangeEvent, this, &testApp::thetaListener);
	ofAddListener(thinkGear.alpha1ChangeEvent, this, &testApp::alpha1Listener);
	ofAddListener(thinkGear.beta1ChangeEvent, this, &testApp::beta1Listener);
	ofAddListener(thinkGear.gamma1ChangeEvent, this, &testApp::gamma1Listener);
	
    font.loadFont("font/DroidSansMono.ttf", 20);
    
    distAw = 0.0;
    prevAw = 0.0;
    currAw = 0.0;
	
    distMw = 0.0;
    prevMw = 0.0;
    currMw = 0.0;
	
	distRw = 0.0;
    prevRw = 0.0;
    currRw = 0.0;
	
    distDw = 0.0;
    prevDw = 0.0;
    currDw = 0.0;
	
	distTw = 0.0;
    prevTw = 0.0;
    currTw = 0.0;
	
    distA1w = 0.0;
    prevA1w = 0.0;
    currA1w = 0.0;
	
	distA2w = 0.0;
    prevA2w = 0.0;
    currA2w = 0.0;
	
	distB1w = 0.0;
    prevB1w = 0.0;
    currB1w = 0.0;
	
	distB2w = 0.0;
    prevB2w = 0.0;
    currB2w = 0.0;
	
	distG1w = 0.0;
    prevG1w = 0.0;
    currG1w = 0.0;
	
	distG2w = 0.0;
    prevG2w = 0.0;
    currG2w = 0.0;
    
    atChangeTime = 0.0;
    attention = 0.0;
    meChangeTime = 0.0;
    meditation = 0.0;
	raChangeTime = 0.0;
    raw = 0.0;
    deChangeTime = 0.0;
    delta = 0.0;
	thChangeTime = 0.0;
    theta = 0.0;
    a1ChangeTime = 0.0;
    alpha1 = 0.0;
	a2ChangeTime = 0.0;
    alpha2 = 0.0;
    b1ChangeTime = 0.0;
    beta1 = 0.0;
	b2ChangeTime = 0.0;
    beta2 = 0.0;
    g1ChangeTime = 0.0;
    gamma1 = 0.0;
	g2ChangeTime = 0.0;
    gamma2 = 0.0;
}

void testApp::update()
{
    thinkGear.update();
    
    float cur = ofGetElapsedTimef();
	
    float progress = cur - atChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevAw = currAw;
    currAw = ofxTweenLite::tween(prevAw, distAw, progress, OF_EASE_SINE_INOUT);
    
    progress = cur - meChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevMw = currMw;
    currMw = ofxTweenLite::tween(prevMw, distMw, progress, OF_EASE_SINE_INOUT);
    
	progress = cur - raChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevRw = currRw;
    currRw = ofxTweenLite::tween(prevRw, distRw, progress, OF_EASE_SINE_INOUT);

	progress = cur - deChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevDw = currDw;
    currDw = ofxTweenLite::tween(prevDw, distDw, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - thChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevTw = currTw;
    currTw = ofxTweenLite::tween(prevTw, distTw, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - a1ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevA1w = currA1w;
    currA1w = ofxTweenLite::tween(prevA1w, distA1w, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - a2ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevA2w = currA2w;
    currA2w = ofxTweenLite::tween(prevA2w, distA2w, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - b1ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevB1w = currB1w;
    currB1w = ofxTweenLite::tween(prevB1w, distB1w, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - b2ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevB2w = currB2w;
    currB2w = ofxTweenLite::tween(prevB2w, distB2w, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - g1ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevG1w = currG1w;
    currG1w = ofxTweenLite::tween(prevG1w, distG1w, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - g2ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevG2w = currG2w;
    currG2w = ofxTweenLite::tween(prevG2w, distG2w, progress, OF_EASE_SINE_INOUT);
	
	//add code to smooth out raw data added
}

void testApp::draw()
{
    ofBackgroundGradient(ofColor::white, ofColor::gray);
    
    ofPushStyle();
    ofSetColor(ofColor::black);
    string qStr = "";
    if (thinkGear.getSignalQuality() == 0.0)
    {
        qStr = "good";
    }
    else 
    {
        qStr = "poor (" + ofToString(thinkGear.getSignalQuality()) + ")";
    }
    font.drawString("signal quality = " + qStr, 10, 40); 
	font.drawString("signal quality = " + qStr, 10, 40); 

    ofPopStyle();
    
    //attn bar
    ofPushMatrix();
//  ofTranslate(0, 20);
	//draw here
//	ofCircle(0,0,currMw);
    ofPushStyle();
    ofSetColor(ofColor::black);
    font.drawString("Attention", 10, ofGetHeight()/7 - 10);
    ofNoFill();
    ofRect(1, ofGetHeight()/7, ofGetWidth() - 2, 60);
    ofSetColor(ofColor::magenta, ofMap(currAw, 0.0, ofGetWidth(), 50, 255));
    ofFill();    
    ofRect(0, ofGetHeight()/7, currAw, 59);
    if (attention > 0.0)
    {
        ofSetColor(ofColor::black, ofMap(currAw, 0.0, ofGetWidth(), 50, 255));
        font.drawString(ofToString(attention), 10, ofGetHeight()/7 + 40);
    }
    ofPopStyle();
    ofPopMatrix();
    
    //meditation bar
	ofPushMatrix();
    ofTranslate(0, 0);
    ofPushStyle();
    ofSetColor(ofColor::black);
    font.drawString("Meditation", 10, (ofGetHeight()/3.9) - 10); 
    ofNoFill();
    ofRect(1, (ofGetHeight()/3.9), ofGetWidth() - 2, 60);    
    ofSetColor(ofColor::cyan, ofMap(currMw, 0.0, ofGetWidth(), 50, 255));
    ofFill();
    ofRect(0, (ofGetHeight()/3.9), currMw, 59);
    if (meditation > 0.0)
    {
        ofSetColor(ofColor::black, ofMap(currMw, 0.0, ofGetWidth(), 50, 255));
        font.drawString(ofToString(meditation), 10, (ofGetHeight()/3.9) + 40);
    }    
    ofPopStyle();
    ofPopMatrix();
    
	//raw bar
    ofPushMatrix();
    ofTranslate(0, 100);
    ofPushStyle();
    ofSetColor(ofColor::black);
    font.drawString("Raw", 10, (ofGetHeight()/3.8) - 10); 
    ofNoFill();
    ofRect(1, (ofGetHeight()/3.8), ofGetWidth() - 2, 60);    
    ofSetColor(ofColor::green, ofMap(currRw, 0.0, ofGetWidth(), 50, 255));
    ofFill();
    ofRect(0, (ofGetHeight()/3.8), currRw, 59);
    if (raw > 0.0)
    {
        ofSetColor(ofColor::black, ofMap(currRw, 0.0, ofGetWidth(), 50, 255));
        font.drawString(ofToString(raw), 10, (ofGetHeight()/3.8) + 40);
    }    
    ofPopStyle();
    ofPopMatrix();
	
	//delta bar
    ofPushMatrix();
    ofTranslate(0, -40);
    ofPushStyle();
    ofSetColor(ofColor::black);
    font.drawString("Delta", 10, (ofGetHeight()/1.8) - 10); 
    ofNoFill();
    ofRect(1, (ofGetHeight()/1.8), ofGetWidth() - 2, 60);    
    ofSetColor(ofColor::orange, ofMap(currDw, 0.0, ofGetWidth(), 50, 255));
    ofFill();
    ofRect(0, (ofGetHeight()/1.8), currDw, 59);
    if (delta > 0.0)
    {
        ofSetColor(ofColor::black, ofMap(currDw, 0.0, ofGetWidth(), 50, 255));
        font.drawString(ofToString(delta), 10, (ofGetHeight()/1.8) + 40);
    }    
    ofPopStyle();
    ofPopMatrix();
	
	//theta bar
    ofPushMatrix();
    ofTranslate(0, -40);
    ofPushStyle();
    ofSetColor(ofColor::black);
    font.drawString("Theta", 10, (ofGetHeight()/1.5) - 10); 
    ofNoFill();
    ofRect(1, (ofGetHeight()/1.5), ofGetWidth() - 2, 60);    
    ofSetColor(ofColor::yellow, ofMap(currTw, 0.0, ofGetWidth(), 50, 255));
    ofFill();
    ofRect(0, (ofGetHeight()/1.5), currTw, 59);
    if (theta > 0.0)
    {
        ofSetColor(ofColor::black, ofMap(currTw, 0.0, ofGetWidth(), 50, 255));
        font.drawString(ofToString(theta), 10, (ofGetHeight()/1.5) + 40);
    }    
    ofPopStyle();
    ofPopMatrix();
	
	//alpha1 bar
	ofPushMatrix();
    ofTranslate(0, -40);
    ofPushStyle();
    ofSetColor(ofColor::black);
    font.drawString("Alpha1", 10, ofGetHeight()-(ofGetHeight()/4.5) - 10); 
    ofNoFill();
    ofRect(1, ofGetHeight()-(ofGetHeight()/4.5), ofGetWidth() - 2, 60);    
    ofSetColor(ofColor::pink, ofMap(currA1w, 0.0, ofGetWidth(), 50, 255));
    ofFill();
    ofRect(0, ofGetHeight()-(ofGetHeight()/4.5), currA1w, 59);
    if (alpha1 > 0.0)
    {
        ofSetColor(ofColor::black, ofMap(currA1w, 0.0, ofGetWidth(), 50, 255));
        font.drawString(ofToString(alpha1), 10, ofGetHeight()-(ofGetHeight()/4.5) + 40);
    }    
    ofPopStyle();
    ofPopMatrix();
	
	//beta1 bar
	ofPushMatrix();
    ofTranslate(0, -40);
    ofPushStyle();
    ofSetColor(ofColor::black);
    font.drawString("Beta1", 10, ofGetHeight()-(ofGetHeight()/9) - 10); 
    ofNoFill();
    ofRect(1, ofGetHeight()-(ofGetHeight()/9), ofGetWidth() - 2, 60);    
    ofSetColor(ofColor::red, ofMap(currB1w, 0.0, ofGetWidth(), 50, 255));
    ofFill();
    ofRect(0, ofGetHeight()-(ofGetHeight()/9), currB1w, 59);
    if (beta1> 0.0)
    {
        ofSetColor(ofColor::black, ofMap(currB1w, 0.0, ofGetWidth(), 50, 255));
        font.drawString(ofToString(beta1), 10, ofGetHeight()-(ofGetHeight()/9) + 40);
    }    
    ofPopStyle();
    ofPopMatrix();
	
	//gamma1 bar
	ofPushMatrix();
    ofTranslate(0, -40);
    ofPushStyle();
    ofSetColor(ofColor::black);
    font.drawString("Gamma1", 10, ofGetHeight()-(ofGetHeight()/50) - 10); 
    ofNoFill();
    ofRect(1, ofGetHeight()-(ofGetHeight()/50), ofGetWidth() - 2, 60);    
    ofSetColor(ofColor::blue, ofMap(currG1w, 0.0, ofGetWidth(), 50, 255));
    ofFill();
    ofRect(0, ofGetHeight()-(ofGetHeight()/50), currG1w, 59);
    if (gamma1 > 0.0)
    {
        ofSetColor(ofColor::black, ofMap(currG1w, 0.0, ofGetWidth(), 50, 255));
        font.drawString(ofToString(gamma1), 10, ofGetHeight()-(ofGetHeight()/50) + 40);
    }    
    ofPopStyle();
    ofPopMatrix();
    
    ofSetWindowTitle("fps = " + ofToString(ofGetFrameRate()));
}

void testApp::attentionListener(float &param)
{
    attention = param;
    distAw = ofMap(attention, 0.0, 100.0, 0, ofGetWidth());
    atChangeTime = ofGetElapsedTimef();
}

void testApp::meditationListener(float &param)
{
    meditation = param;
    distMw = ofMap(meditation, 0.0, 100.0, 0, ofGetWidth());
    meChangeTime = ofGetElapsedTimef();    
}

void testApp::blinkListener(float &param)
{
//    meditation = param;
//    distMw = ofMap(meditation, 0.0, 100.0, 0, ofGetWidth());
//    meChangeTime = ofGetElapsedTimef();   
	cout << "blink: "<<param<<endl;
}

void testApp::rawListener(float &param)
{
	raw = param;
	distRw = ofMap(raw, 0.0, 100.0, 0, ofGetWidth());
	raChangeTime = ofGetElapsedTimef();   
	//cout << "raw: "<<param<<endl;
}

void testApp::deltaListener(float &param)
{
	delta = param;
	distDw = ofMap(delta, 0.0, 100.0, 0, ofGetWidth());
	deChangeTime = ofGetElapsedTimef(); 
}

void testApp::thetaListener(float &param)
{
	theta = param;
	distTw = ofMap(theta, 0.0, 100.0, 0, ofGetWidth());
	thChangeTime = ofGetElapsedTimef(); 
//	cout << "theta: "<<param<<endl;
}

void testApp::alpha1Listener(float &param)
{
	alpha1 = param;
	distA1w = ofMap(alpha1, 0.0, 100.0, 0, ofGetWidth());
	a1ChangeTime = ofGetElapsedTimef(); 
//	cout << "alpha1: "<<param<<endl;
}

void testApp::beta1Listener(float &param)
{
	beta1 = param;
	distB1w = ofMap(beta1, 0.0, 100.0, 0, ofGetWidth());
	b1ChangeTime = ofGetElapsedTimef(); 
}

void testApp::gamma1Listener(float &param)
{
	gamma1 = param;
	distG1w = ofMap(gamma1, 0.0, 100.0, 0, ofGetWidth());
	g1ChangeTime = ofGetElapsedTimef(); 
}


void testApp::keyPressed(int key){}
void testApp::keyReleased(int key){}
void testApp::mouseMoved(int x, int y){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){}