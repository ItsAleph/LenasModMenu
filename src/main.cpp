#include <Geode/Geode.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>

using namespace geode::prelude;
using namespace std;

/**
 * Main layer exposing mod menu's functionality.
*/
class ModMenuLayer : public geode::Popup<> {
	protected:
	    static ModMenuLayer* current;

		bool setup() override {
			this->setTitle("Lena's Mod Menu");

			return true;
		}

		void onClose(cocos2d::CCObject* sender) override {
			std::cout << "Mod menu closed" << std::endl;
			this->removeFromParent();
			ModMenuLayer::current = nullptr;
		}
	
	public:
		/**
		 * Creates an instance of this class. Note: this a fullscreen popup.
		*/
	    static ModMenuLayer* create() {
			std::cout << "Creating mod menu" << std::endl;
			auto ret = new ModMenuLayer();
			auto winSize = CCDirector::sharedDirector()->getWinSize();

			auto offsetX = winSize.width - (winSize.width * 0.1); // 10% of the screen width
			auto offsetY = winSize.height - (winSize.height * 0.05); // 5% of the screen height
			auto width = abs(winSize.width - (offsetX * 2)); // menu width
			auto height = abs(winSize.height - (offsetY * 2)); // menu height

			if (ret && ret->init(width, height)) {
				// ret->setPosition(winSize.width - offsetX, winSize.height - offsetY);
				ret->autorelease();
				return ret;
			}

			CC_SAFE_DELETE(ret);
			return nullptr;
		}

		static ModMenuLayer* get() {
			if (!current) {
				auto menu = ModMenuLayer::create();
				current = menu;
			}
			return current;
		}
};

class $modify(CCKeyboardDispatcher) {
	bool dispatchKeyboardMSG(enumKeyCodes key, bool down) {
		if (down && key == KEY_Tab) {
			auto modMenu = ModMenuLayer::get();

			if (modMenu) {
				CCDirector::sharedDirector()->getRunningScene()->addChild(modMenu);
				return true;
			}
		}

		return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down);
	}
};
