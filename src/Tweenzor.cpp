/*
 *  Tweenzor.cpp
 *  openFrameworks
 *
 *  Created by Nick Hardeman on 10/31/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 *  Updated by Kojo Kumah in 12/2014
 *
 */

#include "Tweenzor.h"

Tweenzor* Tweenzor::__instance = 0;

//--------------------------------------------------------------
Tweenzor* Tweenzor::Instance() {
	if (__instance == 0) {
		__instance = new Tweenzor();
		__instance->_currMillis = 0;
		removeAllTweens();
	}
	return __instance;
}

//--------------------------------------------------------------
void Tweenzor::init() {
	Instance();
}

//--------------------------------------------------------------
void Tweenzor::update(int a_millis) {
	
	__instance->_currMillis = a_millis;
		
    // check for finished tweens then call their callbacks if they have any
	// TODO, check for length changes in case a callback changes the size of tweens vector
    int len = __instance->_tweens.size();
    for(int i = 0; i < len; ++i){
        Tween * tween = __instance->_tweens[i];
        
		if(tween->complete() && tween->hasListener) {
            (*(tween->listener.m_inner))();
            
            // callback has changed tweens vector, start over. Don't worry, callbacks will not be repeated
            // TODO, maybe find more efficient way to do this?
            if(len != __instance->_tweens.size()){
                len = __instance->_tweens.size();
                i = 0;
            }
		}
	}
	
    // remove finished tweens from vector
	if(__instance->_tweens.size() > 0) {
		int _totesTweens = __instance->_tweens.size();
		for(int i = _totesTweens-1; i >= 0; i--) {
			if(__instance->_tweens[i]->complete()) {
                switch(__instance->_tweens[i]->getTweenType()){
                    case Tween::FLOAT:
                        removeTween( __instance->_tweens[i]->getProperty() );
                    break;
                    case Tween::VEC2:
                        removeTween( static_cast<TweenVec2 *>(__instance->_tweens[i])->getProperty() );
                    break;
                    case Tween::VEC3:
                        removeTween( __instance->_tweens[i]->getProperty() );
                    break;
                    case Tween::VEC4:
                        removeTween( __instance->_tweens[i]->getProperty() );
                    break;
                    case Tween::RECT:
                        removeTween( __instance->_tweens[i]->getProperty() );
                    break;
                    case Tween::COLOR:
                        removeTween( __instance->_tweens[i]->getProperty() );
                    break;
                }
			}
		}
	}
	
    // Update remaining tweens
    vector<Tween *>::iterator it;
	for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
		(*it)->update( __instance->_currMillis );
	}
	
}


// float
//--------------------------------------------------------------
// add a tween in seconds, pass in float for delay and duration //
Tween& Tweenzor::add(float* a_property, float a_begin, float a_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
	removeTween( a_property ); // remove tween for this property if one already exists
	Tween * tweenzlebob = new Tween( a_property, __instance->_currMillis, a_begin, a_end, a_duration, a_delay, a_easeType, a_p, a_a );
	__instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

Tween& Tweenzor::to(float* a_property, float a_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    return add(a_property, *a_property, a_end, a_duration, a_delay, a_easeType, a_p, a_a);
}

Tween& Tweenzor::from(float* a_property, float a_begin, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    return add(a_property, a_begin, *a_property, a_duration, a_delay, a_easeType, a_p, a_a);
}

// add a tween that uses frames as time //
Tween& Tweenzor::framesAdd(float* a_property, float a_begin, float a_end, int a_duration, int a_delay, int a_easeType, float a_p, float a_a) {
    removeTween( a_property ); // remove tween for this property if one already exists
    Tween * tweenzlebob = new Tween( a_property, __instance->_currMillis, a_begin, a_end, a_duration, a_delay, a_easeType, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

Tween& Tweenzor::framesTo(float* a_property, float a_end, int a_duration, int a_delay, int a_easeType, float a_p, float a_a) {
    return add(a_property, *a_property, a_end, a_duration, a_delay, a_easeType, a_p, a_a);
}

Tween& Tweenzor::framesFrom(float* a_property, float a_begin, int a_duration, int a_delay, int a_easeType, float a_p, float a_a) {
    return add(a_property, a_begin, *a_property, a_duration, a_delay, a_easeType, a_p, a_a);
}

// ofVec2f
//--------------------------------------------------------------
TweenVec2& Tweenzor::add(ofVec2f *a_vec, const ofVec2f &c_begin, const ofVec2f &c_end, float a_duration, float a_delay, int a_easetype, float a_p, float a_a) {
    removeTween(a_vec);
    TweenVec2 * tweenzlebob = new TweenVec2( a_vec, __instance->_currMillis, c_begin, c_end, a_duration, a_delay, a_easetype, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

TweenVec2& Tweenzor::to(ofVec2f *a_vec, const ofVec2f &c_end, float a_duration, float a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, *a_vec, c_end, a_duration, a_delay, a_easetype, a_p, a_a);
}

TweenVec2& Tweenzor::from(ofVec2f *a_vec, const ofVec2f &c_begin, float a_duration, float a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, c_begin, *a_vec, a_duration, a_delay, a_easetype, a_p, a_a);
}

TweenVec2& Tweenzor::framesAdd(ofVec2f* a_vec, const ofVec2f& v_begin, const ofVec2f& v_end, int a_duration, int a_delay, int a_easeType, float a_p, float a_a){
    removeTween(a_vec);
    TweenVec2 * tweenzlebob = new TweenVec2( a_vec, __instance->_currMillis, v_begin, v_end, a_duration, a_delay, a_easeType, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

TweenVec2& Tweenzor::framesTo(ofVec2f *a_vec, const ofVec2f &c_end, int a_duration, int a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, *a_vec, c_end, a_duration, a_delay, a_easetype, a_p, a_a);
}

TweenVec2& Tweenzor::framesFrom(ofVec2f *a_vec, const ofVec2f &c_begin, int a_duration, int a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, c_begin, *a_vec, a_duration, a_delay, a_easetype, a_p, a_a);
}

// ofVec3f
//--------------------------------------------------------------
TweenVec3& Tweenzor::add(ofVec3f *a_vec, const ofVec3f &c_begin, const ofVec3f &c_end, float a_duration, float a_delay, int a_easetype, float a_p, float a_a) {
    removeTween(a_vec);
    TweenVec3 * tweenzlebob = new TweenVec3( a_vec, __instance->_currMillis, c_begin, c_end, a_duration, a_delay, a_easetype, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

TweenVec3& Tweenzor::to(ofVec3f *a_vec, const ofVec3f &c_end, float a_duration, float a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, *a_vec, c_end, a_duration, a_delay, a_easetype, a_p, a_a);
}

TweenVec3& Tweenzor::from(ofVec3f *a_vec, const ofVec3f &c_begin, float a_duration, float a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, c_begin, *a_vec, a_duration, a_delay, a_easetype, a_p, a_a);
}

TweenVec3& Tweenzor::framesAdd(ofVec3f* a_vec, const ofVec3f& v_begin, const ofVec3f& v_end, int a_duration, int a_delay, int a_easeType, float a_p, float a_a){
    removeTween(a_vec);
    TweenVec3 * tweenzlebob = new TweenVec3( a_vec, __instance->_currMillis, v_begin, v_end, a_duration, a_delay, a_easeType, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

TweenVec3& Tweenzor::framesTo(ofVec3f *a_vec, const ofVec3f &c_end, int a_duration, int a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, *a_vec, c_end, a_duration, a_delay, a_easetype, a_p, a_a);
}

TweenVec3& Tweenzor::framesFrom(ofVec3f *a_vec, const ofVec3f &c_begin, int a_duration, int a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, c_begin, *a_vec, a_duration, a_delay, a_easetype, a_p, a_a);
}


// ofVec4f
//--------------------------------------------------------------
TweenVec4& Tweenzor::add(ofVec4f *a_vec, const ofVec4f &c_begin, const ofVec4f &c_end, float a_duration, float a_delay, int a_easetype, float a_p, float a_a) {
    removeTween(a_vec);
    TweenVec4 * tweenzlebob = new TweenVec4( a_vec, __instance->_currMillis, c_begin, c_end, a_duration, a_delay, a_easetype, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

TweenVec4& Tweenzor::to(ofVec4f *a_vec, const ofVec4f &c_end, float a_duration, float a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, *a_vec, c_end, a_duration, a_delay, a_easetype, a_p, a_a);
}

TweenVec4& Tweenzor::from(ofVec4f *a_vec, const ofVec4f &c_begin, float a_duration, float a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, c_begin, *a_vec, a_duration, a_delay, a_easetype, a_p, a_a);
}

TweenVec4& Tweenzor::framesAdd(ofVec4f* a_vec, const ofVec4f& v_begin, const ofVec4f& v_end, int a_duration, int a_delay, int a_easeType, float a_p, float a_a){
    removeTween(a_vec);
    TweenVec4 * tweenzlebob = new TweenVec4( a_vec, __instance->_currMillis, v_begin, v_end, a_duration, a_delay, a_easeType, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

TweenVec4& Tweenzor::framesTo(ofVec4f *a_vec, const ofVec4f &c_end, int a_duration, int a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, *a_vec, c_end, a_duration, a_delay, a_easetype, a_p, a_a);
}

TweenVec4& Tweenzor::framesFrom(ofVec4f *a_vec, const ofVec4f &c_begin, int a_duration, int a_delay, int a_easetype, float a_p, float a_a) {
    return add(a_vec, c_begin, *a_vec, a_duration, a_delay, a_easetype, a_p, a_a);
}

// ofRectangle
//--------------------------------------------------------------
TweenRect& Tweenzor::add(ofRectangle * a_rect, const ofRectangle& r_begin, const ofRectangle& r_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    removeTween(a_rect);
    TweenRect * tweenzlebob = new TweenRect( a_rect, __instance->_currMillis, r_begin, r_end, a_duration, a_delay, a_easeType, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

TweenRect& Tweenzor::to(ofRectangle * a_rect, const ofRectangle& r_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    return add(a_rect, *a_rect, r_end, a_duration, a_delay, a_easeType, a_p, a_a);
}

TweenRect& Tweenzor::from(ofRectangle * a_rect, const ofRectangle& r_begin, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    return add(a_rect, r_begin, *a_rect, a_duration, a_delay, a_easeType, a_p, a_a);
}

TweenRect& Tweenzor::framesAdd(ofRectangle * a_rect, const ofRectangle& r_begin, const ofRectangle& r_end, int a_duration, int a_delay, int a_easeType, float a_p, float a_a) {
    removeTween(a_rect);
    TweenRect * tweenzlebob = new TweenRect( a_rect, __instance->_currMillis, r_begin, r_end, a_duration, a_delay, a_easeType, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

TweenRect& Tweenzor::framesTo(ofRectangle * a_rect, const ofRectangle& r_end, int a_duration, int a_delay, int a_easeType, float a_p, float a_a) {
    return add(a_rect, *a_rect, r_end, a_duration, a_delay, a_easeType, a_p, a_a);
}

TweenRect& Tweenzor::framesFrom(ofRectangle * a_rect, const ofRectangle& r_begin, int a_duration, int a_delay, int a_easeType, float a_p, float a_a) {
    return add(a_rect, r_begin, *a_rect, a_duration, a_delay, a_easeType, a_p, a_a);
}

// ofFloatColor
//--------------------------------------------------------------
TweenColor& Tweenzor::add(ofFloatColor *a_color, const ofFloatColor &c_begin, const ofFloatColor &c_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    removeTween(a_color);
    TweenColor * tweenzlebob = new TweenColor( a_color, __instance->_currMillis, c_begin, c_end, a_duration, a_delay, a_easeType, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

TweenColor& Tweenzor::to(ofFloatColor *a_color, const ofFloatColor &c_end, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    return add(a_color, *a_color, c_end, a_duration, a_delay, a_easeType, a_p, a_a);
}

TweenColor& Tweenzor::from(ofFloatColor *a_color, const ofFloatColor &c_begin, float a_duration, float a_delay, int a_easeType, float a_p, float a_a) {
    return add(a_color, c_begin, *a_color, a_duration, a_delay, a_easeType, a_p, a_a);
}

TweenColor& Tweenzor::framesAdd(ofFloatColor *a_color, const ofFloatColor &c_begin, const ofFloatColor &c_end, int a_duration, int a_delay, int a_easeType, float a_p, float a_a) {
    removeTween(a_color);
    TweenColor * tweenzlebob = new TweenColor( a_color, __instance->_currMillis, c_begin, c_end, a_duration, a_delay, a_easeType, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}


//--------------------------------------------------------------
Tween* Tweenzor::getTween( float* a_property ) {
    int len = __instance->_tweens.size();
    for(int i = 0; i < len; ++i){
        Tween * tween = __instance->_tweens[i];
        if(tween->getProperty() == a_property){
            return tween;
        }
    }
	return NULL;
}

TweenVec2 * Tweenzor::getTween(ofVec2f * vec) {
    vector<Tween *>::iterator it;
    for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); ++it ) {
        if((*it)->getTweenType() == Tween::VEC2 && static_cast<TweenVec2 *>(*it)->getProperty() == vec) {
            return static_cast<TweenVec2 *>(*it);
        }
    }
    return NULL;
}

TweenVec3 * Tweenzor::getTween(ofVec3f *vec) {
    vector<Tween *>::iterator it;
    for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); ++it ) {
        if((*it)->getTweenType() == Tween::VEC3 && static_cast<TweenVec3 *>(*it)->getProperty() == vec) {
            return static_cast<TweenVec3 *>(*it);
        }
    }
    return NULL;
}

TweenVec4 * Tweenzor::getTween(ofVec4f *vec) {
    vector<Tween *>::iterator it;
    for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); ++it ) {
        if((*it)->getTweenType() == Tween::VEC4 && static_cast<TweenVec4 *>(*it)->getProperty() == vec) {
            return static_cast<TweenVec4 *>(*it);
        }
    }
    return NULL;
}

TweenRect * Tweenzor::getTween(ofRectangle *rect) {
    vector<Tween *>::iterator it;
    for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); ++it ) {
        if((*it)->getTweenType() == Tween::RECT && static_cast<TweenRect *>(*it)->getProperty() == rect) {
            return static_cast<TweenRect *>(*it);
        }
    }
    return NULL;
}

TweenColor * Tweenzor::getTween(ofFloatColor *color) {
    vector<Tween *>::iterator it;
    for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); ++it ) {
        if((*it)->getTweenType() == Tween::COLOR && static_cast<TweenColor *>(*it)->getProperty() == color) {
            return static_cast<TweenColor *>(*it);
        }
    }
    return NULL;
}

//--------------------------------------------------------------
void Tweenzor::removeCompleteListener( Tween* a_tween ) {
	if(a_tween == NULL) return;
    a_tween->listener.clear();
}

void Tweenzor::removeCompleteListener( float* a_property ) {
	removeCompleteListener( getTween(a_property) );
}

void Tweenzor::removeCompleteListener( ofVec2f * a_property ) {
    removeCompleteListener( getTween(a_property) );
}

void Tweenzor::removeCompleteListener( ofVec3f * a_property ) {
    removeCompleteListener( getTween(a_property) );
}

void Tweenzor::removeCompleteListener( ofVec4f * a_property ) {
    removeCompleteListener( getTween(a_property) );
}

void Tweenzor::removeAllListeners() {
    int len = __instance->_tweens.size();
    for(int i = 0; i < len; ++i){
        Tween * tween = __instance->_tweens[i];
        tween->listener.clear();
    }
}

//--------------------------------------------------------------
void Tweenzor::removeTween( float* a_property ) {
    bool printed = false;
    cout << "Remove tween ";
    if (__instance->_tweens.size() > 0) {
        int i = 0;
        vector<Tween *>::iterator it;
        for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
            if((*it)->getTweenType() == Tween::FLOAT){
                if((*it)->getProperty() == a_property ) {
                
                    cout << " named " << (*it)->name << endl;
                    printed = true;
                    
                    //cout << "Tweenzor :: removeTween : property = " <<  it->getProperty() << " = " << a_property << endl;
                    (*it)->stop();
                    delete *it;
                    __instance->_tweens.erase( it );
                    break;
                }
            }
            i++;
        }
    }
    if(!printed) cout << "." << endl;
}

void Tweenzor::removeTween( ofVec2f * a_property ) {
    if (__instance->_tweens.size() > 0) {
        int i = 0;
        vector<Tween *>::iterator it;
        for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
            if((*it)->getTweenType() == Tween::VEC2){
                if (static_cast<TweenVec2 *>(*it)->getProperty() == a_property ) {
                    //cout << "Tweenzor :: removeTween : property = " <<  it->getProperty() << " = " << a_property << endl;
                    (*it)->remove();
                    delete *it;
                    __instance->_tweens.erase( it );
                    break;
                }
            }
            i++;
        }
    }
}

void Tweenzor::removeTween( ofVec3f * a_property ) {
    if (__instance->_tweens.size() > 0) {
        int i = 0;
        vector<Tween *>::iterator it;
        for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
            if((*it)->getTweenType() == Tween::VEC3){
                if (static_cast<TweenVec3 *>(*it)->getProperty() == a_property ) {
                    //cout << "Tweenzor :: removeTween : property = " <<  it->getProperty() << " = " << a_property << endl;
                    (*it)->remove();
                    delete *it;
                    __instance->_tweens.erase( it );
                    break;
                }
            }
            i++;
        }
    }
}

void Tweenzor::removeTween( ofVec4f * a_property ) {
    if (__instance->_tweens.size() > 0) {
        int i = 0;
        vector<Tween *>::iterator it;
        for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
            if((*it)->getTweenType() == Tween::VEC4){
                if (static_cast<TweenVec4 *>(*it)->getProperty() == a_property ) {
                    //cout << "Tweenzor :: removeTween : property = " <<  it->getProperty() << " = " << a_property << endl;
                    (*it)->remove();
                    delete *it;
                    __instance->_tweens.erase( it );
                    break;
                }
            }
            i++;
        }
    }
}

void Tweenzor::removeTween(ofRectangle * a_property) {
    if (__instance->_tweens.size() > 0) {
        int i = 0;
        vector<Tween *>::iterator it;
        for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
            if((*it)->getTweenType() == Tween::RECT){
                if (static_cast<TweenRect *>(*it)->getProperty() == a_property ) {
                    //cout << "Tweenzor :: removeTween : property = " <<  it->getProperty() << " = " << a_property << endl;
                    (*it)->remove();
                    delete *it;
                    __instance->_tweens.erase( it );
                    break;
                }
            }
            i++;
        }
    }
}

void Tweenzor::removeTween(ofFloatColor * a_property) {
    if (__instance->_tweens.size() > 0) {
        int i = 0;
        vector<Tween *>::iterator it;
        for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
            if((*it)->getTweenType() == Tween::COLOR){
                if (static_cast<TweenColor *>(*it)->getProperty() == a_property ) {
                    //cout << "Tweenzor :: removeTween : property = " <<  it->getProperty() << " = " << a_property << endl;
                    (*it)->remove();
                    delete *it;
                    __instance->_tweens.erase( it );
                    break;
                }
            }
            i++;
        }
    }
}

void Tweenzor::removeAllTweens() {
    int len = __instance->_tweens.size();
    for(int i = 0; i < len; ++i){
        Tween * tween = __instance->_tweens[i];
        tween->stop();
        delete tween; // deleting a Tween also removes it's listeners
    }
	__instance->_tweens.clear();
	cout << "Tweenzor :: removeAllTweens : " << __instance->_tweens.empty() << endl;
}

//--------------------------------------------------------------
void Tweenzor::destroy() {
	removeAllTweens();
	
	if(__instance != 0) {
		delete __instance;
		__instance = 0;
		
		cout << "Tweenzor :: destroy : " << endl;
	}
	
}

//--------------------------------------------------------------
void Tweenzor::pauseAllTweens() {
	if (__instance->_tweens.size() > 0) {
		vector<Tween *>::iterator it;
		for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
			(*it)->pause();
		}
	}
}

//--------------------------------------------------------------
void Tweenzor::resetAllTweens() {
	if (__instance->_tweens.size() > 0) {
		vector<Tween *>::iterator it;
		for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
			(*it)->reset(__instance->_currMillis);
		}
	}
}

//--------------------------------------------------------------
void Tweenzor::resumeAllTweens() {
	if (__instance->_tweens.size() > 0) {
		vector<Tween *>::iterator it;
		for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
			(*it)->resume(__instance->_currMillis);
		}
	}
}

// toggle pause / resume all tweens //
//--------------------------------------------------------------
void Tweenzor::toggleAllTweens() {
	if (__instance->_tweens.size() > 0) {
		vector<Tween *>::iterator it;
		for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
			(*it)->toggle(__instance->_currMillis);
		}
	}
}

//--------------------------------------------------------------
Tween* Tweenzor::getRecentTween() {
	if (__instance->_tweens.size() > 0) {
		return __instance->_tweens[__instance->_tweens.size() - 1];
	}
  return 0;
}

//--------------------------------------------------------------
int Tweenzor::getSize() {
	return __instance->_tweens.size();
}







