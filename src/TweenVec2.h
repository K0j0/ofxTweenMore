/*
 *  Tween.h
 *  openFrameworks
 *
 *  Created by Nick Hardeman on 10/20/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _TWEENVEC2_
#define _TWEENVEC2_


#include "Tween.h"

class TweenVec2 : public Tween {
public:
        
    TweenVec2(ofVec2f * a_property, ofVec2f a_begin, ofVec2f a_end, int a_delay, int a_duration, int a_easeType, float a_p=0, float a_a=0);
    TweenVec2(ofVec2f * a_property, int a_millis, ofVec2f a_begin, ofVec2f a_end, float a_delay, float a_duration, int a_easeType, float a_p=0, float a_a=0);
    
    void update(int a_millis);
    
    ofVec2f * getProperty();
    ofVec2f getPropertyValue();
    float getPropertyPct();
    void updateProperty();
    
    
protected:
    void _setup(ofVec2f * a_property, ofVec2f a_begin, ofVec2f a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a);
    
    ofVec2f _change, _begin, _end;
    ofVec2f _initBegin, _initEnd; // store these, since during a ping pong, we need to switch them //
    
    ofVec2f *_propAdd;
};

#endif