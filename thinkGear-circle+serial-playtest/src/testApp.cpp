#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetCircleResolution(50);
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    
    thinkGear.setup();
    ofAddListener(thinkGear.attentionChangeEvent, this, &testApp::attentionListener);
    ofAddListener(thinkGear.meditationChangeEvent, this, &testApp::meditationListener);
	ofAddListener(thinkGear.blinkChangeEvent, this, &testApp::blinkListener);
    
    font.loadFont("font/DroidSansMono.ttf", 20);
	
    
    distAw = 0.0;
    prevAw = 0.0;
    currAw = 0.0;
    distMw = 0.0;
    prevMw = 0.0;
    currMw = 0.0;
    
    atChangeTime = 0.0;
    attention = 0.0;
    meChangeTime = 0.0;
    meditation = 0.0;
	
	//serial start
	ofSetVerticalSync(true);
	
	bSendSerialMessage = false;
	ofBackground(255);	
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	//font.loadFont("font/DroidSansMono.ttf", 10);
	
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	
	// this should be set to whatever com port your serial device is connected to.
	// (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
	// arduino users check in arduino app....
	int baud = 9600;
	serial.setup(0, baud); //open the first device
	//serial.setup("COM4", baud); // windows example
	//serial.setup("/dev/tty.usbmodemfa131", baud); // mac osx example
	//serial.setup("/dev/ttyUSB0", baud); //linux example
	
	nTimesRead = 0;
	nBytesRead = 0;
	readTime = 0;
	memset(bytesReadString, 0, 4);
	//serial end
	serial.writeByte('L');
	
}
//--------------------------------------------------------------
void testApp::update(){
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
    
	//serial start
	if (bSendSerialMessage){
		
		// (1) write the letter "a" to serial:
		//serial.writeByte('H');

		
		// (2) read
		// now we try to read 3 bytes
		// since we might not get them all the time 3 - but sometimes 0, 6, or something else,
		// we will try to read three bytes, as much as we can
		// otherwise, we may have a "lag" if we don't read fast enough
		// or just read three every time. now, we will be sure to 
		// read as much as we can in groups of three...
		
		nTimesRead = 0;
		nBytesRead = 0;
		int nRead  = 0;  // a temp variable to keep count per read
		
		unsigned char bytesReturned[3];
		
		memset(bytesReadString, 0, 4);
		memset(bytesReturned, 0, 3);
		
		while( (nRead = serial.readBytes( bytesReturned, 3)) > 0){
			nTimesRead++;	
			nBytesRead = nRead;
		};
		
		memcpy(bytesReadString, bytesReturned, 3);
		
		bSendSerialMessage = false;
		readTime = ofGetElapsedTimef();
	}
		//serial end	
}
//--------------------------------------------------------------
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
    ofPopStyle();
	
	//blink
	font.drawString("Blink", 10, (blink)); 
    
	//directions
	if (attention < 1 && meditation < 1) {
		font.drawString("CONCENTRATE ON DOT", ofGetWidth()/2, ofGetHeight()/2);
	}

	
    //attention bar
    ofPushMatrix();
    ofTranslate(0, 30);
    ofPushStyle();
    ofSetColor(ofColor::black);
    font.drawString("Attention", 10, ofGetHeight()/11 - 10);
    ofNoFill();
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, currAw);
//	ofRect(1, ofGetHeight()/11, ofGetWidth() - 2, 60);
    ofSetColor(ofColor::yellow, ofMap(currAw, 0.0, ofGetWidth(), 50, 255));
    ofFill(); 
	ofCircle(ofGetWidth()/2, ofGetHeight()/2, currAw);
//  ofRect(0, ofGetHeight()/11, currAw, 59);
	ofSetColor(ofColor::black, ofMap(currAw, 0.0, ofGetWidth(), 50, 255));
	font.drawString(ofToString(attention), 10, ofGetHeight()/11 + 40);
	
    if (attention >= 30.0) {
		serial.writeByte('H');
		bSendSerialMessage = true;
    }
	else if (attention < 30.0) {
		bSendSerialMessage = true;
		serial.writeByte('L');
	}
    ofPopStyle();
    ofPopMatrix();
    
	//key circle
	ofSetColor(ofColor::black);
//	ofTranslate(0, 30);
	ofCircle(ofGetWidth()/2, (ofGetHeight()/2)+30, 2);
	
	//meditation bar
    ofPushMatrix();
    ofTranslate(0, 30);
    ofPushStyle();
    ofSetColor(ofColor::black);
    font.drawString("Meditation", 10, (ofGetHeight()/3.5) - 10); 
    ofNoFill();
	ofCircle(ofGetWidth()/2, ofGetHeight()/2, currMw);
//  ofRect(1, (ofGetHeight()/3.5), ofGetWidth() - 2, 60);    
    ofSetColor(ofColor::cyan, ofMap(currMw, 0.0, ofGetWidth(), 50, 255));
    ofFill();
	ofCircle(ofGetWidth()/2, ofGetHeight()/2, currMw);
//	ofRect(0, (ofGetHeight()/3.5), currMw, 59);
	ofSetColor(ofColor::black, ofMap(currMw, 0.0, ofGetWidth(), 50, 255));
	font.drawString(ofToString(meditation), 10, (ofGetHeight()/3.5) + 40); 
	
//	if (meditation >= 20.0) {
//		serial.writeByte('H');
//		bSendSerialMessage = true;
//    }
//	else if (meditation < 20.0) {
//		bSendSerialMessage = true;
//		serial.writeByte('L');
//	}
	
    ofPopStyle();
    ofPopMatrix();
    
				
    ofSetWindowTitle("fps = " + ofToString(ofGetFrameRate()));
	
	//start serial
	//serial.writeByte('H');
	//cout << 'writeByte' << endl;
	if (nBytesRead > 0 && ((ofGetElapsedTimef() - readTime) < 0.5f)){
		ofSetColor(0);
	} else {
		ofSetColor(220);
	}
	
	//activate to see serial connection
//	string msg;
//	msg += "click to test serial:\n";
//	msg += "nBytes read " + ofToString(nBytesRead) + "\n";
//	msg += "nTimes read " + ofToString(nTimesRead) + "\n";
//	msg += "read: " + ofToString(bytesReadString) + "\n";
//	msg += "(at time " + ofToString(readTime, 3) + ")";
//	font.drawString(msg, ofGetWidth()/1.3, 100);
	//end serial

}
//--------------------------------------------------------------
void testApp::attentionListener(float &param){
    attention = param;
    distAw = ofMap(attention, 0.0, 100.0, 0, ofGetWidth());
    atChangeTime = ofGetElapsedTimef();
}
//--------------------------------------------------------------
void testApp::meditationListener(float &param){
    meditation = param;
    distMw = ofMap(meditation, 0.0, 100.0, 0, ofGetWidth());
    meChangeTime = ofGetElapsedTimef();    
}
//--------------------------------------------------------------
void testApp::blinkListener(float &param){
//    meditation = param;
//    distMw = ofMap(meditation, 0.0, 100.0, 0, ofGetWidth());
//    meChangeTime = ofGetElapsedTimef();   
	cout << "blink: "<<param<<endl;
	blink = param;
}
//--------------------------------------------------------------


void testApp::keyPressed(int key){}
//--------------------------------------------------------------
void testApp::keyReleased(int key){}
//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){}
//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//activate for mouse click serial test¨
	//bSendSerialMessage = true;
}
//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){}
//--------------------------------------------------------------
void testApp::windowResized(int w, int h){}
//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){}
//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){}