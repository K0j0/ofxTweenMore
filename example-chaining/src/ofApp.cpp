#include "ofApp.h"
#include "TweenMore.h"

ofVec2f v1;
ofVec3f v2;
ofVec4f v3;
ofFloatColor col;
ofRectangle rect;

//--------------------------------------------------------------
void ofApp::setup(){
    ofLog() << "Start. elapsed: " << ofGetElapsedTimeMillis();
    TM::init(); // can use TM as shorthand for TweenMore
    
    f = 10;
    TM::to(&f, 400, 2, 4).chainTo(200, 1, 1);
    // Set name on tween
    Tween * floatTween = TM::getTween(&f);
    floatTween->name = "floatTween";
    floatTween->getNext()->name = "floatTween - chain";
    
    
    v1 = ofVec2f(10, 100);
    TM::to(&v1, ofVec2f(120,250), 1, 8).chainTo(ofVec2f(200, 100), 1, 1);
    // Set name on tween
    TweenVec2 * vec2Tween = TM::getTween(&v1);
    vec2Tween->name = "vec2Tween";
    vec2Tween->getNext()->name = "vec2Tween - chain";
    
    v2 = ofVec3f(500, 150, 1);
    TM::to(&v2, ofVec3f(350, 250, 0), 1, 11).chainTo(ofVec3f(200, 150, 1), 1, 1);
    // Set name on tween
    TweenVec3 * vec3Tween = TM::getTween(&v2);
    vec3Tween->name = "vec3Tween";
    vec3Tween->getNext()->name = "vec3Tween - chain";
    
    v3 = ofVec4f(10,280, 500, 280);
    TM::to(&v3, ofVec4f(100, 190, 340, 190), 1, 14).chainTo(ofVec4f(200, 200, 200, 250), 1, 1);
    // Set name on tween
    TweenVec4 * vec4Tween = TM::getTween(&v3);
    vec4Tween->name = "vec4Tween";
    vec4Tween->getNext()->name = "vec4Tween - chain";
    
    rect = ofRectangle(10, 350, 80, 120);
    TM::to(&rect, ofRectangle(300, 400, 120, 80), 1, 17).chainTo(ofRectangle(200, 300, 60, 60), 1, 1);
    // Set name on tween
    TweenRect * rectTween = TM::getTween(&rect);
    rectTween->name = "Rectangle & Color";
    rectTween->getNext()->name = "Rectangle & Color - chain";
    
    col = ofColor::white;
    TM::to(&col, ofColor::black, 1, 17).chainTo(ofColor::pink, 1, 1);
}

//--------------------------------------------------------------
void ofApp::update(){
    TM::update(ofGetElapsedTimeMillis());
}

//--------------------------------------------------------------
void ofApp::draw(){    
    ofSetColor(ofColor::red);
    ofDrawCircle(f, 50, 5);
    // draw tween name
    Tween * floatTween = TM::getTween(&f);
    if(floatTween != NULL) ofDrawBitmapStringHighlight(floatTween->name, f, 35);
    else ofDrawBitmapStringHighlight("floatTween - done", f, 35);

    
    ofSetColor(ofColor::yellow);
    ofDrawCircle(v1.x, v1.y, 5);
    // draw tween name
    TweenVec2 * vec2Tween = TM::getTween(&v1);
    if(vec2Tween != NULL) ofDrawBitmapStringHighlight(vec2Tween->name, v1.x, v1.y - 15, 5);
    else ofDrawBitmapStringHighlight("vec2Tween - done", v1.x, v1.y - 15, 5);
    
    
    ofColor blueFade = ofColor::blue;
    blueFade.a = v2.z * 255;
    ofSetColor(blueFade);
    ofDrawCircle(v2, 5);
    // draw tween name
    TweenVec3 * vec3Tween = TM::getTween(&v2);
    if(vec3Tween != NULL) ofDrawBitmapStringHighlight(vec3Tween->name, v2.x, v2.y - 15, 5);
    else ofDrawBitmapStringHighlight("vec3Tween - done", v2.x, v2.y - 15, 5);

    
    ofSetColor(ofColor::orange);
    ofDrawCircle(v3.x, v3.y, 5);
    ofDrawCircle(v3.z, v3.w, 5);
    // draw tween name
    TweenVec4 * vec4Tween = TM::getTween(&v3);
    if(vec4Tween != NULL){
        ofDrawBitmapStringHighlight(vec4Tween->name, v3.x, v3.y - 15, 5);
        ofDrawBitmapStringHighlight(vec4Tween->name, v3.z, v3.w - 15, 5);
    }
    else{
        ofDrawBitmapStringHighlight("vec4Tween - done", v3.x, v3.y - 15, 5);
        ofDrawBitmapStringHighlight("vec4Tween - done", v3.z, v3.w - 15, 5);
    }
    
    ofSetColor(col);
    ofDrawRectangle(rect);
    // draw tween name
    TweenRect * rectTween = TM::getTween(&rect);
    if(rectTween != NULL) ofDrawBitmapStringHighlight(rectTween->name, rect.x, rect.y - 15, 5);
    else ofDrawBitmapStringHighlight("Rectangle & Color - done", rect.x, rect.y - 15, 5);
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
