#include "ofApp.h"

ofFloatColor color;

struct box{
	box(ofColor _color, ofVec2f _start, ofVec2f _target){
		color = _color;
		pos = start = _start;
		target = _target;
	}
	ofColor color;
	ofVec2f pos;

	ofVec2f start;
	ofVec2f target;
};
vector<box> boxes;

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofSetCircleResolution(60);
    
    TM::init();
    
    float width = ofGetWindowWidth();
    float height = ofGetWindowHeight();
    center.x = width/2;
    center.y = height/2;

    box b1 = box(ofColor::red, ofVec2f(10, 50), ofVec2f(width -10, 50));
    box b2 = box(ofColor::yellow, ofVec2f(10, 150), ofVec2f(width -10, 150));
    box b3 = box(ofColor::green, ofVec2f(10, 250), ofVec2f(width -10, 250));

    boxes.push_back(b1);
    boxes.push_back(b2);
    boxes.push_back(b3);

    for(int i = 0; i < 3; ++i){
    	TM::to(&boxes[i].pos, boxes[i].target, 3).setGroupID(i).setRepeat(-1, true);
    }
}


//--------------------------------------------------------------
void ofApp::update(){
	TM::update(ofGetElapsedTimeMillis());
}

//--------------------------------------------------------------
void ofApp::draw(){

	for(uint i = 0; i < boxes.size(); ++i){
		ofSetColor(boxes[i].color);
		ofDrawCircle(boxes[i].pos.x, boxes[i].pos.y, 5);
	}

}


//--------------------------------------------------------------
void ofApp::exit() {
	TweenMore::destroy();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch(key){
		case OF_KEY_LEFT:
			TweenMore::removeTweenGroup(0);
		break;
		case OF_KEY_DOWN:
			TweenMore::removeTweenGroup(1);
		break;
		case OF_KEY_RIGHT:
			TweenMore::removeTweenGroup(2);
		break;
	}
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
