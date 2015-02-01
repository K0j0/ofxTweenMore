//
//  TweenRect.cpp
//  TweenMoreSimpleExample
//
//  Created by Kojo Kumah on 1/2/15.
//
//

#include "TweenRect.h"


//--------------------------------------------------------------
// pass in ints for delay and duration as number of frames //
TweenRect::TweenRect(ofRectangle * a_property, ofRectangle  a_begin, ofRectangle  a_end, int a_duration, int a_delay, int a_easeType, float a_p, float a_a) {
    _useSeconds = false;
    _time		= 0.f;
    
    _setup(a_property, a_begin, a_end, (float)a_duration, (float)a_delay, a_easeType, a_p, a_a);
}

//--------------------------------------------------------------
// pass in floats for delay and duration as seconds //
TweenRect::TweenRect(ofRectangle * a_property, int a_millis, ofRectangle  a_begin, ofRectangle  a_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    _useSeconds = true;
    // convert seconds to millis //
    a_delay		= a_delay * 1000.f;
    a_duration	= a_duration * 1000.f;
    
    _startTime	= a_millis;
    _time = 0.f;
    
    _setup(a_property, a_begin, a_end, a_duration, a_delay, a_easeType, a_p, a_a);
}

//--------------------------------------------------------------
void TweenRect::_setup(ofRectangle * a_property, ofRectangle a_begin, ofRectangle a_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    _tweenType = RECT;
    
    _propAdd	= a_property;
    
    _begin		= ofVec4f(a_begin.x, a_begin.y, a_begin.width, a_begin.height);
    _end		= ofVec4f(a_end.x, a_end.y, a_end.width, a_end.height);
    _change		= _end - _begin;
    
    _initBegin	= _begin;
    _initEnd	= _end;
    
    _beginRect = a_begin;
    _endRect = a_end;
    
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

    name = "-unassigned rect tween-";
	_next = NULL;
	hasListener = false;
}

void TweenRect::updateComplete(bool bTweenIsComplete, int a_millis){
    if(bTweenIsComplete) {
        _isComplete = true;
        _isRunning = false;
        // let's make sure we hit the initial values //
        if(_dir == 1) {
            *_propAdd = _endRect;
        } else {
            *_propAdd = _beginRect;
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
void TweenRect::updateProperty() {
    _propAdd->x = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.x, _change.x, _duration, _easeType, _p, _a);
    _propAdd->y = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.y, _change.y, _duration, _easeType, _p, _a);
    _propAdd->width = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.z, _change.z, _duration, _easeType, _p, _a);
    _propAdd->height = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin.w, _change.w, _duration, _easeType, _p, _a);
}

//--------------------------------------------------------------
ofRectangle * TweenRect::getProperty() {
    return _propAdd;
}

//--------------------------------------------------------------
ofRectangle TweenRect::getPropertyValue() {
    return *_propAdd;
}

void TweenRect::reset(int a_millis) {
    if (!_isComplete) {
        *_propAdd = _beginRect;
        
        _startTime = a_millis;
        _time = 0.f;
        
        _isComplete = false;
    }
    cout << "Tween :: reset : running: " << running() << " complete: " << complete() << endl;
}

// GETTERS //
//--------------------------------------------------------------
float TweenRect::getPropertyPct() {
    float pct;
    if (*_propAdd == _beginRect) {
        pct = 0;
    } else if(*_propAdd == _endRect) {
        pct = 1;
    } else {
        // first check for x then for y
        if((_end.x - _begin.x) != 0) pct = (_propAdd->x - _begin.x) / (_end.x - _begin.x);
        else if((_end.y - _begin.y) != 0) pct = (_propAdd->y - _begin.y) / (_end.y - _begin.y);
        else if((_end.z - _begin.z) != 0) pct = (_propAdd->width - _begin.z) / (_end.z - _begin.z);
        else pct = (_propAdd->height - _begin.w) / (_end.w - _begin.w);
    }
    return pct < 0 ? pct * -1 : pct;
}

// Chaining
TweenRect & TweenRect::chainTo(ofRectangle a_end, int a_duration, int a_delay, int a_easeType, float a_p, float a_a){
    _next = new TweenRect(this->_propAdd, 0, this->_endRect, a_end, a_duration, a_delay, a_easeType, a_p, a_a);
    _next->name = "chainer";
    return *(static_cast<TweenRect *>(_next));
}

TweenRect & TweenRect::chainFrom(ofRectangle a_begin, int a_duration, int a_delay, int a_easeType, float a_p, float a_a){
    _next = new TweenRect(this->_propAdd, 0, a_begin, this->_endRect, a_duration, a_delay, a_easeType, a_p, a_a);
    _next->name = "chainer";
    return *(static_cast<TweenRect *>(_next));
}

TweenRect * TweenRect::getNext(){
    return static_cast<TweenRect *>(_next);
}
