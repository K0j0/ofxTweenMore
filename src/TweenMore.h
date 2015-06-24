
#ifndef _TWEENMORE_
#define _TWEENMORE_

#include "ofColor.h"
#include "ofVec2f.h"
#include "Tween.h"
#include "TweenVec2.h"
#include "TweenVec3.h"
#include "TweenVec4.h"
#include "TweenColor.h"
#include "TweenRect.h"
#include "TweenListener.h"


class TweenMore {
public:
	static TweenMore* Instance();
	
	static void init();
	static void update(int a_millis);
	static Tween& addTween(Tween * tween);
    
    // float
    static Tween& add(float* a_property, float a_begin, float a_end,float a_duration,  float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static Tween& to(float* a_property, float a_end, float a_duration,  float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static Tween& from(float* a_property, float a_begin, float a_duration,  float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
	static Tween& framesAdd(float* a_property, float a_begin, float a_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static Tween& framesTo(float* a_property, float a_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static Tween& framesFrom(float* a_property, float a_begin, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);

    // ofVec2f
    static TweenVec2& add(ofVec2f* a_vec, const ofVec2f& v_begin, const ofVec2f& v_end, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec2& to(ofVec2f* a_vec, const ofVec2f& v_end, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec2& from(ofVec2f* a_vec, const ofVec2f& v_begin, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec2& framesAdd(ofVec2f* a_vec, const ofVec2f& v_begin, const ofVec2f& v_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec2& framesTo(ofVec2f* a_vec, const ofVec2f& v_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec2& framesFrom(ofVec2f* a_vec, const ofVec2f& v_begin, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    
    // ofVec3f
    static TweenVec3& add(ofVec3f* a_vec, const ofVec3f& v_begin, const ofVec3f& v_end, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec3& to(ofVec3f* a_vec, const ofVec3f& v_end, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec3& from(ofVec3f* a_vec, const ofVec3f& v_begin, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec3& framesAdd(ofVec3f* a_vec, const ofVec3f& v_begin, const ofVec3f& v_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec3& framesTo(ofVec3f* a_vec, const ofVec3f& v_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec3& framesFrom(ofVec3f* a_vec, const ofVec3f& v_begin, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    
    // ofVec4f
    static TweenVec4& add(ofVec4f* a_vec, const ofVec4f& v_begin, const ofVec4f& v_end, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec4& to(ofVec4f* a_vec, const ofVec4f& v_end, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec4& from(ofVec4f* a_vec, const ofVec4f& v_begin, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec4& framesAdd(ofVec4f* a_vec, const ofVec4f& v_begin, const ofVec4f& v_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec4& framesTo(ofVec4f* a_vec, const ofVec4f& v_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenVec4& framesFrom(ofVec4f* a_vec, const ofVec4f& v_begin, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    
    // ofRectangle
    static TweenRect& add(ofRectangle* a_rect, const ofRectangle& r_begin, const ofRectangle& r_end, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenRect& to(ofRectangle* a_rect, const ofRectangle& r_end, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenRect& from(ofRectangle* a_rect, const ofRectangle& r_begin, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenRect& framesAdd(ofRectangle* a_rect, const ofRectangle& r_begin, const ofRectangle& r_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenRect& framesTo(ofRectangle* a_rect, const ofRectangle& r_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenRect& framesFrom(ofRectangle* a_rect, const ofRectangle& r_begin, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    
    // ofFloatColor
    static TweenColor& add(ofFloatColor* a_color, const ofFloatColor& c_begin, const ofFloatColor& c_end, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenColor& to(ofFloatColor* a_color, const ofFloatColor& c_end, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenColor& from(ofFloatColor* a_color, const ofFloatColor& c_begin, float a_duration, float a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenColor& framesAdd(ofFloatColor* a_color, const ofFloatColor& c_begin, const ofFloatColor& c_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenColor& framesTo(ofFloatColor* a_color, const ofFloatColor& c_end, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    static TweenColor& framesFrom(ofFloatColor* a_color, const ofFloatColor& c_begin, int a_duration, int a_delay=0, int a_easeType=EASE_LINEAR, float a_p=0, float a_a=0);
    
    static void removeTween(Tween * tween);
	static void removeTween(float * a_property);
    static void removeTween(ofVec2f * a_property);
    static void removeTween(ofVec3f * a_property);
    static void removeTween(ofVec4f * a_property);
    static void removeTween(ofFloatColor * a_property);
    static void removeTween(ofRectangle * a_property);
    static void removeAllTweens();
    static void removeTweenGroup(int id);
	
	static void destroy();
	
	static void pauseAllTweens();
	static void resumeAllTweens();
	static void resetAllTweens();
	static void toggleAllTweens();
	
	static int getSize();
	
	static Tween* getTween(float * a_property);
    static TweenVec2 * getTween(ofVec2f *vec);
    static TweenVec3 * getTween(ofVec3f *vec);
    static TweenVec4 * getTween(ofVec4f *vec);
    static TweenRect * getTween(ofRectangle *rect);
    static TweenColor * getTween(ofFloatColor *color);

	static Tween* getRecentTween();
    
	
	static void removeCompleteListener( Tween* a_tween );
	static void removeCompleteListener( float* a_property );
    static void removeCompleteListener( ofVec2f * a_property );
    static void removeCompleteListener( ofVec3f * a_property );
    static void removeCompleteListener( ofVec4f * a_property );
	static void removeAllListeners();
	

protected:
	TweenMore() {};
	
private:
	static TweenMore* __instance;
	vector <Tween *> _tweens;	
	int _currMillis;
};

typedef TweenMore TM;

#endif






