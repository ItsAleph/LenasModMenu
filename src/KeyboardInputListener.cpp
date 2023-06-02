#include <Geode/Geode.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>

#include "ModMenuLayer.hpp"
// #include <hjfod.custom-keybinds/include/Keybinds.hpp> // TODO: Figure out
// how to bind globally

using namespace geode;

class $modify(cocos2d::CCKeyboardDispatcher){bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool down){
    if (down && key == cocos2d::KEY_Tab){auto modMenu = ModMenuLayer::get();

if (modMenu)
{
    modMenu->destroyObj();
    return true;
}
else
{
    modMenu = ModMenuLayer::create();

    if (modMenu)
    {
        cocos2d::CCDirector::sharedDirector()->getRunningScene()->addChild(modMenu);
        return true;
    }
    else
    {
        return false;
    }
}
}

return cocos2d::CCKeyboardDispatcher::dispatchKeyboardMSG(key, down);
}
}
;
