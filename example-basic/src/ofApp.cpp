#include "ofApp.h"

ofFloatColor color;
//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofSetCircleResolution(60);
    
    // must call this before adding any tweens //
    Tweenzor::init();
    
    // float tween
    f = 380;
    Tweenzor::add(&f, f, 10, 0, 2).setRepeat(-1, true); // -1 will repeat forever
	
    // ofVec2 tween
    vec2 = ofVec2f(100, 380);
    Tweenzor::add(&vec2, vec2, ofVec2f(200, 10), 0, 2).setRepeat(-1, true);
    
    // ofVec3, z will control alpha
    vec3 = ofVec3f(200, 380, 1);
    Tweenzor::add(&vec3, vec3, ofVec3f(300, 10, 0), 0, 2).setRepeat(-1, true);
	
    // ofVec4, will treat as 2 separate coordinates
    vec4 = ofVec4f(350, 380, 450, 380);
    Tweenzor::add(&vec4, vec4, ofVec4f(450, 10, 350, 10), 0, 2).setRepeat(-1, true);
    
    // ofFloatColor
    floatColor = ofColor::orange;
    Tweenzor::add(&floatColor, floatColor, ofColor::pink, 0, 2).setRepeat(-1, true);
    
    // ofRectangle
    rect = ofRectangle(500, 200, 160, 100);
    Tweenzor::add(&rect, rect, ofRectangle(600, 300, 80, 50), 0, 2).setRepeat(-1, true);
}


//--------------------------------------------------------------
void ofApp::update(){
    Tweenzor::update( ofGetElapsedTimeMillis() );
    ofLog() << vec3;
}

//--------------------------------------------------------------

void ofApp::draw(){
    ofDrawBitmapStringHighlight("float", 10, 400);
    ofSetColor(ofColor::red);
    ofDrawCircle(30, f, 5);

    ofDrawBitmapStringHighlight("ofVec2", 80, 400);
    ofSetColor(ofColor::blue);
    ofDrawCircle(vec2.x, vec2.y, 5);
    
    ofDrawBitmapStringHighlight("ofVec3", 180, 400);
    ofColor color = ofColor::yellow;
    color.a = vec3.z * 255;
    ofSetColor(color);
    ofDrawCircle(vec3.x, vec3.y, 5);
    
    ofDrawBitmapStringHighlight("ofVec4", 375, 400);
    ofSetColor(ofColor::green);
    ofDrawCircle(vec4.x, vec4.y, 5);
    ofDrawCircle(vec4.z, vec4.w, 5);
    
    ofDrawBitmapStringHighlight("ofRectangle and ofFloatColor", 550, 400);
    ofSetColor(floatColor);
    ofDrawRectangle(rect);
}


//--------------------------------------------------------------
void ofApp::exit() {
	Tweenzor::destroy();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}