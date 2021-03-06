

#ifndef _TWEENVEC2_
#define _TWEENVEC2_


#include "Tween.h"

class TweenVec2 : public Tween {
public:
        
    TweenVec2(ofVec2f * a_property, ofVec2f a_begin, ofVec2f a_end, int a_duration, int a_delay, int a_easeType, float a_p=0, float a_a=0);
    TweenVec2(ofVec2f * a_property, int a_millis, ofVec2f a_begin, ofVec2f a_end, float a_duration, float a_delay, int a_easeType, float a_p=0, float a_a=0);
    
    void updateComplete(bool bTweenIsComplete, int a_millis);
    
    ofVec2f * getProperty();
    ofVec2f getPropertyValue();
    // TODO, optimize by storing which properties have the greatest range in setup() then just compare those
    float getPropertyPct();
    void updateProperty();
    
    void reset(int a_millis);
    
    // Chaining functions
    TweenVec2 & chainTo(ofVec2f a_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    TweenVec2 & chainFrom(ofVec2f a_begin, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    TweenVec2 * getNext();
    
    
protected:
    void _setup(ofVec2f * a_property, ofVec2f a_begin, ofVec2f a_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a);
    
    ofVec2f _change, _begin, _end;
    ofVec2f _initBegin, _initEnd; // store these, since during a ping pong, we need to switch them //
    
    ofVec2f *_propAdd;
};

#endif