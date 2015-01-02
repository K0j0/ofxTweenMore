//
//  TweenColor.cpp
//  TweenzorSimpleExample
//
//  Created by Kojo Kumah on 1/1/15.
//
//

#include "TweenColor.h"

//--------------------------------------------------------------
// pass in ints for delay and duration as number of frames //
TweenColor::TweenColor(ofFloatColor * a_property, ofFloatColor  a_begin, ofFloatColor  a_end, int a_delay, int a_duration, int a_easeType, float a_p, float a_a) {
    _useSeconds = false;
    _time		= 0.f;
    
    _setup(a_property, a_begin, a_end, (float)a_delay, (float)a_duration, a_easeType, a_p, a_a);
}

//--------------------------------------------------------------
// pass in floats for delay and duration as seconds //
TweenColor::TweenColor(ofFloatColor * a_property, int a_millis, ofFloatColor  a_begin, ofFloatColor  a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a) {
    _useSeconds = true;
    // convert seconds to millis //
    a_delay		= a_delay * 1000.f;
    a_duration	= a_duration * 1000.f;
    
    _startTime	= a_millis;
    _time = 0.f;
    
    _setup(a_property, a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a);
}

// TODO, implement with a Vector4. Seems I can't have negative rgba values for ofColor which is a problem for _change
//--------------------------------------------------------------
void TweenColor::_setup(ofFloatColor * a_property, ofFloatColor a_begin, ofFloatColor a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a) {
    _tweenType = VEC2;
    
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

void TweenColor::updateComplete(bool bTweenIsComplete, int a_millis){
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
void TweenColor::updateProperty() {
    _propAdd->r = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.r, _change.r, _duration, _easeType, _p, _a);
    _propAdd->b = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.b, _change.b, _duration, _easeType, _p, _a);
    _propAdd->g = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.g, _change.g, _duration, _easeType, _p, _a);
    _propAdd->a = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.a, _change.a, _duration, _easeType, _p, _a);
}

//--------------------------------------------------------------
ofFloatColor * TweenColor::getProperty() {
    return _propAdd;
}

//--------------------------------------------------------------
ofFloatColor TweenColor::getPropertyValue() {
    return *_propAdd;
}


// GETTERS //
//--------------------------------------------------------------
float TweenColor::getPropertyPct() {
    float pct;
    if (*_propAdd == _begin) {
        pct = 0;
    } else if(*_propAdd == _end) {
        pct = 1;
    } else {
        // first check for x then for y
        pct = (_propAdd->getHex() - _begin.getHex()) / (_end.getHex() - _begin.getHex());
    }
    return pct < 0 ? pct * -1 : pct;
}