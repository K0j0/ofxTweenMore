//
//  TweenEvent2.h
//  TweenzorSimpleExample
//
//  Created by Kojo Kumah on 12/27/14.
//
//


#ifndef _TWEEN_EVENT2_
#define _TWEEN_EVENT2_

#include "ofMain.h"

class Tween;

// event delegation //
/// http://www.codeproject.com/KB/cpp/accppdelegates.aspx //

template <typename Parameter>
class TweenEvent2 {
private:
    class Base {
    public:
        virtual ~Base() { }
        virtual void operator()(Parameter args) = 0;
    };
    Base* pointerino;
    bool _assigned;
    
public:
    unsigned int ID; // this is the tween that is using it //
    template <typename Class>
    class T : public Base {
        // Signature applied to a pointer-to-member for target class.
        typedef void (Class::*Func)(Parameter args);
        
        
    private:
        Class* mThis; // Pointer to the object we are delegating to.
        Func   mFunc; // Address of the function on the delegate object.
        
    public:
        
        T(Class* aThis, void (Class::*aFunc)(Parameter args)) : mThis(aThis), mFunc(aFunc) { }
        
        virtual void operator()(Parameter args) {
            return (mThis->*mFunc)(args);
        }
        
        
    };
    
    ~TweenEvent2() {	}//cout << "calling the deconstructor" << endl;}//destroy(); }
    
    TweenEvent2() {_assigned = false;}
    // associates with the tween //
    virtual void setID(unsigned int a_id) {
        ID = a_id;
    }
    virtual unsigned int getID() {
        return ID;
    }
    
    void destroy() {
        if (_assigned) {
            //cout << "there is a pointerino" << endl;
            delete pointerino;
            pointerino = NULL;
        }
        _assigned = false;
        //cout << "deleting pointerino _assigned = " << _assigned << endl;
    }
    
    TweenEvent2& operator = (Base* aPtr) {
        pointerino = aPtr;
        _assigned = true;
        return *this;
    }
    
    bool operator == (const bool& b) {
        return _assigned;
    }
    
    void operator()(Parameter args) {
        if (pointerino) {
            //cout << "TweenEvent2 :: operator args = " << *args << "  _assigned = " << _assigned << endl;
            (*pointerino)(args);
        }
    }
};	

#endif