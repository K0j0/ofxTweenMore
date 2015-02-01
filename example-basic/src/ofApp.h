#pragma once

#include "ofMain.h"
#include "ofxTweenMore.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    // properties to tween
    float f;
    ofVec2f vec2;
    ofVec3f vec3;
    ofVec4f vec4;
    ofFloatColor floatColor;
    ofRectangle rect;
};
