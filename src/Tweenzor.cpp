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
Tween& Tweenzor::add(float* a_property, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a) {
	removeTween( a_property ); // remove tween for this property if one already exists
	Tween * tweenzlebob = new Tween( a_property, __instance->_currMillis, a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a );
	__instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

// add a tween that uses frames as time //
Tween& Tweenzor::framesAdd(float* a_property, float a_begin, float a_end, int a_delay, int a_duration, int a_easeType, float a_p, float a_a) {
    removeTween( a_property ); // remove tween for this property if one already exists
    Tween * tweenzlebob = new Tween( a_property, __instance->_currMillis, a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

// ofVec2f
//--------------------------------------------------------------
TweenVec2& Tweenzor::add(ofVec2f *a_vec, const ofVec2f &c_begin, const ofVec2f &c_end, float a_delay, float a_duration, int a_easetype, float a_p, float a_a) {
    removeTween(a_vec);
    TweenVec2 * tweenzlebob = new TweenVec2( a_vec, __instance->_currMillis, c_begin, c_end, a_delay, a_duration, a_easetype, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

TweenVec2& Tweenzor::framesAdd(ofVec2f* a_vec, const ofVec2f& v_begin, const ofVec2f& v_end, int a_delay, int a_duration, int a_easeType, float a_p, float a_a){
    removeTween(a_vec);
    TweenVec2 * tweenzlebob = new TweenVec2( a_vec, __instance->_currMillis, v_begin, v_end, a_delay, a_duration, a_easeType, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
    return *tweenzlebob;
}

// ofVec3f
//--------------------------------------------------------------


// ofVec4f
//--------------------------------------------------------------


// ofRectangle
//--------------------------------------------------------------


// ofFloatColor
//--------------------------------------------------------------


//--------------------------------------------------------------
void Tweenzor::add(ofFloatColor *a_color, const ofFloatColor &c_begin, const ofFloatColor &c_end, float a_delay, float a_duration, int a_easetype, float a_p, float a_a) {
    add(&a_color->r, c_begin.r, c_end.r, a_delay, a_duration, a_easetype, a_p, a_a);
    add(&a_color->g, c_begin.g, c_end.g, a_delay, a_duration, a_easetype, a_p, a_a);
    add(&a_color->b, c_begin.b, c_end.b, a_delay, a_duration, a_easetype, a_p, a_a);
    add(&a_color->a, c_begin.a, c_end.a, a_delay, a_duration, a_easetype, a_p, a_a);
}

void Tweenzor::add(ofVec3f *a_vec, const ofVec3f &c_begin, const ofVec3f &c_end, float a_delay, float a_duration, int a_easetype, float a_p, float a_a) {
    add(&a_vec->x, c_begin.x, c_end.x, a_delay, a_duration, a_easetype, a_p, a_a);
    add(&a_vec->y, c_begin.y, c_end.y, a_delay, a_duration, a_easetype, a_p, a_a);
    add(&a_vec->z, c_begin.z, c_end.z, a_delay, a_duration, a_easetype, a_p, a_a);
}
void Tweenzor::add(ofVec4f *a_vec, const ofVec4f &c_begin, const ofVec4f &c_end, float a_delay, float a_duration, int a_easetype, float a_p, float a_a) {
    add(&a_vec->x, c_begin.x, c_end.x, a_delay, a_duration, a_easetype, a_p, a_a);
    add(&a_vec->y, c_begin.y, c_end.y, a_delay, a_duration, a_easetype, a_p, a_a);
    add(&a_vec->z, c_begin.z, c_end.z, a_delay, a_duration, a_easetype, a_p, a_a);
    add(&a_vec->w, c_begin.w, c_end.w, a_delay, a_duration, a_easetype, a_p, a_a);
}

void Tweenzor::add(ofRectangle* a_rect, const ofRectangle& r_begin, const ofRectangle& r_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a) {
    add(&a_rect->position.x, r_begin.position.x, r_end.position.x, a_delay, a_duration, a_easeType, a_p, a_a);
    add(&a_rect->position.y, r_begin.position.y, r_end.position.y, a_delay, a_duration, a_easeType, a_p, a_a);
    add(&a_rect->position.z, r_begin.position.z, r_end.position.z, a_delay, a_duration, a_easeType, a_p, a_a);
    add(&a_rect->width, r_begin.width, r_end.width, a_delay, a_duration, a_easeType, a_p, a_a);
    add(&a_rect->height, r_begin.height, r_end.height, a_delay, a_duration, a_easeType, a_p, a_a);
}

//--------------------------------------------------------------

// TODO, Decide whether or not to keep these
void Tweenzor::add(vector <float *> a_properties, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a) {
    for (unsigned int i = 0; i < a_properties.size(); i++) {
        add(a_properties[i], a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a);
    }
}

void Tweenzor::add( TweenParams& a_params ) {
	if(a_params.bUseSeconds) {
		add(a_params.property, a_params.begin, a_params.end, a_params.delay, a_params.duration, a_params.easeType, a_params.p, a_params.a);
	} else {
		add(a_params.property, a_params.begin, a_params.end, (int)a_params.delay, (int)a_params.duration, a_params.easeType, a_params.p, a_params.a);
	}
}

void Tweenzor::add( vector<TweenParams>& a_params ) {
	for(unsigned int i = 0; i < a_params.size(); i++) {
		add( a_params[i] );
	}
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

Tween* Tweenzor::getTween(ofVec3f *vec) {
    return getTween(&vec->x);
}
Tween* Tweenzor::getTween(ofVec4f *vec) {
    return getTween(&vec->x);
}

Tween* Tweenzor::getTween(ofRectangle *rect) {
    return getTween(&rect->position.x);
}

Tween* Tweenzor::getTween(ofFloatColor *color) {
    return getTween(&color->r);
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
            if ( (*it)->getProperty() == a_property ) {
                
                cout << " named " << (*it)->name << endl;
                printed = true;
                
                //cout << "Tweenzor :: removeTween : property = " <<  it->getProperty() << " = " << a_property << endl;
                (*it)->stop();
                delete *it;
                __instance->_tweens.erase( it );
                break;
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
            if((*it)->getTweenType() == TweenVec2::VEC2){
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







