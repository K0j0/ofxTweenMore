#include "ofApp.h"
#include "Tweenzor.h"

ofVec2f v1;
ofVec3f v2;
ofVec4f v3;
ofFloatColor col;
ofRectangle rect;

//--------------------------------------------------------------
void ofApp::setup(){
    ofLog() << "Start. elapsed: " << ofGetElapsedTimeMillis();
    TM::init();
    
    f = 10;
//    TM::to(&f, 400, 3, 4).chainTo(100, 2, 1);
//    TM::to(&f, 400, 3);
//    TM::add(&f, 10, 400, 3);
    
    f2 = 20;
//    TM::from(&f2, 400, 3, 4).chainFrom(200, 2, 1);
//    TM::from(&f2, 400, 3, 4).setRepeat(1, true);
//    TM::from(&f2, 400, 3, 4).setRepeat(1, true).chainFrom(200, 2, 1).setRepeat(1);
    
    v1 = ofVec2f(50, 50);
//    TM::to(&v1, ofVec2f(100,100), 2, 4).chainTo(ofVec2f(200, 50), 2, 1);
    
    v2 = ofVec3f(60, 60, 1);
//    TM::to(&v2, ofVec3f(120, 120, 0), 2, 4).chainTo(ofVec3f(200, 60, 1), 2, 1);
    
    v3 = ofVec4f(70,70, 300, 300);
//    TM::to(&v3, ofVec4f(140, 140, 140, 140), 2, 4).chainTo(ofVec4f(300, 70, 300, 140), 2, 1);
    
    rect = ofRectangle(100, 100, 80, 120);
    TM::to(&rect, ofRectangle( 80, 80, 120, 80), 2, 4).chainTo(ofRectangle(110, 150, 60, 20), 2, 1);
    
    col = ofColor::white;
    TM::to(&col, ofColor::black, 2, 4).chainTo(ofColor::pink, 2, 1);
}

//--------------------------------------------------------------
void ofApp::update(){
//    if(f < 400) ofLog() << "elapsed: " << ofGetElapsedTimeMillis();
    TM::update(ofGetElapsedTimeMillis());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::red);
    ofDrawCircle(f, 100, 5);

    ofSetColor(ofColor::green);
    ofDrawCircle(f2, 120, 5);
    
    ofSetColor(ofColor::yellow);
    ofDrawCircle(v1.x, v1.y, 5);
    
    ofColor blueFade = ofColor::blue;
    blueFade.a = v2.z * 255;
    ofSetColor(blueFade);
    ofDrawCircle(v2, 5);
    
    ofSetColor(ofColor::orange);
    ofDrawCircle(v3.x, v3.y, 5);
    ofDrawCircle(v3.z, v3.w, 5);
    
    ofSetColor(col);
    ofDrawRectangle(rect);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
