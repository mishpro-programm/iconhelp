#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/ProfilePage.hpp>
class $modify(MProfilePage, ProfilePage) {

	void loadPageFromUserInfo(GJUserScore* p0) {
		ProfilePage::loadPageFromUserInfo(p0);
		auto menu = as<CCNode*>(this->getChildren()->objectAtIndex(0))->getChildByID("player-menu");
		
		auto cSize = new CCSize(42.6f, 42.6f);
		auto cubeSprite = menu->getChildByID("player-icon");
		auto cubeBtn = CCMenuItemSpriteExtra::create(cubeSprite->getChildByID("player-icon"), this, menu_selector(MProfilePage::onCubeInfo));
		cubeSprite->removeFromParentAndCleanup(false);
		cubeBtn->setPosition(cubeSprite->getPositionX(), cubeSprite->getPositionY());
		cubeBtn->setContentSize(cSize);
		menu->addChild(btn);
	}

	void onCubeInfo(CCObject*) {
		auto popup = ItemInfoPopup::create(m_score->m_playerCube, GameManager::sharedState()->iconTypeToUnlockType(IconType::Cube));
		popup->setZOrder(this->getZOrder() + 1);
		CCScene::get()->addChild(popup);
	}
};
