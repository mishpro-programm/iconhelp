#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/ProfilePage.hpp>
class $modify(MProfilePage, ProfilePage) {

	bool init(int accId, bool ownProfile) {
		if (!ProfilePage::init(accId, ownProfile)) {
			return false;
		}
		//170.5,-10
		auto sprite = ButtonSprite::create("Icons");
		auto btn = CCMenuItemSpriteExtra::create(sprite, nullptr, menu_selector(MProfilePage::onIconsInfo));
		btn->setPosition(170.5f, -10.f);
		this->getChildByID("player-menu")->addChild(btn);

		return true;
	}

	void onIconsInfo(CCObject*) {
		FLAlertLayer::create("Geode", "Hello from my custom mod!", "OK")->show();
	}
};
