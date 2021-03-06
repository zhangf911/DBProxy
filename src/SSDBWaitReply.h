#ifndef _SSDB_WAIT_REPLY_H
#define _SSDB_WAIT_REPLY_H

#include <vector>
#include <string>
#include <memory>

#include "BaseWaitReply.h"

class SSDBSingleWaitReply : public BaseWaitReply
{
public:
    SSDBSingleWaitReply(ClientLogicSession* client);
private:
    virtual void    onBackendReply(int64_t dbServerSocketID, const char* buffer, int len);
    void            mergeAndSend(ClientLogicSession*);
};

class SSDBMultiSetWaitReply : public BaseWaitReply
{
public:
    SSDBMultiSetWaitReply(ClientLogicSession* client);
private:
    virtual void    onBackendReply(int64_t dbServerSocketID, const char* buffer, int len);
    void            mergeAndSend(ClientLogicSession*);
};

class SSDBMultiGetWaitReply : public BaseWaitReply
{
public:
    SSDBMultiGetWaitReply(ClientLogicSession* client);
private:
    virtual void    onBackendReply(int64_t dbServerSocketID, const char* buffer, int len);
    void            mergeAndSend(ClientLogicSession*);
};

typedef SSDBMultiSetWaitReply SSDBMultiDelWaitReply;

#endif