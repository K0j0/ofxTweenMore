/*
 *  Tweenzor.h
 *  openFrameworks
 *
 *  Created by Nick Hardeman on 10/31/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _TWEENZOR_
#define _TWEENZOR_

#include "ofColor.h"
#include "ofVec2f.h"
#include "Tween.h"
#include "TweenVec2.h"
#include "TweenEvent.h"
#include "TweenListener.h"

typedef struct _tweenParams {
	_tweenParams() {
		bUseSeconds = true;
		duration	= 1.f;
		delay		= 0.f;
	}
	
	// params for a tween using frames //
	_tweenParams( float* a_property, float a_end, int a_delay, int a_duration, int a_easeType=EASE_LINEAR) {
		bUseSeconds = false;
		setup( a_property, *a_property, a_end, a_delay, a_duration, a_easeType );
	}
	_tweenParams( float* a_property, float a_begin, float a_end, int a_delay, int a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0) {
		bUseSeconds = false;
		setup( a_property, a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a );
	}
	
	
	// params for seconds based tween //
	_tweenParams( float* a_property, float a_end, float a_delay, float a_duration, int a_easeType=EASE_LINEAR ) {
		bUseSeconds = true;
		setup( a_property, *a_property, a_end, a_delay, a_duration, a_easeType );
	}
	_tweenParams( float* a_property, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0 ) {
		bUseSeconds = true;
		setup( a_property, a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a );
	}
	// setup in frame //
	void setup( float* a_property, float a_begin, float a_end, int a_delay, int a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0 ) {
		property	= a_property;
		begin		= a_begin;
		end			= a_end;
		delay		= a_delay;
		duration	= a_duration;
		easeType	= a_easeType;
		p			= a_p;
		a			= a_a;
		bUseSeconds	= false;
	}
	// setup in seconds //
	void setup( float* a_property, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0 ) {
		property	= a_property;
		begin		= a_begin;
		end			= a_end;
		delay		= a_delay;
		duration	= a_duration;
		easeType	= a_easeType;
		p			= a_p;
		a			= a_a;
		bUseSeconds	= true;
	}
	
	float *property;
	float begin, end;
	float duration;
	float delay;
	int easeType;
	// amplitude and period for certain easing functions (elastic, bounce and back)
	float a;
	float p;
	
	bool bUseSeconds;
} TweenParams;



class Tweenzor {
public:
	static Tweenzor* Instance();
	
	static void init();
	static void update(int a_millis);
    
    // float
	static Tween& framesAdd(float* a_property, float a_begin, float a_end, int a_delay, int a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
	static Tween& add(float* a_property, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);

    // ofVec2f
    static TweenVec2& add(ofVec2f* a_vec, const ofVec2f& v_begin, const ofVec2f& v_end, float a_delay, float a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec2& add(ofVec2f* a_vec, const ofVec2f& v_begin, const ofVec2f& v_end, int a_delay, int a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    
    // ofVec3f
    static void add(ofVec3f* a_vec, const ofVec3f& v_begin, const ofVec3f& v_end, float a_delay, float a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    
    // ofVec4f
    static void add(ofVec4f* a_vec, const ofVec4f& v_begin, const ofVec4f& v_end, float a_delay, float a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    
    // ofRectangle
    static void add(ofRectangle* a_rect, const ofRectangle& r_begin, const ofRectangle& r_end, float a_delay, float a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    
    // ofFloatColor
    static void add(ofFloatColor* a_color, const ofFloatColor& c_begin, const ofFloatColor& c_end, float a_delay, float a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    
	// I never use these. Decide whether or not to keep them
    static void add(vector <float *> a_properties, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
	static void add( TweenParams& a_params );
	static void add( vector<TweenParams>& a_params );
    
    
    static void removeTween(Tween * tween);
	static void removeTween(float * a_property);
    static void removeTween(ofVec2f * a_property);
    static void removeAllTweens();
	
	static void destroy();
	
	static void pauseAllTweens();
	static void resumeAllTweens();
	static void resetAllTweens();
	static void toggleAllTweens();
	
	static int getSize();
	
	static Tween* getTween(float * a_property);
    static TweenVec2 * getTween(ofVec2f *vec);
    static Tween* getTween(ofVec3f *vec);
    static Tween* getTween(ofVec4f *vec);
    static Tween* getTween(ofRectangle *rect);
    static Tween* getTween(ofFloatColor *color);
    
	static Tween* getRecentTween();
    
	
	static void removeCompleteListener( Tween* a_tween );
	static void removeCompleteListener( float* a_property );
    static void removeCompleteListener( ofVec2f * a_property );
	static void removeAllListeners();
	

protected:
	Tweenzor() {};
	
private:
	static Tweenzor* __instance;
	vector <Tween *> _tweens;	
	int _currMillis;
};

#endif






