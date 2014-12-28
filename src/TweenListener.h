#ifndef _TWEEN_LISTNER_
#define _TWEEN_LISTNER_

#include "ofMain.h"

class TweenListener{
private:
    class InnerBase{
    public:
        InnerBase(){}
        virtual void operator()() = 0;
        virtual void clear() = 0;
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
            if(m_target == NULL || m_callback == NULL){
                ofLogError() << "TweenListener callback has NULL properties";
                return;
            }
            (m_target->*m_callback)();
        }
        
        virtual void clear(){
            m_target = NULL;
            m_callback = NULL;
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
        
        virtual void operator()(){
            if(m_target == NULL || m_callback == NULL){
                ofLogError() << "TweenListener callback has NULL properties";
                return;
            }
            (m_target->*m_callback)(m_p);
        }
        
        virtual void clear(){
            m_target = NULL;
            m_callback = NULL;
            // can't set m_p to NULL since = becomes ambiguous for strings (and probably other types). Not sure if this is a real leak or problem
        }
        
    protected:
        Class * m_target;
        void (Class::*m_callback)(Param p);
        Param m_p;
    };
    
    
    TweenListener() {}
    InnerBase * m_inner;
    void clear() { m_inner->clear(); }
};

#endif