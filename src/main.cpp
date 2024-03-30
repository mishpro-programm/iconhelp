#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/ProfilePage.hpp>
class $modify(MProfilePage, ProfilePage) {

	void loadPageFromUserInfo(GJUserScore* p0) {
		ProfilePage::loadPageFromUserInfo(p0);
		//170.5,-10
		auto sprite = ButtonSprite::create("Icons");
		auto btn = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(MProfilePage::onIconsInfo));
		btn->setPosition(170.5f, -10.f);
		auto menu = as<CCNode*>(this->getChildren()->objectAtIndex(0))->getChildByID("player-menu");
		if(menu){
			menu->addChild(btn);
		}
	}

	void onIconsInfo(CCObject*) {
		auto popup = ItemInfoPopup::create(m_score->m_playerCube, GameManager::sharedState()->iconTypeToUnlockType(IconType::Cube));
		popup->setZOrder(this->getZOrder() + 1);
		CCScene::get()->addChild(popup);
	}
};
