#include <Geode/Geode.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>

using namespace geode::prelude;

/**
 * Main layer exposing mod menu's functionality.
*/
class ModMenuLayer : public geode::Popup<> {
	protected:
		bool setup() override {
			this->setTitle("Lena's Mod Menu");

			return true;
		}
	
	public:
		/**
		 * Creates an instance of this class. Note: this a fullscreen popup.
		*/
	    static ModMenuLayer* create() {
			auto ret = new ModMenuLayer();
			auto winSize = CCDirector::sharedDirector()->getWinSize();

			if (ret && ret->init(winSize.width, winSize.height)) {
				ret->autorelease();
				return ret;
			}

			CC_SAFE_DELETE(ret);
			return nullptr;
		}
};

class $modify(CCKeyboardDispatcher) {
	bool dispatchKeyboardMSG(enumKeyCodes key, bool down) {
		if (down && key == KEY_Tab) {
			auto modMenu = ModMenuLayer::create();

			if (modMenu) {
				CCDirector::sharedDirector()->getRunningScene()->addChild(modMenu);
				return true;
			}
		}

		return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down);
	}
};