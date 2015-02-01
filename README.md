#ofxTweenMore
A fork of [ofxTweenzor](https://github.com/NickHardeman/ofxTweenzor) with some API changes and new features

##C++ Tweening Library

What's different?
--------
* To and From tweens (Shorthand for when you want to start or end with a variable's current value)
* Swapped position of delay and duration and made delay optional (Less typing since tweens don't always need a delay)
* TM shorthand (Just a typedef for a little less typing)
* Ping ponged tweens no longer count against a tween's count (If ping pong is set to true, going out and back is counted as 1 iteration rather than 2)
* Specific tween types for certain parameters (@tiagosr added a feature to tween vectors, colors and rectangles. Now those kinds of tweens can be referenced explicitly. They're no longer just a bunch of float tweens)
* Generlaized callbacks (callbacks can now take any parameter or no paramater, rather than just float)
  * Callback parameters can also be passed to a callback function

  ```TM::to(&myVar, targetValue, duration).addListener(this, &ofApp::callbackNoParams);```

  or

    ```TM::to(&myVar, targetValue, duration).addListener(this, &ofApp::callbackIntParam, 17);```

    or  even

    ```TM::to(&myVar, targetValue, duration).addListener(this, &ofApp::callbackPointerParam, &someObject);```



* Simple chaining (A simple way to create a sequence of tweens for the same property)

    ```TM::to(&myVar, targetValue1, duration).chainTo(targetValue2, duration).chainTo(targetValue3, duration);```



What's planned?
--------
* Tween groups that can be controlled/deleted together
* A timeline
* Maybe even more generalized callbacks with return types other than void
* Custom tween handlers (onStart, onUpdate) with parameters
* Lambda callbacks once C++11 is fully supported in OFX
