#include "ofApp.h"

ofFloatColor color;
//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofSetCircleResolution(60);
    
    // must call this before adding any tweens /
    Tweenzor::init();
    
    // float tween
    f = 380;
//    Tweenzor::to(&f, 10, 2).setRepeat(-1, true); // -1 will repeat forever

    Tweenzor::to(&f, 10, 2).chainTo(250, 7, 2);

    // same as this
//    Tweenzor::add(&f, f, 10, 2).setRepeat(-1, true);

    /*
	
    // ofVec2 tween
    vec2 = ofVec2f(100, 380);
    Tweenzor::to(&vec2, ofVec2f(200, 10), 2).setRepeat(-1, true);
    // same as this
//    Tweenzor::add(&vec2, vec2, ofVec2f(200, 10), 2).setRepeat(-1, true);
    
    // ofVec3, z will control alpha
    vec3 = ofVec3f(200, 380, 1);
    Tweenzor::to(&vec3, ofVec3f(300, 10, 0), 2).setRepeat(-1, true);
    // same as this
//    Tweenzor::add(&vec3, vec3, ofVec3f(300, 10, 0), 2).setRepeat(-1, true);
	
    // ofVec4, will treat as 2 separate coordinates
    vec4 = ofVec4f(350, 380, 450, 380);
    Tweenzor::to(&vec4, ofVec4f(450, 10, 350, 10), 2).setRepeat(-1, true);
    // same as this
//    Tweenzor::add(&vec4, vec4, ofVec4f(450, 10, 350, 10), 2).setRepeat(-1, true);
    
    // ofFloatColor
    floatColor = ofColor::orange;
    Tweenzor::to(&floatColor, ofColor::violet, 2).setRepeat(-1, true);
    // same as this
//    Tweenzor::add(&floatColor, floatColor, ofColor::violet, 2).setRepeat(-1, true);
    
    // ofRectangle
    rect = ofRectangle(500, 200, 160, 100);
    Tweenzor::to(&rect, ofRectangle(600, 300, 80, 50), 2).setRepeat(-1, true);
    // same as this
//    Tweenzor::add(&rect, rect, ofRectangle(600, 300, 80, 50), 2).setRepeat(-1, true);
 *
 */
}


//--------------------------------------------------------------
void ofApp::update(){
    Tweenzor::update(ofGetElapsedTimeMillis());
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
