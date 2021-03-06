﻿#ifndef SESSIONLISTDAO_H
#define SESSIONLISTDAO_H

#include "DaoInterface.h"
#include "../include/CommonStrcut.h"
#include <vector>

#ifdef _LINUX
#include <memory>
#endif

namespace QTalk {
    namespace Entity {
        struct ImSessionInfo;
    }
}
class SessionListDao : public DaoInterface{
public:
    explicit SessionListDao(qtalk::sqlite::database *sqlDb = nullptr);
    bool creatTable() override;
    bool clearData() override;

public:
//    bool insertSessionInfo(const QTalk::Entity::ImSessionInfo &imSessionInfo);
//
//    bool bulkInsertSessionInfo(const std::vector<QTalk::Entity::ImSessionInfo> &sessionList);

    bool bulkDeleteSession(const std::vector<std::string> &groupIds);

    bool bulkremoveSessionMessage(const std::vector<std::string> &groupIds);

    std::shared_ptr<std::vector<std::shared_ptr<QTalk::Entity::ImSessionInfo>>> QueryImSessionInfos();
    std::shared_ptr<std::vector<std::shared_ptr<QTalk::Entity::ImSessionInfo> > > reloadSession();
    //
    void updateUnreadCount();
    //
    void getRecentSession(std::vector<QTalk::StShareSession>& sessions);

    void updateRealJidForFixBug();
    // 修正消息type
    void fixMessageType();
    //
    void clearSelfUnRead(const std::string& xmppId);

public:
    bool deleteAllSession();

//    bool initSession();
//
//    bool initConfigSessions();

//    bool initSessionInfo(std::vector<std::string> *userList);
};

#endif // SESSIONLISTDAO_H
