#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/ProfilePage.hpp>
class $modify(MProfilePage, ProfilePage) {

	void loadPageFromUserInfo(GJUserScore* p0) {
		ProfilePage::loadPageFromUserInfo(p0);
		//170.5,-10
		auto sprite = as<CCNode*>(this->getChildren()->objectAtIndex(0))->getChildByID("player-menu")->getChildByID("player-icon");
		auto btn = CCMenuItemSpriteExtra::create(sprite->getChildByID("player-icon"), this, menu_selector(MProfilePage::onIconsInfo));
		sprite->removeFromParentAndCleanup(false);
		btn->setPosition(sprite->getPositionX(), sprite->getPositionY());
		auto menu = as<CCNode*>(this->getChildren()->objectAtIndex(0))->getChildByID("player-menu");
		if(menu){
			menu->addChild(btn);
			//menu->updateLayout();
		}
	}

	void onIconsInfo(CCObject*) {
		auto popup = ItemInfoPopup::create(m_score->m_playerCube, GameManager::sharedState()->iconTypeToUnlockType(IconType::Cube));
		popup->setZOrder(this->getZOrder() + 1);
		CCScene::get()->addChild(popup);
	}
};
