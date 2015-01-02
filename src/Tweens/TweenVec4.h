//
//  TweenVec4.h
//  TweenzorSimpleExample
//
//  Created by Kojo Kumah on 12/28/14.
//
//

#ifndef TweenzorSimpleExample_TweenVec4_h
#define TweenzorSimpleExample_TweenVec4_h


#include "Tween.h"

class TweenVec4 : public Tween {
public:
    
    TweenVec4(ofVec4f * a_property, ofVec4f a_begin, ofVec4f a_end, int a_duration, int a_delay, int a_easeType, float a_p=0, float a_a=0);
    TweenVec4(ofVec4f * a_property, int a_millis, ofVec4f a_begin, ofVec4f a_end, float a_duration, float a_delay, int a_easeType, float a_p=0, float a_a=0);
    
    void updateComplete(bool bTweenIsComplete, int a_millis);
    
    ofVec4f * getProperty();
    ofVec4f getPropertyValue();
    // TODO, optimize by storing which properties have the greatest range in setup() then just compare those
    float getPropertyPct();
    void updateProperty();
    
    
protected:
    void _setup(ofVec4f * a_property, ofVec4f a_begin, ofVec4f a_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a);
    
    ofVec4f _change, _begin, _end;
    ofVec4f _initBegin, _initEnd; // store these, since during a ping pong, we need to switch them //
    
    ofVec4f *_propAdd;
};


#endif
