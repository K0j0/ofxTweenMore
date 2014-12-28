#ifndef _TWEEN_LISTNER_
#define _TWEEN_LISTNER_

#include "ofMain.h"

class TweenListener{
private:
    class InnerBase{
    public:
        InnerBase(){}
        virtual void operator()() = 0;
    };
    
public:
    // void function no parameters
    template<class Class>
    class InnerTL : public InnerBase {
    public:
        InnerTL(){
            m_target = NULL;
            m_callback = NULL;
        }
        
        InnerTL(Class * target, void (Class::*callback)()){
            m_target = target;
            m_callback = callback;
        }
        
        ~InnerTL(){}
        
        virtual void operator()(){
            (m_target->*m_callback)();
        }
        
    protected:
        Class * m_target;
        void (Class::*m_callback)();
    };
    
    // void function dynamic parameter
    template<class Class, typename Param>
    class InnerTL2 : public InnerBase {
    public:
        InnerTL2(){
            m_target = NULL;
            m_callback = NULL;
            m_p = NULL;
        }
        
        InnerTL2(Class * target, void (Class::*callback)(Param p), Param p){
            m_target = target;
            m_callback = callback;
            m_p = p;
        }
        
        ~InnerTL2(){}
        
        virtual void operator()(Param p){
            (m_target->*m_callback)(p);
//            m_callback(p);
//            (m_target)->(m_callback)(m_p);
        }
        
        virtual void operator()(){
            ofLogWarning() << "Wil this work?";
            (m_target->*m_callback)(m_p);
        }
        
    protected:
        Class * m_target;
        void (Class::*m_callback)(Param p);
        Param m_p;
    };
    
    
    TweenListener() {}
    InnerBase * m_inner;
};

#endif