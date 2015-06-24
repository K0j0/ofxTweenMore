#include "ofApp.h"


struct littleBall{
	littleBall(ofColor _color, ofVec2f _start, ofVec2f _target){
		color = _color;
		pos = start = _start;
		target = _target;
	}
	ofColor color;
	ofVec2f pos; // current position

	ofVec2f start; // start position
	ofVec2f target; // end position
};
vector<littleBall> boxes;

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofSetCircleResolution(60);
    
    TM::init();
    
    float width = ofGetWindowWidth();

    int padding = 50;
    // make 3 little balls
    littleBall b1 = littleBall(ofColor::red, ofVec2f(padding, 50), ofVec2f(width - padding, 50));
    littleBall b2 = littleBall(ofColor::yellow, ofVec2f(padding, 150), ofVec2f(width - padding, 150));
    littleBall b3 = littleBall(ofColor::green, ofVec2f(padding, 250), ofVec2f(width - padding, 250));

    boxes.push_back(b1);
    boxes.push_back(b2);
    boxes.push_back(b3);

    // tween position to target and loop forever, set each to have group id of loop index
    for(int i = 0; i < 3; ++i){
    	TM::to(&boxes[i].pos, boxes[i].target, 3).setRepeat(-1, true).setGroupID(i);
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
	ofDrawBitmapStringHighlight("Left Arrow to stop RED (0)\nDown Arrow to  YELLOW (1)\nRight Arrow to stop GREEN (2)", 50, 350);

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
