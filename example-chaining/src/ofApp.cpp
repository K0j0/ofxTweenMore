#include "ofApp.h"
#include "Tweenzor.h"

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
    TM::from(&f2, 400, 3, 4).setRepeat(1, true);
//        TM::from(&f2, 400, 3, 4).setRepeat(1, true).chainFrom(200, 2, 1);
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
