#include <Geode/Geode.hpp>

/**
 * Main layer exposing mod menu's functionality.
 */
class ModMenuLayer : public geode::Popup<>
{
  protected:
    static ModMenuLayer *current;

    bool setup() override;
    void onClose(cocos2d::CCObject *sender) override;

  public:
    void destroyObj();

    /**
     * Creates an instance of this class.
     */
    static ModMenuLayer *create();

    static ModMenuLayer *get();
};
