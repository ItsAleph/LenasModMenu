#include "ModMenuLayer.hpp"

#include <Geode/Geode.hpp>

bool ModMenuLayer::setup()
{
    this->setTitle("Lena's Mod Menu");

    auto menu = cocos2d::CCMenu::create();
    auto button = ButtonSprite::create("Some option");

    if (!(button) || !(menu))
        return false;

    menu->addChild(button);
    menu->updateLayout();
    this->addChild(menu);
    this->updateLayout();

    return true;
}

void ModMenuLayer::onClose(cocos2d::CCObject *sender)
{
    this->destroyObj();
}

void ModMenuLayer::destroyObj()
{
    this->removeFromParent();
    current = nullptr;
}

/**
 * Creates an instance of this class.
 */
ModMenuLayer *ModMenuLayer::create()
{
    auto ret = new ModMenuLayer();
    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

    auto offsetX = winSize.width - (winSize.width * 0.05);   // 5% of the screen width
    auto offsetY = winSize.height - (winSize.height * 0.05); // 5% of the screen height
    auto width = abs(winSize.width - (offsetX * 2));         // menu width
    auto height = abs(winSize.height - (offsetY * 2));       // menu height

    if (ret && ret->init(width, height))
    {
        current = ret;
        ret->setID("lenas-mod-menu-layer");
        ret->setZOrder(100);
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return nullptr;
}

ModMenuLayer *ModMenuLayer::get()
{
    return current;
}

ModMenuLayer *ModMenuLayer::current = nullptr;
