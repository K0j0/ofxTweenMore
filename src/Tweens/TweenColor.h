//
//  TweenColor.h
//  TweenzorSimpleExample
//
//  Created by Kojo Kumah on 1/1/15.
//
//

#ifndef __TweenzorSimpleExample__TweenColor__
#define __TweenzorSimpleExample__TweenColor__

#include "Tween.h"

class TweenColor : public Tween {
public:
    
    TweenColor(ofFloatColor * a_property, ofFloatColor a_begin, ofFloatColor a_end, int a_delay, int a_duration, int a_easeType, float a_p=0, float a_a=0);
    TweenColor(ofFloatColor * a_property, int a_millis, ofFloatColor a_begin, ofFloatColor a_end, float a_delay, float a_duration, int a_easeType, float a_p=0, float a_a=0);
    
    void updateComplete(bool bTweenIsComplete, int a_millis);
    
    ofFloatColor * getProperty();
    ofFloatColor getPropertyValue();
    // TODO, optimize by storing which properties have the greatest range in setup() then just compare those
    float getPropertyPct();
    void updateProperty();
    
    
protected:
    void _setup(ofFloatColor * a_property, ofFloatColor a_begin, ofFloatColor a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a);
    
    ofVec4f _change, _begin, _end;
    ofVec4f _initBegin, _initEnd; // store these, since during a ping pong, we need to switch them //
    ofFloatColor _beginColor, _endColor;
    
    ofFloatColor *_propAdd;
};



#endif /* defined(__TweenzorSimpleExample__TweenColor__) */
