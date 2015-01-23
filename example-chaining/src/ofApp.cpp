#include "ofApp.h"
#include "Tweenzor.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofLog() << "Start. elapsed: " << ofGetElapsedTimeMillis();
    Tweenzor::init();
    
    f = 10;
    Tweenzor::to(&f, 400, 3, 4).chainTo(100, 2, 1);
//    Tweenzor::to(&f, 400, 3);
//    Tweenzor::add(&f, 10, 400, 3);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(f < 400) ofLog() << "elapsed: " << ofGetElapsedTimeMillis();
    Tweenzor::update(ofGetElapsedTimeMillis());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::red);
    ofDrawCircle(f, 100, 5);

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
