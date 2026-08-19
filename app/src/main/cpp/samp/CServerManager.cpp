#include "main.h"
#include "CServerManager.h"
#include "settings.h"

#include "gui/gui.h"
extern UI *pUI;
#include "net/netgame.h"
extern CNetGame *pNetGame;
#include "java/jniutil.h"

extern CJavaWrapper *pJavaWrapper;

int CServerInstance::iServer = -1;

void CServerInstance::initConnection(int id) {
    CServerInstance::iServer = id;

    // Подключаемся по IP и порту, указанным в settings.ini
    pNetGame = new CNetGame(
            pSettings->Get().szIP,
            pSettings->Get().iPort,
            pSettings->Get().szNickName,
            pSettings->Get().szPassword);
}
