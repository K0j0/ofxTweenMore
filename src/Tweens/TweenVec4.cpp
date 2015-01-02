//
//  TweenVec4.cpp
//  TweenzorSimpleExample
//
//  Created by Kojo Kumah on 12/28/14.
//
//

#include "TweenVec4.h"

//--------------------------------------------------------------
// pass in ints for delay and duration as number of frames //
TweenVec4::TweenVec4(ofVec4f * a_property, ofVec4f  a_begin, ofVec4f  a_end, int a_duration, int a_delay, int a_easeType, float a_p, float a_a) {
    _useSeconds = false;
    _time		= 0.f;
    
    _setup(a_property, a_begin, a_end, (float)a_duration, (float)a_delay, a_easeType, a_p, a_a);
}

//--------------------------------------------------------------
// pass in floats for delay and duration as seconds //
TweenVec4::TweenVec4(ofVec4f * a_property, int a_millis, ofVec4f  a_begin, ofVec4f  a_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    _useSeconds = true;
    // convert seconds to millis //
    a_delay		= a_delay * 1000.f;
    a_duration	= a_duration * 1000.f;
    
    _startTime	= a_millis;
    _time = 0.f;
    
    _setup(a_property, a_begin, a_end, a_duration, a_delay, a_easeType, a_p, a_a);
}

//--------------------------------------------------------------
void TweenVec4::_setup(ofVec4f * a_property, ofVec4f a_begin, ofVec4f a_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    _tweenType = VEC4;
    
    _propAdd	= a_property;
    
    _begin		= a_begin;
    _end		= a_end;
    _change		= _end - _begin;
    
    _initBegin	= _begin;
    _initEnd	= _end;
    
    _delay		= a_delay;
    _duration	= a_duration;
    
    _easeType	= a_easeType;
    
    _p			= a_p;
    _a			= a_a;
    
    // use setRepeat to alter _repeat and _pingPong //
    _repeatTotal= 0; // dont repeat, only execute once //
    _repeatCount= 0; // we have not repeated at all //
    _pingPong	= false; // dont go back and forth //
    _dir		= 1; // go from _begin -> _end;
    
    _isRunning	= true;
    _isComplete = false;
}

void TweenVec4::updateComplete(bool bTweenIsComplete, int a_millis){
    if(bTweenIsComplete) {
        _isComplete = true;
        _isRunning = false;
        // let's make sure we hit the initial values //
        if(_dir == 1) {
            *_propAdd = _initEnd;
        } else {
            *_propAdd = _initBegin;
        }
        
    } else {
        if (_useSeconds) {
            _startTime = a_millis;
        } else {
            _time = 0;
        }
        _delay = 0;
        if(_pingPong) {
            _dir = _dir == 1 ? -1 : 1;
        }
        // adjust for the proper direction of the tween //
        if(_dir == 1) {
            _begin		= _initBegin;
            _end		= _initEnd;
            _change		= _end - _begin;
        } else {
            _begin		= _initEnd;
            _end		= _initBegin;
            _change		= _end - _begin;
        }
    }
}

//--------------------------------------------------------------
void TweenVec4::updateProperty() {
    _propAdd->x = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.x, _change.x, _duration, _easeType, _p, _a);
    _propAdd->y = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.y, _change.y, _duration, _easeType, _p, _a);
    _propAdd->z = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.z, _change.z, _duration, _easeType, _p, _a);
    _propAdd->w = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.w, _change.w, _duration, _easeType, _p, _a);
}

//--------------------------------------------------------------
ofVec4f * TweenVec4::getProperty() {
    return _propAdd;
}

//--------------------------------------------------------------
ofVec4f TweenVec4::getPropertyValue() {
    return *_propAdd;
}


// GETTERS //
//--------------------------------------------------------------
float TweenVec4::getPropertyPct() {
    float pct;
    if (*_propAdd == _begin) {
        pct = 0;
    } else if(*_propAdd == _end) {
        pct = 1;
    } else {
        // first check for x then for y
        if((_end.x - _begin.x) != 0) pct = (_propAdd->x - _begin.x) / (_end.x - _begin.x);
        else if((_end.y - _begin.y) != 0) pct = (_propAdd->y - _begin.y) / (_end.y - _begin.y);
        else if((_end.z - _begin.z) != 0) pct = (_propAdd->z - _begin.z) / (_end.z - _begin.z);
        else pct = (_propAdd->w - _begin.w) / (_end.w - _begin.w);
    }
    return pct < 0 ? pct * -1 : pct;
}

