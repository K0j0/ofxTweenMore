//
//  TweenVec3.h
//  TweenzorSimpleExample
//
//  Created by Kojo Kumah on 12/28/14.
//
//

#ifndef _TWEENVEC_3_
#define _TWEENVEC_3_


#include "Tween.h"

class TweenVec3 : public Tween {
public:
    
    TweenVec3(ofVec3f * a_property, ofVec3f a_begin, ofVec3f a_end, int a_duration, int a_delay, int a_easeType, float a_p=0, float a_a=0);
    TweenVec3(ofVec3f * a_property, int a_millis, ofVec3f a_begin, ofVec3f a_end, float a_duration, float a_delay, int a_easeType, float a_p=0, float a_a=0);
    
    void updateComplete(bool bTweenIsComplete, int a_millis);
    
    ofVec3f * getProperty();
    ofVec3f getPropertyValue();
    // TODO, optimize by storing which properties have the greatest range in setup() then just compare those
    float getPropertyPct();
    void updateProperty();
    
    void reset(int a_millis);
    
    // Chaining functions
    TweenVec3 & chainTo(ofVec3f a_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    TweenVec3 & chainFrom(ofVec3f a_begin, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    TweenVec3 * getNext();
    
    
protected:
    void _setup(ofVec3f * a_property, ofVec3f a_begin, ofVec3f a_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a);
    
    ofVec3f _change, _begin, _end;
    ofVec3f _initBegin, _initEnd; // store these, since during a ping pong, we need to switch them //
    
    ofVec3f *_propAdd;
};


#endif
